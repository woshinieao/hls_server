#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h> 
#include <pthread.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/epoll.h> /* epoll function */
#include <errno.h>

#include "mydb.h"

#include "hlsServer.h"

static tIrDevInfo   m_pDevList[MAX_DEV_NUM];
static tServerInfo   m_pServerInfo;
static int m_iDevNum = 0;
static db_ops *pDb_ops; 
pthread_mutex_t pid_mutex;




static int hls_dev_logout(long hDev);
static int hls_dev_load();
int hls_dev_status();


int HeartBeat(long /*hDevice*/, int /*iusrdata*/) 
{
	return 0;
}

int AlarmAck(long hDevice, int iusrdata, int ialarmtype, int /*ipara*/, int* pPara )
 {

 printf("\n\n\n\n 11111111111111111111 AlarmAck 111111111111111111111111111n\n\n");
  unsigned char state;
  int i=0;
  switch(ialarmtype)
  {
  	case MINOR_ALARM_CHANNEL_STATE:
		if(hDevice <0 || hDevice != m_pServerInfo.hDev)
			return 0;
		for(i=0;i<m_iDevNum;i++)
		{
			state = (pPara[1] & (1<<i)) ? 1:0;
			if(m_pDevList[i].online == state)
				continue;
			
			if(i>=m_iDevNum )
				return 0;

			if(state ==0) //设备掉线，关闭相关子进程
			{
				m_pDevList[i].online = -1;
			//	m_pDevList[i].devStat = DEV_FFMPEG_OFFLINE;
				if(m_pDevList[i].pid[0]>0)
					kill(m_pDevList[i].pid[0], SIGKILL);
				else if(m_pDevList[i].pid[1]>0)
					kill(m_pDevList[i].pid[1], SIGKILL);
				
				
			}
			else  //设备上线
			{
				if(m_pDevList[i].hDev<0 && m_pDevList[i].online == -1) /*新设备上线*/
				{
					tDeviceInfo  info;
					memset(&info,0,sizeof(tDeviceInfo));
					m_pDevList[i].hDev = NetClient_Login(m_pDevList[i].ip,m_pDevList[i].port,m_pDevList[i].user,m_pDevList[i].passwd,&info);
					if(m_pDevList[i].hDev>0)
					{
						NetClient_HeartBeatSubscribe(m_pDevList[i].hDev,15, 0, HeartBeat);//设备心跳注册	
						printf("dev :%s login success!\n",m_pDevList[i].ip);
						m_pDevList[i].online = 1;
					}
					else
					{
						printf("dev :%s login failed !\n",m_pDevList[i].ip);
						break;
					}

				}
				else
					m_pDevList[i].online = 1;
			}
		}
	  break;
  default:
	  break;
  }
  return 0;
  }


int DevNotify(long hDev,int message,long lPrivate)   /*服务器掉线*/
{
printf("\n\n\n\n 222222222222222222 dev notify 22222222222222222222 n\n\n");
	switch(message)
	{
	
	case MSG_NET_FAILED:
		if(hDev<0 || hDev != m_pServerInfo.hDev)
			return 0;
		for(int i=0;i<m_iDevNum;i++)
		{
			kill(m_pDevList[i].pid[0], SIGKILL);
			kill(m_pDevList[i].pid[1], SIGKILL);
			hls_dev_logout(m_pDevList[i].hDev);
			pthread_mutex_lock(&pid_mutex);
			memset(&m_pDevList[i],-1,sizeof(tIrDevInfo));
			pthread_mutex_unlock(&pid_mutex);
		}
		break;
	case MSG_RECONNECT_SUCCESS:
		if(hDev<0 || hDev != m_pServerInfo.hDev)
			return 0;
		hls_dev_load();
		hls_dev_login();
		break;
	default:
		break;
	}
	return 0;

}


int CreateAllDirectory(char *dir)
{
	
	char *pTemp     = NULL;
	char *pTemp1    = NULL;
	char ch;
	char path[128];
	
	strcpy(path,dir);
    if(access(path,0) == 0)
    {
        return bTRUE;
    }

	pTemp = path;
	/*去掉第一个跟路径*/
	while(*pTemp == '\\' || *pTemp == '/')
		pTemp++;
    while(1)
    {
    	pTemp1 = pTemp;
        pTemp = strchr(pTemp1,'\\');
        if(pTemp == NULL)
        {
        	pTemp = strchr(pTemp1,'/');
			if(pTemp == NULL)
            	break;
        }
		ch = *pTemp;
        if(*(pTemp-1) == ':')
        {
            pTemp += 1;
            continue;
        }
        *pTemp = 0;
        if(access(path,0) != 0)
        {
            if(mkdir(path,0777) != 0)
            {
                return bFALSE;
            }
        }
        *pTemp = ch;
        pTemp++;
    }
    return bTRUE;


}


static int hls_server_load()
{
	void *result;
	char **row;
	char sql[320];
	tServerInfo *pServer = NULL;
	int iRow = 0;
	

	pServer = &m_pServerInfo;
	sprintf(sql,"SELECT dev_ip,dev_name,port,login_user,login_passwd  FROM table_client_dev");
	result = pDb_ops->getfirst(sql);
	while (result)
	{
		
		row   = (char **)result;
		iRow  = 0;
		pServer->hDev = -1;

		/*dev_ip*/
		if(row[iRow] == NULL)
			goto failed;
		strcpy(pServer->ip,row[iRow]);
		iRow++;

		/*name*/
		if(row[iRow] == NULL)
			goto failed;
		strcpy(pServer->name,row[iRow]);
		iRow++;

		/*port*/
		if(row[iRow] == NULL)
			goto failed;
		pServer->port= atoi(row[iRow]);
		iRow++;

		/*user*/
		if(row[iRow] == NULL)
			goto failed;
		strcpy(pServer->user,row[iRow]);
		iRow++;

		/*port*/
		if(row[iRow] == NULL)
			goto failed;
		strcpy(pServer->passwd,row[iRow]);
		iRow++;

		result =pDb_ops->getnext();
	}
	return bTRUE;
failed:
	return bFALSE;
}


int hls_server_login()
{
	tDeviceInfo  info;
	memset(&info,0,sizeof(tDeviceInfo));		
	NetClient_SetNetPort(6080, 6090);
	if(!NetClient_Startup())
	{
	   printf("Net client start up failed!\n");
	   return bTRUE;
	}
	
	m_pServerInfo.hDev = NetClient_Login(m_pServerInfo.ip,m_pServerInfo.port,m_pServerInfo.user,m_pServerInfo.passwd,&info);
	if(m_pServerInfo.hDev>=0)
	{
		NetClient_HeartBeatSubscribe(m_pServerInfo.hDev,15, 0, HeartBeat);//设备心跳注册	
		printf("Server :%s login success!\n",m_pServerInfo.ip);
		return bTRUE;
	}
	else
	{
		printf("Server :%s login failed !\n",m_pServerInfo.ip);
		return bFALSE;
	}	
}


int hls_dev_load()
{
	void *result;
	char **row;
	char sql[320];
	tIrDevInfo *pDev = NULL;
	int iRow = 0;
	m_iDevNum = 0;
	int idevNum = 0;

	//time_t now = time(NULL);
	memset(m_pDevList,-1,sizeof(m_pDevList));
	for(idevNum=0;idevNum<MAX_DEV_NUM;idevNum++)
	{
		m_pDevList[idevNum].hDev    = -1;
		m_pDevList[idevNum].online  = bFALSE;
		//m_pDevList[idevNum].devStat= DEV_FFMPEG_CLEAR;
	}
	
//	sprintf(sql,"select dev_ip,dev_name,a.dev_id,port,login_user,login_passwd,output_value,plc_timer,cruise_state,room_id,c.update_time,c.cur_preset_id,plc_num,ir_url,vl_url from table_dev_list a left join table_plc_port b on a.plc_port=b.line left join table_dev_state c on a.dev_id=c.dev_id order by a.channel_id asc");

	sprintf(sql,"SELECT dev_id,dev_ip,dev_name,port,login_user,login_passwd	FROM table_dev_list order by channel_id asc");
	
	pDev   = &m_pDevList[m_iDevNum];
	result = pDb_ops->getfirst(sql);
	while (result)
	{
		pDev = &m_pDevList[m_iDevNum];
		row   = (char **)result;
		iRow  = 0;

		pDev->hDev = -1;
		
		/*dev_id*/
		if(row[iRow] == NULL)
			continue;
		strcpy(pDev->dev_id,row[iRow]);
		iRow++;	
		
		/*dev_ip*/
		if(row[iRow] == NULL)
			continue;
		strcpy(pDev->ip,row[iRow]);
		iRow++;
		

		
		/*dev_name*/
		if(row[iRow] == NULL)
			continue;
		strcpy(pDev->name,row[iRow]);
		iRow++;

		/*dev_port*/
		if(row[iRow] == NULL)
			continue;
		pDev->port=atoi(row[iRow]);
		iRow++;

		
		/*user*/
		if(row[iRow] == NULL)
			strcpy(pDev->user,"admin");
		else
			strcpy(pDev->user,row[iRow]);
		iRow++;

		/*passwd*/
		if(row[iRow] == NULL)
			strcpy(pDev->passwd,"admin");
		else
			strcpy(pDev->passwd,row[iRow]);
		iRow++;
		
		m_iDevNum++;
		result = pDb_ops->getnext();
	}
	if(m_iDevNum<=0)
	{
		printf("load dev failed!\n");
		return bFALSE;
	}
	return bTRUE;
}


void hls_signal_handler(int signo) 
{

	int i=0;
	pid_t chlpid;
	if (signo == SIGCHLD) 
	{
		while((chlpid = waitpid(-1,NULL,WNOHANG))>0)
		{

	
		printf(" hls_signal_handler :  chlpid = %d\n",chlpid);
			if(chlpid<=0)
				return;
			for( i = 0;i<m_iDevNum;i++)
	        {
				//谙呱璞?子进程异常
				if(m_pDevList[i].hDev<0)
					continue;
	        	if(m_pDevList[i].pid[0] == chlpid )
	        	{
	        		m_pDevList[i].pid[0] = -1;
					break;
				}
				if( m_pDevList[i].pid[1] == chlpid)
	        	{
	        		m_pDevList[i].pid[1] = -1;
					break;
				}
			}
			
			printf("dev_id : %s\n"
					"pid[0]: %d\n"
					"pid[1]: %d\n",m_pDevList[i].dev_id,m_pDevList[i].pid[0],m_pDevList[i].pid[1]);
		printf("-------------------------------------------------\n");		
		}
	}

    return ;
}


int hls_dev_fork(tIrDevInfo *dev,int channel)
{
	pid_t tmppid=0;
	char url[256]= {'\0'};
	char path[256]= {'\0'};
	char tspath[256]= {'\0'};

	if(dev->pid[channel]>0)
		return -1;
	if(channel==1)
	{
		//sprintf(url,"rtsp://%s:554/h264/ch1/main/av_stream",m_pDevList[i].ip);
		strcpy(url,"rtsp://192.168.1.64:554/h264/ch1/main/av_stream");
		sprintf(path,"/var/www/media/stream/%s/vl/stream.m3u8",dev->dev_id);
		sprintf(tspath,"/var/www/media/stream/%s/vl/hs%%02d.ts",dev->dev_id);


		
		//strcpy(path,"/var/www/media/stream/XJ-20130312-169/vl/stream.m3u8");
		//strcpy(tspath,"/var/www/media/stream/XJ-20130312-169/vl/hs%02d.ts");
	}
	else if(channel == 0)
	{

	//	sprintf(url,"rtsp://%s:8556/h264",m_pDevList[i].ip);
		strcpy(url,"rtsp://192.168.1.169:8556/h264");
		
		//sprintf(url,"rtsp://%s:554/h264/ch1/main/av_stream",m_pDevList[i].ip);
		sprintf(path,"/var/www/media/stream/%s/ir/stream.m3u8",dev->dev_id);
		sprintf(tspath,"/var/www/media/stream/%s/ir/hs%%02d.ts",dev->dev_id);

	//	strcpy(path,"/var/www/media/stream/XJ-20130312-169/ir/stream.m3u8");
	//	strcpy(tspath,"/var/www/media/stream/XJ-20130312-169/ir/hs%02d.ts");
	}
	else
		return -1;

	CreateAllDirectory(path);
	CreateAllDirectory(tspath);

	if((tmppid = fork())==0)
	{
//  FILE * fdwrite = freopen("/home/nieao/111.txt","w",stdout);
  FILE * fdread = freopen("/home/nieao/111.txt","w",stdin);

		execl("/usr/local/bin/ffmpeg","ffmpeg &","-i",url,"-strict","-2",
			  "-codec:v","copy", "-flags", "ildct+ilme",
			  "-b:v", "4000k", "-minrate", "4000k", "-maxrate", "4000k","-bufsize", "1835k", "-f", "hls",
			  "-hls_list_size", "5", "-hls_time", "10", "-hls_allow_cache", "1", "-hls_flags", "delete_segments", "-hls_wrap", "6", 
		  	  "-hls_segment_filename",tspath, path,NULL);
	


	//	execl("/usr/local/bin/ffmpeg", "ffmpeg &" ,"-probesize","32768", "-i",url,"-y","-t","15", "-ss", "1","-f", "image2","-r","1", "/home/samba/lll.jpg", NULL);
	fclose(fdread);
		exit(0);
	}	
	else if(tmppid>0)
	{
		pthread_mutex_lock(&pid_mutex);
		dev->pid[channel] = tmppid;
		pthread_mutex_unlock(&pid_mutex);			
		printf("\n**********************************dev  = %s  channel=%d  pid = %d \n",dev->dev_id,channel,dev->pid[channel]);
		
	}

	return 0;
}


int hls_dev_login()
{
	int i=0;
	tDeviceInfo  info;
	memset(&info,0,sizeof(tDeviceInfo));
	for(i=0;i<m_iDevNum;i++)
	{
		printf(" \n\n **************************************   dev_id :%s  !\n",m_pDevList[i].dev_id);
		if(m_pDevList[i].online == 1)
			continue;
		if(m_pDevList[i].hDev<0   )
			m_pDevList[i].hDev = NetClient_Login(m_pDevList[i].ip,m_pDevList[i].port,m_pDevList[i].user,m_pDevList[i].passwd,&info);
		if(m_pDevList[i].hDev>0)
		{
			NetClient_HeartBeatSubscribe(m_pDevList[i].hDev,15, 0, HeartBeat);//设备心跳注册	
			printf("dev :%s login success!\n",m_pDevList[i].ip);
			m_pDevList[i].online = 1;
		//	m_pDevList[i].devStat = DEV_FFMPEG_CLEAR;
		hls_dev_fork(&m_pDevList[i],0);
		hls_dev_fork(&m_pDevList[i],1);
		}
		else
			printf("dev :%s login failed !\n",m_pDevList[i].ip);
		m_pDevList[i].online = 1;
	}

/*
	for(i=0;i<m_iDevNum;i++)	
	printf(" \n\n **************************************   dev_id :%s  !\n",m_pDevList[i].dev_id);

	for(i=0;i<m_iDevNum;i++)
	{
		if(m_pDevList[i].online!= 1)
			continue;
		m_pDevList[i].hDev = 10+i;
		m_pDevList[i].online = 1;
		hls_dev_fork(&m_pDevList[i],0);
		hls_dev_fork(&m_pDevList[i],1);

		
	}

*/



return bTRUE;

	
}






static int hls_dev_logout(long hDev)
{     		
	int i=0;
	for(i=0;i<m_iDevNum;i++)
		if(m_pDevList[i].hDev == hDev)
			break;
	if(i>=m_iDevNum)
		return bTRUE;

	if(m_pDevList[i].pid[0] != -1)
		kill(m_pDevList[i].pid[0],SIGKILL);
	if(m_pDevList[i].pid[1] != -1)
		kill(m_pDevList[i].pid[1],SIGKILL);
	NetClient_Logout(hDev);	
	pthread_mutex_lock(&pid_mutex);
	memset(&m_pDevList[i],-1,sizeof(tIrDevInfo));
	pthread_mutex_unlock(&pid_mutex);
	return bTRUE;
}



int hls_init_data()
{
	int ret= -1;
	pthread_mutex_init(&pid_mutex, 0);
	pDb_ops  = db_init_mysql();
	
	if((ret = hls_server_load())<0)
		return bFALSE;

		signal(SIGCHLD, hls_signal_handler);
	if((ret = hls_dev_load())<0)
		return bFALSE;
	

	return bTRUE;
}



int hls_init_socket()
{
	int listen_fd = -1;
	int ret = -1;
	int  nNetTimeout=1;
	
	struct sockaddr_un srv_addr;
	
	listen_fd=socket(PF_UNIX,SOCK_STREAM,0);
	if(listen_fd<0)
	{
		perror("cannot create communication socket");
		return -1;
	}  


	srv_addr.sun_family=AF_UNIX;
	strncpy(srv_addr.sun_path,HLS_UNIX_DOMAIN,sizeof(srv_addr.sun_path));
	printf("srv_addr.sun_path=%s\n",srv_addr.sun_path+1);
	unlink(HLS_UNIX_DOMAIN);
	setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR ,&nNetTimeout,sizeof(int));
	ret=bind(listen_fd,(struct sockaddr*)&srv_addr,sizeof(srv_addr));
	if(ret==-1)
	{
		perror("cannot bind server socket");
		close(listen_fd);
		unlink(HLS_UNIX_DOMAIN);
		return -1;
	}

	ret=listen(listen_fd,MAX_SERVER_CHANNEL_NUM);
	if(ret==-1)
	{
		perror("cannot listen the client connect request");
		close(listen_fd);
		unlink(HLS_UNIX_DOMAIN);
		return -1;
	}
	return listen_fd;
}




void hls_fork_server()
{

	int i=0;
	int ret = -1;
	int  nNet=1;

	int listen_fd = -1;
	int com_fd = -1;
	int active_fd = -1;
	
	int fdMax = 0;
	fd_set inset,tmp_inset;
	
	socklen_t len = -1;
	struct timeval tv;
	struct sockaddr_un clt_addr;
	struct sockaddr_un srv_addr;
	
	tCtrlMsg msg;
	int msg_len = sizeof(tCtrlMsg);

	tv.tv_sec = 10;
	tv.tv_usec = 0;
	len=sizeof(clt_addr);
	
	signal(SIGCHLD, hls_signal_handler);
	

	listen_fd = hls_init_socket();

	printf("\n***********************************\n"
			"     Start Listening!	id : %d \n"
			"***********************************\n",listen_fd);
	
	FD_ZERO(&inset);
	FD_SET(listen_fd,&inset);

	len=sizeof(clt_addr);
	fdMax = listen_fd+1;

	while(1)
	{
		
		tmp_inset = inset;
		ret = select(fdMax, &tmp_inset,NULL, NULL,  NULL);
		if(ret <=0)
			continue;
		if (FD_ISSET(listen_fd,&tmp_inset) > 0)
		{
			//连接处理
			com_fd=accept(listen_fd,(struct sockaddr*)&clt_addr,&len);
			if(com_fd<0)
			{
				printf(" accept client connect error");
				continue;
				//unlink(UNIX_DOMAIN);
				
			}
			//将连接上的套接字存入集合
			FD_SET(com_fd,&inset);
			fdMax = com_fd+1;
		
			printf("|****************************|\n");
			printf("|* id	  :%d  connect!    **|\n",com_fd);			
			
			continue;
		}
		for (active_fd=0;active_fd<fdMax;++active_fd)
		{

			if (FD_ISSET(active_fd,&tmp_inset) <= 0)
				continue;
			memset(&msg,0,sizeof(msg));
			int channel = 0;
			ret = recv(active_fd,&msg,msg_len,0);
			if(ret == msg_len)
			{
				for(i=0;i<MAX_DEV_NUM;i++)
						if(strcmp(m_pDevList[i].dev_id,msg.DevId)== 0)
							break;
				if(i>=MAX_DEV_NUM)
					break;
				channel = msg.iparam1-1;
				 if(msg.hlscmd== DEV_FFMPEG_PLAY)
				 {
					hls_dev_fork(&m_pDevList[i],channel);
				 }
				else
				{
					if(m_pDevList[i].pid[channel]>0)
						kill(m_pDevList[i].pid[channel],SIGKILL);
				}
				printf("|*cmd:%d channel :%d pid0 :%d pid1 : %d*|\n",msg.hlscmd,channel,m_pDevList[i].pid[0],m_pDevList[i].pid[1]);
				
			}
			else
			{
				
				//下线处理
				FD_CLR(active_fd,&inset);
				close(active_fd);
				printf("|* id     :%d  exit   !          |\n",active_fd);
				printf("|****************************|\n");
				break;
			}
		
		}
	
	}
	

	close(listen_fd);
	return ;
}








