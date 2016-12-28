/**************************************************************************************************
* File Name     : NetSDK.h
* Module Name   : Net_SDK
* Description   : ����SDK
* Author/Date   : Janekey/ 2011.09.17
* Version       : 1.3.3.2
* State         : create
* -----------------------------------History-------------------------------------------------------
* Modifier/Date : 2011.05.27
* Modify Reason : ��ʼ�����淶ע��
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.30
* Modify Reason : ����ͼ��ֱ��ʺ�ģʽ��ȡͼ���С
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.21
* Modify Reason : ���Ӵ�����ͻ��˿���FPGA�ĺ����Լ��ϴ��������ļ��Ľӿ�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.17
* Version:        1.2.2.9
*                 ������׼��ע��
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.22
* Version:        1.2.2.10
*                 ��FPGA���ƺ�ɾ������Ҫ����ʱ����IrSDK.hͷ�ļ�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.24
* Version:        1.2.3.1
*                 �޸���������Ӧ��ʽ����һ��ʱ���ȡ��������������ʱ������������Ϣ
*                 �����豸״̬ͨ���ص����أ������������ɹ���Ϣ
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.24
* Version:        1.2.6.1
*                 �����˻�ȡ��������״̬��Ϣ���� NetClient_GetServerState
*                 ������SD��װ�ء�ж�ء���ʽ������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.27
* Version:        1.2.6.2
*                 ������Զ�̲���������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.2
* Version:        1.2.8.2
*                 �������豸������FPGA��������NetClient_RebootDev��NetClient_ResetFPGA
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.3
* Version:        1.3.2.1
*                 �������豸ץͼ���豸¼��Ŀ��ƹ��ܺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.3
* Version:        1.3.3.2
*                 ������ɾ���ļ��Ĺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.1.4
* Version:        1.3.4.1
*                 ������NetClient_SetNotifyHwnd������Ϣ֪ͨ���ô�NetClient_Startup�з��룬
*                 ���ⴰ��δ����ʱ��������NetSDK
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.3.31
* Version:        1.3.6.1
*                 NetClient_PTZCruise�����޸��ˣ�ֱ����������Ѳ����
*                 ���ӻ�ȡѲ��״̬���� NetClient_PTZCruiseRunning()
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.4.12
* Version:        1.3.8.1
*                 NetClient_GetChannelInfo �����޸ģ���ȡ��ͨ����Ϣ���ݷ������
*                 ��ȡ��ͨ����Ϣ����ͼ���С��ͨ������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.6
* Version:        1.3.9.2
*                 ����Ԥ��λ�����Ӻ�ɾ��
*                 ��̨��ʼ�������޸�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.28
* Version:        1.3.9.3
*                 �澯������һ������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.26
* Version:        1.3.9.4
*                 ���Ӻ���NetClient_GotoPreset
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.7.24
* Version:        1.3.9.8
*                 ��Ƶ��������޸ģ������������÷�ʽ
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.8.20
* Version:        1.4.2.0
*                 ȥ��SMTP��FTP���úͻ�ȡ
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.8.22
* Version:        1.4.2.1
*                 �ļ����سɹ�ʱ���йر������ļ�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.9.8
* Version:        1.4.2.2
*                 ���ӿ��Ź�ʹ�ܺ��� NetClient_EnableWatchdog
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.10.11
* Version:        1.4.3.1
*                 ÿ��Ԥ��λ���������4�����¶���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.11.15
* Version:        1.4.4.1
*                 �澯�ص������޸�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.03.95
* Version:        1.5.1.1
*                 API����������channel
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.9
* Version:        1.8.1.1
*                 ��������ע��
*                 ���ӻص�֪ͨ����NetClient_SetNotifyCBF
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.29
* Version:        1.9.1.1
* Modify Reason : socket�ر�ʱ����shutdown���ص�¼�߳�ֱ�ӹر�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2014.10.21
* Version:        2.6.0.1
*                 ͳһϵͳ������
* -------------------------------------------------------------------------------------------------
**************************************************************************************************/
#ifndef NET_SDK_CLIENT_INCLUDE_H
#define NET_SDK_CLIENT_INCLUDE_H

/*LINUX�汾��SDK����*/
//#define HAVE_LINUX

/*WINDOWS�汾��SDK����*/


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


//�ͻ����յ�����Ϣ
typedef enum
{
	MSG_DATA_ERR = 0,        //�������������쳣
	MSG_PLAY_ERR,            //�ͻ��˲��ų����쳣
	MSG_REFUSED,             //�ͻ������ӱ��ܾ�
	MSG_GET_STRING,          //�ͻ����յ���Ϣ�ַ���
	MSG_SERVER_CLOSE,        //�������˳�
	MSG_NET_FAILED,          //�������ͨ�ų����쳣
	MSG_RECONNECT_SUCCESS,   //�����ɹ�
	MSG_RECV_FRAME,          //�ͻ����յ�һ֡����
}eClientRecvMsg;


typedef struct {
    BYTE m_bytRemoteChannel;    //��Ӧ������ͨ��
    BYTE m_bytSendMode;         //���䷽ʽ(TCP/UDP/MULTIMODE)
    BYTE m_bytLinkType;         //Զ�̽��뷽ʽ(ADSL/PSTN/LAN/ISDN)

    BYTE m_bytPlayMode;         //���ŷ�ʽ(STREAM/TOKEN)
    char* m_sIP;                //��Ӧ������IP      
    char* m_sUserName;          //�û���
    char* m_sUserPassWord;      //�û�����
    BOOL m_bUserCheck;          //�Ƿ���Ҫ�����û���������
    HWND m_hShowVideo;          //��Ƶ��ʾ����
    BYTE m_bytDecodeMode;       //��������(SOFTDEC(Default) / HARDDEC/MATRIXDEC/H264DEC)
}tClientInfo;

typedef struct {	
    char* m_sIP;//��Ӧ������IP      	
    char* m_sUserName;//�û���	
    char* m_sUserPassWord;//�û�����
    BYTE m_bytSendMode;//���䷽ʽ(TCP/UDP/MULTIMODE)	
    BOOL m_bUserCheck;//�Ƿ���Ҫ�����û���������
}tVoiceCommInfo ;

typedef enum 
{
    StandardNone	= 0x80000000,
    StandardNTSC	= 0x00000001,
    StandardPAL		= 0x00000002,
    StandardSECAM	= 0x00000004,
} eVideoStandard;


//���紫�����Э��
enum { UDPMODE =0 , TCPMODE , MULTIMODE }; 

//DirectDraw��ʾģʽ
enum { NORMALMODE = 0 , OVERLAYMODE };

//��Ƶ����
enum { LOWQUALITY = 0 , HIGHQUALITY };

//���ŷ�ʽ,STREAM �����ڿ����·����, TOKEN ������խ����·����
enum { STREAM = 0, TOKEN };

//���紫�����
/////////////////////////////////////////////////////
// ADSL: 1M ~ 4M 
// PSTN: <56k
// ISDN: >64k < 128K
// LAN:  >10M 
/////////////////////////////////////////////////////
enum { LAN = 0, ADSL, ISDN, PSTN }; 

//���뷽ʽ
enum { SOFTDEC = 0, HARDDEC ,MATRIXDEC, H264DEC };


#define  MAX_RS485_PORT_NUM    256
#define  MAX_RS232_PORT_NUM    64

/*��������*/
typedef enum 
{
    RS232 =  0,
    RS485 =  1,
    RS422 =  2,
}eSerialType;



/* ������־ */ 
#define MAJOR_ALL             0x0

/* ���� */ 
#define MAJOR_OPERATION       0x1 

enum 
{
    MINOR_OPR_ALL = 0,                 /*ȫ��*/
    MINOR_OPR_REMOTE_PTZ,              /*Զ����̨����*/
    MINOR_OPR_REMOTE_PLAYTIME,        /*Զ�̰�ʱ��ط�*/
    MINOR_OPR_REMOTE_PALYFILE,        /*Զ���ļ��ط�*/
    MINOR_OPR_REMOTE_UPGRADE,         /*Զ������*/
    MINOR_OPR_VOICE_STOP,             /*�����Խ�����*/
    MINOR_OPR_VOICE_START,            /*�����Խ���ʼ*/
    MINOR_OPR_REMOTE_RESTART,         /*Զ������*/
    MINOR_OPR_REMOTE_DEF_WITHDRAW,    /*Զ�̳���*/
    MINOR_OPR_REMOTE_DEF_LAY,         /*Զ�̲���*/
    MINOR_OPR_REMOTE_GETSTATE,        /*Զ�̻�ȡ״̬*/ 
    MINOR_OPR_REMOTE_CONFIG,          /*Զ������*/
    MINOR_OPR_REMOTE_GETPARA,         /*Զ�̻�ȡ����*/
    MINOR_OPR_REMOTE_RECORD_STOP,     /*Զ��ֹͣ¼��*/   
    MINOR_OPR_REMOTE_RECORD_START,    /*Զ������¼��*/  
    MINOR_OPR_REMOTE_CANCEL,          /*Զ��ע��*/
    MINOR_OPR_REMOTE_LOGIN,           /*Զ�̵�½*/
    MINOR_OPR_LOCAL_UPGRADE,          /*��������*/   
    MINOR_OPR_LOCAL_PTZ_CTRL,         /*������̨����*/
    MINOR_OPR_LOCAL_RECORD_STOP,      /*����ֹͣ¼��*/ 
    MINOR_OPR_LOCAL_RECORD_START,     /*���ؿ�ʼ¼��*/
    MINOR_OPR_LOCAL_PLAYTIME,         /*���ذ�ʱ��ط�*/
    MINOR_OPR_LOCAL_PLAYFILE,         /*�����ļ��ط�*/
    MINOR_OPR_LOCAL_CONFIG,           /*��������*/
    MINOR_OPR_LOCAL_CANCEL,           /*����ע��*/
    MINOR_OPR_LOCAL_LOGIN,            /*���ص�¼*/
    MINOR_OPR_SHUTDOWN_ILLEGAL,       /*�Ƿ��ػ�*/
    MINOR_OPR_SHUTDOWN,               /*�ػ�*/
    MINOR_OPR_START,                  /*����*/
    MINOR_OPR_LOG_REMOVE,             /*��־���*/
    MINOR_OPR_FILE_BACKUP,            /*�����ļ�*/
    MINOR_OPR_NUM                     /*������������*/
};


/*Զ�̲���ϸ��*/
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
	OPR_DETAIL_DEL_FILE,     /*ɾ���ļ�*/	
	OPR_DETAIL_FACE_DETECT,
	OPR_DETAIL_FPGA_CTRL,
	OPR_DETAIL_FPGA_RESET,   /*FPGA����*/
	OPR_DETAIL_DEV_REBOOT,   /*�豸����*/	
	OPR_DETAIL_NUM,
};

/* �쳣 */ 
//������ 
#define   MAJOR_EXCEPTION       0x2 
//������
enum 
{
    MINOR_EXCEPTION_ALL=0,               /*ȫ��*/
    MINOR_EXCEPTION_IP_CONFLICT,         /*IP��ͻ*/
    MINOR_EXCEPTION_DISK_FULL,           /*Ӳ����*/
    MINOR_EXCEPTION_DISK_ERRO,           /*Ӳ�̴���*/
    MINOR_EXCEPTION_ACCESS_INVALID,      /*�Ƿ�����*/
    MINOR_EXCEPTION_INPUT_SIG_LOST,      /*�����źŶ�ʧ*/
    MINOR_EXCEPTION_INPUT_SIG_RESCURE,   /*�����źŻָ�*/
    MINOR_EXCEPTION_NUM                  /*�쳣����*/
};

/*����*/
//������
#define MAJOR_ALARM              0x3
//������ 
enum
{
    MINOR_ALARM_ALL = 0,                   /*ȫ��*/
	MINOR_ALARM_VIDEO_LOST,                /*��Ƶ��ʧ*/
	MINOR_ALARM_VIDEO_RECOVERY,            /*��Ƶ�ָ�*/
    MINOR_ALARM_HIDE_STOP,                 /*�ڵ���������*/
    MINOR_ALARM_HIDE_START,                /*�ڵ�������ʼ*/
    MINOR_ALARM_MOTION_DETCT_STOP,         /*�ƶ���ⱨ����ʼ*/
    MINOR_ALARM_MOTION_DETCT_START,        /*�ƶ���ⱨ����ʼ*/
    MINOR_ALARM_OUT_START,                 /*���������ʼ*/
    MINOR_ALARM_OUT_END,                   /*�����������*/
    MINOR_ALARM_IN_START,                  /*��������*/
    MINOR_ALARM_IN_END,                    /*����������ʧ*/
   	MINOR_ALARM_SD_FULL,                   /*SD���洢��*/
   	MINOR_ALARM_SD_ERROR,                  /*��ȡSD������*/
    MINOR_ALARM_ETH_LOST,                  /*���߶Ͽ���*/
    MINOR_ALARM_GOTO_PRESET,               /*����Ԥ��λ*/
    MINOR_ALARM_HIGH_TEMP,                 /*���¸澯*/
    MINOR_ALARM_TEMP_LOG,                  /*�¶ȼ�¼*/
    MINOR_ALARM_CHANNEL_STATE,             /*ͨ��״̬�ı�*/
    MINOR_ALARM_ERROR_FPGA,                /*FPGA����*/
    MINOR_ALRAM_ERROR_DM368,               /*DM368����*/
    MINOR_ALARM_OTHER,                     /*�������͸澯*/    
    MINOR_ALARM_NUM                        /*��������*/
};


/*��־�ķ��ؽ��*/
#define MAX_LOG_DESC_LEN       32
#define MAX_NAMELEN            40
typedef struct {
    char      strLogTime[MAX_LOG_DESC_LEN];     //ʱ��
    char 	  strMajorType[MAX_LOG_DESC_LEN];   //������
    char 	  strMinorType[MAX_LOG_DESC_LEN];   //������
    char      strDetail[MAX_LOG_DESC_LEN];      //��ϸ��Ϣ
    char	  strUser[MAX_NAMELEN];             //����Ա
    DWORD     dwRemoteHostAddr;                 //Զ��������ַ
    DWORD	  dwChannel;                        //ͨ����
}tDevLog;

/*ʱ����ҵĽṹ*/
typedef struct{
    DWORD dwYear;		//��
    DWORD dwMonth;      //��
    DWORD dwDay;		//��
    DWORD dwHour;		//ʱ
    DWORD dwMinute;	//��
    DWORD dwSecond;	//��
}tNetTime ;


#define MAX_SERIAL_NUM_LEN 	32
#define MAX_VERSION_LEN     32
#define MAX_DEV_NAME_LEN    32

#define DEV_TYPE_IPNC    0
#define DEV_TYPE_SERVER  1

typedef struct  {
    char SerialNumber[MAX_SERIAL_NUM_LEN];   //���к�
    char SoftWareVersion[MAX_VERSION_LEN];   //����汾��
	char HardWareVersion[MAX_VERSION_LEN];   //Ӳ���汾��
	char DevName[MAX_DEV_NAME_LEN];          //�豸��
	BYTE byteIpncType;						 //���� 
    BYTE byAlarmInPortNum;				     //�����������
    BYTE byAlarmOutPortNum;				     //�����������
    BYTE byChanNum;						     //ͨ������
}tDeviceInfo;


/*!�豸ע����Ϣ�ṹ*/
#define MAC_LEN				20
#define VERSION_INFO_LEN	20
#define IP_LEN				20
typedef struct tagRegisterInfo
{
    unsigned int  DeviceID;				/*�豸ID�ţ���Ʒ���кţ�*/
    unsigned char DeviceIP[IP_LEN];		/*�豸��IP��ַ��*/
    unsigned char DeviceMAC[MAC_LEN];	/*�豸��MAC��ַ*/
    unsigned int  DeviceCmdPort;	    /*�豸ͨѶ�˿�*/
    unsigned int  DeviceDataPort;       /*�豸���ݶ˿�*/
    unsigned int  DeviceType;			/*�豸����*/
    unsigned char DeviceVersion[VERSION_INFO_LEN]; /*!�豸����汾��*/
}RegisterInfo, *LPRegisterInfo;
//�豸ע��ص�

/****************************��Ƶ��س���***************************************************/

/*������Ƶͼ���С*/
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


// ��Ƶ��������
#define VIDEO_NULL          0x0 // û����Ƶ
#define VIDEO_H264          0x1 // ��׼H.264�ͺ���H.264���������������
#define VIDEO_MJPEG         0x2
#define VIDEO_MPEG4         0x3 // ��׼MPEG4
#define VIDEO_IR            0x4 //������Ƶ

// ��Ƶ��������
#define AUDIO_NULL          0x0000 // û����Ƶ
#define AUDIO_ADPCM         0x1000 // ADPCM 
#define AUDIO_MPEG          0x2000 // MPEG ϵ����Ƶ��������������Ӧ����MPEG��Ƶ
// Gϵ����Ƶ
#define AUDIO_G711_U		0x7110
#define AUDIO_G711_A		0x7111
#define AUDIO_G722_1		0x7221
#define AUDIO_G723_1        0x7231
#define AUDIO_G726          0x7260
#define AUDIO_G729          0x7290

/**********************************************************************************
* Function:      NetClient_GetPicRes
* Description:   ����ͼ��ֱ����Լ�ģʽ��ȡͼ���С
* Input:         ePicResolution picRes      ͼ��ֱ���
*                eVideoStandard videoStand  ��Ƶģʽ      
* Output:        int& iWidth   ͼ����
*                int &iHeight  ͼ��߶�
* Return:        �ɹ���ȡ����TRUE,���򷵻�FALSE
************************************************************************************/
NET_SDK_API BOOL  NetClient_GetPicRes(ePicResolution picRes,eVideoStandard videoStand,int& iWidth, int &iHeight );


/****************************��̨��س���***************************************************/
/*֧�ֵ���̨Э���б�*/
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

/*��̨Э������*/
typedef enum
{ 
	PTZ_CMD_UP,                /* ��̨��SS���ٶ����� */
	PTZ_CMD_DOWN,	           /* ��̨��SS���ٶ��¸� */
	PTZ_CMD_LEFT,	           /* ��̨��SS���ٶ���ת */
	PTZ_CMD_RIGHT,             /* ��̨��SS���ٶ���ת */
    PTZ_CMD_UP_LEFT,		   /* ��̨��SS���ٶ���������ת */
 	PTZ_CMD_DOWN_LEFT,	       /* ��̨��SS���ٶ���������ת */
 	PTZ_CMD_UP_RIGHT,		   /* ��̨��SS���ٶ��¸�����ת */
    PTZ_CMD_DOWN_RIGHT,	       /* ��̨��SS���ٶ��¸�����ת */
	PTZ_CMD_STOP,	           /* ֹͣ��̨Ѳ����ɨ�衢������ڡ��������*/

	PTZ_CMD_IRIS_OPEN,         /* ��Ȧ���ٶ�SS���� */
	PTZ_CMD_IRIS_CLOSE,	       /* ��Ȧ���ٶ�SS��С */
    PTZ_CMD_ZOOM_IN,           /* �������ٶ�SS���(���ʱ��) */
    PTZ_CMD_ZOOM_OUT,		   /* �������ٶ�SS��С(���ʱ�С) */
 
 	PTZ_CMD_FOCUS_IN,	       /* �������ٶ�SSǰ�� */
    PTZ_CMD_FOCUS_OUT,		   /* �������ٶ�SS��� */

	/*ֹͣλ*/
	PTZ_CMD_PTSTOP_2,
	PTZ_CMD_ZOOM_STOP,
	PTZ_CMD_FOCUS_STOP,
	PTZ_CMD_FOCUS_AUTO,        /*�Զ�������*/
	PTZ_CMD_IRIS_AUTO,         /*�Զ���Ȧ*/

	/*λ������*/
	PTZ_CMD_SET_LEFT_LIMIT,
	PTZ_CMD_SET_RIGHT_LIMIT,

	/*���ò���*/
	PTZ_CMD_SET_ZOOM_SPEED,    /* ����ZOOM����*/
	PTZ_CMD_SET_FOCUS_SPEED,   /* ����FOCUS����*/
	PTZ_CMD_SET_LENS_SPEED,
	PTZ_CMD_SET_SCAN_SPEED,
	PTZ_CMD_SET_ROTATE_SPEED,
	
	/*Ԥ��λ*/
	PTZ_CMD_SET_PRESET,        /*����Ԥ�õ� */
	PTZ_CMD_GOTO_PRESET,       /* ��ת��Ԥ�õ� */
	PTZ_CMD_CLEAR_PRESET,	   /* ���Ԥ�õ� */
	PTZ_CMD_SAVE_PRESET,       /* ����Ԥ�õ� */

	PTZ_CMD_AUTO_PAN,
 	PTZ_CMD_CAM_LIGHT,
 	PTZ_CMD_CAM_POWER,

	PTZ_CMD_SET_AUTO_PAN_SPEED,

	PTZ_CMD_LIGHT_ON,          /*�ƹ⿪*/
 	PTZ_CMD_LIGHT_OFF,         /*�ƹ��*/
 	
	PTZ_CMD_SWITCH_ON,
	PTZ_CMD_SWITCH_OFF,
	
	PTZ_CMD_BRUSH_ON,         /*��ˢ��*/
    PTZ_CMD_BRUSH_OFF,        /*��ˢ��*/

	PTZ_CMD_SET_ROTATE_ON,
	PTZ_CMD_SET_ROTATE_OFF,
	
	/*Scan*/
	PTZ_CMD_SCAN_ON,           /* ֹͣ��ɨ��*/
	PTZ_CMD_SCAN_OFF,          /* ��ʼ��ɨ��*/
	
	PTZ_CMD_SET_SCAN_LIMIT,
	PTZ_CMD_SCAN_RANDOM_ON,
	PTZ_CMD_SCAN_RANDOM_OFF,
	
	/*Ѳ��*/
 	PTZ_CMD_CRUISE_ON,        /* ��ʼѲ�� */
    PTZ_CMD_CRUISE_OFF,       /* ֹͣѲ�� */
    PTZ_CMD_SET_CRUISE_STOP_TIME, 
	PTZ_CMD_SET_CRUISE_SPEED,
	PTZ_CMD_CLEAR_CRUISE_POINT,
	PTZ_CMD_CLEAR_ALL_CRUISE_POINT,
	PTZ_CMD_ADD_CRUISE_POINT,
    PTZ_CMD_CRUISE_SET_BEGIN,
	PTZ_CMD_CRUISE_SET_END,
	PTZ_CMD_AUTO_CRUISE,

	/*Patrol����*/
	PTZ_CMD_PATROL_LEARN_BEGIN,
	PTZ_CMD_PATROL_LEARN_END,
	PTZ_CMD_PATROL_ON,
	PTZ_CMD_PATROL_OFF,

	PTZ_CMD_PATTERN_SET,
	PTZ_CMD_PATTERN_RUN,

	/*��չ����*/
	PTZ_CMD_HOME,
	PTZ_CMD_FLIP,
	PTZ_CMD_RESET,

	/*OSD Menu*/
	PTZ_CMD_OSD_MENU,
	PTZ_CMD_OSD_MENU_ENTER,

	/*PTZ��ѯ����*/
	PTZ_CMD_QUERY_HORIZON,   /*ˮƽ�Ƕ�*/
	PTZ_CMD_QUERY_VERTICAL,  /*������*/

	PTZ_CMD_QUERY_PRESET,    /*Ԥ��λ��ѯ*/

	/*������ƶ�*/
	RAIL_CMD_UP,
	RAIL_CMD_DOWN,
	RAIL_CMD_SET_PRESET,     /*����Ԥ�õ� */
	RAIL_CMD_GOTO_PRESET,    /* ��ת��Ԥ�õ� */
	RAIL_CMD_CLEAR_PRESET,	 /* ���Ԥ�õ� */	

	/*��ͬ��̨ר��*/
	PTZ_CMD_PRIVATE   = 1000,    /*һЩ˽�еĿ���*/
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

/*��ȡSDK�汾��*/
NET_SDK_API DWORD  NetClient_GetVersion();

/**********************************************************************************
* Function:      NetClient_Startup
* Description:   �Կͻ��˽��г�ʼ��
* Input:         ��
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_Startup();

//������Ϣ�ص�
typedef int( *CBF_Notify)(long hDev, int message,long lPrivate);

NET_SDK_API BOOL  NetClient_SetNotifyCBF(CBF_Notify cbNotify,long lPrivate=0);

#ifdef WIN32
/**********************************************************************************
* Function:      NetClient_SetNotifyHwnd
* Description:   ���ÿͻ��˽��յ��������������ַ���ʱ��
*                ��ͻ���Ӧ�ó�������Ϣ��Ŀ�Ĵ��ں���ϢID
* Input:         DWORD nMessage   ��ϢID
*                HWND hWnd       ��Ϣ���մ���
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SetNotifyHwnd(int nMessage , HWND hWnd);
#endif

/*NetSDK����*/
NET_SDK_API BOOL    NetClient_Cleanup();

typedef  void (CALLBACK *ReadDataCallBack)(DWORD nPort , BYTE* pPacketBuffer , DWORD nPacketSize, int FrameType );
/**********************************************************************************
* Function:      NetClient_Start
* Description:   �����ͻ�������
* Input:         tClientInfo*  pClientInfo  �ͻ���������Ϣ�ṹ��
*                ReadDataCallBack cbf ����˿ڽ��յ����ݵĻص�����,�ͻ�����������ȡ������.
*                ���ReadDataCallBackΪNULL , ��ʾ����Ҫ��ȡ��������ReadDataCallBack����˵����
*			 	     nPort 		  :  ������ͨ�����
*				     pPacketBuffer :  ѹ�����ݻ�����
*				     nPacketSize   :  ѹ�����ݳ���
*				     FrameType     :  ѹ������֡����
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API long    NetClient_Start(tClientInfo*  pClientInfo ,ReadDataCallBack cbf);

/*ֹͣ�ͻ���*/
NET_SDK_API BOOL     NetClient_Stop(long hDev);

//�ͻ���״̬
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

/*��ȡ�ͻ���״̬*/
NET_SDK_API long    NetClient_GetState(long hDev);


/*��ȡͨ����*/
NET_SDK_API WORD    NetClient_GetServerChannelNum( char* sIPAddress );

/**********************************************************************************
* Function:      NetClient_CommandToServerEx
* Description:   ���������˷��������ַ���
* Input:         char* sIP      ������IP��ַ
*                char* sCommand �����ַ���
*                WORD wLen      �����ַ�������
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToServerEx(char* sIP , char* sCommand , WORD wLen );

/**********************************************************************************
* Function:      NetClient_CommandToServer
* Description:   ��hDev���Ӿ�������ӵķ������˷��������ַ���
* Input:         long hDev      NetClient_Start�ɹ��ķ���ֵ
*                char* sCommand �����ַ���
*                WORD wLen      �����ַ�������
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToServer(long hDev , char* sCommand , WORD wLen );


/**********************************************************************************
* Function:      NetClient_SetNetPort
* Description:   ��������ͨ�Ŷ˿�
* Input:         dServerPort ����������ͨ�Ŷ˿�
*                dClientPort ���ͻ���ͨ�Ŷ˿�
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
* Notes:         �����������õ�����ͨ�Ŷ˿ںű�����ͻ�������һ�£����ܱ�֤�������Ϳͻ�������ͨ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SetNetPort( WORD dServerPort , WORD dClientPort);



/**********************************************************************************
* Function:      NetClient_SetWait
* Description:   �������ӷ������˵ĵȴ�ʱ��ͳ��Դ���
* Input:         dwEachWaitTime : �ȴ�ʱ��,��λ�Ǻ���,��Χ��300 - 10000
*                dwTryNum, : ���Դ��� . ��Χ�� 1 - 50
* Output:        ��
* Return:        ����TRUE ��ʾ�ɹ�, ����FALSE ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL     NetClient_SetWait( DWORD dEachWaitTime , DWORD dTryNum );


NET_SDK_API BOOL    NetClient_SetCmdTimerOut(int seconds);

/**********************************************************************************
* Function:      NetClient_ReadLastMessage
* Description:   ��ȡ�������˵���Ϣ���͵����һ����Ϣ
* Input:         char* sIP : ��ȡ���������ַ����ķ�����IP��ַ
*                char* sCommand :  ��ȡ�����յ������ַ���
*                WORD* wLen       ��ȡ�����ַ����ĳ���
* Output:        ��
* Return:        ��
************************************************************************************/ 
NET_SDK_API void    NetClient_ReadLastMessage(char* sIP, char* sCommand, WORD* wLen);



/**********************************************************************************
* Function:      NetClient_StartEx
* Description:   ���������ָ������˿ں����ݶ˿ڽ������� 
* Input:         tClientInfo*  pClientInfo   �ͻ�������Ϣ
*                ReadDataCallBack            ���ݶ�ȡ�ص�
*                WORD wCommandPort           �������Ĺ���˿�
*                WORD wDataPort              �����������ݶ˿�
* Output:        ��
* Return:        -1 ��ʾʧ��, ������ֵ��ʾ���Ӿ��
* Notes:         �˺�����������TCP����ģʽ
************************************************************************************/ 
NET_SDK_API long   NetClient_StartEx(tClientInfo*  pClientInfo ,ReadDataCallBack pReadDataCB, WORD wCommandPort, WORD wDataPort);

//������Ϣ�ص�
typedef int( *CBF_AlarmInfo)(long hDevice, int iusrdata, int ialarmtype, int iPara, int* pPara );

/**********************************************************************************
* Function:      NetClient_AlarmSubscribe
* Description:   �豸������Ϣ�Ķ��� 
* Input:         long hDev      �豸�����NetClient_Login()�����ķ���ֵ
*                int iusrdata   �û��Զ�����?
*                CBF_AlarmInfo cbf �豸������Ϣ�Ļص�����
* Output:        ��
* Return:        TRUE ��ʾ�ɹ�,����ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_AlarmSubscribe(long hDev, int iusrdata, CBF_AlarmInfo cbf);

/*�澯IO���*/
NET_SDK_API BOOL     NetClient_AlarmIoOut(long hDev,long channel,int iAlarmNo,int iValue);


/**********************************************************************************
* Function:      NetClient_AlarmUnSubscribe
* Description:   �豸������Ϣ���˶� 
* Input:         long hDev     �豸�����NetClient_Login()�����ķ���ֵ
* Output:        ��
* Return:        TRUE ��ʾ�ɹ�,����ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_AlarmUnSubscribe(long hDev);

//�豸�����ص�
typedef int( *CBF_HeartBeat)(long hDevice, int iusrdata);
/**********************************************************************************
* Function:      NetClient_HeartBeatSubscribe
* Description:   ע�ᱣ��������Ϣ
* Input:         long hDev     �豸�����NetClient_Login()�����ķ���ֵ
*                unsigned int intervals  �豸�������ļ��
*                int iusrdata  �û�˽������;�����豸������Ϣ�Ļص������ﴫ�ظ��û�
*                CBF_HeartBeat cbf  �豸������Ϣ�Ļص�����
* Output:        ��
* Return:         TRUE ��ʾ�ɹ�,����ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_HeartBeatSubscribe(long hDev, unsigned int intervals, \
                                                           int iusrdata, CBF_HeartBeat cbf);

/**********************************************************************************
* Function:      NetClient_HeartBeatUnSubscribe
* Description:   �豸����������Ϣ���˶� 
* Input:         long hDev    �豸�����NetClient_Login()�����ķ���ֵ
* Output:        ��
* Return:        ��ʾ�ɹ�,����ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_HeartBeatUnSubscribe(long hDev);



/**********************************************************************************
* Function:      NetClient_Login
* Description:   Զ�̵�½ǰ���豸 
* Input:         char *sIP       �豸��IP��ַ��������
*                WORD wPort      �豸�Ķ˿�
*                char *sUserName �豸��½���û���
*                char *sPassword �豸�ĵ�½����
* Output:        tDeviceInfo* pDeviceInfo  �豸��Ϣ
* Return:        ����-1��ʾʧ��;����ֵ��Ϊ���������Ĳ���
************************************************************************************/ 
NET_SDK_API long   NetClient_Login(char *sIP,WORD wPort,char *sUserName,char *sPassword,tDeviceInfo* pDeviceInfo);


NET_SDK_API BOOL   NetClient_GetDeviceInfo(long hDev,tDeviceInfo *info);
/**********************************************************************************
* Function:      NetClient_Logout
* Description:   �ǳ�ǰ���豸 
* Input:         long hDev     �豸���
* Output:        ��
* Return:        TRUE ��ʾ�ɹ�,����ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_Logout(long hDev);


//�����Ԥ������
typedef struct
{
	int lChannel;//ͨ����
	int lLinkMode;//0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ
	HWND hPlayWnd;//���Ŵ��ڵľ��,ΪNULL��ʾ������ͼ��
	char* sMultiCastIP;//�ಥ���ַ
}tNetClientInfo;

NET_SDK_API char* NetClient_GetChannelUrl(long hDev,long channel );

NET_SDK_API char* NetClient_GetDevIp(long hDev);

#ifdef HAVE_MEDIA_SDK
typedef void( *PlayCallBack)(const char *pBuffer,void* pParameter);
NET_SDK_API long  NetClient_ClientPlay(long hDev, tNetClientInfo *client,void ( *PlayCallBack) (const char *pBuffer,void* pParameter),void* pUser);
NET_SDK_API long  NetClient_StopClientPlay(long lUserId);

/*������*/

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
* Description:   ������Ϣ�ַ������Ѿ���½��ǰ�� 
* Input:         long hDev     �豸���
*                char* sCommand ��Ϣ�ַ���
*              	 WORD wLen     �������ݵĻ�����ָ��
* Output:        ��
* Return:        TRUE��ʾ�ɹ�������ֵ��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CommandToDev(long hDev , char* sCommand , WORD wLen );

typedef int (CALLBACK *CBF_Register)(RegisterInfo*  lprs);
/**********************************************************************************
* Function:      NetClient_SetRegisterCB
* Description:   �����豸��ע��ص����� 
* Input:         CBF_Register cbf    �ص�����ָ��
* Output:        ��
* Return:        ��
************************************************************************************/ 
NET_SDK_API void   NetClient_SetRegisterCB(CBF_Register cbf);

/**********************************************************************************
* Function:      NetClient_Upgrade
* Description:   ��ʼ���� 
* Input:         long hDev     �豸���
*                char* sFileName      �����ļ�������·��(������.tar.gz���ļ�)
*                unsigned int uLength  �������ݵĻ������ĳ���
*                WORD wDeviceDataPort  �豸�������ݵĶ˿ں�
* Output:        ��
* Return:        �����������Ϊ������������������� -1��ʾ��������ʧ��
************************************************************************************/ 
NET_SDK_API long   NetClient_Upgrade(long hDev, const char* sFileName, WORD wDeviceDataPort);


/**********************************************************************************
* Function:      NetClient_CloseUpgradeHandle
* Description:   �ر�NetClient_Upgrade�ӿ��������ľ�����ͷ���Դ 
* Input:         long hUpgradeHandle    NetClient_Upgrade()�����ķ���ֵ
* Output:        ��
* Return:        TRUE��ʾ�ɹ��� FALSE��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_CloseUpgradeHandle(long hUpgradeHandle);


/**********************************************************************************
* Function:      NetClient_GetUpgradeState
* Description:   ��ȡ������״̬ 
* Input:         long hUpgradeHandle    NetClient_Upgrade()�����ķ���ֵ
* Output:        unsigned int* nprogress  ���������������������(�ٷֱ�) 
* Return:        ��������״̬
*   			 -1��ʾʧ�ܣ�����ֵ���¶��壺 
*   			  1�������ɹ�  
*   			  2���������� , nprogress��ʾ������Ϣ���ٷֱȣ�
*   			  3������ʧ�� 
*   			  4������Ͽ�,״̬δ֪ 
*   			  5�������ļ����԰汾��ƥ�� 
************************************************************************************/ 
NET_SDK_API int   NetClient_GetUpgradeState(long hUpgradeHandle, unsigned int* nprogress);


typedef int  ( *CBF_SerialCom)(long hSerial,int iUsrData,void *pBuffer,unsigned int uLength);

/**********************************************************************************
* Function:      NetClient_SerialStart
* Description:   ��ͨ��ͨ�� 
* Input:         long hDev       �豸�����ͨ��NetClient_Login ()������ȡ
*                eSerialType iSerialType   �������ͣ�����ΪRS232,RS485����
*                unsigned int uPort    ���ڿ����豸�ţ���R485�ԣ���Ч��Χ��MAX_RS485_PORT_NUM,������0��ʼ
*                int iUsrData  �û��Զ������ݣ�����ͨ��ͨ�����ݻص��еõ�
*                CBF_SerialCom  ͨ��ͨ���ص�����
* Output:        ��
* Return:        ͨ��ͨ���������Ϊ������������������� INVALID_long_VALUE��ʾ����͸��ͨ��ʧ��
************************************************************************************/ 
NET_SDK_API long   NetClient_SerialStart(long hDev, eSerialType iSerialType, unsigned int uPort,int iUsrData, CBF_SerialCom pSerialCB );


/**********************************************************************************
* Function:      NetClient_SerialSend
* Description:   ����ͨ��ͨ������ 
* Input:         long hSerial    ͸��ͨ�������ͨ��NetClient_SerialStart��ȡ
*                char *pBuf      �������ݵĻ�����ָ��
*                unsigned int uLength  �������ݵĻ������ĳ���
* Output:        ��
* Return:        TRUE��ʾ����͸��ͨ�����ݳɹ���FALSE��ʾ����͸��ͨ������ʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SerialSend(long hSerial,char *pBuf,unsigned int uLength);


/**********************************************************************************
* Function:      NetClient_SerialStop
* Description:   �ر�͸��ͨ�� 
* Input:         long hSerial    ͸��ͨ�������ͨ��NetClient_SerialStart��ȡ
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_SerialStop(long hSerial);


/**********************************************************************************
* Function:      NetClient_PTZInit
* Description:   ��ʼ����̨
* Input:         long hDev  �豸���
*                unsigned int channel_id ��̨ͨ��ID
*                unsigned int cam_id ��̨��ַ
*                unsigned int ptz_type ���õ���̨Э������
*                unsigned int baudrat ������̨�Ĵ��ڲ�����
* Output:        ��
* Return:       ����TRUE��ʾ�ɹ��������ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_PTZInit   (long hDev, long channel, unsigned int cam_id,   unsigned int ptz_type, unsigned int baudrat);

/**********************************************************************************
* Function:      NetClient_PTZControl
* Description:   ��̨����
* Input:         long hDev  �豸���
*                unsigned int channel_id ��̨ͨ��ID
*                unsigned int ucommand  ��̨����
*                int iparam1   �������1
*                int iparam2   �������2
*                int iparam3   �������3
*                int iparam4   �������4
* Output:        ��
* Return:       ����TRUE��ʾ�ɹ��������ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL  NetClient_PTZControl(long hDev, long channel, unsigned int ucommand, int iparam1, int iparam2, int iparam3, int iparam4);

/*�ýṹ������Ѳ��*/
typedef struct __ptzCruise
{
	int preset_id;
	int duration;
	int action;
}tCruise;

/**********************************************************************************
* Function:      NetClient_PTZCruise
* Description:   ��̨Ѳ��
* Input:         long hDev  �豸���
*                int iCruise  Ѳ����Ԥ��λ����
*                tCruise *pCruiseList Ԥ��λ����
* Output:        ��
* Return:       ����TRUE��ʾ�ɹ��������ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZCruise (long hDev,long channel, int iCruise,tCruise *pCruiseList);

/**********************************************************************************
* Function:      NetClient_PTZCruiseRunning
* Description:   �ж��Ƿ��Ѿ�����Ѳ��
* Input:         long hDev  �豸���
* Output:        ��
* Return:        ����Ѳ������TRUE,���򷵻�FALSE,�����ʧ��Ҳ����FALSE
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZCruiseRunning (long hDev,long channel);


/**********************************************************************************
* Function:      NetClient_PTZCruise
* Description:   ��̨Ѳ��
* Input:         long hDev  �豸���
* Output:        int iCruise  Ѳ����Ԥ��λ����
*                tCruise *pCruiseList Ԥ��λ����
* Return:       ����TRUE��ʾ�ɹ��������ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_GetCruise(long hDev, long channel,int& iCruise,tCruise *pCruiseList);

#define PTZ_REQ_PARA 1

/*�ýṹ����������ķ���ֵ*/
typedef struct  
{  unsigned int channel_id ; //ͨ����
   unsigned int cam_id;      //����ͨ�ŵ�ַ(1-255)
   unsigned int protocol;    //����Э�� 
   unsigned int baudrate;    //��������   
}tPtzParam;

/**********************************************************************************
* Function:      NetClient_PTZReq
* Description:   ��ȡ��̨��Ϣ
* Input:         long hDev  �豸���
*                unsigned int channel_id ��̨ͨ��ID
*                unsigned int ucommand  ��̨����
*                void *retBuf  ������Ϣ�����ַ
*                int *retLen   ���û�������󳤶�
* Output:        void *retBuf  ��ȡ��������Ϣ
*                int *retLen   ����������Ϣ����
* Return:        ����TRUE��ʾ�ɹ��������ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL    NetClient_PTZReq (long hDev, long uchannel, unsigned int ucommand, void *retBuf,int *retLen);


/*��ѯ��ʽ*/
#define LOG_FIND_ALL         0
#define LOG_FIND_TYPE        1
#define LOG_FIND_TIME        2
#define LOG_FIND_TYPEANDTIME 3

/**********************************************************************************
* Function:      NetClient_LogFindNext
* Description:   ��ѯָ���豸�ϵ���־��¼
* Input:         long hDev  �豸�����ͨ��NetClient_Login ()������ȡ
*                BYTE bytSelectMode  ��ѯ��ʽ��:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ�������
*                BYTE bytChannel     Ҫ��ѯ��ͨ���ţ�0��ʾ��ѯ���е�ͨ��
*                BYTE bytMajorType   �豸������
*                BYTE bytMinorType   �豸������
*                tNetTime*  lpStartTime  ��ʼʱ�� 
*                tNetTime*  lpStopTime   ����ʱ��
* Output:        ��
* Return:        ��ѯ��־�ľ���� -1��ʾ������ѯ��־ʧ��
************************************************************************************/ 
NET_SDK_API long  NetClient_LogFindStart(long hDev, BYTE bytSelectMode, BYTE bytChannel, BYTE bytMajorType, \
                                        BYTE bytMinorType, tNetTime*  lpStartTime, tNetTime*  lpStopTime);


/*NetClient_LogFindNext�ķ���ֵ*/
#define NET_DEV_FILE_SUCCESS     1000 //����ļ���Ϣ 
#define NET_DEV_FILE_NOFIND      1001 //û���ļ� 
#define NET_DEV_ISFINDING        1002 //���ڲ����ļ� 
#define NET_DEV_NOMOREFILE       1003 //�����ļ�ʱû�и�����ļ� 
#define NET_DEV_FILE_EXCEPTION   1004 //�����ļ�ʱ�쳣
#define NET_DEV_FIND_TIMEOUT     1005  //���ҳ�ʱ


/**********************************************************************************
* Function:      NetClient_LogFindNext
* Description:   ��ȡһ����־��Ϣ 
* Input:         long lLogHandle     �Ѿ��򿪵Ĳ�ѯ��־���
* Output:        tDevLog*  lpLogData ��ѯ����һ����־��Ϣ
* Return:        ��־��ѯ״̬,1000��ʾ��ȡ�ɹ�
************************************************************************************/ 
NET_SDK_API long  NetClient_LogFindNext(long lLogHandle, tDevLog*  lpLogData);


/**********************************************************************************
* Function:      NetClient_LogFindStop
* Description:   �ͷŲ����ļ�����Դ 
* Input:         long lLogHandle �Ѿ��򿪵Ĳ�ѯ��־���
* Output:        ��
* Return:        TRUE��ʾ�ɹ���FALSE��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_LogFindStop(long  lLogHandle);

/*�ļ� ����*/
/*Ҫ���ҵ��ļ����ͳ���*/
enum
{
  FILETYPE_ALL = 0,    /*��������*/
  FILETYPE_TIMED,      /*��ʱ����*/
  FILETYPE_ALARM,      /*�澯����*/
  FILETYPE_MANUAL,     /*�ֶ�����*/
  FILETYPE_NUM
};

/**********************************************************************************
* Function:      NetClient_FileFindStart
* Description:   ��ѯָ���豸�ϵ���Ƶ�ļ�
* Input:         long hDev     �豸�����ͨ��NetClient_Login ()������ȡ
*                long lChannel Ҫ��ѯ��ͨ����,ͨ����0��ʼ������0��ʾ��һͨ��
*                DWORD dwFileType �ļ����ͣ�0 �� ȫ����1 �� ��ʱ¼��2 - �ƶ���⣬3 �� ������  
*                tNetTime*  lpStartTime �ļ��Ŀ�ʼʱ��
*                tNetTime*  lpStopTime  �ļ��Ľ���ʱ��
* Output:        ��
* Return:        ��ѯ�ļ��ľ���� INVALID_long_VALUE��ʾ������ѯ�ļ�ʧ��,
?               ���ýӿڷ��سɹ���,�Ϳ��Ե���NetClient_FileFindNext�ӿ�����ȡ�ļ���Ϣ
************************************************************************************/ 
NET_SDK_API long  NetClient_FileFindStart(long hDev,long lChannel,DWORD dwFileType, tNetTime*  lpStartTime, tNetTime*  lpStopTime);

#ifndef MAX_FILE_NAME_LEN
#define MAX_FILE_NAME_LEN  256
#endif

typedef struct
{
	char sFileName[MAX_FILE_NAME_LEN];  //�ļ���
    DWORD dwFileType;                   //�ļ������ͣ��Ͳ���ʱ����һ�£�
	DWORD dwFileSize;                   //�ļ��Ĵ�С
	tNetTime StartTime;                 //�ļ��Ŀ�ʼʱ��
	tNetTime StopTime;                  //�ļ��Ľ���ʱ��
}tFileFindData;


/**********************************************************************************
* Function:      NetClient_FileFindNext
* Description:   ��ȡ��һ���ļ���Ϣ 
* Input:         long lFindHandle �Ѿ��򿪵Ĳ�ѯ�ļ��������NetClient_FindFile��ȡ            
* Output:        tFileFindData* lpFindData  ��ѯ����һ���ļ���Ϣ
* Return:        �ļ���ѯ״̬,1000��ʾ��ȡ�ɹ�,����ֵ˵����NetClient_LogFindNext
************************************************************************************/ 
NET_SDK_API long  NetClient_FileFindNext(long lFindHandle, tFileFindData* lpFindData);


/**********************************************************************************
* Function:      NetClient_FileFindClose
* Description:   �ͷŲ����ļ�����Դ 
* Input:         long lFindHandle �Ѿ��򿪵Ĳ�ѯ�ļ��������NetClient_FindFile��ȡ
* Output:        ��
* Return:        TRUE��ʾ�ɹ���FALSE��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_FileFindClose(long lFindHandle);



/**********************************************************************************
* Function:      NetClient_GetFileByName
* Description:   ���豸�ϰ��ļ�������
* Input:         long hDev  �豸�����ͨ��NetClient_Login ()������ȡ
*                char *sFileName      Ҫ���ص��ļ���
*                char *sSavedFileName ���غ󱣴浽PC�����ļ���
* Output:        ��
* Return:        �ļ����صľ����ʧ�ܷ���-1
************************************************************************************/ 
NET_SDK_API long   NetClient_GetFileByName(long hDev,char *sFileName,char *sSavedFileName);

/**********************************************************************************
* Function:      NetClient_StopGetFile
* Description:   �ر��ļ�����
* Input:         long lFileDownloadHandle  �Ѿ��򿪵��ļ����ؾ������NetClient_GetFileByName��ȡ
* Output:        ��
* Return:        TRUE��ʾ�ɹ���FALSE��ʾʧ�� 
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_StopGetFile(long lFileDownloadHandle);


/**********************************************************************************
* Function:      NetClient_GetDownloadPos
* Description:   ��ȡ�ļ����ؽ���
* Input:         long lFileDownloadHandle  �Ѿ��򿪵��ļ����ؾ������NetClient_GetFileByName��ȡ
* Output:        ��
* Return:         -1��ʾʧ�ܣ�0-100:���صĽ��ȣ�100��ʾ���ؽ�����>100: ��������ԭ�������쳣��ֹ 
************************************************************************************/ 
NET_SDK_API int   NetClient_GetDownloadPos(long lFileDownloadHandle);

/**********************************************************************************
* Function:      NetClient_DelFile
* Description:   ���豸��ɾ���ļ�
* Input:         long hDev  �豸�����ͨ��NetClient_Login ()������ȡ
*                char *sFileName      Ҫɾ�����ļ�����֧��ͨ���
* Output:        ��
* Return:        TRUE��ʾ�ɹ���FALSE��ʾʧ��
************************************************************************************/ 
NET_SDK_API BOOL   NetClient_DelFile(long hDev,char *sFileName);


typedef struct tagChannelInfo
{
	unsigned int   channelId;     /*ͨ��ID*/
	unsigned char  videoStand;    /*��Ƶ��ʽ*/
	unsigned char  videoCodec;    /*����뷽ʽ*/
	unsigned char  picQuality;    /*ͼ������*/
	unsigned char  rateControl;   /*���ʿ���*/
	int            imageWidth;    /*ͼ����*/
	int            imageHeight;   /*ͼ��߶�*/
	int            frameRate;     /*֡����*/
	unsigned short transPort;     /*ͨ��������õĶ˿ں�*/
	unsigned short transType;     /*����Э��*/
	char           name[32];      /*ͨ����*/
	char           url[64];
	char           devId[MAX_SERIAL_NUM_LEN];	
}ChannelInfo;

NET_SDK_API BOOL  NetClient_GetConfig(long hDev, long channel,DWORD dwCommand, void* lpOutBuffer, DWORD *lpOutBufferSize);

/**********************************************************************************
* Function:      NetClient_GetChannelInfo
* Description:   ��ȡ��Ƶͨ����Ϣ
* Input:         long hDev �豸���
*                BYTE& dwChannelNum    ͨ���������Ĵ�С
*                ChannelInfo *pChannel ����ͨ����Ϣ�����飬������dwChannelNumȷ��
* Output:        BYTE& dwChannelNum   ����ͨ����
*                ChannelInfo *pChannel ͨ���б������ȷ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetChannelInfo(long hDev,BYTE& byteMediaNum, ChannelInfo *pMediaChannel);

/**********************************************************************************
* Function:      NetClient_GetChannelState
* Description:   ��ȡͨ��״̬
* Input:         long hDev �豸���
*                BYTE& dwChannelNum    ͨ���������Ĵ�С
*                ChannelInfo *pChannel ����ͨ����Ϣ�����飬������dwChannelNumȷ��
* Output:        BYTE& dwChannelNum   ����ͨ����
*                ChannelInfo *pChannel ͨ���б������ȷ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
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
	int iEmiss;         /*������*/
	int iDistance;      /*����*/	
	int highTempThresh; /*������ֵ*/
	int predictTempThresh;
	int reserve2; 

	//char name[32];
}tPresetRect;

/*Ԥ�õ��λ����Ϣ*/
typedef struct tagPresetInfo
{
	int         preset_id;
	//char        name[MAX_PRESET_NAME_LEN];
	int         num;
	tPresetRect rect[MAX_PRESET_RECT_NUM];
}tPresetInfo;

/**********************************************************************************
* Function:      NetClient_GetPresetInfo
* Description:   ��ȡԤ��λ��Ϣ
* Input:         long hDev �豸���
*                BYTE& iPresetNum     Ԥ��λ����
*                tPresetInfo *pPreset  Ԥ��λ����
* Output:        BYTE& dwChannelNum    ����Ԥ��λ����
*                tPresetInfo *pPreset  Ԥ��λ�б������ȷ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetPresetInfo(long hDev,long channel,int& iPresetNum,tPresetInfo *pPreset);


NET_SDK_API BOOL  NetClient_GetCurPreset(long hDev,long channel,int* presetId);

/**********************************************************************************
* Function:      NetClient_GetPresetInfo
* Description:   ����Ԥ��λ��Ϣ
* Input:         long hDev �豸���
*                tPresetInfo *pPreset  Ԥ��λ����
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SetPresetInfo(long hDev,long channel,tPresetInfo *pPreset);


/**********************************************************************************
* Function:      NetClient_GotoPreset
* Description:   ��תԤ��λ
* Input:         long hDev �豸���
*                int iPresetId  Ԥ��λ����
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GotoPreset(long hDev,long channel,int iPresetId);

/**********************************************************************************
* Function:      NetClient_ClearPresetInfo
* Description:   ���Ԥ��λ��Ϣ
* Input:         long hDev      �豸���
*                long channel   ͨ����
*                int iPresetId  Ԥ��λ����
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_ClearPresetInfo(long hDev,long channel,int iPresetId);

/**********************************************************************************
* Function:      NetClient_EnableWatchdog
* Description:   ʹ��watchdog
* Input:         long hDev �豸���
*                long channel   ͨ����
*                int enable  1 ��ʾʹ��
*                            0 ��ʾ��ʹ��
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
* Notes:         ��ʹ���л�����ʹ�ܣ����Ź���ʱ��ϵͳ������
************************************************************************************/
NET_SDK_API BOOL   NetClient_EnableWatchdog(long hDev,long channel,int enable);

/*��ȡ������״̬*/
typedef struct tagServerState
{
	float fCpuUsage;    /*CPUռ����*/
	float fMemTotal;    /*���ڴ��С  M*/
	float fMemFree;     /*�����ڴ��С M*/
	float fSDTotal;     /*SD��������*/
	float fSDFree;      /*SD����������*/
}tServerState;

/**********************************************************************************
* Function:      NetClient_GetServerState
* Description:   ��ȡ��������״̬
* Input:         long hDev �豸���
* Output:        tServerState *pState  ��������״̬��Ϣ
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_GetServerState(long hDev,long channel,tServerState *pState);

/**********************************************************************************
* Function:      NetClient_SDFormat
* Description:   ��ʽ��SD��
* Input:         long hDev �豸���
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDFormat(long hDev,long channel);

/**********************************************************************************
* Function:      NetClient_SDMount
* Description:   ת��SD��
* Input:         long hDev �豸���
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDMount(long hDev,long channel);

/**********************************************************************************
* Function:      NetClient_SDUnMount
* Description:   ж��SD��
* Input:         long hDev �豸���
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL   NetClient_SDUnMount(long hDev,long channel);

/*ͬ��Ԥ��λ��Ϣ*/
NET_SDK_API BOOL   NetClient_SynPreset(long hDev,long channel);

/*ͬ��Ѳ����Ϣ*/
NET_SDK_API BOOL   NetClient_SynCruise(long hDev,long channel);

/*ͬ��Ѳ����Ϣ*/
NET_SDK_API BOOL   NetClient_StartCruise(long hDev,long channel,BOOL bStart);

/*�������ݿ�*/
NET_SDK_API BOOL   NetClient_ReloadDB(long hDev);

/*�����豸*/
NET_SDK_API BOOL   NetClient_PowerCtrl(long hDev,long channel,BOOL bOn);


/*�����豸*/
NET_SDK_API BOOL   NetClient_RebootDev(long hDev,long channel);
/*����FPGA*/
NET_SDK_API BOOL   NetClient_ResetFPGA(long hDev,long channel);

/*ǰ���豸ץͼ*/
NET_SDK_API BOOL   NetClient_DevCapPic(long hDev,long channel);

/*ǰ���豸������Ƶ¼��*/
NET_SDK_API BOOL   NetClient_DevStartIrRecord(long hDev,long channel);

/*ֹͣ������Ƶ¼��*/
NET_SDK_API BOOL   NetClient_DevStopIrRecord(long hDev,long channel);

/*��������*/

/*����������Ϣ*/
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

/*���ø澯�������ͣ����Զ������*/
#define ALARM_MODE_FTP   0x0001
#define ALARM_MODE_SMTP  0x0002
#define ALARM_MODE_SD    0x0004
NET_SDK_API BOOL   NetClient_SetAlarmMode(long hDev,long channel,WORD dwAlarmMode);

NET_SDK_API BOOL    NetClient_SetAlarmTemp(long hDev,long channel,float fTemp);

NET_SDK_API BOOL    NetClient_GetAlarmTemp(long hDev,long channel,float* fTemp);

/*�����豸ʱ��*/
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


/*�ɼ������ID,Ϊ�˱��ڿ��ƣ����ù̶�ID*/
#define STREAM_ID_RAW           0  /*ԭʼ������ʱû��*/
#define STREAM_ID_MJPEG         1
#define STREAM_ID_MPEG4_1       2  /*���ֻ��һ��MPEG4������ѡ��һ��*/
#define STREAM_ID_MPEG4_2       3
#define STREAM_ID_H264_1        4  /*���ֻ��һ��H264������ѡ��һ��*/
#define STREAM_ID_H264_2        5
#define STREAM_ID_IR            6  /*������Ƶ��*/

#define MAX_VL_STREAM_NUM       7

#define ALL_STREAM_CHANNEL      0xFF /*����ͨ��*/

#define VL_CHANNEL_INDEX        0 /*�ɼ���ͨ��*/
#define IR_CHANNEL_INDEX        1 /*����ͨ��*/

/*��Ƶ��������*/
/*��Ƶ����*/
typedef struct
{
	BYTE cmd;
	BYTE channel;
	WORD len;
	BYTE data[4];
}VideoPara_t;

/*���úͻ�ȡ����*/
NET_SDK_API BOOL    NetClient_SetBrightness(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetBrightness(long hDev,long channel,DWORD& wValue);

/*���úͻ�ȡ�Աȶ�*/
NET_SDK_API BOOL    NetClient_SetContrast(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetContrast(long hDev,long channel,DWORD& wValue);


/*���úͻ�ȡ���Ͷ�*/
NET_SDK_API BOOL    NetClient_SetSaturation(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetSaturation(long hDev,long channel,DWORD& wValue);


/*���úͻ�ȡ��ƽ��*/
NET_SDK_API BOOL    NetClient_SetWhiteBalance(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetWhiteBalance(long hDev,long channel,DWORD& wValue);

/*���úͻ�ȡ�񻯶�*/
NET_SDK_API BOOL    NetClient_SetSharpness(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetSharpness(long hDev,long channel,DWORD& wValue);

/*���úͻ񱳾���*/
NET_SDK_API BOOL    NetClient_SetBacklight(long hDev,long channel,DWORD wValue);
NET_SDK_API BOOL    NetClient_GetBacklight(long hDev,long channel,DWORD& wValue);

/*���ð׹�ģʽ*/
NET_SDK_API BOOL    NetClient_SetDayNight(long hDev,long channel, DWORD  wValue);
NET_SDK_API BOOL    NetClient_GetDayNight(long hDev,long channel, DWORD& wValue);

typedef enum
{
	/*������*/
	H264_720P = 1,
	H264_FD1,
	H264_1080P,
	
	MPEG4_SXVGA,
	MPEG4_FD1,
	MPEG4_720P,
	MPEG4_1080P,
	
	MJPEG_UXGA,  
	MJPEG_QXGA,
	CHAN_ONE_END,                      /*����������*/

	/*˫����*/
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

	/*������*/
	IR_240P_MPEG4_YUV_480P,               /*����+����YUV��MPEG4ѹ��*/
	IR_288P_MPEG4_YUV_576P,
    IR_120P_MPEG4_YUV_240P,

	IR_240P_H264_YUV_480P,                /*����+����YUV��H264ѹ��*/
	IR_288P_H264_YUV_576P,
    IR_120P_H264_YUV_240P,
    
	CHAN_DOUBLE_END,                   /*˫����*/
	
	/*������*/
	MPEG4_720P__MJPEG_VGA__MPEG4_CIF,
	H264_720P__MJPEG_VGA__H264_CIF,

	IR_240P_H264_YUV_480P_VL_576P,         /*����+����YUV+�ɼ���YUV��H264ѹ��*/
	IR_288P_H264_YUV_576P_VL_576P,      
	IR_288P_H264_YUV_288P_VL_288P,         /*���Ŵ�*/
    IR_120P_H264_YUV_240P_VL_576P,

	IR_240P_MPEG4_YUV_480P_VL_576P,         /*����+����YUV+�ɼ���YUV��MPEG4ѹ��*/
	IR_288P_MPEG4_YUV_576P_VL_576P,
	IR_288P_MPEG4_YUV_288P_VL_288P,        /*���Ŵ�*/
    IR_120P_MPEG4_YUV_240P_VL_576P,
	
	CHAN_TRI_END,                          /*������*/

    
    CODEC_NUM,
}eCodecTypes;
/*������Ƶģʽ*/
NET_SDK_API BOOL    NetClient_SetVideoCodec(long hDev,long channel,BYTE byteMediaNum,ChannelInfo *pMediaChannel);

/*���ʿ��Ʒ�ʽ*/
typedef enum
{
	RATE_CONTROL_NONE = 0,
	RATE_CONTROL_CVBR,
	RATE_CONTROL_CBR,
	RATE_CONTROL_NUM
}eRateControl;

/*����֡�ʿ���*/
NET_SDK_API BOOL    NetClient_SetRateControl(long hDev,long channel,DWORD dwRateControl);
NET_SDK_API BOOL    NetClient_GetRateControl(long hDev,long channel,DWORD& dwRateControl);

/*����JPEG����*/
NET_SDK_API BOOL     NetClient_SetJpgQuality(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetJpgQuality(long hDev,long channel,DWORD& wValue);

/*���ñ�����*/
NET_SDK_API BOOL     NetClient_SetEncBitrate(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetEncBitrate(long hDev,long channel,DWORD& wValue);

/*����֡��*/
NET_SDK_API BOOL     NetClient_SetEncFramerate(long hDev,long channel,DWORD  wValue);
NET_SDK_API BOOL     NetClient_GetEncFramerate(long hDev,long channel,DWORD& wValue);

/*����OSD*/
#define OSD_TEXT         0x0001  /*�û�������ı�*/
#define OSD_TEXT_TIME    0x0002  /*��ʾʱ��*/
#define OSD_LOGO         0x0004  /*��ʾLOGO*/
#define OSD_HISTOGRAM    0x0008  /*��ʾֱ��ͼ*/
#define NO_OSD_TEXT      0x0100  /*ȡ���ı�OSD��ʾ*/
#define NO_OSD_TEXT_TIME 0x0200  /*ȡ���ı�ʱ�����ʾ*/
#define NO_OSD_LOGO      0x0400  /*ȡ��OSD��Logo��ʾ*/
#define NO_OSD_HISTOGRAM 0x0800  /*ȡ��OSD��ֱ��ͼ��ʾ*/
NET_SDK_API BOOL    NetClient_SetOSD(long hDev,long channel,DWORD dwOsdType,char *pInOsdText);

#define VL_AEWB_NONE        0x0000
#define VL_AEWB_APPRO       0x0001
#define VL_AEWB_TI          0x0002
#define VL_AEWB_ALL         0x000F
#define VL_GBCE             0x0010  /*ȫ�ֶԱȶ���ǿ*/

#define SENSOR_MODE_DEFAULT    0
#define SENSOR_MODE_BINNING    1
#define SENSOR_MODE_SKIPPING   2
#define SENSOR_MODE_WINDOW     3

/*�ɼ�����Ϲ����㷨*/
#define FILTER_VIDEO_STABILIZATION          0x0001  
#define FILTER_LENS_DISTORTION_CORRECTION   0x0002
#define FILTER_SPATIAL_NOISE_FILTER         0x0004
#define FILTER_TEMPRORAL_NOISE_FILTER       0x0008

NET_SDK_API BOOL   NetClient_SetFilter(long hDev,long channel,DWORD dwFeature);

/*************************************FPGA����**************************************************/

/*����FPGA���ƣ���Ҫ����IrSDK.hͷ�ļ��������Ǹ�ͷ�ļ��ж���*/

/*��Щ����NetSDK��Ҳʹ�ã������ظ����ã����ú�����*/


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

/*����FPGA���ƣ���Ҫ����IrSDK.hͷ�ļ��������Ǹ�ͷ�ļ��ж���*/
#define MAX_READ_DATA_LEN     1024

#define MAX_TEMP_OBJ_NUM      8

/**********************************************************************************
* Function:      NetClient_FpgaCtrl
* Description:   ����FPGA�豸
* Input:         long hDev              �豸���
*                long channel           ͨ����
*                unsigned short cmd     FPGA����
*                unsigned short cmdType ��������
*                unsigned char* pBuff   �����������������
*                int iBufLen            �������������
*                unsigned char *pRetBuf ����ؽ��ջ�����
*                int *pRetLen           ���ػ������ܳ���
* Output:        unsigned char *pRetBuf �����
*                int *pRetLen           ���ػ���������
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
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
* Description:   �������豸�����ļ���FPGAʹ��
* Input:         long hSerial    �����豸���
*                char *fileName  �����ļ���
*                Fpga_FileTrans  pCbFileTrans  �ļ�����״̬�ص�
*                long lPrivate   �ص������Ĳ���
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL    NetClient_SendFpgaFile(long hDev,int fileType,char *fileName,Fpga_FileTrans pCbFileTrans = NULL,long lPrivate=0 );


/**********************************************************************************
* Function:      NetClient_RecvFpgaFile
* Description:   �������豸���մ�FPGA�������ļ�
* Input:         long hSerial    �����豸���
*                int fileType    �ļ�����
*                char *fileName  �����ļ���
*                Fpga_FileTrans pCbFileTrans  �ļ�����״̬�ص�
*                long lPrivate   �ص������Ĳ���
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
NET_SDK_API BOOL    NetClient_RecvFpgaFile(long hDev,int fileType,char *fileName,Fpga_FileTrans pCbFileTrans = NULL,long lPrivate=0);


/***********************************************************************************************/

#endif

