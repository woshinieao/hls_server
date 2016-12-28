#ifndef _HLSSERVER_H_L
#define _HLSSERVER_H_L
/**/
//#define bFALSE				-1
//#define bTRUE				0
//#include "IrSDK.h"

#include "NetSDK.h"



#define MAX_PATH_LEN 		1024
#define MAX_DEV_NUM			24
#define MAX_SERVER_CHANNEL_NUM (2*MAX_DEV_NUM)

#define NET_SDK_SERVER_PORT      6080    
#define NET_SDK_CLIENT_PORT      6090
#define MAX_SERIAL_NUM_LEN 	32
#define MAX_VERSION_LEN     32
#define MAX_DEV_NAME_LEN	32
#define MAX_IP_STR_LEN     32
#define MAX_USER_NAME_LEN  32
#define MAX_PASSWORD_LEN   32




#define MAX_DEVID_LEN	128


#define HLS_UNIX_DOMAIN "/tmp/HLS.domain"


typedef enum 
{
	FPGA_CTRL_NULL,
}eFpgaCmd;

typedef enum
{ 
	
	DEV_FFMPEG_CLEAR	=	0,
	DEV_FFMPEG_PLAY	,
	DEV_FFMPEG_STOP,
	DEV_FFMPEG_OFFLINE,
	DEV_FFMPEG_EXIT,
		
}eHlsCmd;


typedef enum
{ 
	INF_GET_PRESETID = 0,
	INF_SET_OBJECT,
	INF_SYNC_PRESET,
	INF_SYNC_CRUISE,
	INF_CRUISE_ON,
	INF_CRUISE_OFF,
	INF_RECORD_ON,
	INF_RECORD_OFF,
	INF_RECORD_TIMER,
	INF_PIC_GRAP,
		
}eInfoCmd;





typedef struct _tServerInfo
{
	long	 hDev;								/*NetSDKµÇÂ½¾ä±ú*/
	char	 ip[MAX_IP_STR_LEN];
	char	 name[MAX_DEV_NAME_LEN]; 
	char	 dev_id[MAX_SERIAL_NUM_LEN];
	char	 user[MAX_USER_NAME_LEN];			/*ÓÃ»§Ãû*/
	char	 passwd[MAX_PASSWORD_LEN];	   /*ÃÜÂë*/
	unsigned int 	 port;

}tServerInfo;



typedef struct _IrDevinfo
{

	long	 		hDev;							/*NetSDKµÇÂ½¾ä±ú*/
	char	 		ip[MAX_IP_STR_LEN];
	char		 	name[MAX_DEV_NAME_LEN];
	char	 		dev_id[MAX_SERIAL_NUM_LEN];
	char	 		user[MAX_USER_NAME_LEN];		/*ÓÃ»§Ãû*/
	char	 		passwd[MAX_PASSWORD_LEN];	    /*ÃÜÂë*/
	unsigned int 	port;
	int 			online;	
	int 			devStat;
	pid_t 			pid[2];
	 
}tIrDevInfo;


typedef struct _ctrl_msg
{
	long 	cgid;
	int 	channel;
	char 	DevId[MAX_DEVID_LEN];  /*ÐòÁÐºÅ*/
	int 	cmdType;
	ePtzCmd ptzcmd;
	eFpgaCmd fpgacmd;
	eInfoCmd infocmd;
	eHlsCmd	 hlscmd;
	int 	iparam1;
	int 	iparam2;
	int 	iparam3;
	int 	iparam4;
	//tPresetInfo info;
	long	timeval;
	
}tCtrlMsg;




int hls_init_data();
int hls_server_login();
int hls_dev_login();
int hls_dev_fork(tIrDevInfo dev,int channel);
void hls_fork_server();


#endif

