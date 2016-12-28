/**************************************************************************************************
* File Name     : NetSDK.h
* Module Name   : Net_SDK
* Description   : 网络SDK
* Author/Date   : Janekey/ 2011.09.17
* Version       : 1.3.3.2
* State         : create
* -----------------------------------History-------------------------------------------------------
* Modifier/Date : 2011.05.27
* Modify Reason : 开始创建规范注释
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.30
* Modify Reason : 根据图像分辨率和模式获取图像大小
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.21
* Modify Reason : 增加从网络客户端控制FPGA的函数以及上传和下载文件的接口
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.17
* Version:        1.2.2.9
*                 创建标准化注释
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.22
* Version:        1.2.2.10
*                 在FPGA控制宏删除，需要调用时包含IrSDK.h头文件
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.24
* Version:        1.2.3.1
*                 修改了心跳响应方式，在一段时间获取不到服务器心跳时，发送重连消息
*                 对于设备状态通过回调返回，增加了重连成功消息
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.24
* Version:        1.2.6.1
*                 增加了获取服务器的状态信息函数 NetClient_GetServerState
*                 增加了SD卡装载、卸载、格式化功能
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.27
* Version:        1.2.6.2
*                 增加了远程操作子类型
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.2
* Version:        1.2.8.2
*                 增加了设备重启和FPGA重启命令NetClient_RebootDev和NetClient_ResetFPGA
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.3
* Version:        1.3.2.1
*                 增加了设备抓图和设备录像的控制功能函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.3
* Version:        1.3.3.2
*                 增加了删除文件的功能
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.1.4
* Version:        1.3.4.1
*                 增加了NetClient_SetNotifyHwnd，将消息通知设置从NetClient_Startup中分离，
*                 避免窗口未创建时不能启动NetSDK
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.3.31
* Version:        1.3.6.1
*                 NetClient_PTZCruise函数修改了，直接设置设置巡航点
*                 增加获取巡航状态函数 NetClient_PTZCruiseRunning()
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.4.12
* Version:        1.3.8.1
*                 NetClient_GetChannelInfo 参数修改，获取的通道信息内容发生变更
*                 获取的通道信息包括图像大小和通道名称
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.6
* Version:        1.3.9.2
*                 增加预置位的增加和删除
*                 云台初始化功能修改
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.28
* Version:        1.3.9.3
*                 告警增加了一个参数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.26
* Version:        1.3.9.4
*                 增加函数NetClient_GotoPreset
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.7.24
* Version:        1.3.9.8
*                 视频编码进行修改，采用灵活的配置方式
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.8.20
* Version:        1.4.2.0
*                 去掉SMTP和FTP配置和获取
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.8.22
* Version:        1.4.2.1
*                 文件下载成功时自行关闭下载文件
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.9.8
* Version:        1.4.2.2
*                 增加开门狗使能函数 NetClient_EnableWatchdog
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.10.11
* Version:        1.4.3.1
*                 每个预置位可增加最多4个测温对象
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.11.15
* Version:        1.4.4.1
*                 告警回调参数修改
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.03.95
* Version:        1.5.1.1
*                 API函数增加了channel
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.9
* Version:        1.8.1.1
*                 重新增加注释
*                 增加回调通知函数NetClient_SetNotifyCBF
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.29
* Version:        1.9.1.1
* Modify Reason : socket关闭时增加shutdown，重登录线程直接关闭
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.21
* Version:        2.6.0.1
*                 统一系统级调用
* -------------------------------------------------------------------------------------------------
**************************************************************************************************/
#ifndef NET_SDK_CLIENT_INCLUDE_H
#define NET_SDK_CLIENT_INCLUDE_H

/*LINUX版本的SDK开启*/
//#define HAVE_LINUX

/*WINDOWS版本的SDK开启*/


#ifdef WIN32
//#define _WINDLL

#define NET_SDK_API  extern "C" __declspec(dllexport) 

//#define NET_SDK_API  extern "C" __declspec(dllimport) 


#else  //Linux

#define NET_SDK_API 
#define CALLBACK

#ifndef SDK_TYPE
#define SDK_TYPE
typedef void* HANDLE;
typedef int                 BOOL;
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned int        DWORD;
typedef long                HWND;
typedef unsigned int        COLORREF;


typedef struct __DC
{
	void*   surface;        //SDL Surface
    HWND    hWnd;           // HDC window handle
}DC;
typedef DC* HDC;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef NULL
#define NULL                0
#endif

#endif //SDK_TYPE

#endif  //LINUX


//客户端收到的消息
typedef enum
{
	MSG_DATA_ERR = 0,        //接受网络数据异常
	MSG_PLAY_ERR,            //客户端播放出现异常
	MSG_REFUSED,             //客户端连接被拒绝
	MSG_GET_STRING,          //客户端收到消息字符串
	MSG_SERVER_CLOSE,        //服务器退出
	MSG_NET_FAILED,          //与服务器通信出现异常
	MSG_RECONNECT_SUCCESS,   //重连成功
	MSG_RECV_FRAME,          //客户端收到一帧数据
}eClientRecvMsg;


typedef struct {
    BYTE m_bytRemoteChannel;    //对应服务器通道
    BYTE m_bytSendMode;         //传输方式(TCP/UDP/MULTIMODE)
    BYTE m_bytLinkType;         //远程接入方式(ADSL/PSTN/LAN/ISDN)

    BYTE m_bytPlayMode;         //播放方式(STREAM/TOKEN)
    char* m_sIP;                //对应服务器IP      
    char* m_sUserName;          //用户名
    char* m_sUserPassWord;      //用户密码
    BOOL m_bUserCheck;          //是否需要发送用户名和密码
    HWND m_hShowVideo;          //视频显示窗口
    BYTE m_bytDecodeMode;       //解码类型(SOFTDEC(Default) / HARDDEC/MATRIXDEC/H264DEC)
}tClientInfo;

typedef struct {	
    char* m_sIP;//对应服务器IP      	
    char* m_sUserName;//用户名	
    char* m_sUserPassWord;//用户密码
    BYTE m_bytSendMode;//传输方式(TCP/UDP/MULTIMODE)	
    BOOL m_bUserCheck;//是否需要发送用户名和密码
}tVoiceCommInfo ;

typedef enum 
{
    StandardNone	= 0x80000000,
    StandardNTSC	= 0x00000001,
    StandardPAL		= 0x00000002,
    StandardSECAM	= 0x00000004,
} eVideoStandard;


//网络传输控制协议
enum { UDPMODE =0 , TCPMODE , MULTIMODE }; 

//DirectDraw显示模式
enum { NORMALMODE = 0 , OVERLAYMODE };

//视频质量
enum { LOWQUALITY = 0 , HIGHQUALITY };

//播放方式,STREAM 适用于宽带多路连接, TOKEN 适用于窄带多路连接
enum { STREAM = 0, TOKEN };

//网络传输介质
/////////////////////////////////////////////////////
// ADSL: 1M ~ 4M 
// PSTN: <56k
// ISDN: >64k < 128K
// LAN:  >10M 
/////////////////////////////////////////////////////
enum { LAN = 0, ADSL, ISDN, PSTN }; 

//解码方式
enum { SOFTDEC = 0, HARDDEC ,MATRIXDEC, H264DEC };


#define  MAX_RS485_PORT_NUM    256
#define  MAX_RS232_PORT_NUM    64

/*串口类型*/
typedef enum 
{
    RS232 =  0,
    RS485 =  1,
    RS422 =  2,
}eSerialType;



/* 所有日志 */ 
#define MAJOR_ALL             0x0

/* 操作 */ 
#define MAJOR_OPERATION       0x1 

enum 
{
    MINOR_OPR_ALL = 0,                 /*全部*/
    MINOR_OPR_REMOTE_PTZ,              /*远程云台控制*/
    MINOR_OPR_REMOTE_PLAYTIME,        /*远程按时间回放*/
    MINOR_OPR_REMOTE_PALYFILE,        /*远程文件回放*/
    MINOR_OPR_REMOTE_UPGRADE,         /*远程升级*/
    MINOR_OPR_VOICE_STOP,             /*语音对讲结束*/
    MINOR_OPR_VOICE_START,            /*语音对讲开始*/
    MINOR_OPR_REMOTE_RESTART,         /*远程重启*/
    MINOR_OPR_REMOTE_DEF_WITHDRAW,    /*远程撤防*/
    MINOR_OPR_REMOTE_DEF_LAY,         /*远程布防*/
    MINOR_OPR_REMOTE_GETSTATE,        /*远程获取状态*/ 
    MINOR_OPR_REMOTE_CONFIG,          /*远程配置*/
    MINOR_OPR_REMOTE_GETPARA,         /*远程获取参数*/
    MINOR_OPR_REMOTE_RECORD_STOP,     /*远程停止录像*/   
    MINOR_OPR_REMOTE_RECORD_START,    /*远程启动录像*/  
    MINOR_OPR_REMOTE_CANCEL,          /*远程注销*/
    MINOR_OPR_REMOTE_LOGIN,           /*远程登陆*/
    MINOR_OPR_LOCAL_UPGRADE,          /*本地升级*/   
    MINOR_OPR_LOCAL_PTZ_CTRL,         /*本地云台控制*/
    MINOR_OPR_LOCAL_RECORD_STOP,      /*本地停止录像*/ 
    MINOR_OPR_LOCAL_RECORD_START,     /*本地开始录像*/
    MINOR_OPR_LOCAL_PLAYTIME,         /*本地按时间回放*/
    MINOR_OPR_LOCAL_PLAYFILE,         /*本地文件回放*/
    MINOR_OPR_LOCAL_CONFIG,           /*本地配置*/
    MINOR_OPR_LOCAL_CANCEL,           /*本地注销*/
    MINOR_OPR_LOCAL_LOGIN,            /*本地登录*/
    MINOR_OPR_SHUTDOWN_ILLEGAL,       /*非法关机*/
    MINOR_OPR_SHUTDOWN,               /*关机*/
    MINOR_OPR_START,                  /*开机*/
    MINOR_OPR_LOG_REMOVE,             /*日志清除*/
    MINOR_OPR_FILE_BACKUP,            /*备份文件*/
    MINOR_OPR_NUM                     /*操作类型总数*/
};


/*远程操作细节*/
enum
{
	OPR_DETAIL_ALL = 0,
	OPR_DETAIL_COMMON,
	OPR_DETAIL_FTP,      
	OPR_DETAIL_SMTP,
	OPR_DETAIL_NET,
	OPR_DETAIL_ALARM,
	OPR_DETAIL_VIDEO_PARA,
	OPR_DETAIL_PTZ,
	OPR_DETAIL_USER,
	OPR_DETAIL_TIME,
	OPR_DETAIL_SD_FORMAT,
	OPR_DETAIL_DEL_FILE,     /*删除文件*/	
	OPR_DETAIL_FACE_DETECT,
	OPR_DETAIL_FPGA_CTRL,
	OPR_DETAIL_FPGA_RESET,   /*FPGA重启*/
	OPR_DETAIL_DEV_REBOOT,   /*设备重启*/	
	OPR_DETAIL_NUM,
};

/* 异常 */ 
//主类型 
#define   MAJOR_EXCEPTION       0x2 
//次类型
enum 
{
    MINOR_EXCEPTION_ALL=0,               /*全部*/
    MINOR_EXCEPTION_IP_CONFLICT,         /*IP冲突*/
    MINOR_EXCEPTION_DISK_FULL,           /*硬盘满*/
    MINOR_EXCEPTION_DISK_ERRO,           /*硬盘错误*/
    MINOR_EXCEPTION_ACCESS_INVALID,      /*非法访问*/
    MINOR_EXCEPTION_INPUT_SIG_LOST,      /*输入信号丢失*/
    MINOR_EXCEPTION_INPUT_SIG_RESCURE,   /*输入信号恢复*/
    MINOR_EXCEPTION_NUM                  /*异常总数*/
};

/*报警*/
//主类型
#define MAJOR_ALARM              0x3
//次类型 
enum
{
    MINOR_ALARM_ALL = 0,                   /*全部*/
	MINOR_ALARM_VIDEO_LOST,                /*视频丢失*/
	MINOR_ALARM_VIDEO_RECOVERY,            /*视频恢复*/
    MINOR_ALARM_HIDE_STOP,                 /*遮挡报警结束*/
    MINOR_ALARM_HIDE_START,                /*遮挡报警开始*/
    MINOR_ALARM_MOTION_DETCT_STOP,         /*移动侦测报警开始*/
    MINOR_ALARM_MOTION_DETCT_START,        /*移动侦测报警开始*/
    MINOR_ALARM_OUT_START,                 /*报警输出开始*/
    MINOR_ALARM_OUT_END,                   /*报警输出结束*/
    MINOR_ALARM_IN_START,                  /*报警输入*/
    MINOR_ALARM_IN_END,                    /*报警输入消失*/
   	MINOR_ALARM_SD_FULL,                   /*SD卡存储满*/
   	MINOR_ALARM_SD_ERROR,                  /*读取SD卡错误*/
    MINOR_ALARM_ETH_LOST,                  /*网线断开了*/
    MINOR_ALARM_GOTO_PRESET,               /*到了预置位*/
    MINOR_ALARM_HIGH_TEMP,                 /*高温告警*/
    MINOR_ALARM_TEMP_LOG,                  /*温度记录*/
    MINOR_ALARM_CHANNEL_STATE,             /*通道状态改变*/
    MINOR_ALARM_ERROR_FPGA,                /*FPGA故障*/
    MINOR_ALRAM_ERROR_DM368,               /*DM368故障*/
    MINOR_ALARM_OTHER,                     /*其他类型告警*/    
    MINOR_ALARM_NUM                        /*报警总数*/
};


/*日志的返回结果*/
#define MAX_LOG_DESC_LEN       32
#define MAX_NAMELEN            40
typedef struct {
    char      strLogTime[MAX_LOG_DESC_LEN];     //时间
    char 	  strMajorType[MAX_LOG_DESC_LEN];   //主类型
    char 	  strMinorType[MAX_LOG_DESC_LEN];   //次类型
    char      strDetail[MAX_LOG_DESC_LEN];      //详细信息
    char	  strUser[MAX_NAMELEN];             //操作员
    DWORD     dwRemoteHostAddr;                 //远程主机地址
    DWORD	  dwChannel;                        //通道号
}tDevLog;

/*时间查找的结构*/
typedef struct{
    DWORD dwYear;		//年
    DWORD dwMonth;      //月
    DWORD dwDay;		//日
    DWORD dwHour;		//时
    DWORD dwMinute;	//分
    DWORD dwSecond;	//秒
}tNetTime ;


#define MAX_SERIAL_NUM_LEN 	32
#define MAX_VERSION_LEN     32
#define MAX_DEV_NAME_LEN    32

#define DEV_TYPE_IPNC    0
#define DEV_TYPE_SERVER  1

typedef struct  {
    char SerialNumber[MAX_SERIAL_NUM_LEN];   //序列号
    char SoftWareVersion[MAX_VERSION_LEN];   //软件版本号
	char HardWareVersion[MAX_VERSION_LEN];   //硬件版本号
	char DevName[MAX_DEV_NAME_LEN];          //设备名
	BYTE byteIpncType;						 //类型 
    BYTE byAlarmInPortNum;				     //报警输入个数
    BYTE byAlarmOutPortNum;				     //报警输出个数
    BYTE byChanNum;						     //通道个数
}tDeviceInfo;


/*!设备注册信息结构*/
#define MAC_LEN				20
#define VERSION_INFO_LEN	20
#define IP_LEN				20
typedef struct tagRegisterInfo
{
    unsigned int  DeviceID;				/*设备ID号（产品序列号）*/
    unsigned char DeviceIP[IP_LEN];		/*设备的IP地址号*/
    unsigned char DeviceMAC[MAC_LEN];	/*设备的MAC地址*/
    unsigned int  DeviceCmdPort;	    /*设备通讯端口*/
    unsigned int  DeviceDataPort;       /*设备数据端口*/
    unsigned int  DeviceType;			/*设备类型*/
    unsigned char DeviceVersion[VERSION_INFO_LEN]; /*!设备软件版本号*/
}RegisterInfo, *LPRegisterInfo;
//设备注册回调

/****************************视频相关常量***************************************************/

/*各种视频图像大小*/
typedef enum 
{
	PIC_RES_FD1 = 1,                    // 720*576(PAL)  720*480(NTSC) (Full D1)
	PIC_RES_D1 ,						// 704*576(PAL)  720*480(NTSC) (4CIF)
 	PIC_RES_HD1,						// 352*576(PAL)  352*480(NTSC)
	PIC_RES_BCIF,					    // 704*288(PAL)  704*240(NTSC)
	PIC_RES_CIF,						// 352*288(PAL)  352*240(NTSC)
	PIC_RES_QCIF,						// 176*144(PAL)  176*120(NTSC)
	PIC_RES_VGA,						// 640*480 
	PIC_RES_QVGA,						// 320*240  
	PIC_RES_SVCD,						// 480*480
	PIC_RES_QQVGA,						// 160*120
	PIC_RES_SVGA,						// 800*600
	PIC_RES_XVGA,						// 1024*768
	PIC_RES_WXGA,						// 1280*800 1366*768 1280*768
	PIC_RES_SXGA,						// 1280*1024  
	PIC_RES_WSXGA,						// 1600*1024  
	PIC_RES_UXGA,						// 1600*1200
	PIC_RES_WUXGA,						// 1920*1200
	PIC_RES_QXGA,                       // 2048*1536
	PIC_RES_WQXGA,                      // 2560*1600
	PIC_RES_QSXGA,                      // 2560*2048
	PIC_RES_QUXGA,                      // 3200*2400
	PIC_RES_4K2K,                       // 4096*2048
	PIC_RES_LTF,						// 240*192
	PIC_RES_720,						// 1280*720
	PIC_RES_1080,						// 1920*1080
	PIC_RES_1_3M,						// 1280*960

	IR_RES_320X240,                    //302*240
	IR_RES_384X288,                    //384*288

	PIC_RES_NR  

} ePicResolution;


// 视频编码类型
#define VIDEO_NULL          0x0 // 没有视频
#define VIDEO_H264          0x1 // 标准H.264和海康H.264都可以用这个定义
#define VIDEO_MJPEG         0x2
#define VIDEO_MPEG4         0x3 // 标准MPEG4
#define VIDEO_IR            0x4 //红外视频

// 音频编码类型
#define AUDIO_NULL          0x0000 // 没有音频
#define AUDIO_ADPCM         0x1000 // ADPCM 
#define AUDIO_MPEG          0x2000 // MPEG 系列音频，解码器能自适应各种MPEG音频
// G系列音频
#define AUDIO_G711_U		0x7110
#define AUDIO_G711_A		0x7111
#define AUDIO_G722_1		0x7221
#define AUDIO_G723_1        0x7231
#define AUDIO_G726          0x7260
#define AUDIO_G729          0x7290

/**********************************************************************************
* Function:      NetClient_GetPicRes
* Description:   根据图像分辨率以及模式获取图像大小
* Input:         ePicResolution picRes      图像分辨率
*                eVideoStandard videoStand  视频模式      
* Output:        int& iWidth   图像宽度
*                int &iHeight  图像高度
* Return:        成功获取返回TRUE,否则返回FALSE
************************************************************************************/
NET_SDK_API BOOL  NetClient_GetPicRes(ePicResolution picRes,eVideoStandard videoStand,int& iWidth, int &iHeight );


/****************************云台相关常量***************************************************/
/*支持的云台协议列表*/
typedef enum 
{
	PTZ_NONE            = 0,   //None Ptz
	PTZ_PELCO_P,               //Pelco-P Protocol
	PTZ_PELCO_P1,              //Pelco-P1 Protocol
	PTZ_PELCO_D,               //Pelco-D Protocol
	PTZ_PELCO_D1,              //Pelco-D1 Protocol
	PTZ_PELCO_D2,              //Pelco-D2 Protocol
	PTZ_PELCO_ASCII,           //Pelcoascii Protocol
	PTZ_YAAN_P,                //Yaan Protocol
	PTZ_PANASONIC,             //Panasonic Protocol
	PTZ_PANASONIC_WV_CS,       //Panasonic Protocol
	PTZ_STANDARD,              //PTZ standard protocol
	PTZ_PHILIPS,               //Philips Protocol
	PTZ_SAMSUNG,               //Samsung Protocol
	PTZ_SONY,                  //Sony Protocol
	PTZ_WV_CS850I,             //Wv_cs850i Protocol
	PTZ_WV_CS850II,            //Wv_cs850ii Protocol
	PTZ_LILIN,                 //Lilin Protocol
	
    /* expand ptz protocol */
	PTZ_SAMSUNG_SCC641,        //Samsung SCC-641
	PTZ_DRX502A,               //DRX-502A(Dome)
	PTZ_NK97CHE,               //NK-97CHE
	PTZ_LVCA720,               //LG LPT-A100L
	PTZ_SJ2819RX,              //SJ2819RX
	PTZ_MRX1000,               //Samsung MRX-1000
	PTZ_SPD1600,               //Techwin SPD1600/2500
	PTZ_WPT101,                //WonWoo Eng:SBO-201P1
	PTZ_UNKNOWN,               //UNKNOWN
}ePtzProto;

/*云台协议命令*/
typedef enum
{ 
	PTZ_CMD_UP,                /* 云台以SS的速度上仰 */
	PTZ_CMD_DOWN,	           /* 云台以SS的速度下俯 */
	PTZ_CMD_LEFT,	           /* 云台以SS的速度左转 */
	PTZ_CMD_RIGHT,             /* 云台以SS的速度右转 */
    PTZ_CMD_UP_LEFT,		   /* 云台以SS的速度上仰和左转 */
 	PTZ_CMD_DOWN_LEFT,	       /* 云台以SS的速度上仰和右转 */
 	PTZ_CMD_UP_RIGHT,		   /* 云台以SS的速度下俯和左转 */
    PTZ_CMD_DOWN_RIGHT,	       /* 云台以SS的速度下俯和右转 */
	PTZ_CMD_STOP,	           /* 停止云台巡航、扫描、焦距调节、焦点调节*/

	PTZ_CMD_IRIS_OPEN,         /* 光圈以速度SS扩大 */
	PTZ_CMD_IRIS_CLOSE,	       /* 光圈以速度SS缩小 */
    PTZ_CMD_ZOOM_IN,           /* 焦距以速度SS变大(倍率变大) */
    PTZ_CMD_ZOOM_OUT,		   /* 焦距以速度SS变小(倍率变小) */
 
 	PTZ_CMD_FOCUS_IN,	       /* 焦点以速度SS前调 */
    PTZ_CMD_FOCUS_OUT,		   /* 焦点以速度SS后调 */

	/*停止位*/
	PTZ_CMD_PTSTOP_2,
	PTZ_CMD_ZOOM_STOP,
	PTZ_CMD_FOCUS_STOP,
	PTZ_CMD_FOCUS_AUTO,        /*自动调焦距*/
	PTZ_CMD_IRIS_AUTO,         /*自动光圈*/

	/*位置限制*/
	PTZ_CMD_SET_LEFT_LIMIT,
	PTZ_CMD_SET_RIGHT_LIMIT,

	/*设置步长*/
	PTZ_CMD_SET_ZOOM_SPEED,    /* 设置ZOOM步长*/
	PTZ_CMD_SET_FOCUS_SPEED,   /* 设置FOCUS步长*/
	PTZ_CMD_SET_LENS_SPEED,
	PTZ_CMD_SET_SCAN_SPEED,
	PTZ_CMD_SET_ROTATE_SPEED,
	
	/*预置位*/
	PTZ_CMD_SET_PRESET,        /*设置预置点 */
	PTZ_CMD_GOTO_PRESET,       /* 运转到预置点 */
	PTZ_CMD_CLEAR_PRESET,	   /* 清除预置点 */
	PTZ_CMD_SAVE_PRESET,       /* 保存预置点 */

	PTZ_CMD_AUTO_PAN,
 	PTZ_CMD_CAM_LIGHT,
 	PTZ_CMD_CAM_POWER,

	PTZ_CMD_SET_AUTO_PAN_SPEED,

	PTZ_CMD_LIGHT_ON,          /*灯光开*/
 	PTZ_CMD_LIGHT_OFF,         /*灯光关*/
 	
	PTZ_CMD_SWITCH_ON,
	PTZ_CMD_SWITCH_OFF,
	
	PTZ_CMD_BRUSH_ON,         /*雨刷开*/
    PTZ_CMD_BRUSH_OFF,        /*雨刷开*/

	PTZ_CMD_SET_ROTATE_ON,
	PTZ_CMD_SET_ROTATE_OFF,
	
	/*Scan*/
	PTZ_CMD_SCAN_ON,           /* 停止线扫描*/
	PTZ_CMD_SCAN_OFF,          /* 开始线扫描*/
	
	PTZ_CMD_SET_SCAN_LIMIT,
	PTZ_CMD_SCAN_RANDOM_ON,
	PTZ_CMD_SCAN_RANDOM_OFF,
	
	/*巡航*/
 	PTZ_CMD_CRUISE_ON,        /* 开始巡航 */
    PTZ_CMD_CRUISE_OFF,       /* 停止巡航 */
    PTZ_CMD_SET_CRUISE_STOP_TIME, 
	PTZ_CMD_SET_CRUISE_SPEED,
	PTZ_CMD_CLEAR_CRUISE_POINT,
	PTZ_CMD_CLEAR_ALL_CRUISE_POINT,
	PTZ_CMD_ADD_CRUISE_POINT,
    PTZ_CMD_CRUISE_SET_BEGIN,
	PTZ_CMD_CRUISE_SET_END,
	PTZ_CMD_AUTO_CRUISE,

	/*Patrol命令*/
	PTZ_CMD_PATROL_LEARN_BEGIN,
	PTZ_CMD_PATROL_LEARN_END,
	PTZ_CMD_PATROL_ON,
	PTZ_CMD_PATROL_OFF,

	PTZ_CMD_PATTERN_SET,
	PTZ_CMD_PATTERN_RUN,

	/*扩展命令*/
	PTZ_CMD_HOME,
	PTZ_CMD_FLIP,
	PTZ_CMD_RESET,

	/*OSD Menu*/
	PTZ_CMD_OSD_MENU,
	PTZ_CMD_OSD_MENU_ENTER,

	/*PTZ查询命令*/
	PTZ_CMD_QUERY_HORIZON,   /*水平角度*/
	PTZ_CMD_QUERY_VERTICAL,  /*俯仰角*/

	PTZ_CMD_QUERY_PRESET,    /*预置位查询*/

	/*轨道车移动*/
	RAIL_CMD_UP,
	RAIL_CMD_DOWN,
	RAIL_CMD_SET_PRESET,     /*设置预置点 */
	RAIL_CMD_GOTO_PRESET,    /* 运转到预置点 */
	RAIL_CMD_CLEAR_PRESET,	 /* 清除预置点 */	

	/*不同云台专用*/
	PTZ_CMD_PRIVATE   = 1000,    /*一些私有的控制*/
	PTZ_CMD_SONY_VERTICAL_STOP,
	PTZ_CMD_SONY_LEVEL_STOP,
	PTZ_CMD_SONY_INCLINE_STOP,
	PTZ_CMD_SONY_IRIS_STOP,
	
	PTZ_CMD_CS850II_ZOOM_STOP,    /*Wv_cs850ii*/
	PTZ_CMD_CS850II_FOCUS_STOP,
	PTZ_CMD_CS850II_IRIS_STOP,

	PTZ_CMD_NK97_MENU_UP,
 	PTZ_CMD_NK97_MENU_DOWN,
 	PTZ_CMD_NK97_MENU_VALUE_UP,
 	PTZ_CMD_NK97_MENU_VALUE_DOWN,
	PTZ_CMD_NK97_CAMRESET,

	PTZ_CMD_SJ2819RX_WIPER,
	PTZ_CMD_MRX1000_AUX,

}ePtzCmd;          

/*获取SDK版本号*/
NET_SDK_API DWORD  NetClient_GetVersion();

/**********************************************************************************
* Function:      NetClient_Startup
* Description:   对客户端进行初始化
* Input:         无
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_Startup();

//报警信息回调
typedef int( *CBF_Notify)(long hDev, int message,long lPrivate);

NET_SDK_API BOOL  NetClient_SetNotifyCBF(CBF_Notify cbNotify,long lPrivate=0);

#ifdef WIN32
/**********************************************************************************
* Function:      NetClient_SetNotifyHwnd
* Description:   设置客户端接收到服务器端命令字符串时，
*                向客户端应用程序发送消息的目的窗口和消息ID
* Input:         DWORD nMessage   消息ID
*                HWND hWnd       消息接收窗口
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SetNotifyHwnd(int nMessage , HWND hWnd);
#endif

/*NetSDK清理*/
NET_SDK_API BOOL    NetClient_Cleanup();

typedef  void (CALLBACK *ReadDataCallBack)(DWORD nPort , BYTE* pPacketBuffer , DWORD nPacketSize, int FrameType );
/**********************************************************************************
* Function:      NetClient_Start
* Description:   启动客户端连接
* Input:         tClientInfo*  pClientInfo  客户端连接信息结构体
*                ReadDataCallBack cbf 网络端口接收到数据的回调函数,客户端用它来读取数据流.
*                如果ReadDataCallBack为NULL , 表示不需要读取数据流；ReadDataCallBack函数说明：
*			 	     nPort 		  :  服务器通道编号
*				     pPacketBuffer :  压缩数据缓冲区
*				     nPacketSize   :  压缩数据长度
*				     FrameType     :  压缩数据帧类型
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API long    NetClient_Start(tClientInfo*  pClientInfo ,ReadDataCallBack cbf);

/*停止客户端*/
NET_SDK_API BOOL     NetClient_Stop(long hDev);

//客户端状态
typedef enum
{
	CLIENT_INVALID    = -1,
	CLIENT_CONNECTING =  1,
	CLIENT_RECEIVING,
	CLIENT_HALT,
	CLIENT_FINISH,
	CLIENT_UNREACHABLE,
	CLIENT_REFUSE,
}eClientStatus;

/*获取客户端状态*/
NET_SDK_API long    NetClient_GetState(long hDev);


/*获取通道数*/
NET_SDK_API WORD    NetClient_GetServerChannelNum( char* sIPAddress );

/**********************************************************************************
* Function:      NetClient_CommandToServerEx
* Description:   给服务器端发送命令字符串
* Input:         char* sIP      服务器IP地址
*                char* sCommand 命令字符串
*                WORD wLen      命令字符串长度
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToServerEx(char* sIP , char* sCommand , WORD wLen );

/**********************************************************************************
* Function:      NetClient_CommandToServer
* Description:   向hDev连接句柄所连接的服务器端发送命令字符串
* Input:         long hDev      NetClient_Start成功的返回值
*                char* sCommand 命令字符串
*                WORD wLen      命令字符串长度
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToServer(long hDev , char* sCommand , WORD wLen );


/**********************************************************************************
* Function:      NetClient_SetNetPort
* Description:   设置网络通信端口
* Input:         dServerPort ：服务器端通信端口
*                dClientPort ：客户端通信端口
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
* Notes:         服务器端设置的网络通信端口号必须与客户端设置一致，才能保证服务器和客户端正常通信
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SetNetPort( WORD dServerPort , WORD dClientPort);



/**********************************************************************************
* Function:      NetClient_SetWait
* Description:   设置连接服务器端的等待时间和尝试次数
* Input:         dwEachWaitTime : 等待时间,单位是毫秒,范围是300 - 10000
*                dwTryNum, : 尝试次数 . 范围是 1 - 50
* Output:        无
* Return:        返回TRUE 表示成功, 返回FALSE 表示失败
************************************************************************************/ 
NET_SDK_API BOOL     NetClient_SetWait( DWORD dEachWaitTime , DWORD dTryNum );


NET_SDK_API BOOL    NetClient_SetCmdTimerOut(int seconds);

/**********************************************************************************
* Function:      NetClient_ReadLastMessage
* Description:   读取服务器端的消息发送的最后一个消息
* Input:         char* sIP : 获取发送命令字符串的服务器IP地址
*                char* sCommand :  获取最后接收的命令字符串
*                WORD* wLen       获取命令字符串的长度
* Output:        无
* Return:        无
************************************************************************************/ 
NET_SDK_API void    NetClient_ReadLastMessage(char* sIP, char* sCommand, WORD* wLen);



/**********************************************************************************
* Function:      NetClient_StartEx
* Description:   与服务器的指定管理端口和数据端口建立连接 
* Input:         tClientInfo*  pClientInfo   客户连接信息
*                ReadDataCallBack            数据读取回调
*                WORD wCommandPort           服务器的管理端口
*                WORD wDataPort              服务器的数据端口
* Output:        无
* Return:        -1 表示失败, 其它的值表示连接句柄
* Notes:         此函数仅适用于TCP连接模式
************************************************************************************/ 
NET_SDK_API long   NetClient_StartEx(tClientInfo*  pClientInfo ,ReadDataCallBack pReadDataCB, WORD wCommandPort, WORD wDataPort);

//报警信息回调
typedef int( *CBF_AlarmInfo)(long hDevice, int iusrdata, int ialarmtype, int iPara, int* pPara );

/**********************************************************************************
* Function:      NetClient_AlarmSubscribe
* Description:   设备报警信息的订阅 
* Input:         long hDev      设备句柄；NetClient_Login()函数的返回值
*                int iusrdata   用户自定义数?
*                CBF_AlarmInfo cbf 设备报警信息的回调函数
* Output:        无
* Return:        TRUE 表示成功,其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_AlarmSubscribe(long hDev, int iusrdata, CBF_AlarmInfo cbf);

/*告警IO输出*/
NET_SDK_API BOOL     NetClient_AlarmIoOut(long hDev,long channel,int iAlarmNo,int iValue);


/**********************************************************************************
* Function:      NetClient_AlarmUnSubscribe
* Description:   设备报警信息的退订 
* Input:         long hDev     设备句柄；NetClient_Login()函数的返回值
* Output:        无
* Return:        TRUE 表示成功,其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_AlarmUnSubscribe(long hDev);

//设备心跳回调
typedef int( *CBF_HeartBeat)(long hDevice, int iusrdata);
/**********************************************************************************
* Function:      NetClient_HeartBeatSubscribe
* Description:   注册保活心跳信息
* Input:         long hDev     设备句柄；NetClient_Login()函数的返回值
*                unsigned int intervals  设备心跳包的间隔
*                int iusrdata  用户私有数据;会在设备心跳信息的回调函数里传回给用户
*                CBF_HeartBeat cbf  设备心跳信息的回调函数
* Output:        无
* Return:         TRUE 表示成功,其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_HeartBeatSubscribe(long hDev, unsigned int intervals, \
                                                           int iusrdata, CBF_HeartBeat cbf);

/**********************************************************************************
* Function:      NetClient_HeartBeatUnSubscribe
* Description:   设备保活心跳信息的退订 
* Input:         long hDev    设备句柄；NetClient_Login()函数的返回值
* Output:        无
* Return:        表示成功,其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_HeartBeatUnSubscribe(long hDev);



/**********************************************************************************
* Function:      NetClient_Login
* Description:   远程登陆前端设备 
* Input:         char *sIP       设备的IP地址或者域名
*                WORD wPort      设备的端口
*                char *sUserName 设备登陆的用户名
*                char *sPassword 设备的登陆密码
* Output:        tDeviceInfo* pDeviceInfo  设备信息
* Return:        返回-1表示失败;其它值作为后续函数的参数
************************************************************************************/ 
NET_SDK_API long   NetClient_Login(char *sIP,WORD wPort,char *sUserName,char *sPassword,tDeviceInfo* pDeviceInfo);


NET_SDK_API BOOL   NetClient_GetDeviceInfo(long hDev,tDeviceInfo *info);
/**********************************************************************************
* Function:      NetClient_Logout
* Description:   登出前端设备 
* Input:         long hDev     设备句柄
* Output:        无
* Return:        TRUE 表示成功,其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_Logout(long hDev);


//软解码预览参数
typedef struct
{
	int lChannel;//通道号
	int lLinkMode;//0：TCP方式,1：UDP方式,2：多播方式
	HWND hPlayWnd;//播放窗口的句柄,为NULL表示不播放图象
	char* sMultiCastIP;//多播组地址
}tNetClientInfo;

NET_SDK_API char* NetClient_GetChannelUrl(long hDev,long channel );

NET_SDK_API char* NetClient_GetDevIp(long hDev);

#ifdef HAVE_MEDIA_SDK
typedef void( *PlayCallBack)(const char *pBuffer,void* pParameter);
NET_SDK_API long  NetClient_ClientPlay(long hDev, tNetClientInfo *client,void ( *PlayCallBack) (const char *pBuffer,void* pParameter),void* pUser);
NET_SDK_API long  NetClient_StopClientPlay(long lUserId);

/*网络流*/

typedef void (*fRealDataCallBack_V2) (long lUserID,unsigned char *pBuffer,long dwBufSize,void* pUser);
NET_SDK_API long  NetClient_RealPlay(long hDev, tNetClientInfo *client,void ( *fRealDataCallBack_V2) (long lUserID,unsigned char *pBuffer,long dwBufSize,void* pUser),void *pUser);
NET_SDK_API void  NetClient_StopRealPlay(long lUserID);

NET_SDK_API long  NetClient_PlayBackStart(long hDev, char *fileName,fRealDataCallBack_V2 cbReadData, void *pUser);
NET_SDK_API void  NetClient_PlayBackStop(long lUserID);

NET_SDK_API long  NetClient_RealPlayBack(long hDev,char* fileName,HWND hWnd);
NET_SDK_API void  NetClient_StopRealPlayBack(long lUserID);

NET_SDK_API long  NetClient_PlayBackByTime(long hDev, long channel,tNetTime* StartTime,tNetTime* StopTime ,fRealDataCallBack_V2 cbReadData, void *pUser);

#endif

/**********************************************************************************
* Function:      NetClient_CommandToDev
* Description:   发送消息字符串到已经登陆的前端 
* Input:         long hDev     设备句柄
*                char* sCommand 消息字符串
*              	 WORD wLen     发送数据的缓冲区指针
* Output:        无
* Return:        TRUE表示成功，其它值表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToDev(long hDev , char* sCommand , WORD wLen );

typedef int (CALLBACK *CBF_Register)(RegisterInfo*  lprs);
/**********************************************************************************
* Function:      NetClient_SetRegisterCB
* Description:   设置设备的注册回调函数 
* Input:         CBF_Register cbf    回调函数指针
* Output:        无
* Return:        无
************************************************************************************/ 
NET_SDK_API void   NetClient_SetRegisterCB(CBF_Register cbf);

/**********************************************************************************
* Function:      NetClient_Upgrade
* Description:   开始升级 
* Input:         long hDev     设备句柄
*                char* sFileName      升级文件的完整路径(必需是.tar.gz的文件)
*                unsigned int uLength  发送数据的缓冲区的长度
*                WORD wDeviceDataPort  设备接收数据的端口号
* Output:        无
* Return:        升级句柄，作为后续函数的输入参数； -1表示启动升级失败
************************************************************************************/ 
NET_SDK_API long   NetClient_Upgrade(long hDev, const char* sFileName, WORD wDeviceDataPort);


/**********************************************************************************
* Function:      NetClient_CloseUpgradeHandle
* Description:   关闭NetClient_Upgrade接口所创建的句柄，释放资源 
* Input:         long hUpgradeHandle    NetClient_Upgrade()函数的返回值
* Output:        无
* Return:        TRUE表示成功， FALSE表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CloseUpgradeHandle(long hUpgradeHandle);


/**********************************************************************************
* Function:      NetClient_GetUpgradeState
* Description:   获取升级的状态 
* Input:         long hUpgradeHandle    NetClient_Upgrade()函数的返回值
* Output:        unsigned int* nprogress  输出参数，返回升级进度(百分比) 
* Return:        返回升级状态
*   			 -1表示失败，其他值如下定义： 
*   			  1：升级成功  
*   			  2：正在升级 , nprogress表示进度信息（百分比）
*   			  3：升级失败 
*   			  4：网络断开,状态未知 
*   			  5：升级文件语言版本不匹配 
************************************************************************************/ 
NET_SDK_API int   NetClient_GetUpgradeState(long hUpgradeHandle, unsigned int* nprogress);


typedef int  ( *CBF_SerialCom)(long hSerial,int iUsrData,void *pBuffer,unsigned int uLength);

/**********************************************************************************
* Function:      NetClient_SerialStart
* Description:   打开通明通道 
* Input:         long hDev       设备句柄，通过NetClient_Login ()函数获取
*                eSerialType iSerialType   串口类型，可以为RS232,RS485类型
*                unsigned int uPort    串口控制设备号，对R485以，有效范围见MAX_RS485_PORT_NUM,计数从0开始
*                int iUsrData  用户自定义数据，会在通明通道数据回调中得到
*                CBF_SerialCom  通明通道回调函数
* Output:        无
* Return:        通明通道句柄，作为后续函数的输入参数； INVALID_long_VALUE表示启动透明通道失败
************************************************************************************/ 
NET_SDK_API long   NetClient_SerialStart(long hDev, eSerialType iSerialType, unsigned int uPort,int iUsrData, CBF_SerialCom pSerialCB );


/**********************************************************************************
* Function:      NetClient_SerialSend
* Description:   发送通明通道数据 
* Input:         long hSerial    透明通道句柄，通过NetClient_SerialStart获取
*                char *pBuf      发送数据的缓冲区指针
*                unsigned int uLength  发送数据的缓冲区的长度
* Output:        无
* Return:        TRUE表示发送透明通道数据成功，FALSE表示发送透明通道数据失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SerialSend(long hSerial,char *pBuf,unsigned int uLength);


/**********************************************************************************
* Function:      NetClient_SerialStop
* Description:   关闭透明通道 
* Input:         long hSerial    透明通道句柄，通过NetClient_SerialStart获取
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SerialStop(long hSerial);


/**********************************************************************************
* Function:      NetClient_PTZInit
* Description:   初始化云台
* Input:         long hDev  设备句柄
*                unsigned int channel_id 云台通道ID
*                unsigned int cam_id 云台地址
*                unsigned int ptz_type 采用的云台协议类型
*                unsigned int baudrat 控制云台的窗口波特率
* Output:        无
* Return:       返回TRUE表示成功，否则表示失败
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_PTZInit   (long hDev, long channel, unsigned int cam_id,   unsigned int ptz_type, unsigned int baudrat);

/**********************************************************************************
* Function:      NetClient_PTZControl
* Description:   云台控制
* Input:         long hDev  设备句柄
*                unsigned int channel_id 云台通道ID
*                unsigned int ucommand  云台命令
*                int iparam1   命令参数1
*                int iparam2   命令参数2
*                int iparam3   命令参数3
*                int iparam4   命令参数4
* Output:        无
* Return:       返回TRUE表示成功，否则表示失败
************************************************************************************/ 
NET_SDK_API BOOL  NetClient_PTZControl(long hDev, long channel, unsigned int ucommand, int iparam1, int iparam2, int iparam3, int iparam4);

/*该结构体用于巡航*/
typedef struct __ptzCruise
{
	int preset_id;
	int duration;
	int action;
}tCruise;

/**********************************************************************************
* Function:      NetClient_PTZCruise
* Description:   云台巡航
* Input:         long hDev  设备句柄
*                int iCruise  巡航中预置位个数
*                tCruise *pCruiseList 预置位链表
* Output:        无
* Return:       返回TRUE表示成功，否则表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZCruise (long hDev,long channel, int iCruise,tCruise *pCruiseList);

/**********************************************************************************
* Function:      NetClient_PTZCruiseRunning
* Description:   判断是否已经启动巡航
* Input:         long hDev  设备句柄
* Output:        无
* Return:        启动巡航返回TRUE,否则返回FALSE,命令发送失败也返回FALSE
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZCruiseRunning (long hDev,long channel);


/**********************************************************************************
* Function:      NetClient_PTZCruise
* Description:   云台巡航
* Input:         long hDev  设备句柄
* Output:        int iCruise  巡航中预置位个数
*                tCruise *pCruiseList 预置位链表
* Return:       返回TRUE表示成功，否则表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_GetCruise(long hDev, long channel,int& iCruise,tCruise *pCruiseList);

#define PTZ_REQ_PARA 1

/*该结构体用于请求的返回值*/
typedef struct  
{  unsigned int channel_id ; //通道号
   unsigned int cam_id;      //串口通信地址(1-255)
   unsigned int protocol;    //串口协议 
   unsigned int baudrate;    //串口速率   
}tPtzParam;

/**********************************************************************************
* Function:      NetClient_PTZReq
* Description:   获取云台信息
* Input:         long hDev  设备句柄
*                unsigned int channel_id 云台通道ID
*                unsigned int ucommand  云台命令
*                void *retBuf  配置信息保存地址
*                int *retLen   配置缓冲区最大长度
* Output:        void *retBuf  获取的配置信息
*                int *retLen   返回配置消息长度
* Return:        返回TRUE表示成功，否则表示失败
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZReq (long hDev, long uchannel, unsigned int ucommand, void *retBuf,int *retLen);


/*查询方式*/
#define LOG_FIND_ALL         0
#define LOG_FIND_TYPE        1
#define LOG_FIND_TIME        2
#define LOG_FIND_TYPEANDTIME 3

/**********************************************************************************
* Function:      NetClient_LogFindNext
* Description:   查询指定设备上的日志记录
* Input:         long hDev  设备句柄，通过NetClient_Login ()函数获取
*                BYTE bytSelectMode  查询方式，:0－全部，1－按类型，2－按时间，3－按时间和类型
*                BYTE bytChannel     要查询的通道号，0表示查询所有的通道
*                BYTE bytMajorType   设备主类型
*                BYTE bytMinorType   设备次类型
*                tNetTime*  lpStartTime  开始时间 
*                tNetTime*  lpStopTime   结束时间
* Output:        无
* Return:        查询日志的句柄； -1表示启动查询日志失败
************************************************************************************/ 
NET_SDK_API long  NetClient_LogFindStart(long hDev, BYTE bytSelectMode, BYTE bytChannel, BYTE bytMajorType, \
                                        BYTE bytMinorType, tNetTime*  lpStartTime, tNetTime*  lpStopTime);


/*NetClient_LogFindNext的返回值*/
#define NET_DEV_FILE_SUCCESS     1000 //获得文件信息 
#define NET_DEV_FILE_NOFIND      1001 //没有文件 
#define NET_DEV_ISFINDING        1002 //正在查找文件 
#define NET_DEV_NOMOREFILE       1003 //查找文件时没有更多的文件 
#define NET_DEV_FILE_EXCEPTION   1004 //查找文件时异常
#define NET_DEV_FIND_TIMEOUT     1005  //查找超时


/**********************************************************************************
* Function:      NetClient_LogFindNext
* Description:   获取一条日志信息 
* Input:         long lLogHandle     已经打开的查询日志句柄
* Output:        tDevLog*  lpLogData 查询到的一条日志信息
* Return:        日志查询状态,1000表示获取成功
************************************************************************************/ 
NET_SDK_API long  NetClient_LogFindNext(long lLogHandle, tDevLog*  lpLogData);


/**********************************************************************************
* Function:      NetClient_LogFindStop
* Description:   释放查找文件的资源 
* Input:         long lLogHandle 已经打开的查询日志句柄
* Output:        无
* Return:        TRUE表示成功，FALSE表示失败
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_LogFindStop(long  lLogHandle);

/*文件 查找*/
/*要查找的文件类型常量*/
enum
{
  FILETYPE_ALL = 0,    /*所有类型*/
  FILETYPE_TIMED,      /*定时触发*/
  FILETYPE_ALARM,      /*告警产生*/
  FILETYPE_MANUAL,     /*手动触发*/
  FILETYPE_NUM
};

/**********************************************************************************
* Function:      NetClient_FileFindStart
* Description:   查询指定设备上的视频文件
* Input:         long hDev     设备句柄，通过NetClient_Login ()函数获取
*                long lChannel 要查询的通道号,通道从0开始计数，0表示第一通道
*                DWORD dwFileType 文件类型，0 － 全部，1 － 定时录像，2 - 移动侦测，3 － 报警触  
*                tNetTime*  lpStartTime 文件的开始时间
*                tNetTime*  lpStopTime  文件的结束时间
* Output:        无
* Return:        查询文件的句柄； INVALID_long_VALUE表示启动查询文件失败,
?               当该接口返回成功后,就可以调用NetClient_FileFindNext接口来获取文件信息
************************************************************************************/ 
NET_SDK_API long  NetClient_FileFindStart(long hDev,long lChannel,DWORD dwFileType, tNetTime*  lpStartTime, tNetTime*  lpStopTime);

#ifndef MAX_FILE_NAME_LEN
#define MAX_FILE_NAME_LEN  256
#endif

typedef struct
{
	char sFileName[MAX_FILE_NAME_LEN];  //文件名
    DWORD dwFileType;                   //文件的类型，和查找时保持一致，
	DWORD dwFileSize;                   //文件的大小
	tNetTime StartTime;                 //文件的开始时间
	tNetTime StopTime;                  //文件的结束时间
}tFileFindData;


/**********************************************************************************
* Function:      NetClient_FileFindNext
* Description:   获取下一条文件信息 
* Input:         long lFindHandle 已经打开的查询文件句柄，由NetClient_FindFile获取            
* Output:        tFileFindData* lpFindData  查询到的一条文件信息
* Return:        文件查询状态,1000表示获取成功,返回值说明见NetClient_LogFindNext
************************************************************************************/ 
NET_SDK_API long  NetClient_FileFindNext(long lFindHandle, tFileFindData* lpFindData);


/**********************************************************************************
* Function:      NetClient_FileFindClose
* Description:   释放查找文件的资源 
* Input:         long lFindHandle 已经打开的查询文件句柄，由NetClient_FindFile获取
* Output:        无
* Return:        TRUE表示成功，FALSE表示失败
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_FileFindClose(long lFindHandle);



/**********************************************************************************
* Function:      NetClient_GetFileByName
* Description:   从设备上按文件名下载
* Input:         long hDev  设备句柄，通过NetClient_Login ()函数获取
*                char *sFileName      要下载的文件名
*                char *sSavedFileName 下载后保存到PC机的文件名
* Output:        无
* Return:        文件下载的句柄；失败返回-1
************************************************************************************/ 
NET_SDK_API long   NetClient_GetFileByName(long hDev,char *sFileName,char *sSavedFileName);

/**********************************************************************************
* Function:      NetClient_StopGetFile
* Description:   关闭文件下载
* Input:         long lFileDownloadHandle  已经打开的文件下载句柄，由NetClient_GetFileByName获取
* Output:        无
* Return:        TRUE表示成功，FALSE表示失败 
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_StopGetFile(long lFileDownloadHandle);


/**********************************************************************************
* Function:      NetClient_GetDownloadPos
* Description:   获取文件下载进度
* Input:         long lFileDownloadHandle  已经打开的文件下载句柄，由NetClient_GetFileByName获取
* Output:        无
* Return:         -1表示失败，0-100:下载的进度，100表示下载结束，>100: 由于网络原因下载异常终止 
************************************************************************************/ 
NET_SDK_API int   NetClient_GetDownloadPos(long lFileDownloadHandle);

/**********************************************************************************
* Function:      NetClient_DelFile
* Description:   在设备上删除文件
* Input:         long hDev  设备句柄，通过NetClient_Login ()函数获取
*                char *sFileName      要删除的文件名，支持通配符
* Output:        无
* Return:        TRUE表示成功，FALSE表示失败
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_DelFile(long hDev,char *sFileName);


typedef struct tagChannelInfo
{
	unsigned int   channelId;     /*通道ID*/
	unsigned char  videoStand;    /*视频制式*/
	unsigned char  videoCodec;    /*编解码方式*/
	unsigned char  picQuality;    /*图像质量*/
	unsigned char  rateControl;   /*速率控制*/
	int            imageWidth;    /*图像宽度*/
	int            imageHeight;   /*图像高度*/
	int            frameRate;     /*帧码流*/
	unsigned short transPort;     /*通道传输采用的端口号*/
	unsigned short transType;     /*传输协议*/
	char           name[32];      /*通道名*/
	char           url[64];
	char           devId[MAX_SERIAL_NUM_LEN];	
}ChannelInfo;

NET_SDK_API BOOL  NetClient_GetConfig(long hDev, long channel,DWORD dwCommand, void* lpOutBuffer, DWORD *lpOutBufferSize);

/**********************************************************************************
* Function:      NetClient_GetChannelInfo
* Description:   获取视频通道信息
* Input:         long hDev 设备句柄
*                BYTE& dwChannelNum    通道缓冲区的大小
*                ChannelInfo *pChannel 接收通道信息的数组，个数由dwChannelNum确定
* Output:        BYTE& dwChannelNum   返回通道数
*                ChannelInfo *pChannel 通道列表，最多由确定
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetChannelInfo(long hDev,BYTE& byteMediaNum, ChannelInfo *pMediaChannel);

/**********************************************************************************
* Function:      NetClient_GetChannelState
* Description:   获取通道状态
* Input:         long hDev 设备句柄
*                BYTE& dwChannelNum    通道缓冲区的大小
*                ChannelInfo *pChannel 接收通道信息的数组，个数由dwChannelNum确定
* Output:        BYTE& dwChannelNum   返回通道数
*                ChannelInfo *pChannel 通道列表，最多由确定
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetChannelState(long hDev,BYTE& channel,BYTE* state);

#define MAX_PRESET_NUM            128
#define MAX_CRUISE_NUM            500
#define MAX_PRESET_NAME_LEN       64
#define MAX_PRESET_RECT_NUM       4
typedef struct tagPresetRect
{
	int top;
	int left;
	int width;
	int height;
	int iEmiss;         /*发射率*/
	int iDistance;      /*距离*/	
	int highTempThresh; /*高温阈值*/
	int predictTempThresh;
	int reserve2; 

	//char name[32];
}tPresetRect;

/*预置点的位置信息*/
typedef struct tagPresetInfo
{
	int         preset_id;
	//char        name[MAX_PRESET_NAME_LEN];
	int         num;
	tPresetRect rect[MAX_PRESET_RECT_NUM];
}tPresetInfo;

/**********************************************************************************
* Function:      NetClient_GetPresetInfo
* Description:   获取预置位信息
* Input:         long hDev 设备句柄
*                BYTE& iPresetNum     预置位个数
*                tPresetInfo *pPreset  预置位数组
* Output:        BYTE& dwChannelNum    返回预置位个数
*                tPresetInfo *pPreset  预置位列表，最多由确定
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetPresetInfo(long hDev,long channel,int& iPresetNum,tPresetInfo *pPreset);


NET_SDK_API BOOL  NetClient_GetCurPreset(long hDev,long channel,int* presetId);

/**********************************************************************************
* Function:      NetClient_GetPresetInfo
* Description:   设置预置位信息
* Input:         long hDev 设备句柄
*                tPresetInfo *pPreset  预置位数组
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SetPresetInfo(long hDev,long channel,tPresetInfo *pPreset);


/**********************************************************************************
* Function:      NetClient_GotoPreset
* Description:   跳转预置位
* Input:         long hDev 设备句柄
*                int iPresetId  预置位数组
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GotoPreset(long hDev,long channel,int iPresetId);

/**********************************************************************************
* Function:      NetClient_ClearPresetInfo
* Description:   清除预置位信息
* Input:         long hDev      设备句柄
*                long channel   通道号
*                int iPresetId  预置位数组
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_ClearPresetInfo(long hDev,long channel,int iPresetId);

/**********************************************************************************
* Function:      NetClient_EnableWatchdog
* Description:   使能watchdog
* Input:         long hDev 设备句柄
*                long channel   通道号
*                int enable  1 表示使能
*                            0 表示不使能
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
* Notes:         从使能切换到不使能，看门狗超时后，系统会重启
************************************************************************************/
NET_SDK_API BOOL   NetClient_EnableWatchdog(long hDev,long channel,int enable);

/*获取服务器状态*/
typedef struct tagServerState
{
	float fCpuUsage;    /*CPU占用率*/
	float fMemTotal;    /*总内存大小  M*/
	float fMemFree;     /*空闲内存大小 M*/
	float fSDTotal;     /*SD卡总容量*/
	float fSDFree;      /*SD卡空闲容量*/
}tServerState;

/**********************************************************************************
* Function:      NetClient_GetServerState
* Description:   获取服务器的状态
* Input:         long hDev 设备句柄
* Output:        tServerState *pState  服务器的状态信息
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetServerState(long hDev,long channel,tServerState *pState);

/**********************************************************************************
* Function:      NetClient_SDFormat
* Description:   格式化SD卡
* Input:         long hDev 设备句柄
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDFormat(long hDev,long channel);

/**********************************************************************************
* Function:      NetClient_SDMount
* Description:   转载SD卡
* Input:         long hDev 设备句柄
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDMount(long hDev,long channel);

/**********************************************************************************
* Function:      NetClient_SDUnMount
* Description:   卸载SD卡
* Input:         long hDev 设备句柄
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDUnMount(long hDev,long channel);

/*同步预置位信息*/
NET_SDK_API BOOL   NetClient_SynPreset(long hDev,long channel);

/*同步巡航信息*/
NET_SDK_API BOOL   NetClient_SynCruise(long hDev,long channel);

/*同步巡航信息*/
NET_SDK_API BOOL   NetClient_StartCruise(long hDev,long channel,BOOL bStart);

/*重载数据库*/
NET_SDK_API BOOL   NetClient_ReloadDB(long hDev);

/*重启设备*/
NET_SDK_API BOOL   NetClient_PowerCtrl(long hDev,long channel,BOOL bOn);


/*重启设备*/
NET_SDK_API BOOL   NetClient_RebootDev(long hDev,long channel);
/*重启FPGA*/
NET_SDK_API BOOL   NetClient_ResetFPGA(long hDev,long channel);

/*前端设备抓图*/
NET_SDK_API BOOL   NetClient_DevCapPic(long hDev,long channel);

/*前端设备红外视频录像*/
NET_SDK_API BOOL   NetClient_DevStartIrRecord(long hDev,long channel);

/*停止红外视频录像*/
NET_SDK_API BOOL   NetClient_DevStopIrRecord(long hDev,long channel);

/*设置网络*/

/*网络配置消息*/
typedef struct
{
	DWORD dwNetIp;
	DWORD dwNetMask;
	DWORD dwNetGateWay;
	DWORD dwDNS;
	DWORD dwNetIp2;
} Net_Config_Data;

NET_SDK_API BOOL   NetClient_SetNetConfig(long hDev,long channel,Net_Config_Data *pInConfig);
NET_SDK_API BOOL   NetClient_GetNetConfig(long hDev,long channel,Net_Config_Data *pOutConfig);

NET_SDK_API BOOL   NetClient_AddUser(long hDev,char* pUserName,char* pPassword,DWORD dwAuth);
NET_SDK_API BOOL   NetClient_DelUser(long hDev,char* pUserName);

/*设置告警触发类型，可以多种组合*/
#define ALARM_MODE_FTP   0x0001
#define ALARM_MODE_SMTP  0x0002
#define ALARM_MODE_SD    0x0004
NET_SDK_API BOOL   NetClient_SetAlarmMode(long hDev,long channel,WORD dwAlarmMode);

NET_SDK_API BOOL    NetClient_SetAlarmTemp(long hDev,long channel,float fTemp);

NET_SDK_API BOOL    NetClient_GetAlarmTemp(long hDev,long channel,float* fTemp);

/*设置设备时间*/
NET_SDK_API BOOL   NetClient_SetTime(long hDev,long channel,tNetTime *pTime);

NET_SDK_API BOOL   NetClient_GetTime(long hDev,long channel,tNetTime *pTime);

typedef enum{
	FACE_NO_DETECT = 0,
	FACE_DETECT,
	FACE_MASK ,
	FACE_RECOGIZE,
	FACE_REGUSER,  //ANR
	FACE_DELUSER,  //ANR
	FACE_TYPE_NUM
}FACE_TYPE;


/*可见光的流ID,为了便于控制，采用固定ID*/
#define STREAM_ID_RAW           0  /*原始流，暂时没用*/
#define STREAM_ID_MJPEG         1
#define STREAM_ID_MPEG4_1       2  /*如果只有一条MPEG4流，则选第一个*/
#define STREAM_ID_MPEG4_2       3
#define STREAM_ID_H264_1        4  /*如果只有一条H264流，则选第一个*/
#define STREAM_ID_H264_2        5
#define STREAM_ID_IR            6  /*红外视频流*/

#define MAX_VL_STREAM_NUM       7

#define ALL_STREAM_CHANNEL      0xFF /*所有通道*/

#define VL_CHANNEL_INDEX        0 /*可见光通道*/
#define IR_CHANNEL_INDEX        1 /*红外通道*/

/*视频参数控制*/
/*视频参数*/
typedef struct
{
	BYTE cmd;
	BYTE channel;
	WORD len;
	BYTE data[4];
}VideoPara_t;

/*设置和获取亮度*/
NET_SDK_API BOOL    NetClient_SetBrightness(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetBrightness(long hDev,long channel,DWORD& wValue);

/*设置和获取对比度*/
NET_SDK_API BOOL    NetClient_SetContrast(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetContrast(long hDev,long channel,DWORD& wValue);


/*设置和获取饱和度*/
NET_SDK_API BOOL    NetClient_SetSaturation(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetSaturation(long hDev,long channel,DWORD& wValue);


/*设置和获取白平衡*/
NET_SDK_API BOOL    NetClient_SetWhiteBalance(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetWhiteBalance(long hDev,long channel,DWORD& wValue);

/*设置和获取锐化度*/
NET_SDK_API BOOL    NetClient_SetSharpness(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetSharpness(long hDev,long channel,DWORD& wValue);

/*设置和获背景光*/
NET_SDK_API BOOL    NetClient_SetBacklight(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetBacklight(long hDev,long channel,DWORD& wValue);

/*设置白光模式*/
NET_SDK_API BOOL    NetClient_SetDayNight(long hDev,long channel, DWORD  wValue);
NET_SDK_API BOOL    NetClient_GetDayNight(long hDev,long channel, DWORD& wValue);

typedef enum
{
	/*单码流*/
	H264_720P = 1,
	H264_FD1,
	H264_1080P,
	
	MPEG4_SXVGA,
	MPEG4_FD1,
	MPEG4_720P,
	MPEG4_1080P,
	
	MJPEG_UXGA,  
	MJPEG_QXGA,
	CHAN_ONE_END,                      /*单码流结束*/

	/*双码流*/
	H264_720P__MJPEG_VGA,
	H264_VGA__MJPEG_VGA,
	H264_FD1__MJPEG_FD1,
	
	H264_720P__H264_CIF,
	H264_FD1__H264_FD1,
	H264_FD1__MPEG4_FD1,

	MPEG4_720P__MPEG4_CIF,
	MPEG4_FD1__MPEG4_FD1,
	MPEG4_720P__MJPEG_VGA,
	MPEG4_VGA__MJPEG_VGA,
	MPEG4_FD1__MJPEG_FD1,

	/*红外流*/
	IR_240P_MPEG4_YUV_480P,               /*红外+红外YUV的MPEG4压缩*/
	IR_288P_MPEG4_YUV_576P,
    IR_120P_MPEG4_YUV_240P,

	IR_240P_H264_YUV_480P,                /*红外+红外YUV的H264压缩*/
	IR_288P_H264_YUV_576P,
    IR_120P_H264_YUV_240P,
    
	CHAN_DOUBLE_END,                   /*双码流*/
	
	/*三码流*/
	MPEG4_720P__MJPEG_VGA__MPEG4_CIF,
	H264_720P__MJPEG_VGA__H264_CIF,

	IR_240P_H264_YUV_480P_VL_576P,         /*红外+红外YUV+可见光YUV的H264压缩*/
	IR_288P_H264_YUV_576P_VL_576P,      
	IR_288P_H264_YUV_288P_VL_288P,         /*不放大*/
    IR_120P_H264_YUV_240P_VL_576P,

	IR_240P_MPEG4_YUV_480P_VL_576P,         /*红外+红外YUV+可见光YUV的MPEG4压缩*/
	IR_288P_MPEG4_YUV_576P_VL_576P,
	IR_288P_MPEG4_YUV_288P_VL_288P,        /*不放大*/
    IR_120P_MPEG4_YUV_240P_VL_576P,
	
	CHAN_TRI_END,                          /*三码流*/

    
    CODEC_NUM,
}eCodecTypes;
/*设置视频模式*/
NET_SDK_API BOOL    NetClient_SetVideoCodec(long hDev,long channel,BYTE byteMediaNum,ChannelInfo *pMediaChannel);

/*速率控制方式*/
typedef enum
{
	RATE_CONTROL_NONE = 0,
	RATE_CONTROL_CVBR,
	RATE_CONTROL_CBR,
	RATE_CONTROL_NUM
}eRateControl;

/*设置帧率控制*/
NET_SDK_API BOOL    NetClient_SetRateControl(long hDev,long channel,DWORD dwRateControl);
NET_SDK_API BOOL    NetClient_GetRateControl(long hDev,long channel,DWORD& dwRateControl);

/*设置JPEG质量*/
NET_SDK_API BOOL     NetClient_SetJpgQuality(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetJpgQuality(long hDev,long channel,DWORD& wValue);

/*设置编码率*/
NET_SDK_API BOOL     NetClient_SetEncBitrate(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetEncBitrate(long hDev,long channel,DWORD& wValue);

/*设置帧率*/
NET_SDK_API BOOL     NetClient_SetEncFramerate(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetEncFramerate(long hDev,long channel,DWORD& wValue);

/*设置OSD*/
#define OSD_TEXT         0x0001  /*用户定义的文本*/
#define OSD_TEXT_TIME    0x0002  /*显示时间*/
#define OSD_LOGO         0x0004  /*显示LOGO*/
#define OSD_HISTOGRAM    0x0008  /*显示直方图*/
#define NO_OSD_TEXT      0x0100  /*取消文本OSD显示*/
#define NO_OSD_TEXT_TIME 0x0200  /*取消文本时间戳显示*/
#define NO_OSD_LOGO      0x0400  /*取消OSD的Logo显示*/
#define NO_OSD_HISTOGRAM 0x0800  /*取消OSD的直方图显示*/
NET_SDK_API BOOL    NetClient_SetOSD(long hDev,long channel,DWORD dwOsdType,char *pInOsdText);

#define VL_AEWB_NONE        0x0000
#define VL_AEWB_APPRO       0x0001
#define VL_AEWB_TI          0x0002
#define VL_AEWB_ALL         0x000F
#define VL_GBCE             0x0010  /*全局对比度增强*/

#define SENSOR_MODE_DEFAULT    0
#define SENSOR_MODE_BINNING    1
#define SENSOR_MODE_SKIPPING   2
#define SENSOR_MODE_WINDOW     3

/*可见光加上过滤算法*/
#define FILTER_VIDEO_STABILIZATION          0x0001  
#define FILTER_LENS_DISTORTION_CORRECTION   0x0002
#define FILTER_SPATIAL_NOISE_FILTER         0x0004
#define FILTER_TEMPRORAL_NOISE_FILTER       0x0008

NET_SDK_API BOOL   NetClient_SetFilter(long hDev,long channel,DWORD dwFeature);

/*************************************FPGA控制**************************************************/

/*调用FPGA控制，需要包含IrSDK.h头文件，宏在那个头文件中定义*/

/*这些宏在NetSDK中也使用，避免重复调用，采用宏区分*/


typedef struct _object_pt
{
	unsigned int  no;
	unsigned short x;
	unsigned short y;
	unsigned int   color;
	float    fAlarmHighTemp;
	float    fAlarmLowTemp;
	float    fEmiss;
	int      distance;
}tFpgaObjPt;

typedef struct _object_rect
{
	unsigned int   no;
	unsigned short left;
	unsigned short top;
	unsigned short width;
	unsigned short height;
	unsigned int   color;	
	float    fAlarmHighTemp;
	float    fAlarmLowTemp;
	float    fEmiss;
	int      distance;
}tFpgaObjRect;

typedef struct _object_circle
{
	unsigned int   no;
	unsigned short center_x;
	unsigned short center_y;
	unsigned short radius;
	unsigned short reserve;
	unsigned int   color;	
	float    fAlarmHighTemp;
	float    fAlarmLowTemp;
	float    fEmiss;
	int      distance;	
}tFpgaObjCircle;

typedef struct _object_line
{
	unsigned int  no;
	unsigned short pt1x;
	unsigned short pt1y;
	unsigned short pt2x;
	unsigned short pt2y;
	unsigned int   color;
	float    fAlarmHighTemp;
	float    fAlarmLowTemp;
	float    fEmiss;
	int      distance;
}tFpgaObjLine;

#define MAX_POLYGON_NUM  16

typedef struct _object_polygon
{
	unsigned int no;
	int      num;
	unsigned short  x_list[MAX_POLYGON_NUM];
	unsigned short  y_list[MAX_POLYGON_NUM];
	unsigned int   color;
	float    fAlarmHighTemp;
	float    fAlarmLowTemp;
	float    fEmiss;
	int      distance;	
}tFpgaObjPolygon;


typedef struct _object_temp_ret
{
	unsigned int no;
	float fMaxTemp;
	float fMinTmep;
	float fAvgTemp;
}tFpgaObjTemp;

/*调用FPGA控制，需要包含IrSDK.h头文件，宏在那个头文件中定义*/
#define MAX_READ_DATA_LEN     1024

#define MAX_TEMP_OBJ_NUM      8

/**********************************************************************************
* Function:      NetClient_FpgaCtrl
* Description:   控制FPGA设备
* Input:         long hDev              设备句柄
*                long channel           通道号
*                unsigned short cmd     FPGA命令
*                unsigned short cmdType 命令类型
*                unsigned char* pBuff   命令参数缓冲区长度
*                int iBufLen            命令参数缓冲区
*                unsigned char *pRetBuf 命令返回接收缓冲区
*                int *pRetLen           返回缓冲区总长度
* Output:        unsigned char *pRetBuf 命令返回
*                int *pRetLen           返回缓冲区长度
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_FpgaCtrl(long hDev,long channel,unsigned short cmd,unsigned short cmdType=1/*FPGA_CTRL_TYPE_REQUEST_NO_REPLY*/,unsigned char* pBuff=NULL,int iBufLen=0,unsigned char *pRetBuf = NULL,int *pRetLen = NULL);

NET_SDK_API BOOL   NetClient_FpagSetObjPt     (long hDev,long channel,unsigned int  objNo,unsigned short cmdType,tFpgaObjPt      *pt);
NET_SDK_API BOOL   NetClient_FpagSetObjRect   (long hDev,long channel,unsigned int  objNo,unsigned short cmdType,tFpgaObjRect    *pRect);
NET_SDK_API BOOL   NetClient_FpagSetObjCircle (long hDev,long channel,unsigned int  objNo,unsigned short cmdType,tFpgaObjCircle  *pCircle);
NET_SDK_API BOOL   NetClient_FpagSetObjPolygon(long hDev,long channel,unsigned int  objNo,unsigned short cmdType,tFpgaObjPolygon *pPoly);
NET_SDK_API BOOL   NetClient_FpagSetObjLine   (long hDev,long channel,unsigned int  objNo,unsigned short cmdType,tFpgaObjLine *pLine);


NET_SDK_API BOOL   NetClient_FpagGetObjPt        (long hDev,long channel,tFpgaObjTemp   pTemp[MAX_TEMP_OBJ_NUM]);
NET_SDK_API BOOL   NetClient_FpagGetObjLine      (long hDev,long channel,tFpgaObjTemp   pTemp[MAX_TEMP_OBJ_NUM]);
NET_SDK_API BOOL   NetClient_FpagGetObjRectTemp  (long hDev,long channel,tFpgaObjTemp   pTemp[MAX_TEMP_OBJ_NUM]);
NET_SDK_API BOOL   NetClient_FpagGetObjCircleTemp(long hDev,long channel,tFpgaObjTemp   pTemp[MAX_TEMP_OBJ_NUM]);
NET_SDK_API BOOL   NetClient_FpagGetObjPolyTemp  (long hDev,long channel,tFpgaObjTemp   pTemp[MAX_TEMP_OBJ_NUM]);

typedef int (*Fpga_FileTrans)(long lPrivate, int totalLen, int curLen);

/**********************************************************************************
* Function:      NetClient_SendFpgaFile
* Description:   往网络设备发送文件供FPGA使用
* Input:         long hSerial    串口设备句柄
*                char *fileName  发送文件名
*                Fpga_FileTrans  pCbFileTrans  文件传输状态回调
*                long lPrivate   回调函数的参数
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL    NetClient_SendFpgaFile(long hDev,int fileType,char *fileName,Fpga_FileTrans pCbFileTrans = NULL,long lPrivate=0 );


/**********************************************************************************
* Function:      NetClient_RecvFpgaFile
* Description:   从网络设备接收从FPGA传来的文件
* Input:         long hSerial    串口设备句柄
*                int fileType    文件类型
*                char *fileName  保存文件名
*                Fpga_FileTrans pCbFileTrans  文件传输状态回调
*                long lPrivate   回调函数的参数
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
NET_SDK_API BOOL    NetClient_RecvFpgaFile(long hDev,int fileType,char *fileName,Fpga_FileTrans pCbFileTrans = NULL,long lPrivate=0);


/***********************************************************************************************/

#endif

