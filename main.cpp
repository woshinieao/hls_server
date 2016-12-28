#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

#include "hlsServer.h"
#include "mydb.h"





int GetExeName(char *pName)
{
	int iResult = 0;
	char pPath[MAX_PATH_LEN];
	memset(pPath,0,sizeof(pPath));
	iResult = readlink("/proc/self/exe",pPath,MAX_PATH_LEN);
	if(iResult < 0 || iResult > MAX_PATH_LEN)
		return -1;
	while(pPath[iResult] != '/' && iResult >=0)
	{
		iResult--;
	}
	strcpy(pName,pPath+iResult+1);
	return 0;


}

pid_t GetpidByName(char *name)
{
	pid_t 	pid = -1;
	DIR *			dirHandle;	// handle of the directory.
	struct dirent * dirEntry;	// single directory item.
	//prpsinfo_t	  prp;
	int fd;
	if((dirHandle = opendir("/proc")) == NULL)
	{
		return -1;
	}


	
	// open '/proc' use relative path. 
	chdir("/proc");
	while((dirEntry = readdir(dirHandle)) != NULL)
	{
		if(dirEntry->d_name[0] !='.')
		{
	printf("name:%s\n",dirEntry->d_name);
			if((fd= open(dirEntry->d_name, O_RDONLY)) != -1)
			{
				FILE *stream;
				char fname[128];

				sprintf(fname , "%s/cmdline",dirEntry->d_name);
	
				stream = fopen(fname,"r");
				if(stream)
				{
					fgets(fname,128,stream);
		printf("fname:%s\n",fname);			
					if (strstr(fname, name))
					{
						// get the pid we want.

					printf("\n\n\n dirEntry->d_name:%s\n",dirEntry->d_name);	
						pid = atoi(dirEntry->d_name);
						if (pid > 0)
					{
						fclose(stream);
						close(fd);
						break;
					}
				}
				fclose(stream);
			}

				close(fd);
		}
	}
	}  // end of while.
	closedir(dirHandle);

	return pid;
}


int IsAlreadyRuning()
{
	pid_t pid ;
	char prog_name[MAX_PATH_LEN];
	char curDir[MAX_PATH_LEN];
	int iRet = -1;

	getcwd(curDir,MAX_PATH_LEN);
	memset(prog_name,0,sizeof(prog_name));
	do
	{
		if(GetExeName(prog_name)<0)
			break;
		pid = GetpidByName(prog_name);
		if(pid <= 0 || pid == (pid_t)getpid())
			break;
		iRet = 0;

	}while(0);
	chdir(curDir);
	return iRet;
}


int main(int argc, char *argv[])
{

	if(IsAlreadyRuning()== 0)
	{
		printf("IrServer is Already Running,exit\n");
		return 0;
	}

	hls_init_data();
	if(hls_server_login() == bFALSE)
		return bFALSE;	
		
	hls_dev_login();
	
	hls_fork_server();
	
}


