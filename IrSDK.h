/**************************************************************************************************
* File Name     : IrSDK.h
* Module Name   : IR_SDK
* Description   : 红外分析开发包
* Author/Date   : Janekey/ 2011.01.21
* Version       : 3.1.1.1
* State         : create
* -----------------------------------History-------------------------------------------------------
* Modifier/Date : 2011.01.21
* Modify Reason : 开始创建规范注释
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.01.22
* Modify Reason : 定义两种温度类型，一种是真实温度，一种是温度*10,便于在函数调用中好区分
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.02.22
* Modify Reason : 增加了红外流的相关SDK
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.02.25
* Modify Reason : 增加了红外视频文件的类型转换函数，这个主要是方便测试，以后不会公开
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.03.2
* Modify Reason : 增加了网络流录像功能
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.04.22
* Modify Reason : 定义了通用串口命令结构体
*                 增加了串口命令发送函数
*                 增加了解析串口命令响应缓冲区的组合和解析
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.18
* Modify Reason : 增加了串口发送文件接口
*                 增加了串口发送命令宏
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.23
* Modify Reason : 串口发送函数增加等待功能
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.25
* Modify Reason : 增加了串口发送和接收文件线程，传输状态通过回调上传给上层程序
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.26
* Modify Reason : 发送串口命令增加了获取返回缓冲区的参数,有的命令会携带参数
*                 增加了串口发送命令和文件类型定义常量
*                 去掉了串口读回调IrSerial_ReadCmdRet，这部分不再需要
*                 发送文件增加了文件类型
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.1
* Modify Reason : 增加了缺省红外图像的宽度和高度大小，如果红外图像大小改变了，需要改变
*                 该宏，暂时只能采用这种龌龊方法
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.21
* Modify Reason : SERIAL_CMD 开头的命令采用FPGA_CTL来替换，不仅仅是通过串口控制FPGA
*                 还通过网络来控制FPGA
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.24
* Modify Reason : 增加设置和获取镜筒温度的函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.06
* Modify Reason : 增加获取板子温度
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.07
* Modify Reason : 增加设置和获取快门、镜筒基准温度，以及快门、镜筒校正系数，用于校正
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.21
*                 将校正部分的参数设置都去掉了，参数的设置放到了温度曲线中，这部分校正不对用户开放
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.08.8
*                 增加了BDB黑体温度通过串口的读取和设置
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.7
*                 增加了FPGA获取版本号的宏
*                 IrImage_DrawVL->IrImage_DrawVLEx 
*                 IrImage_DrawIr->IrImage_DrawIrEx 导出函数名不能相同
*                 为了其他语言调用，将declspec修改为stdcall,在.def文件中导出函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.7
* Version:        3.0.1.3
*                 IrVideo_Control修改了调用参数，控制参数只有两个，一个命令，一个命令对应的参数
*                 便于VB调用以及代码可读性
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.13
* Version:        3.0.2.1
*                 增加了去锅盖接口函数
*                 增加获取原始AD的函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.22
* Version:        3.0.2.2
*                 增加了FPGA自定义控制命令的宏
*                 增加了获取锐化级别的函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.10
* Version:        3.0.2.3
*                 增加了获取映射AD的范围
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.15
* Version:        3.0.4.3
*                 解决了视频和流媒体播放时进行测温分析时闪烁的问题
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.16
* Version:        3.0.4.4
*                 在创建memDC时指定位置，否则会获取整个DC，导致刷屏有问题
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.16
* Version:        3.0.4.5
*                 FPGA增加滤波系数文件
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.27
* Version:        3.0.6.1
*                 红外对象设置和获取测温对象功能移为通用功能
*                 红外视频和红外流媒体抓图也保存测温对象
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.07
* Version:        3.0.8.1
*                 增加了设置和获取设置测温校正的功能
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.08
* Version:        3.1.1.1
*                 修改了温度曲线，支持多工作环境下测温
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.13
* Version:        3.1.1.2
*                 计算温度时增加了黑体的发射率
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.3.28
* Version:        3.1.3.1
*                 Ir_AdToTemp增加了发射率参数和距离参数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.4.6
* Version:        3.2.2.1
*                 增加了可见光的帧类型，融合可见光和红外
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.5.11
* Version:        3.2.2.3
*                 增加FPGA命令
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.19
* Version:        3.2.3.4
*                 增加了锗玻璃透过率的配置参数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.11.26
* Version:        3.2.3.6
*                 增加了获取AD缓冲区的命令Ir_GetAdBuffer
*                 设置了视频处理回调函数IrVideo_SetAdFilter
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.12.5
* Version:        3.2.4.1
*                 增加视频流回调函数
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.1.5
* Version:        3.3.1.2
*                 修改了测温方式
* -------------------------------------------------------------------------------------------------
**************************************************************************************************/

#ifndef IR_SDK_INCLUDE_H
#define IR_SDK_INCLUDE_H

//#define IR_SDK_API __declspec(dllexport)
#define IR_SDK_API  __stdcall

#ifndef IR_TEMP_TYPE
typedef  float IR_TEMP_TYPE;          /*实际温度*/
#endif

#ifndef IR_TEMP_10FOLD_TYPE
typedef short IR_TEMP_10FOLD_TYPE;    /*实际温度*10 整数*/ 
#endif

#ifndef IR_TEMP_100FOLD_TYPE
typedef short IR_TEMP_100FOLD_TYPE;   /*实际温度*100 整数*/
#endif

#define IR288

/*缺省红外图像大小*/
#ifdef IR288
#define DEFAULT_IR_IMG_WIDTH   384
#define DEFAULT_IR_IMG_HEIGHT  288
#else
#define DEFAULT_IR_IMG_WIDTH   320
#define DEFAULT_IR_IMG_HEIGHT  240
#endif


/*摄氏温度转华氏温度*/
#define CDEGREE_TO_FDEGREE(fTemp)   (float)((fTemp)*1.8 + 32.0)

 // 华氏温度转换到摄氏温度
#define  FDEGREE_TO_CDEGREE(fValue) (float)(((fValue) - 32.0 )/9.0 * 5.0)

/*摄氏温度转绝对温度*/
#define CDEGREE_TO_ABSOLUTE(fTemp)  (float)((fTemp) + 237.15)

#define ERROR_IR_FILE_PARA                   -1    /*参数设置错误*/
#define ERROR_IR_FILE_NOT_EXIST              -2    /*文件不存在*/
#define ERROR_IR_FILE_VERSION_NOT_SUPPORT    -3    /*版本不支持*/
#define ERROR_IR_FILE_READ_ERROR             -4    /*读写错误*/
#define ERROR_IR_FILE_NO_MEM                 -5    /*没有内存*/
#define ERROR_IR_FILE_NO_VOICE               -6    /*没有语音注释*/
#define ERROR_IR_FILE_WRITE_ERROR            -7    /*写错误*/
#define ERROR_IR_FILE_CORRUPT                -8    /*文件破坏了*/

/*USB设备读取*/
#define ERROR_USB_DEV_NOT_EXIST             -20   /*该USB设备不存在*/
#define ERROR_USB_NO_ENOUGH_SPACE           -21   /*当前硬盘空间不够*/
#define ERROR_USB_RECORD_AVI                -22   /*AVI录像失败*/

/****************************通用IR操作接口**********************************************/
/*获取版本号*/
DWORD IR_SDK_API Ir_GetVersion();

/*获取红外图像、视频或USB视频的图像大小*/
int IR_SDK_API   Ir_GetWidth(long hIr);
int IR_SDK_API   Ir_GetHeight(long hIr);

/**********************************************************************************
* Function:      Ir_GetSaveTime
* Description:   获取红外图像或视频的采集时间
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
* Output:        无
* Return:        返回文件的生成时间
* Notes:         该时间和文件的创建时间可能不一致， 
************************************************************************************/
DWORD IR_SDK_API Ir_GetSaveTime(long hIr);

/**********************************************************************************
* Function:      Ir_GetAd
* Description:   获取图像坐标(x,y)处的响应值AD,该AD是八领域的平均值
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                int x,y     图像上的坐标
* Output:        无
* Return:        返回响应AD，可能为负数
************************************************************************************/
int IR_SDK_API   Ir_GetAd(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetAdBuffer
* Description:   获取AD缓冲区，用于视频分析
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
* Output:        short** pAdBuffer  返回的AD缓冲区
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API   Ir_GetAdBuffer(long hIr,short** pAdBuffer);

/**********************************************************************************
* Function:      Ir_GetAd
* Description:   获取图像坐标(x,y)处的原始响应值AD
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                int x,y     图像上的坐标
* Output:        无
* Return:        返回响应AD，可能为负数
************************************************************************************/
int IR_SDK_API   Ir_GetOrignAd(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetBitmapBit
* Description:   获取(x,y)处的灰度值
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                int x,y     图像上的坐标
* Output:        无
* Return:        响应值AD映射的灰度值
* Notes:         调节对比度和亮度会影响该值   
************************************************************************************/
BYTE IR_SDK_API Ir_GetBitmapBit(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetTemperature
* Description:   获取(x,y)处的温度值
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                int x,y     图像上的坐标
*                int iEmiss  发射率，默认为98
*                int iDistance 距离，默认为14
* Output:        无
* Return:        坐标处的温度值，小数点精度只有1位
************************************************************************************/
IR_TEMP_TYPE IR_SDK_API Ir_GetTemperature(long hIr,int x,int y,int iEmiss=98,int iDistance=14);

IR_TEMP_TYPE IR_SDK_API Ir_GetTemperature_Test(long hIr,int x,int y,float fcoef,int iConst);

/**********************************************************************************
* Function:      Ir_AdToTemp
* Description:   由响应值AD计算温度
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                short sAd   红外响应值
*                int iEmiss  发射率，默认为98
*                int iDistance 距离，默认为14
* Output:        float *pTemp 返回计算的温度
* Return:        如果计算正确，则返回TRUE,否则返回FALSE,此时pTemp的返回值无效
************************************************************************************/
 BOOL IR_SDK_API Ir_AdToTemp(long hIr,short sAd,IR_TEMP_TYPE *pTemp,int iEmiss=98,int iDistance=14);


/**********************************************************************************
* Function:      Ir_GetRGB
* Description:   获取(x,y)处的RGB值
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                int x,y     图像上的坐标
* Output:        无
* Return:        图像坐标的RGB值，其中alpha通道没用，该颜色是调色板颜色、等温线、告警色映射的
* Notes:         之前显示坐标和图像左边必须转换   
************************************************************************************/
RGBQUAD IR_SDK_API Ir_GetRGB(long hIr,int x,int y);

/************************测温参数**************************************************/
/*获取和设置快门温度*/
IR_TEMP_TYPE IR_SDK_API Ir_GetShutterTemp(long hIr);
void IR_SDK_API  Ir_SetShutterTemp(long hIr,IR_TEMP_TYPE fTemp);

/*获取和设置大气温度*/
void IR_SDK_API  Ir_SetAtmosTemp(long hIr,IR_TEMP_TYPE fTemp);
IR_TEMP_TYPE IR_SDK_API Ir_GetAtmosTemp(long hIr);

/*获取焦平面温度*/
IR_TEMP_TYPE IR_SDK_API Ir_GetFPATemp(long hIr);

/*获取板子温度*/
IR_TEMP_TYPE IR_SDK_API Ir_GetBoardTemp(long hIr);

/*获取和设置镜筒温度*/
void IR_SDK_API  Ir_SetBarrelTemp(long hIr,IR_TEMP_TYPE fTemp);
IR_TEMP_TYPE IR_SDK_API Ir_GetBarrelTemp(long hIr);

/*获取和设置发射率*/
int IR_SDK_API   Ir_GetEmiss(long hIr);
void IR_SDK_API  Ir_SetEmiss(long hIr,int iEmiss);

/*获取和设置湿度*/
int  IR_SDK_API  Ir_GetRelHum(long hIr);
void IR_SDK_API  Ir_SetRelHum(long hIr,int iHum);

WORD IR_SDK_API  Ir_GetCorrectCoef(long hIr);
void IR_SDK_API  Ir_SetCorrectCoef(long hIr,WORD wCoef);

int  IR_SDK_API  Ir_GetFrameType(long hIr);


/**********************************************************************************
* Function:      Ir_LoadPara
* Description:   从文件读取测温参数
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                char* FileName 测温参数文件名
* Output:        无
* Return:        参数文件载入成功返回TRUE,否则返回FALSE
* Notes:         该函数少用，一般在应用程序中读取配置好些
* Usage:         配置文件采用ini文件，参数采用ini文件中的一个section,注意名称必须一致
*                   [PARA]
*                   ATMOS_TEMP=19.2
*                   SHUTTER_TEMP=19.2
*                   EMISS=98
*                   HUM=70
************************************************************************************/
BOOL IR_SDK_API  Ir_LoadPara(long hIr,char* FileName);

#define BYTE_REL_HUM       0x0001  /*湿度*/
#define BYTE_EMISS         0x0002  /*发射率*/
#define BYTE_CORRECT_COEF  0x0004  /*校正系数*/
#define BYTE_DISTANCE      0x0008  /*距离*/
#define BYTE_TRANSMISSION  0x0010  /*穿透率*/

typedef struct __TempMeasurePara
{
	/*参数设置掩码*/
	DWORD dwFlag;

	/*校正参数*/
	long lRelHum;
	long lEmiss;
	long lCorrectCoef;
	long lDistance;
	long lTransmiss;
	

}tTempMeasurePara;

/**********************************************************************************
* Function:      Ir_SetMeasurePara
* Description:   设置测温校正系数
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
*                tTempMeasurePara *pPara 测温校正系数
* Output:        无
* Return:        设置成功返回TRUE，设置失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_SetMeasurePara(long hIr,tTempMeasurePara *pPara);

/**********************************************************************************
* Function:      Ir_GetMeasurePara
* Description:   获取测温校正系数
* Input:         long hIr    红外句柄，可以是红外图像、视频文件或USB视频
* Output:        tTempMeasurePara *pPara 测温校正系数
* Return:        成功获取返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_GetMeasurePara(long hIr,tTempMeasurePara *pPara);


/************************测温参数(END)**********************************************/

/**********************************************************************************
* Function:      Ir_LoadCurve
* Description:   从文件读取设备参数
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
*                char* FileName 设备参数文件名
* Output:        无
* Return:        设备参数文件载入成功返回TRUE,否则返回FALSE
* Notes:         一般保存的图像文件和视频文件中包含设备参数，不需要载入
*                    如果想采用另外设备参数测温，可以调入另外设备参数文件，该函数可重入
*                USB采集视频需要载入温度曲线
************************************************************************************/
BOOL IR_SDK_API  Ir_LoadCurve(long hIr,char* FileName);

/*获取和设置调色板，调色板最多支持9种*/
int IR_SDK_API   Ir_GetPaletteId(long hIr);
int IR_SDK_API   Ir_SetPaletteId(long hIr,int iPalette);

/**********************************************************************************
* Function:      Ir_GetPaletteData
* Description:   获取指定索引的系统调色板数据
* Input:         int iPalette 调色板索引，非负数，必须小于9
* Output:        无
* Return:        获取调色板数据RGBQUAD,为255个
* Notes:         不需带红外句柄参数
************************************************************************************/
RGBQUAD* IR_SDK_API Ir_GetPaletteData(int iPalette);

/**********************************************************************************
* Function:      Ir_SetAutoMapMode
* Description:   设置AD映射为灰度图采用自动方式还是手动方式
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
*                BOOL bMode     自动方式为TRUE,手动方式为FALSE
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  Ir_SetAutoMapMode(long hIr,BOOL bMode);

/**********************************************************************************
* Function:      Ir_GetAutoMapMode
* Description:   获取AD映射为灰度图的方式，是自动方式还是手动方式
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
* Output:        无
* Return:        自动方式返回TRUE,手动方式返回FALSE
************************************************************************************/
BOOL IR_SDK_API  Ir_GetAutoMapMode(long hIr);

/**********************************************************************************
* Function:      Ir_Light
* Description:   调整亮度和对比度
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
*                int brightness 亮度，范围 -100~100
*                int contrast   对比度，范围-200~200
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  Ir_Light(long hIr,int brightness,int contrast);

/**********************************************************************************
* Function:      Ir_GetBrightness
* Description:   获取设置的亮度
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
* Output:        无
* Return:        亮度值
************************************************************************************/
int IR_SDK_API   Ir_GetBrightness(long hIr);

/**********************************************************************************
* Function:      Ir_GetContrast
* Description:   获取设置的对比度
* Input:         long hIr       红外句柄，可以是红外图像、视频文件或USB视频
* Output:        无
* Return:        对比度
************************************************************************************/
int IR_SDK_API   Ir_GetContrast(long hIr);

/**********************************************************************************
* Function:      Ir_GetTestAd
* Description:   获取参考位置和绝对AD值
* Input:         long hIrStream       视频文件\USB视频\红外视频流句柄
* Output:        int *x,int *y        获取参考位置坐标
*                int *sAd             获取参考位置的绝对AD
* Return:        获取成功返回TRUE，失败返回FALSE
* Usages:        只用于测试中，实际的产品中该功能关闭
************************************************************************************/
BOOL IR_SDK_API  Ir_GetTestAd(long hIrStream,int *x,int *y,int *sAd);


/*设置等温线，通过等温线可以实现报警色*/
typedef struct tagIsothermColor
{
	COLORREF  colorMap;   /*颜色映射*/
	IR_TEMP_10FOLD_TYPE	iMaxTemp;         /*高温阈值，0xFFFF表示无上限*/
	IR_TEMP_10FOLD_TYPE iMinTemp;         /*低温阀值，0xFFFF表示无下限*/
} tIsoThermColorMap;      /*等温线*/

/**********************************************************************************
* Function:      Ir_SetIsoThermColorMap
* Description:   设置等温线数组
* Input:         long hIr      红外句柄，可以是红外图像、视频文件或USB视频
*                tIsoThermColorMap* pIsoThermColorList    等温线列表
*                     每个节点表示温度在iMinTemp和iMinTemp范围内的采用颜色colorMap
*                int iNum  等温线的个数        
* Output:        无
* Return:        无
* Usages:        最多只能设置20组等温线
*                每个等温线节点中iMaxTemp和iMinTemp都表示温度*10，如果值为0xFFFF，
*                    表示该值无效，不采用该上限或下限
*                等温线颜色会替换掉调色板和温度色标的颜色，该优先级最高
************************************************************************************/
void IR_SDK_API Ir_SetIsoThermColorMap(long hIr,tIsoThermColorMap* pIsoThermColorList,int iNum );

/**********************************************************************************
* Function:      Ir_SetColorScale
* Description:   设置颜色温标，根据温度裁剪颜色范围
* Input:         long hIr      红外句柄，可以是红外图像、视频文件或USB视频
*                int  iMinTemp 温度*10,表示温度下限，低于温度采用调色板中灰度0对应的颜色
*                int  iMaxTemp 温度*10,表示温度上限，高于该温度采用调色板中灰度255对应的颜色
* Output:        无
* Return:        无
* Notes:         颜色优先级高于调色板，低于等温线 
************************************************************************************/
void IR_SDK_API Ir_SetColorScale(long hIr,IR_TEMP_10FOLD_TYPE iMinTemp,IR_TEMP_10FOLD_TYPE iMaxTemp);


/**********************************************************************************
* Function:      Ir_RemoveCover
* Description:   去掉锅盖
* Input:         long hIr      红外句柄，可以是红外图像、视频文件或USB视频
* Output:        无
* Return:        成功返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_RemoveCover(long hIr);

/**********************************************************************************
* Function:      Ir_SetMeasureObject
* Description:   红外图像中增加测温对象缓冲区
* Input:         long hIrImage    红外图像句柄
*                unsigned char *pObjectBuf  红外对象缓冲区
*                int iBufSize     红外对象缓冲区大小
* Output:        无
* Return:        无
* Notes:         SDK没有对该缓冲区进行预先设置结构，由用户进行定制和解释
************************************************************************************/
void IR_SDK_API  Ir_SetMeasureObject(long hIrImage,unsigned char *pObjectBuf,int iBufSize);

/**********************************************************************************
* Function:      Ir_GetMeasureObject
* Description:   从红外图像中获取测温对象缓冲区
* Input:         long hIrImage    红外图像句柄             
* Output:        unsigned char *pObjectBuf  红外对象缓冲区
*                int iBufSize     红外对象缓冲区大小
* Return:        获取成功返回TRUE,失败返回FALSE
* Notes:         SDK没有对该缓冲区进行预先设置结构，由用户进行定制和解释
************************************************************************************/
BOOL IR_SDK_API  Ir_GetMeasureObject(long hIrImage,unsigned  char* pObjectBuf,int* pBufSize);


/****************************************************************************************/

/****************************IR视频文件*************************************************/

/**********************************************************************************
* Function:      IrVideo_Open
* Description:   打开红外视频文件
* Input:         char *filename  视频文件名
* Output:        无
* Return:        如果打开成功返回值>0，返回值为红外视频的句柄,
*                如果失败返回负数,可查找错误码
************************************************************************************/
long IR_SDK_API  IrVideo_Open(char *filename);

#define IR_VIDEO_FILE_TYPE_NORMAL           0  /*未压缩*/
#define IR_VIDEO_FILE_TYPE_COMPRESS_SINGLE  1  /*单帧压缩*/
#define IR_VIDEO_FILE_TYPE_COMPRESS_DIFF    2  /*差帧压缩*/
/**********************************************************************************
* Function:      IrVideo_Convert
* Description:   用于红外视频的文件类型转换 
* Input:         char *src_file  要转换的源视频文件名 
*                char* dst_file  要转换的目的视频文件名 
*                int   type      要转换的目的视频文件类型 
* Output:        char* dst_file  生成目标文件 
* Return:        转换成功返回TRUE,失败返回FALSE 
* Notes:         源文件必须是未压缩的，目的文件不能是非压缩的 
************************************************************************************/
BOOL IR_SDK_API IrVideo_Convert(char* src_file,char* dst_file,int type);


typedef void (*OwnerDrawCB)(HDC hdc,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetOwnerDraw
* Description:   用于视频的叠加，便于在视频上叠加分析图像
* Input:         long hFilePlayer     红外视频文件句柄
*                OwnerDrawCB BeforeDrawFunc  用于在视频显示之前进行画图，如清屏之类的，
*                           这个用不好会导致闪烁，慎用，如果要使用，采用memdc
*                OwnerDrawCB AfterDrawFunc 用于视频显示之后进行叠加画图，如红外分析对象
*                long lPrivate 绘图回调函数的私用数据，在回调调用时传给回调函数，可以为视图
* Output:        无
* Return:        无
* Notes:         如果视图在一个控件上播放，可以减少清屏的步骤，如果在view上播放，需要增加
*                    清屏操作
************************************************************************************/
void IR_SDK_API  IrVideo_SetOwnerDraw(long hFilePlayer,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);

typedef void (*AdFilterCB)(HDC hdc,short* pAd,int iWidth,int iHeight,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetAdFilter
* Description:   设置AD过滤处理回调
* Input:         long hFilePlayer     红外视频文件句柄
*                AdFilterCB filterCB  算法使用回调
*                long lPrivate        回调函数采用的私有数据   
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API IrVideo_SetAdFilter(long hFilePlayer,AdFilterCB filterCB,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetDrawPos
* Description:   设置视频显示的位置
* Input:         long hFilePlayer     红外视频文件句柄
*                HDC hdc    视频播放的DC句柄
*                long x=0,long y=0   视频播放的左上角的位置
*                long cx=-1,long cy=-1 视频播放的显示窗口大小，如果采用默认的，则视频
*                    不缩放显示，如果显示窗口小，一部分视频会在窗口外绘画
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrVideo_SetDrawPos(long hFilePlayer,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);

/**********************************************************************************
* Function:      IrVideo_AutoPlay
* Description:   视频开始播放
* Input:         long hFilePlayer     红外视频文件句柄
* Output:        无
* Return:        能正常播放返回TRUE,否则返回FALSE
* Notes:         在该操作之前必须设置显示的位置，操作该函数后视频就会在指定的窗口开始播放了
*                播放后也能动态调整显示的位置，采用IrVideo_SetDrawPos
************************************************************************************/
BOOL IR_SDK_API  IrVideo_AutoPlay(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_Close
* Description:   关闭视频文件，释放相应的资源
* Input:         long hFilePlayer     红外视频文件句柄
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrVideo_Close(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_GetTotalFrame
* Description:   获取视频文件总帧数
* Input:         long hFilePlayer     红外视频文件句柄
* Output:        无
* Return:        视频文件总帧数，获取失败，返回
************************************************************************************/
int IR_SDK_API   IrVideo_GetTotalFrame(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_GetCurFrame
* Description:   获取视频文件正在播放的帧数，一般用于状态条显示
* Input:         long hFilePlayer     红外视频文件句柄
* Output:        无
* Return:        当前帧，如果没有播放，返回0
************************************************************************************/
int IR_SDK_API   IrVideo_GetCurFrame(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_CapturePic
* Description:   从视频中截获图像
* Input:         long hFilePlayer     红外视频文件句柄
*                char* filepath       要保存的图像名
* Output:        无
* Return:        保存成功，返回0，否则为负数
* Usages:        图像文件名必须是bmp或jpg,如果是bmp，则不能测温，只有jpg文件能进行测温
************************************************************************************/
int IR_SDK_API   IrVideo_CapturePic(long hFilePlayer,char* filepath);


/*IR视频播放控制*/
enum eIrPlayMode
{
	IR_FILE_NOINIT = 0,
	IR_FILE_NOPLAY ,          /*无视频状态*/
	IR_FILE_PLAYING,          /*普通播放状态*/
	IR_FILE_PAUSE,            /*暂停状态*/
	IR_FILE_FWORD,		      /*快进*/
	IR_FILE_BACK,			  /*快退*/
	IR_FILE_SLOW,             /*慢放*/
	IR_FILE_FAST,             /*快放*/

	IR_FILE_PLAYSEEK,         /*各种播放状态下的定位播放,传入播放比*/
	IR_FILE_FWORDSEEK,
	IR_FILE_BACKSEEK,
	IR_FILE_FASTSEEK,
	IR_FILE_SLOWSEEK,

	IR_FILE_SOLE,
	IR_FILE_SOLESEEK
};

/**********************************************************************************
* Function:      IrVideo_Control
* Description:   对播放的红外视频进行控制
* Input:         long hFilePlayer     红外视频文件句柄
*                eIrPlayMode playmode 播放控制模式
*                long para            播放控制参数
* Output:        无
*                无
* Return:        控制成功返回0，失败返回-1
* Usages:        eIrPlayMode 表示控制命令
*                IR_FILE_PLAYING、IR_FILE_FAST、IR_FILE_SLOW
*                	 para用于播放速度控制(快播、慢播、正常播放)
*
*                对于IR_FILE_BACK和IR_FILE_FWORD有效 
*                para用于播放的方向控制(快进和慢退),未实现
*                   
*                SEEK类操作有效
*                para用于播放寻帧，播放的百分比*100
*
************************************************************************************/
int IR_SDK_API   IrVideo_Control(long hFilePlayer,eIrPlayMode playmode,long para =1);
/****************************IR视频文件(END)*********************************************/


/****************************IR视频流处理*************************************************/

/**********************************************************************************
* Function:      IrStream_Create
* Description:   创建红外视频流
* Input:         
*                int   iWidth    红外图像宽度
*                int   iHeight   红外图像高度
* Output:        无
* Return:        如果创建成功返回值>0，返回值为红外视频的句柄,否则返回-1
************************************************************************************/
long IR_SDK_API  IrStream_Create(int iWidth,int iHeight);


/**********************************************************************************
* Function:      IrStream_SetOwnerDraw
* Description:   用于视频的叠加，便于在视频上叠加分析图像
* Input:         long hIrStream     红外视频流句柄
*                OwnerDrawCB BeforeDrawFunc  用于在视频显示之前进行画图，如清屏之类的，
*                           这个用不好会导致闪烁，慎用，如果要使用，采用memdc
*                OwnerDrawCB AfterDrawFunc 用于视频显示之后进行叠加画图，如红外分析对象
*                long lPrivate 绘图回调函数的私用数据，在回调调用时传给回调函数，可以为视图
* Output:        无
* Return:        无
* Notes:         如果视图在一个控件上播放，可以减少清屏的步骤，如果在view上播放，需要增加
*                    清屏操作
************************************************************************************/
void IR_SDK_API  IrStream_SetOwnerDraw(long hIrStream,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);




/**********************************************************************************
* Function:      IrStream_SetAdFilter
* Description:   设置AD过滤处理回调
* Input:         long hFilePlayer     红外视频文件句柄
*                AdFilterCB filterCB  算法使用回调
*                long lPrivate        回调函数采用的私有数据   
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API IrStream_SetAdFilter(long hFilePlayer,AdFilterCB filterCB,long lPrivate);

/**********************************************************************************
* Function:      IrStream_SetDrawPos
* Description:   设置视频显示的位置
* Input:         long hIrStream      红外视频流句柄
*                HDC hdc             视频播放的DC句柄
*                long x=0,long y=0   视频播放的左上角的位置
*                long cx=-1,long cy=-1 视频播放的显示窗口大小，如果采用默认的，则视频
*                    不缩放显示，如果显示窗口小，一部分视频会在窗口外绘画
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrStream_SetDrawPos(long hIrStream,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);


/**********************************************************************************
* Function:      IrStream_Close
* Description:   关闭视频流文件，释放相应的资源
* Input:         long hIrStream   红外视频流句柄
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrStream_Close(long hIrStream);

/**********************************************************************************
* Function:      IrStream_InputData
* Description:   输入视频流数据，输入的帧数据可以用于显示
* Input:         long hIrStream   红外视频流句柄
*                void *pData      完整的Y16图像包括一行的视频参数
*                unsigned int len 帧长度
*                unsigned int ts  帧数据的时间戳
* Output:        无
* Return:        插入数据成功返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrStream_InputData(long hIrStream,void *pData,unsigned int len,unsigned int ts=0 );

/**********************************************************************************
* Function:      IrStream_GetTotalFrame
* Description:   获取已经播放的视频流总帧数
* Input:         long hIrStream   红外视频流句柄
* Output:        无
* Return:        视频文件总帧数，获取失败，返回
************************************************************************************/
int IR_SDK_API   IrStream_GetTotalFrame(long hIrStream);


/**********************************************************************************
* Function:      IrStream_CapturePic
* Description:   从视频中截获图像
* Input:         long hIrStream  红外视频流句柄
*                char* filepath  要保存的图像名
* Output:        无
* Return:        保存成功，返回0，否则为负数
* Usages:        图像文件名必须是bmp或jpg,如果是bmp，则不能测温，只有jpg文件能进行测温
************************************************************************************/
int IR_SDK_API   IrStream_CapturePic(long hIrStream,char* filepath);


/**********************************************************************************
* Function:      IrStream_StartRecord
* Description:   从红外视频流开始录像
* Input:         long hIrStream   红外视频流句柄
*                char* FileName   录像文件名
* Output:        无
* Return:        启动录像成功返回0，否则返回负数，可以查看错误码
************************************************************************************/
int IR_SDK_API   IrStream_StartRecord(long hIrStream, char* FileName);

/**********************************************************************************
* Function:      IrUsb_StopRecord
* Description:   停止网络流录像
* Input:         long hIrStream   红外视频流句柄
* Output:        无
* Return:        关闭成功返回0，否则返回-1
************************************************************************************/
int IR_SDK_API   IrStream_StopRecord (long hIrStream);


/****************************USB获取IR视频***********************************************/

/**********************************************************************************
* Function:      IrUsb_Open
* Description:   打开USB设备
* Input:         char *devName           USB设备名，以Ezusb开始
*                int iWidth,int iHeight  USB视频尺寸大小
* Output:        无
* Return:        打开成功返回USB句柄，否则返回-1
************************************************************************************/
long IR_SDK_API  IrUsb_Open(char *devName,int iWidth,int iHeight);

/**********************************************************************************
* Function:      IrUsb_SetOwnerDraw
* Description:   用于视频的叠加，便于在视频上叠加分析图像
* Input:         long hUsbVideo     USB设备句柄
*                OwnerDrawCB BeforeDrawFunc  用于在视频显示之前进行画图，如清屏之类的，
*                           这个用不好会导致闪烁，慎用，如果要使用，采用memdc
*                OwnerDrawCB AfterDrawFunc 用于视频显示之后进行叠加画图，如红外分析对象
*                long lPrivate 绘图回调函数的私用数据，在回调调用时传给回调函数，可以为视图
* Output:        无
* Return:        无
* Notes:         如果视图在一个控件上播放，可以减少清屏的步骤，如果在view上播放，需要增加
*                    清屏操作
************************************************************************************/
void IR_SDK_API  IrUsb_SetOwnerDraw(long hUsbVideo,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);

/**********************************************************************************
* Function:      IrUsb_SetDrawPos
* Description:   设置视频显示的位置
* Input:         long hUsbVideo     USB设备句柄
*                HDC hdc    视频播放的DC句柄
*                long x=0,long y=0   视频播放的左上角的位置
*                long cx=-1,long cy=-1 视频播放的显示窗口大小，如果采用默认的，则视频
*                    不缩放显示，如果显示窗口小，一部分视频会在窗口外绘画
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrUsb_SetDrawPos(long hUsbVideo,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);

/**********************************************************************************
* Function:      IrUsb_AutoPlay
* Description:   USB开始采集
* Input:         long hUsbVideo     USB设备句柄
* Output:        无
* Return:        能正常播放返回TRUE,否则返回FALSE
* Notes:         在该操作之前必须设置显示的位置，操作该函数后视频就会在指定的窗口开始播放了
*                播放后也能动态调整显示的位置，采用IrUsb_SetDrawPos
************************************************************************************/
BOOL IR_SDK_API  IrUsb_AutoPlay(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_Close
* Description:   关闭USB设备
* Input:         long hUsbVideo   USB设备句柄
* Output:        无
* Return:        关闭成功返回0，否则返回-1
************************************************************************************/
int IR_SDK_API   IrUsb_Close(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_CapturePic
* Description:   从视频中截获图像
* Input:         long hUsbVideo   USB设备句柄
*                char* filepath       要保存的图像名
* Output:        无
* Return:        保存成功，返回0，否则为负数
* Usages:        图像文件名必须是bmp或jpg,如果是bmp，则不能测温，只有jpg文件能进行测温
************************************************************************************/
int IR_SDK_API   IrUsb_CapturePic(long hUsbVideo,char* filepath);

/**********************************************************************************
* Function:      IrUsb_StartRecord
* Description:   开始录像
* Input:         long hUsbVideo   USB设备句柄
*                char* FileName   录像文件名
* Output:        无
* Return:        启动录像成功返回0，否则返回负数，可以查看错误码
************************************************************************************/
int IR_SDK_API   IrUsb_StartRecord(long hUsbVideo, char* FileName);

/**********************************************************************************
* Function:      IrUsb_StopRecord
* Description:   停止录像
* Input:         long hUsbVideo   USB设备句柄
* Output:        无
* Return:        关闭成功返回0，否则返回-1
************************************************************************************/
int IR_SDK_API   IrUsb_StopRecord (long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_GetTotalFrame
* Description:   获取已经录像的总帧数
* Input:         long hUsbVideo   USB设备句柄
* Output:        无
* Return:        已经录像的总帧数
* Usages:        可以通过帧数来控制每个视频文件的帧数，满足一定的帧数重创建一个文件录
************************************************************************************/
int IR_SDK_API   IrUsb_GetTotalFrame(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_GetTotalSize
* Description:   获取已经录像文件的总大小
* Input:         long hUsbVideo   USB设备句柄
* Output:        无
* Return:        已经录像文件的大小
* Usages:        可以通过帧数来控制每个视频文件的文件大小，满足一定的大小重创建一个文件录
************************************************************************************/
int IR_SDK_API   IrUsb_GetTotalSize(long hUsbVideo);


typedef enum
{
	IR_CMD_FOCUS_NEAR =1,
	IR_CMD_FOCUS_FAR,
	IR_CMD_FOCUS_STOP,
	IR_CMD_CHANGE_BRIGTH,
	IR_CMD_CHANGE_CONTRAST,
	IR_CMD_CHANGE_CONTRAST2,
	IR_CMD_SEND_SHUTTER,
	IR_CMD_CHANGE_PALLATE,
	IR_CMD_CLEAR_SCREEN,
	IR_CMD_NUM
}eIrCmd;

/**********************************************************************************
* Function:      IrUsb_Control
* Description:   通过USB来控制红外摄像机
* Input:         long hUsbVideo   USB设备句柄
*                eIrCmd cmd       红外控制命令
*                int para1=0,int para2=0 命令附加参数
* Output:        无
* Return:        控制成功返回0，失败返回-1
* Usages:        需要USB采集板子支持USB上传，该功能暂时没用
************************************************************************************/
int IR_SDK_API IrUsb_Control(long hUsbVideo,eIrCmd cmd,int para1=0,int para2=0);
/****************************USB视频(END)***********************************************/



/****************************IR图像处理**************************************************/
/**********************************************************************************
* Function:      IrImage_IsIr
* Description:   判断是否是红外图像，因为红外红图像采用的为通用jpg文件，需要和一般jpg文件区分开
* Input:         char *filename  图像文件名
* Output:        无
* Return:        如果是红外图像返回TRUE,如果不是返回FALSE
* Notes:         只对jpg文件有效
************************************************************************************/
BOOL IR_SDK_API  IrImage_IsIr(char *filename);

/**********************************************************************************
* Function:      IrImage_Open
* Description:   打开红外图像
* Input:         char *filename  图像文件名
* Output:        无
* Return:        如果打开成功，则返回红外图像句柄，否则-1
* Notes:         只对jpg文件有效
************************************************************************************/
long IR_SDK_API  IrImage_Open(char *filename);

/**********************************************************************************
* Function:      IrImage_Save
* Description:   保存红外图像，更新当前红外图像或另存为
* Input:         long hIrImage    红外图像句柄
*                char *filename   要保存的图像文件名
* Output:        无
* Return:        保存成功，返回0，否则为负数
* Usages:        对测温参数、温度曲线、测温对象修改了，就可调用该函数保存下，扩展名为jpg
************************************************************************************/
int IR_SDK_API   IrImage_Save(long hIrImage,char *filename);

/**********************************************************************************
* Function:      IrImage_Close
* Description:   关闭红外文件，释放响应资源
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrImage_Close(long hIrImage);

/**********************************************************************************
* Function:      IrImage_DrawIr
* Description:   在指定窗口绘制图像，平铺制定窗口
* Input:         long hIrImage    红外图像句柄
*                long hDrawWnd    要绘制图像的窗口句柄
* Output:        无
* Return:        无
* Notes:         绘制的图像会缩放以铺满整个窗口
************************************************************************************/
void IR_SDK_API  IrImage_DrawIr(long hIrImage,long hDrawWnd);

/**********************************************************************************
* Function:      IrImage_DrawIr
* Description:   指定的HDC和指定的位置绘图
* Input:         long hIrImage    红外图像句柄
*                HDC hdc          要绘图的CDC的句柄
*                long x,y         在CDC上绘图的起始位置
*                long cx,cy       CDC上绘图的宽度和高度
* Output:        无
* Return:        无
* Notes:         如果不指定cx,cy，则图像按照图像原始大小绘制，可以超过CDC的范围
************************************************************************************/
void IR_SDK_API  IrImage_DrawIrEx(long hIrImage,HDC hdc, long x=0, long y=0, long cx = -1, long cy = -1);

/**********************************************************************************
* Function:      IrImage_PlayVoice
* Description:   播放语音注释
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        如果有语言注释，能正常播放，则返回0，否则返回负数
************************************************************************************/
int IR_SDK_API   IrImage_PlayVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_StopVoice
* Description:   停止播放语言注释
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        无
* Notes:         如果有语言注释在播放，则停止，否则不做任何操作
************************************************************************************/
void IR_SDK_API  IrImage_StopVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_HasVoice
* Description:   判读红外图像是否具有语言注释
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        有语言注释返回TRUE,否则返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_InsertVoiceComment
* Description:   往红外图像中插入语言注释
* Input:         long hIrImage    红外图像句柄
*                char *fileName   语言注释文件
* Output:        无
* Return:        插入语言注释成功返回TRUE,否则返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_InsertVoiceComment(long hIrImage,char *fileName);

/**********************************************************************************
* Function:      IrImage_HasTextComment
* Description:   判断红外图像是否有文本注释
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        有文本注释返回TRUE,否则返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasTextComment(long hIrImage);

/**********************************************************************************
* Function:      IrImage_InsertTextComment
* Description:   往红外图像中插入文本注释
* Input:         long hIrImage    红外图像句柄
*                char *pText      文本注释
* Output:        无
* Return:        插入文本注释成功返回TRUE,否则返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_InsertTextComment(long hIrImage,char *pText);

/**********************************************************************************
* Function:      IrImage_GetTextComment
* Description:   获取红外图像中的文本注释
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        如果有文本注释，则返回文本，否则返回NULL
************************************************************************************/
char* IR_SDK_API IrImage_GetTextComment(long hIrImage);

/**********************************************************************************
* Function:      IrImage_HasVLImage
* Description:   判断红外图像是否附有可见光图像
* Input:         long hIrImage    红外图像句柄
* Output:        无
* Return:        有可见光图像返回TRUE,否则返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasVLImage(long hIrImage);

/**********************************************************************************
* Function:      IrImage_GetVLSize
* Description:   获取可见光图像的大小尺寸
* Input:         long hIrImage     红外图像句柄
* Output:        int *pImageWidth  可见光图像的宽度
*                int *pImageHeight 可见光图像的高度
* Return:        如果获取成功，则返回0，否则返回-1
************************************************************************************/
int IR_SDK_API   IrImage_GetVLSize(long hIrImage,int *pImageWidth,int *pImageHeight);

/**********************************************************************************
* Function:      IrImage_DrawVL
* Description:   在制定窗口绘制图像，平铺制定窗口
* Input:         long hIrImage    红外图像句柄
*                long hDrawWnd    要绘制图像的窗口句柄
* Output:        无
* Return:        无
* Notes:         绘制的图像会缩放以铺满整个窗口
************************************************************************************/
void IR_SDK_API  IrImage_DrawVL(long hIrImage,long hDrawWnd);

/**********************************************************************************
* Function:      IrImage_DrawVL
* Description:   制定的HDC和制定的位置绘图
* Input:         long hIrImage    红外图像句柄
*                HDC hdc          要绘图的CDC的句柄
*                long x,y         在CDC上绘图的起始位置
*                long cx,cy       CDC上绘图的宽度和高度
* Output:        无
* Return:        无
* Notes:         如果不指定cx,cy，则图像按照图像原始大小绘制，可以超过CDC的范围
************************************************************************************/
void IR_SDK_API  IrImage_DrawVLEx(long hIrImage,HDC hdc, long x=0, long y=0, long cx = -1, long cy = -1);



/****************************IR图像处理(END)**********************************************/


/****************************IR校正******************************************************/

/**********************************************************************************
* Function:      IrCorrect_Create
* Description:   创建IR校正
* Input:         int iWidth    红外图像的宽度
*                int iHeight   红外图像的高度
* Output:        无
* Return:        创建成功，返回Correct句柄，否则返回-1
************************************************************************************/
long IR_SDK_API  IrCorrect_Create(int iWidth,int iHeight);

/**********************************************************************************
* Function:      IrCorrect_Close
* Description:   关闭红外校正
* Input:         long hCorrect   红外校正句柄
* Output:        无
* Return:        无
************************************************************************************/
void IR_SDK_API  IrCorrect_Close(long hCorrect);

/**********************************************************************************
* Function:      IrCorrect_LoadHData
* Description:   载入高温本底数据
* Input:         long hCorrect  红外校正句柄
*                char *fileName 高温本底文件 
* Output:        无
* Return:        载入成功，返回TRUE,失败返回FALSE
* Usages:        高温本底图像数据每行十六进值数，表示两个AD
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_LoadHData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_LoadLData
* Description:   载入低温本底数据
* Input:         long hCorrect  红外校正句柄
*                char *fileName 低温本底文件 
* Output:        无
* Return:        载入成功，返回TRUE,失败返回FALSE
* Usages:        低温本底图像数据每行十六进值数，表示两个AD
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_LoadLData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_CalcK
* Description:   计算校验K值
* Input:         long hCorrect  红外校正句柄
* Output:        无
* Return:        成功，返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_CalcK(long hCorrect);

/**********************************************************************************
* Function:      IrCorrect_SaveKData
* Description:   保存K值图像
* Input:         long hCorrect  红外校正句柄
*                char *fileName 校正文件
* Output:        无
* Return:        保存成功，返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SaveKData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_SavetBadPointReport
* Description:   保存坏点报告
* Input:         long hCorrect  红外校正句柄
*                char *fileName 坏点报告文件
* Output:        无
* Return:        保存成功，返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SavetBadPointReport(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_SavetBadPointData
* Description:   保存坏点数据
* Input:         long hCorrect  红外校正句柄
*                char *fileName 坏点数据文件
* Output:        无
* Return:        保存成功，返回TRUE,失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SavetBadPointData(long hCorrect,char *fileName);

/****************************IR校正(END)**************************************************/


/****************************串口控制****************************************************/

/*这些宏在NetSDK中也使用，避免重复调用，采用宏区分*/
#ifndef FPGA_CTRL
#define FPGA_CTRL
#define MAX_FPGA_CTRL_BUF_LEN  2048

#define FPGA_FRAME_START                 0xAA55
#define FPGA_FRAME_END                   0xA5A6

#define FPGA_CTRL_TYPE_REQUEST_REPLY     0      /*消息请求，需要响应*/
#define FPGA_CTRL_TYPE_REQUEST_NO_REPLY  1      /*消息请求,不需要响应*/
#define FPGA_CTRL_TYPE_REPLY             2      /*消息响应*/

#define FPGA_REPLY_SUCCESS               0      /*处理成功*/
#define FPGA_REPLY_FAILURE              -1      /*处理失败*/
#define FPGA_REPLY_RESEND               -2      /*需要重传,CRC错误或帧尾破坏了*/
#define FPGA_REPLY_INVALID_CMD          -3      /*不能识别的命令*/
#define FPGA_REPLY_INVALID_PARA         -4      /*非法的命令参数*/
#define FPGA_REPLY_DEV_BUSY             -5      /*设备繁忙，来不及响应*/

//传输文件类型
#define FILE_TYPE_K                     (0x00000001)
#define FILE_TYPE_B                     (0x00000002)
#define FILE_TYPE_BPLIST                (0x00000003)
#define FILE_TYPE_POWERON_IMAGE         (0x00000004)
#define FILE_TYPE_CODE_BIT              (0x00000005)  /*用于传升级文件*/
#define FILE_TYPE_FILTER_COEF           (0x00000006)  /*滤波系数*/
#define FILE_TYPE_CODE_SREC             (0x00000007)  /*SREC*/
#define FILE_TYPE_TEMP_DATA             (0x00000008)  /*温度数据*/
#define FILE_TYPE_ASCII                 (0x00000009) 
#define FILE_TYPE_HANZI                 (0x0000000A) 






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





typedef enum 
{ 
   FPGA_CTRL_OPEN               = 0  ,  /*打开I2C,对网络SDK有用*/
   FPGA_CTRL_INC_BRIGHTNESS     = 1  ,  /*绝对值增加1 */
   FPGA_CTRL_DEC_BRIGHTNESS          ,  /*绝对值减1*/
   FPGA_CTRL_GET_BRIGHTNESS          ,  /*返回负载数据 4个字节网络序返回亮度值*/
   FPGA_CTRL_SET_BRIGHTNESS          ,  /*设置亮度，发送负载数据 4字节网络序亮度*/
   
   FPGA_CTRL_INC_CONTRAST            ,  /*对比度*/
   FPGA_CTRL_DEC_CONTRAST            , 
   FPGA_CTRL_GET_CONTRAST            ,  /*返回负载数据 4个字节网络序返回对比度*/
   FPGA_CTRL_SET_CONTRAST            , 


   FPGA_CTRL_INC_BRIGHT_CONTRAST_MODE, /*亮度对比度模式*/
   FPGA_CTRL_DEC_BRIGHT_CONTRAST_MODE, 
   FPGA_CTRL_GET_BRIGHT_CONTRAST_MODE, /*返回负载数据 4个字节网络序返回亮度对比度模式*/
   FPGA_CTRL_SET_BRIGHT_CONTRAST_MODE, /*发送负载数据 4个字节网络序，0 手动，2自动*/

   
   FPGA_CTRL_INC_PALETTE             , /*调色板*/
   FPGA_CTRL_DEC_PALETTE             , 
   FPGA_CTRL_GET_PALETTE             , /*返回负载数据 4个字节网络序返回调色板索引*/
   FPGA_CTRL_SET_PALETTE             , 
   

   FPGA_CTRL_CALIBRATE_B1            , /*低温本底校正*/
   FPGA_CTRL_CALIBRATE_B2            , /*高温本底校正*/
   FPGA_CTRL_CALIBRATE_INITK         , /*初始化K值*/
   FPGA_CTRL_CALIBRATE_INITB         , 
   FPGA_CTRL_CALIBRATE_SAVEK         ,
   FPGA_CTRL_CALIBRATE_LOADK         ,
   FPGA_CTRL_BADPOINT_REPLACE        , /*去坏点*/
   FPGA_CTRL_SHARP_DEGREE            , /*锐化等级*/
   FPGA_CTRL_GET_SHARP_DEGREE        , /*获取锐化级别*/
   
   FPGA_CTRL_GET_SHUTTER_STATUS      ,  /*返回负载数据 4个字节网络序返回快门状态*/
   FPGA_CTRL_SET_SHUTTER_STATUS      ,  /*电机控制*/

   
   FPGA_CTRL_SAVE_BPLIST             ,  /*坏点列表相关操作*/
   FPGA_CTRL_LOAD_BPLIST             ,
   FPGA_CTRL_CLR_BPLIST              ,

   FPGA_CTRL_GET_MENU_STATUS   = 100 ,  /*返回负载数据 4个字节网络序返回菜单状态*/
   FPGA_CTRL_SET_MENU_STATUS         ,  /*设置菜单状态*/


   FPGA_CTRL_MENU_RIGHT_MOVE         ,  /*菜单操作*/
   FPGA_CTRL_MENU_LEFT_MOVE          , 
   FPGA_CTRL_MENU_UP_MOVE            , 
   FPGA_CTRL_MENU_DOWN_MOVE          , 
   FPGA_CTRL_UP_CONFIRM              , 
   FPGA_CTRL_DOWN_CONFIRM            ,
   FPGA_CTRL_SHOW_DEBUG              ,

   FPGA_CTRL_SENSOR_VOLT             , /*设置探测器偏差*/
   FPGA_CTRL_SENSOR_LOCK             , /*偏压上锁*/
   FPGA_CTRL_COOLER_VOLT			 , /*制冷机*/    

  //上传文件
   FPGA_CTRL_FILE_SEND_START   = 200 , /*发送文件开始, 发送 负载数据 4字节网络序文件类型+4字节网络序文件长度*/
   FPGA_CTRL_FILE_SEND               , /*发送文件，每块数据最多MAX_SERIAL_DATA_LEN字节*/   
   FPGA_CTRL_FILE_SEND_END           , /*文件发送结束，不带负载数据*/

   //下载文件
   FPGA_CTRL_FILE_REQUEST            ,  /*接收文件，发送负载数据 4字节网络序文件类型，接收负载数据 4字节网络序文件类型*/
   FPGA_CTRL_FILE_GET_NEXT           ,  /*获取文件下一帧，发送不带负载数据，接收为负载数据最多MAX_SERIAL_DATA_LEN字节*/

   FPGA_CTRL_SAVE_CFG         = 300  , /*保存配置*/
   FPGA_CTRL_LOAD_CFG                , /*载入配置*/

		/*测试用命令*/
	FPGA_CTRL_TESTIMAGE     = 400    ,  
	FPGA_CTRL_VIDEOSRC               , 
	FPGA_CTRL_Y32TEST                , 
	FPGA_CTRL_CALB1WITHOUTSHUTTER    , 
	FPGA_CTRL_ZOOM                   ,
	FPGA_CTRL_LOGICEDITION           ,
	FPGA_CTRL_TRYSHUTTER             ,
	FPGA_CTRL_SETFILTERTH            ,
	FPGA_CTRL_SETBCAERASEL           ,
	FPGA_CTRL_CTRLMETHODSEL          ,
	FPGA_CTRL_RMVVLINESWITCH         , 
	FPGA_CTRL_RMVGUOGAISWITCH = 411  , 
	FPGA_CTRL_CALGUOGAI              , 
	FPGA_CTRL_SAVEGUOGAI             ,
	FPGA_CTRL_LOADGUOGAI             ,
	FPGA_CTRL_CLRGUOGAI              ,
	FPGA_CTRL_SETSHARPLOWER          ,
	FPGA_CTRL_SETSHARPUPPER          ,
	FPGA_CTRL_SHOWMENU               ,
	FPGA_CTRL_SHIFTBIT               ,
	FPGA_CTRL_SETINTTIME             ,
	
	FPGA_CTRL_BPCORXPOS      =421    ,
	FPGA_CTRL_BPCORYPOS              ,
	FPGA_CTRL_BPCONFIRM              ,
	FPGA_CTRL_BPCANCEL               ,
	FPGA_CTRL_SHOWCURSOR             ,

	FPGA_CTRL_AUTOFOCUS              , 
	FPGA_CTRL_STEPCTRLMETHODMANUL    ,
	FPGA_CTRL_STEPFRECTRL            ,
	FPGA_CTRL_ABZCLR                 ,
	FPGA_CTRL_VISUALSAMPLESWITCH     ,
	FPGA_CTRL_VISUALSHOWSEL          ,
	FPGA_CTRL_VISUALSAMPLEREF1       ,
	FPGA_CTRL_VISUALSAMPLEREF2       ,
	FPGA_CTRL_CLRSRCEENSWITCH        ,

	FPGA_CTRL_DCMOTORFRECTRL         , 
	FPGA_CTRL_DCMOTORSPEEDCTRL       , 
	FPGA_CTRL_LOADDEFAULTCFG         , 

	FPGA_CTRL_NEARFOCUS              ,
	FPGA_CTRL_FARFOCUS               ,

	FPGA_CTRL_SHUTTER_MOTOR_FRE = 450,
	FPGA_CTRL_SHUTTER_MOTOR_SPEED    ,
	FPGA_CTRL_FOCUS_MOTO_FRE         ,
	FPGA_CTRL_FOCUS_MOTO_SPEED       ,
	FPGA_CTRL_LOAD_DEFAULT_CFG       , /*0 恢复所有配置，1恢复亮度对比度*/               
               
	FPGA_CTRL_SEARCHBP     = 480     ,
	FPGA_CTRL_SETBPTH                ,
	FPGA_CTRL_FOCUSMOTORFRECTRL      , 
	FPGA_CTRL_FOCUSMOTORSPEEDCTRL    , 
	
    FPGA_CTRL_PTZ             = 800  , /*云台控制*/
    FPGA_CTRL_SET_PT          = 801  ,
    FPGA_CTRL_SET_RECT        = 802  ,
    FPGA_CTRL_SET_CIRCLE      = 803  ,
    FPGA_CTRL_SET_POLYGON     = 804  ,
    FPGA_CTRL_GET_RECT_TEMP   = 805  ,  
    FPGA_CTRL_GET_CIRCLE_TEMP = 806  , 
    FPGA_CTRL_GET_POLYGON_TEMP = 807 , /*获取多边形温度*/

   	FPGA_CTRL_CLOSE            = 1000 ,  /*关闭I2C,对网络SDK有用*/
   	FPGA_CTRL_NULL                    ,  /*空命令*/
   
 } eFpgaCmd;

#pragma  pack(1)
typedef struct __fpga_cmd
{
	unsigned short frameStart; /*帧头*/
	unsigned short cmd;        /*串口命令*/
	unsigned short type;       /*命令类型,*/
	short          ret;        /*命令返回值*/
	unsigned short bufLen;     /*缓冲区buf长度*/
	unsigned short crc;        /*按short类型校验*/	
	unsigned char  buf[1];     /*缓冲区，由相应命令解释*/
}tFpgaCmd;
#pragma pack()

#endif

#define COMM_BREAK_DETECTED		1	// A break was detected on input.
#define COMM_CTS_DETECTED		2	// The CTS (clear-to-send) signal changed state. 
#define COMM_DSR_DETECTED		3	// The DSR (data-set-ready) signal changed state. 
#define COMM_ERR_DETECTED	    4	// A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. 
#define COMM_RING_DETECTED		5	// A ring indicator was detected. 
#define COMM_RLSD_DETECTED		6	// The RLSD (receive-line-signal-detect) signal changed state. 
#define COMM_RXCHAR				7	// A character was received and placed in the input buffer. 
#define COMM_RXFLAG_DETECTED    8	// The event character was received and placed in the input buffer.  
#define COMM_TXEMPTY_DETECTED	9	// The last character in the output buffer was sent.  

/*最大的负载数据长度*/
#define MAX_SERIAL_DATA_LEN     512

/**********************************************************************************
* Function:      IrSerial_Open
* Description:   打开串口设备
* Input:         unsigned int portnr   串口端口号
*                unsigned int baud     波特率
*                char parity           奇偶校验
*                unsigned int stopsbits 停止码
*                unsigned long dwCommEvents 要处理的事件
*                unsigned int nBufferSize 串口缓冲区大小
* Output:        无
* Return:        打开成功，返回串口句柄，否则返回-1
* Usages:        
************************************************************************************/
long IR_SDK_API  IrSerial_Open(unsigned int portnr = 1, unsigned int baud = 19200, char parity = 'N', unsigned int databits = 8, unsigned int stopsbits = 1, unsigned long dwCommEvents = EV_RXCHAR | EV_CTS, unsigned int nBufferSize = 1024);

/**********************************************************************************
* Function:      IrSerial_Close
* Description:   关闭串口设备，释放相应资源
* Input:         long hSerial  串口设备句柄
* Output:        无
* Return:        关闭成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_Close(long hSerial);


/**********************************************************************************
* Function:      IrSerial_Write
* Description:   往串口设备写数据
* Input:         long hSerial        串口设备句柄
*                unsigned char *Buff 要发送的数据缓冲区 
*                int iLen            缓冲区数据大小
*                BOOL bWaitReply     是否等待对端响应
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_Write(long hSerial,unsigned char *Buff,int iLen,BOOL bWaitReply=FALSE);


/**********************************************************************************
* Function:      IrSerial_SendCmd
* Description:   往串口设备发送命令
* Input:         long hSerial           串口设备句柄
*                unsigned short cmd     串口命令
*                unsigned short cmdType 命令类型
*                unsigned char* pBuff   命令参数缓冲区长度
*                int iBufLen            命令参数缓冲区
*                unsigned char *pRetBuf 命令返回接收缓冲区
*                int *pRetLen           返回缓冲区总长度
* Output:        unsigned char *pRetBuf 命令返回
*                int *pRetLen           返回缓冲区长度
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_SendCmd(long hSerial,unsigned short cmd,unsigned short cmdType=FPGA_CTRL_TYPE_REQUEST_REPLY,unsigned char* pBuff=NULL,int iBufLen=0,unsigned char *pRetBuf = NULL,int *pRetLen = NULL);


typedef int (*IrSerial_FileTrans)(long lPrivate, int totalLen, int curLen);

/**********************************************************************************
* Function:      IrSerial_SendFile
* Description:   往串口设备发送文件
* Input:         long hSerial           串口设备句柄
*                int fileType           文件类型
*                char *fileName         发送文件名
*                IrSerial_FileTrans pCbFileTrans  文件传输状态回调
*                long lPrivate          回调函数的参数
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_SendFile(long hSerial,int fileType,char *fileName,IrSerial_FileTrans pCbFileTrans = NULL,long lPrivate=0 );


/**********************************************************************************
* Function:      IrSerial_RecvFile
* Description:   从串口接收文件
* Input:         long hSerial           串口设备句柄
*                int fileType           文件类型
*                char *fileName         保存文件名
*                IrSerial_FileTrans pCbFileTrans  文件传输状态回调
*                long lPrivate          回调函数的参数
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_RecvFile(long hSerial,int fileType,char *fileName,IrSerial_FileTrans pCbFileTrans = NULL,long lPrivate=0);


/*************************串口控制(END)************************************************/


/****************************黑体控制****************************************************/

/*BDB黑体读取*/
typedef int (*BDB_ReadCb)(long lPrivate,BYTE *pBuf,int iLen);

/**********************************************************************************
* Function:      BDBCtrl_Open
* Description:   打开串口设备
* Input:         unsigned int portnr   串口端口号
*                unsigned int baud     波特率
*                char parity           奇偶校验
*                unsigned int stopsbits 停止码
*                unsigned long dwCommEvents 要处理的事件
*                unsigned int nBufferSize 串口缓冲区大小
* Output:        无
* Return:        打开成功，返回串口句柄，否则返回-1
* Usages:        如果不需要读取数据，pCbRead设置为空，调用该函数时一般只需指定端口号和波特率，
*                其余可以采用默认
************************************************************************************/
long IR_SDK_API  BDBCtrl_Open(unsigned int portnr = 1, unsigned int baud = 9600, char parity = 'E', unsigned int databits = 7, unsigned int stopsbits = 1, unsigned long dwCommEvents = EV_RXCHAR | EV_CTS, unsigned int nBufferSize = 1024);

/**********************************************************************************
* Function:      BDBCtrl_Close
* Description:   关闭串口设备，释放相应资源
* Input:         long hSerial  串口设备句柄
* Output:        无
* Return:        关闭成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_Close(long hSerial);


/**********************************************************************************
* Function:      IrSerial_Write
* Description:   往串口设备写数据
* Input:         long hSerial        串口设备句柄
*                unsigned char *Buff 要发送的数据缓冲区 
*                int iLen            缓冲区数据大小
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_Write(long hSerial,unsigned char *Buff,int iLen);

/**********************************************************************************
* Function:      BDBCtrl_SetReadCB
* Description:   设置串口读取回调函数
* Input:         long hSerial        串口设备句柄
*                BDB_ReadCb ReadCb 串口数据读取回调函数 
*                long lPrivate      私有数据，回调函数使用
* Output:        无
* Return:        发送成功，返回TRUE，失败返回FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_SetReadCB(long hSerial,BDB_ReadCb ReadCb,long lPrivate=0);

/*************************黑体控制(END)************************************************/

#endif
