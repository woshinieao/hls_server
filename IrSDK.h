/**************************************************************************************************
* File Name     : IrSDK.h
* Module Name   : IR_SDK
* Description   : �������������
* Author/Date   : Janekey/ 2011.01.21
* Version       : 3.1.1.1
* State         : create
* -----------------------------------History-------------------------------------------------------
* Modifier/Date : 2011.01.21
* Modify Reason : ��ʼ�����淶ע��
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.01.22
* Modify Reason : ���������¶����ͣ�һ������ʵ�¶ȣ�һ�����¶�*10,�����ں��������к�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.02.22
* Modify Reason : �����˺����������SDK
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.02.25
* Modify Reason : �����˺�����Ƶ�ļ�������ת�������������Ҫ�Ƿ�����ԣ��Ժ󲻻ṫ��
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.03.2
* Modify Reason : ������������¼����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.04.22
* Modify Reason : ������ͨ�ô�������ṹ��
*                 �����˴�������ͺ���
*                 �����˽�������������Ӧ����������Ϻͽ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.18
* Modify Reason : �����˴��ڷ����ļ��ӿ�
*                 �����˴��ڷ��������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.23
* Modify Reason : ���ڷ��ͺ������ӵȴ�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.25
* Modify Reason : �����˴��ڷ��ͺͽ����ļ��̣߳�����״̬ͨ���ص��ϴ����ϲ����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.05.26
* Modify Reason : ���ʹ������������˻�ȡ���ػ������Ĳ���,�е������Я������
*                 �����˴��ڷ���������ļ����Ͷ��峣��
*                 ȥ���˴��ڶ��ص�IrSerial_ReadCmdRet���ⲿ�ֲ�����Ҫ
*                 �����ļ��������ļ�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.1
* Modify Reason : ������ȱʡ����ͼ��Ŀ�Ⱥ͸߶ȴ�С���������ͼ���С�ı��ˣ���Ҫ�ı�
*                 �ú꣬��ʱֻ�ܲ���������������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.21
* Modify Reason : SERIAL_CMD ��ͷ���������FPGA_CTL���滻����������ͨ�����ڿ���FPGA
*                 ��ͨ������������FPGA
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.06.24
* Modify Reason : �������úͻ�ȡ��Ͳ�¶ȵĺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.06
* Modify Reason : ���ӻ�ȡ�����¶�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.07
* Modify Reason : �������úͻ�ȡ���š���Ͳ��׼�¶ȣ��Լ����š���ͲУ��ϵ��������У��
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.07.21
*                 ��У�����ֵĲ������ö�ȥ���ˣ����������÷ŵ����¶������У��ⲿ��У�������û�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.08.8
*                 ������BDB�����¶�ͨ�����ڵĶ�ȡ������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.7
*                 ������FPGA��ȡ�汾�ŵĺ�
*                 IrImage_DrawVL->IrImage_DrawVLEx 
*                 IrImage_DrawIr->IrImage_DrawIrEx ����������������ͬ
*                 Ϊ���������Ե��ã���declspec�޸�Ϊstdcall,��.def�ļ��е�������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.7
* Version:        3.0.1.3
*                 IrVideo_Control�޸��˵��ò��������Ʋ���ֻ��������һ�����һ�������Ӧ�Ĳ���
*                 ����VB�����Լ�����ɶ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.13
* Version:        3.0.2.1
*                 ������ȥ���ǽӿں���
*                 ���ӻ�ȡԭʼAD�ĺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.9.22
* Version:        3.0.2.2
*                 ������FPGA�Զ����������ĺ�
*                 �����˻�ȡ�񻯼���ĺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.10
* Version:        3.0.2.3
*                 �����˻�ȡӳ��AD�ķ�Χ
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.15
* Version:        3.0.4.3
*                 �������Ƶ����ý�岥��ʱ���в��·���ʱ��˸������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.16
* Version:        3.0.4.4
*                 �ڴ���memDCʱָ��λ�ã�������ȡ����DC������ˢ��������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.10.16
* Version:        3.0.4.5
*                 FPGA�����˲�ϵ���ļ�
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.11.27
* Version:        3.0.6.1
*                 ����������úͻ�ȡ���¶�������Ϊͨ�ù���
*                 ������Ƶ�ͺ�����ý��ץͼҲ������¶���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.07
* Version:        3.0.8.1
*                 ���������úͻ�ȡ���ò���У���Ĺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.08
* Version:        3.1.1.1
*                 �޸����¶����ߣ�֧�ֶ๤�������²���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2011.12.13
* Version:        3.1.1.2
*                 �����¶�ʱ�����˺���ķ�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.3.28
* Version:        3.1.3.1
*                 Ir_AdToTemp�����˷����ʲ����;������
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.4.6
* Version:        3.2.2.1
*                 �����˿ɼ����֡���ͣ��ںϿɼ���ͺ���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.5.11
* Version:        3.2.2.3
*                 ����FPGA����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.6.19
* Version:        3.2.3.4
*                 �������ಣ��͸���ʵ����ò���
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2012.11.26
* Version:        3.2.3.6
*                 �����˻�ȡAD������������Ir_GetAdBuffer
*                 ��������Ƶ����ص�����IrVideo_SetAdFilter
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.12.5
* Version:        3.2.4.1
*                 ������Ƶ���ص�����
* -------------------------------------------------------------------------------------------------
* Modifier/Date : 2013.1.5
* Version:        3.3.1.2
*                 �޸��˲��·�ʽ
* -------------------------------------------------------------------------------------------------
**************************************************************************************************/

#ifndef IR_SDK_INCLUDE_H
#define IR_SDK_INCLUDE_H

//#define IR_SDK_API __declspec(dllexport)
#define IR_SDK_API  __stdcall

#ifndef IR_TEMP_TYPE
typedef  float IR_TEMP_TYPE;          /*ʵ���¶�*/
#endif

#ifndef IR_TEMP_10FOLD_TYPE
typedef short IR_TEMP_10FOLD_TYPE;    /*ʵ���¶�*10 ����*/ 
#endif

#ifndef IR_TEMP_100FOLD_TYPE
typedef short IR_TEMP_100FOLD_TYPE;   /*ʵ���¶�*100 ����*/
#endif

#define IR288

/*ȱʡ����ͼ���С*/
#ifdef IR288
#define DEFAULT_IR_IMG_WIDTH   384
#define DEFAULT_IR_IMG_HEIGHT  288
#else
#define DEFAULT_IR_IMG_WIDTH   320
#define DEFAULT_IR_IMG_HEIGHT  240
#endif


/*�����¶�ת�����¶�*/
#define CDEGREE_TO_FDEGREE(fTemp)   (float)((fTemp)*1.8 + 32.0)

 // �����¶�ת���������¶�
#define  FDEGREE_TO_CDEGREE(fValue) (float)(((fValue) - 32.0 )/9.0 * 5.0)

/*�����¶�ת�����¶�*/
#define CDEGREE_TO_ABSOLUTE(fTemp)  (float)((fTemp) + 237.15)

#define ERROR_IR_FILE_PARA                   -1    /*�������ô���*/
#define ERROR_IR_FILE_NOT_EXIST              -2    /*�ļ�������*/
#define ERROR_IR_FILE_VERSION_NOT_SUPPORT    -3    /*�汾��֧��*/
#define ERROR_IR_FILE_READ_ERROR             -4    /*��д����*/
#define ERROR_IR_FILE_NO_MEM                 -5    /*û���ڴ�*/
#define ERROR_IR_FILE_NO_VOICE               -6    /*û������ע��*/
#define ERROR_IR_FILE_WRITE_ERROR            -7    /*д����*/
#define ERROR_IR_FILE_CORRUPT                -8    /*�ļ��ƻ���*/

/*USB�豸��ȡ*/
#define ERROR_USB_DEV_NOT_EXIST             -20   /*��USB�豸������*/
#define ERROR_USB_NO_ENOUGH_SPACE           -21   /*��ǰӲ�̿ռ䲻��*/
#define ERROR_USB_RECORD_AVI                -22   /*AVI¼��ʧ��*/

/****************************ͨ��IR�����ӿ�**********************************************/
/*��ȡ�汾��*/
DWORD IR_SDK_API Ir_GetVersion();

/*��ȡ����ͼ����Ƶ��USB��Ƶ��ͼ���С*/
int IR_SDK_API   Ir_GetWidth(long hIr);
int IR_SDK_API   Ir_GetHeight(long hIr);

/**********************************************************************************
* Function:      Ir_GetSaveTime
* Description:   ��ȡ����ͼ�����Ƶ�Ĳɼ�ʱ��
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        ��
* Return:        �����ļ�������ʱ��
* Notes:         ��ʱ����ļ��Ĵ���ʱ����ܲ�һ�£� 
************************************************************************************/
DWORD IR_SDK_API Ir_GetSaveTime(long hIr);

/**********************************************************************************
* Function:      Ir_GetAd
* Description:   ��ȡͼ������(x,y)������ӦֵAD,��AD�ǰ������ƽ��ֵ
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int x,y     ͼ���ϵ�����
* Output:        ��
* Return:        ������ӦAD������Ϊ����
************************************************************************************/
int IR_SDK_API   Ir_GetAd(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetAdBuffer
* Description:   ��ȡAD��������������Ƶ����
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        short** pAdBuffer  ���ص�AD������
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API   Ir_GetAdBuffer(long hIr,short** pAdBuffer);

/**********************************************************************************
* Function:      Ir_GetAd
* Description:   ��ȡͼ������(x,y)����ԭʼ��ӦֵAD
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int x,y     ͼ���ϵ�����
* Output:        ��
* Return:        ������ӦAD������Ϊ����
************************************************************************************/
int IR_SDK_API   Ir_GetOrignAd(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetBitmapBit
* Description:   ��ȡ(x,y)���ĻҶ�ֵ
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int x,y     ͼ���ϵ�����
* Output:        ��
* Return:        ��ӦֵADӳ��ĻҶ�ֵ
* Notes:         ���ڶԱȶȺ����Ȼ�Ӱ���ֵ   
************************************************************************************/
BYTE IR_SDK_API Ir_GetBitmapBit(long hIr,int x,int y);

/**********************************************************************************
* Function:      Ir_GetTemperature
* Description:   ��ȡ(x,y)�����¶�ֵ
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int x,y     ͼ���ϵ�����
*                int iEmiss  �����ʣ�Ĭ��Ϊ98
*                int iDistance ���룬Ĭ��Ϊ14
* Output:        ��
* Return:        ���괦���¶�ֵ��С���㾫��ֻ��1λ
************************************************************************************/
IR_TEMP_TYPE IR_SDK_API Ir_GetTemperature(long hIr,int x,int y,int iEmiss=98,int iDistance=14);

IR_TEMP_TYPE IR_SDK_API Ir_GetTemperature_Test(long hIr,int x,int y,float fcoef,int iConst);

/**********************************************************************************
* Function:      Ir_AdToTemp
* Description:   ����ӦֵAD�����¶�
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                short sAd   ������Ӧֵ
*                int iEmiss  �����ʣ�Ĭ��Ϊ98
*                int iDistance ���룬Ĭ��Ϊ14
* Output:        float *pTemp ���ؼ�����¶�
* Return:        ���������ȷ���򷵻�TRUE,���򷵻�FALSE,��ʱpTemp�ķ���ֵ��Ч
************************************************************************************/
 BOOL IR_SDK_API Ir_AdToTemp(long hIr,short sAd,IR_TEMP_TYPE *pTemp,int iEmiss=98,int iDistance=14);


/**********************************************************************************
* Function:      Ir_GetRGB
* Description:   ��ȡ(x,y)����RGBֵ
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int x,y     ͼ���ϵ�����
* Output:        ��
* Return:        ͼ�������RGBֵ������alphaͨ��û�ã�����ɫ�ǵ�ɫ����ɫ�������ߡ��澯ɫӳ���
* Notes:         ֮ǰ��ʾ�����ͼ����߱���ת��   
************************************************************************************/
RGBQUAD IR_SDK_API Ir_GetRGB(long hIr,int x,int y);

/************************���²���**************************************************/
/*��ȡ�����ÿ����¶�*/
IR_TEMP_TYPE IR_SDK_API Ir_GetShutterTemp(long hIr);
void IR_SDK_API  Ir_SetShutterTemp(long hIr,IR_TEMP_TYPE fTemp);

/*��ȡ�����ô����¶�*/
void IR_SDK_API  Ir_SetAtmosTemp(long hIr,IR_TEMP_TYPE fTemp);
IR_TEMP_TYPE IR_SDK_API Ir_GetAtmosTemp(long hIr);

/*��ȡ��ƽ���¶�*/
IR_TEMP_TYPE IR_SDK_API Ir_GetFPATemp(long hIr);

/*��ȡ�����¶�*/
IR_TEMP_TYPE IR_SDK_API Ir_GetBoardTemp(long hIr);

/*��ȡ�����þ�Ͳ�¶�*/
void IR_SDK_API  Ir_SetBarrelTemp(long hIr,IR_TEMP_TYPE fTemp);
IR_TEMP_TYPE IR_SDK_API Ir_GetBarrelTemp(long hIr);

/*��ȡ�����÷�����*/
int IR_SDK_API   Ir_GetEmiss(long hIr);
void IR_SDK_API  Ir_SetEmiss(long hIr,int iEmiss);

/*��ȡ������ʪ��*/
int  IR_SDK_API  Ir_GetRelHum(long hIr);
void IR_SDK_API  Ir_SetRelHum(long hIr,int iHum);

WORD IR_SDK_API  Ir_GetCorrectCoef(long hIr);
void IR_SDK_API  Ir_SetCorrectCoef(long hIr,WORD wCoef);

int  IR_SDK_API  Ir_GetFrameType(long hIr);


/**********************************************************************************
* Function:      Ir_LoadPara
* Description:   ���ļ���ȡ���²���
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                char* FileName ���²����ļ���
* Output:        ��
* Return:        �����ļ�����ɹ�����TRUE,���򷵻�FALSE
* Notes:         �ú������ã�һ����Ӧ�ó����ж�ȡ���ú�Щ
* Usage:         �����ļ�����ini�ļ�����������ini�ļ��е�һ��section,ע�����Ʊ���һ��
*                   [PARA]
*                   ATMOS_TEMP=19.2
*                   SHUTTER_TEMP=19.2
*                   EMISS=98
*                   HUM=70
************************************************************************************/
BOOL IR_SDK_API  Ir_LoadPara(long hIr,char* FileName);

#define BYTE_REL_HUM       0x0001  /*ʪ��*/
#define BYTE_EMISS         0x0002  /*������*/
#define BYTE_CORRECT_COEF  0x0004  /*У��ϵ��*/
#define BYTE_DISTANCE      0x0008  /*����*/
#define BYTE_TRANSMISSION  0x0010  /*��͸��*/

typedef struct __TempMeasurePara
{
	/*������������*/
	DWORD dwFlag;

	/*У������*/
	long lRelHum;
	long lEmiss;
	long lCorrectCoef;
	long lDistance;
	long lTransmiss;
	

}tTempMeasurePara;

/**********************************************************************************
* Function:      Ir_SetMeasurePara
* Description:   ���ò���У��ϵ��
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                tTempMeasurePara *pPara ����У��ϵ��
* Output:        ��
* Return:        ���óɹ�����TRUE������ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_SetMeasurePara(long hIr,tTempMeasurePara *pPara);

/**********************************************************************************
* Function:      Ir_GetMeasurePara
* Description:   ��ȡ����У��ϵ��
* Input:         long hIr    �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        tTempMeasurePara *pPara ����У��ϵ��
* Return:        �ɹ���ȡ����TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_GetMeasurePara(long hIr,tTempMeasurePara *pPara);


/************************���²���(END)**********************************************/

/**********************************************************************************
* Function:      Ir_LoadCurve
* Description:   ���ļ���ȡ�豸����
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                char* FileName �豸�����ļ���
* Output:        ��
* Return:        �豸�����ļ�����ɹ�����TRUE,���򷵻�FALSE
* Notes:         һ�㱣���ͼ���ļ�����Ƶ�ļ��а����豸����������Ҫ����
*                    �������������豸�������£����Ե��������豸�����ļ����ú���������
*                USB�ɼ���Ƶ��Ҫ�����¶�����
************************************************************************************/
BOOL IR_SDK_API  Ir_LoadCurve(long hIr,char* FileName);

/*��ȡ�����õ�ɫ�壬��ɫ�����֧��9��*/
int IR_SDK_API   Ir_GetPaletteId(long hIr);
int IR_SDK_API   Ir_SetPaletteId(long hIr,int iPalette);

/**********************************************************************************
* Function:      Ir_GetPaletteData
* Description:   ��ȡָ��������ϵͳ��ɫ������
* Input:         int iPalette ��ɫ���������Ǹ���������С��9
* Output:        ��
* Return:        ��ȡ��ɫ������RGBQUAD,Ϊ255��
* Notes:         ���������������
************************************************************************************/
RGBQUAD* IR_SDK_API Ir_GetPaletteData(int iPalette);

/**********************************************************************************
* Function:      Ir_SetAutoMapMode
* Description:   ����ADӳ��Ϊ�Ҷ�ͼ�����Զ���ʽ�����ֶ���ʽ
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                BOOL bMode     �Զ���ʽΪTRUE,�ֶ���ʽΪFALSE
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  Ir_SetAutoMapMode(long hIr,BOOL bMode);

/**********************************************************************************
* Function:      Ir_GetAutoMapMode
* Description:   ��ȡADӳ��Ϊ�Ҷ�ͼ�ķ�ʽ�����Զ���ʽ�����ֶ���ʽ
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        ��
* Return:        �Զ���ʽ����TRUE,�ֶ���ʽ����FALSE
************************************************************************************/
BOOL IR_SDK_API  Ir_GetAutoMapMode(long hIr);

/**********************************************************************************
* Function:      Ir_Light
* Description:   �������ȺͶԱȶ�
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int brightness ���ȣ���Χ -100~100
*                int contrast   �Աȶȣ���Χ-200~200
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  Ir_Light(long hIr,int brightness,int contrast);

/**********************************************************************************
* Function:      Ir_GetBrightness
* Description:   ��ȡ���õ�����
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        ��
* Return:        ����ֵ
************************************************************************************/
int IR_SDK_API   Ir_GetBrightness(long hIr);

/**********************************************************************************
* Function:      Ir_GetContrast
* Description:   ��ȡ���õĶԱȶ�
* Input:         long hIr       �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        ��
* Return:        �Աȶ�
************************************************************************************/
int IR_SDK_API   Ir_GetContrast(long hIr);

/**********************************************************************************
* Function:      Ir_GetTestAd
* Description:   ��ȡ�ο�λ�ú;���ADֵ
* Input:         long hIrStream       ��Ƶ�ļ�\USB��Ƶ\������Ƶ�����
* Output:        int *x,int *y        ��ȡ�ο�λ������
*                int *sAd             ��ȡ�ο�λ�õľ���AD
* Return:        ��ȡ�ɹ�����TRUE��ʧ�ܷ���FALSE
* Usages:        ֻ���ڲ����У�ʵ�ʵĲ�Ʒ�иù��ܹر�
************************************************************************************/
BOOL IR_SDK_API  Ir_GetTestAd(long hIrStream,int *x,int *y,int *sAd);


/*���õ����ߣ�ͨ�������߿���ʵ�ֱ���ɫ*/
typedef struct tagIsothermColor
{
	COLORREF  colorMap;   /*��ɫӳ��*/
	IR_TEMP_10FOLD_TYPE	iMaxTemp;         /*������ֵ��0xFFFF��ʾ������*/
	IR_TEMP_10FOLD_TYPE iMinTemp;         /*���·�ֵ��0xFFFF��ʾ������*/
} tIsoThermColorMap;      /*������*/

/**********************************************************************************
* Function:      Ir_SetIsoThermColorMap
* Description:   ���õ���������
* Input:         long hIr      �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                tIsoThermColorMap* pIsoThermColorList    �������б�
*                     ÿ���ڵ��ʾ�¶���iMinTemp��iMinTemp��Χ�ڵĲ�����ɫcolorMap
*                int iNum  �����ߵĸ���        
* Output:        ��
* Return:        ��
* Usages:        ���ֻ������20�������
*                ÿ�������߽ڵ���iMaxTemp��iMinTemp����ʾ�¶�*10�����ֵΪ0xFFFF��
*                    ��ʾ��ֵ��Ч�������ø����޻�����
*                ��������ɫ���滻����ɫ����¶�ɫ�����ɫ�������ȼ����
************************************************************************************/
void IR_SDK_API Ir_SetIsoThermColorMap(long hIr,tIsoThermColorMap* pIsoThermColorList,int iNum );

/**********************************************************************************
* Function:      Ir_SetColorScale
* Description:   ������ɫ�±꣬�����¶Ȳü���ɫ��Χ
* Input:         long hIr      �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
*                int  iMinTemp �¶�*10,��ʾ�¶����ޣ������¶Ȳ��õ�ɫ���лҶ�0��Ӧ����ɫ
*                int  iMaxTemp �¶�*10,��ʾ�¶����ޣ����ڸ��¶Ȳ��õ�ɫ���лҶ�255��Ӧ����ɫ
* Output:        ��
* Return:        ��
* Notes:         ��ɫ���ȼ����ڵ�ɫ�壬���ڵ����� 
************************************************************************************/
void IR_SDK_API Ir_SetColorScale(long hIr,IR_TEMP_10FOLD_TYPE iMinTemp,IR_TEMP_10FOLD_TYPE iMaxTemp);


/**********************************************************************************
* Function:      Ir_RemoveCover
* Description:   ȥ������
* Input:         long hIr      �������������Ǻ���ͼ����Ƶ�ļ���USB��Ƶ
* Output:        ��
* Return:        �ɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API Ir_RemoveCover(long hIr);

/**********************************************************************************
* Function:      Ir_SetMeasureObject
* Description:   ����ͼ�������Ӳ��¶��󻺳���
* Input:         long hIrImage    ����ͼ����
*                unsigned char *pObjectBuf  ������󻺳���
*                int iBufSize     ������󻺳�����С
* Output:        ��
* Return:        ��
* Notes:         SDKû�жԸû���������Ԥ�����ýṹ�����û����ж��ƺͽ���
************************************************************************************/
void IR_SDK_API  Ir_SetMeasureObject(long hIrImage,unsigned char *pObjectBuf,int iBufSize);

/**********************************************************************************
* Function:      Ir_GetMeasureObject
* Description:   �Ӻ���ͼ���л�ȡ���¶��󻺳���
* Input:         long hIrImage    ����ͼ����             
* Output:        unsigned char *pObjectBuf  ������󻺳���
*                int iBufSize     ������󻺳�����С
* Return:        ��ȡ�ɹ�����TRUE,ʧ�ܷ���FALSE
* Notes:         SDKû�жԸû���������Ԥ�����ýṹ�����û����ж��ƺͽ���
************************************************************************************/
BOOL IR_SDK_API  Ir_GetMeasureObject(long hIrImage,unsigned  char* pObjectBuf,int* pBufSize);


/****************************************************************************************/

/****************************IR��Ƶ�ļ�*************************************************/

/**********************************************************************************
* Function:      IrVideo_Open
* Description:   �򿪺�����Ƶ�ļ�
* Input:         char *filename  ��Ƶ�ļ���
* Output:        ��
* Return:        ����򿪳ɹ�����ֵ>0������ֵΪ������Ƶ�ľ��,
*                ���ʧ�ܷ��ظ���,�ɲ��Ҵ�����
************************************************************************************/
long IR_SDK_API  IrVideo_Open(char *filename);

#define IR_VIDEO_FILE_TYPE_NORMAL           0  /*δѹ��*/
#define IR_VIDEO_FILE_TYPE_COMPRESS_SINGLE  1  /*��֡ѹ��*/
#define IR_VIDEO_FILE_TYPE_COMPRESS_DIFF    2  /*��֡ѹ��*/
/**********************************************************************************
* Function:      IrVideo_Convert
* Description:   ���ں�����Ƶ���ļ�����ת�� 
* Input:         char *src_file  Ҫת����Դ��Ƶ�ļ��� 
*                char* dst_file  Ҫת����Ŀ����Ƶ�ļ��� 
*                int   type      Ҫת����Ŀ����Ƶ�ļ����� 
* Output:        char* dst_file  ����Ŀ���ļ� 
* Return:        ת���ɹ�����TRUE,ʧ�ܷ���FALSE 
* Notes:         Դ�ļ�������δѹ���ģ�Ŀ���ļ������Ƿ�ѹ���� 
************************************************************************************/
BOOL IR_SDK_API IrVideo_Convert(char* src_file,char* dst_file,int type);


typedef void (*OwnerDrawCB)(HDC hdc,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetOwnerDraw
* Description:   ������Ƶ�ĵ��ӣ���������Ƶ�ϵ��ӷ���ͼ��
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                OwnerDrawCB BeforeDrawFunc  ��������Ƶ��ʾ֮ǰ���л�ͼ��������֮��ģ�
*                           ����ò��ûᵼ����˸�����ã����Ҫʹ�ã�����memdc
*                OwnerDrawCB AfterDrawFunc ������Ƶ��ʾ֮����е��ӻ�ͼ��������������
*                long lPrivate ��ͼ�ص�������˽�����ݣ��ڻص�����ʱ�����ص�����������Ϊ��ͼ
* Output:        ��
* Return:        ��
* Notes:         �����ͼ��һ���ؼ��ϲ��ţ����Լ��������Ĳ��裬�����view�ϲ��ţ���Ҫ����
*                    ��������
************************************************************************************/
void IR_SDK_API  IrVideo_SetOwnerDraw(long hFilePlayer,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);

typedef void (*AdFilterCB)(HDC hdc,short* pAd,int iWidth,int iHeight,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetAdFilter
* Description:   ����AD���˴���ص�
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                AdFilterCB filterCB  �㷨ʹ�ûص�
*                long lPrivate        �ص��������õ�˽������   
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API IrVideo_SetAdFilter(long hFilePlayer,AdFilterCB filterCB,long lPrivate);

/**********************************************************************************
* Function:      IrVideo_SetDrawPos
* Description:   ������Ƶ��ʾ��λ��
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                HDC hdc    ��Ƶ���ŵ�DC���
*                long x=0,long y=0   ��Ƶ���ŵ����Ͻǵ�λ��
*                long cx=-1,long cy=-1 ��Ƶ���ŵ���ʾ���ڴ�С���������Ĭ�ϵģ�����Ƶ
*                    ��������ʾ�������ʾ����С��һ������Ƶ���ڴ�����滭
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrVideo_SetDrawPos(long hFilePlayer,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);

/**********************************************************************************
* Function:      IrVideo_AutoPlay
* Description:   ��Ƶ��ʼ����
* Input:         long hFilePlayer     ������Ƶ�ļ����
* Output:        ��
* Return:        ���������ŷ���TRUE,���򷵻�FALSE
* Notes:         �ڸò���֮ǰ����������ʾ��λ�ã������ú�������Ƶ�ͻ���ָ���Ĵ��ڿ�ʼ������
*                ���ź�Ҳ�ܶ�̬������ʾ��λ�ã�����IrVideo_SetDrawPos
************************************************************************************/
BOOL IR_SDK_API  IrVideo_AutoPlay(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_Close
* Description:   �ر���Ƶ�ļ����ͷ���Ӧ����Դ
* Input:         long hFilePlayer     ������Ƶ�ļ����
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrVideo_Close(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_GetTotalFrame
* Description:   ��ȡ��Ƶ�ļ���֡��
* Input:         long hFilePlayer     ������Ƶ�ļ����
* Output:        ��
* Return:        ��Ƶ�ļ���֡������ȡʧ�ܣ�����
************************************************************************************/
int IR_SDK_API   IrVideo_GetTotalFrame(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_GetCurFrame
* Description:   ��ȡ��Ƶ�ļ����ڲ��ŵ�֡����һ������״̬����ʾ
* Input:         long hFilePlayer     ������Ƶ�ļ����
* Output:        ��
* Return:        ��ǰ֡�����û�в��ţ�����0
************************************************************************************/
int IR_SDK_API   IrVideo_GetCurFrame(long hFilePlayer);

/**********************************************************************************
* Function:      IrVideo_CapturePic
* Description:   ����Ƶ�нػ�ͼ��
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                char* filepath       Ҫ�����ͼ����
* Output:        ��
* Return:        ����ɹ�������0������Ϊ����
* Usages:        ͼ���ļ���������bmp��jpg,�����bmp�����ܲ��£�ֻ��jpg�ļ��ܽ��в���
************************************************************************************/
int IR_SDK_API   IrVideo_CapturePic(long hFilePlayer,char* filepath);


/*IR��Ƶ���ſ���*/
enum eIrPlayMode
{
	IR_FILE_NOINIT = 0,
	IR_FILE_NOPLAY ,          /*����Ƶ״̬*/
	IR_FILE_PLAYING,          /*��ͨ����״̬*/
	IR_FILE_PAUSE,            /*��ͣ״̬*/
	IR_FILE_FWORD,		      /*���*/
	IR_FILE_BACK,			  /*����*/
	IR_FILE_SLOW,             /*����*/
	IR_FILE_FAST,             /*���*/

	IR_FILE_PLAYSEEK,         /*���ֲ���״̬�µĶ�λ����,���벥�ű�*/
	IR_FILE_FWORDSEEK,
	IR_FILE_BACKSEEK,
	IR_FILE_FASTSEEK,
	IR_FILE_SLOWSEEK,

	IR_FILE_SOLE,
	IR_FILE_SOLESEEK
};

/**********************************************************************************
* Function:      IrVideo_Control
* Description:   �Բ��ŵĺ�����Ƶ���п���
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                eIrPlayMode playmode ���ſ���ģʽ
*                long para            ���ſ��Ʋ���
* Output:        ��
*                ��
* Return:        ���Ƴɹ�����0��ʧ�ܷ���-1
* Usages:        eIrPlayMode ��ʾ��������
*                IR_FILE_PLAYING��IR_FILE_FAST��IR_FILE_SLOW
*                	 para���ڲ����ٶȿ���(�첥����������������)
*
*                ����IR_FILE_BACK��IR_FILE_FWORD��Ч 
*                para���ڲ��ŵķ������(���������),δʵ��
*                   
*                SEEK�������Ч
*                para���ڲ���Ѱ֡�����ŵİٷֱ�*100
*
************************************************************************************/
int IR_SDK_API   IrVideo_Control(long hFilePlayer,eIrPlayMode playmode,long para =1);
/****************************IR��Ƶ�ļ�(END)*********************************************/


/****************************IR��Ƶ������*************************************************/

/**********************************************************************************
* Function:      IrStream_Create
* Description:   ����������Ƶ��
* Input:         
*                int   iWidth    ����ͼ����
*                int   iHeight   ����ͼ��߶�
* Output:        ��
* Return:        ��������ɹ�����ֵ>0������ֵΪ������Ƶ�ľ��,���򷵻�-1
************************************************************************************/
long IR_SDK_API  IrStream_Create(int iWidth,int iHeight);


/**********************************************************************************
* Function:      IrStream_SetOwnerDraw
* Description:   ������Ƶ�ĵ��ӣ���������Ƶ�ϵ��ӷ���ͼ��
* Input:         long hIrStream     ������Ƶ�����
*                OwnerDrawCB BeforeDrawFunc  ��������Ƶ��ʾ֮ǰ���л�ͼ��������֮��ģ�
*                           ����ò��ûᵼ����˸�����ã����Ҫʹ�ã�����memdc
*                OwnerDrawCB AfterDrawFunc ������Ƶ��ʾ֮����е��ӻ�ͼ��������������
*                long lPrivate ��ͼ�ص�������˽�����ݣ��ڻص�����ʱ�����ص�����������Ϊ��ͼ
* Output:        ��
* Return:        ��
* Notes:         �����ͼ��һ���ؼ��ϲ��ţ����Լ��������Ĳ��裬�����view�ϲ��ţ���Ҫ����
*                    ��������
************************************************************************************/
void IR_SDK_API  IrStream_SetOwnerDraw(long hIrStream,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);




/**********************************************************************************
* Function:      IrStream_SetAdFilter
* Description:   ����AD���˴���ص�
* Input:         long hFilePlayer     ������Ƶ�ļ����
*                AdFilterCB filterCB  �㷨ʹ�ûص�
*                long lPrivate        �ص��������õ�˽������   
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API IrStream_SetAdFilter(long hFilePlayer,AdFilterCB filterCB,long lPrivate);

/**********************************************************************************
* Function:      IrStream_SetDrawPos
* Description:   ������Ƶ��ʾ��λ��
* Input:         long hIrStream      ������Ƶ�����
*                HDC hdc             ��Ƶ���ŵ�DC���
*                long x=0,long y=0   ��Ƶ���ŵ����Ͻǵ�λ��
*                long cx=-1,long cy=-1 ��Ƶ���ŵ���ʾ���ڴ�С���������Ĭ�ϵģ�����Ƶ
*                    ��������ʾ�������ʾ����С��һ������Ƶ���ڴ�����滭
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrStream_SetDrawPos(long hIrStream,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);


/**********************************************************************************
* Function:      IrStream_Close
* Description:   �ر���Ƶ���ļ����ͷ���Ӧ����Դ
* Input:         long hIrStream   ������Ƶ�����
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrStream_Close(long hIrStream);

/**********************************************************************************
* Function:      IrStream_InputData
* Description:   ������Ƶ�����ݣ������֡���ݿ���������ʾ
* Input:         long hIrStream   ������Ƶ�����
*                void *pData      ������Y16ͼ�����һ�е���Ƶ����
*                unsigned int len ֡����
*                unsigned int ts  ֡���ݵ�ʱ���
* Output:        ��
* Return:        �������ݳɹ�����TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrStream_InputData(long hIrStream,void *pData,unsigned int len,unsigned int ts=0 );

/**********************************************************************************
* Function:      IrStream_GetTotalFrame
* Description:   ��ȡ�Ѿ����ŵ���Ƶ����֡��
* Input:         long hIrStream   ������Ƶ�����
* Output:        ��
* Return:        ��Ƶ�ļ���֡������ȡʧ�ܣ�����
************************************************************************************/
int IR_SDK_API   IrStream_GetTotalFrame(long hIrStream);


/**********************************************************************************
* Function:      IrStream_CapturePic
* Description:   ����Ƶ�нػ�ͼ��
* Input:         long hIrStream  ������Ƶ�����
*                char* filepath  Ҫ�����ͼ����
* Output:        ��
* Return:        ����ɹ�������0������Ϊ����
* Usages:        ͼ���ļ���������bmp��jpg,�����bmp�����ܲ��£�ֻ��jpg�ļ��ܽ��в���
************************************************************************************/
int IR_SDK_API   IrStream_CapturePic(long hIrStream,char* filepath);


/**********************************************************************************
* Function:      IrStream_StartRecord
* Description:   �Ӻ�����Ƶ����ʼ¼��
* Input:         long hIrStream   ������Ƶ�����
*                char* FileName   ¼���ļ���
* Output:        ��
* Return:        ����¼��ɹ�����0�����򷵻ظ��������Բ鿴������
************************************************************************************/
int IR_SDK_API   IrStream_StartRecord(long hIrStream, char* FileName);

/**********************************************************************************
* Function:      IrUsb_StopRecord
* Description:   ֹͣ������¼��
* Input:         long hIrStream   ������Ƶ�����
* Output:        ��
* Return:        �رճɹ�����0�����򷵻�-1
************************************************************************************/
int IR_SDK_API   IrStream_StopRecord (long hIrStream);


/****************************USB��ȡIR��Ƶ***********************************************/

/**********************************************************************************
* Function:      IrUsb_Open
* Description:   ��USB�豸
* Input:         char *devName           USB�豸������Ezusb��ʼ
*                int iWidth,int iHeight  USB��Ƶ�ߴ��С
* Output:        ��
* Return:        �򿪳ɹ�����USB��������򷵻�-1
************************************************************************************/
long IR_SDK_API  IrUsb_Open(char *devName,int iWidth,int iHeight);

/**********************************************************************************
* Function:      IrUsb_SetOwnerDraw
* Description:   ������Ƶ�ĵ��ӣ���������Ƶ�ϵ��ӷ���ͼ��
* Input:         long hUsbVideo     USB�豸���
*                OwnerDrawCB BeforeDrawFunc  ��������Ƶ��ʾ֮ǰ���л�ͼ��������֮��ģ�
*                           ����ò��ûᵼ����˸�����ã����Ҫʹ�ã�����memdc
*                OwnerDrawCB AfterDrawFunc ������Ƶ��ʾ֮����е��ӻ�ͼ��������������
*                long lPrivate ��ͼ�ص�������˽�����ݣ��ڻص�����ʱ�����ص�����������Ϊ��ͼ
* Output:        ��
* Return:        ��
* Notes:         �����ͼ��һ���ؼ��ϲ��ţ����Լ��������Ĳ��裬�����view�ϲ��ţ���Ҫ����
*                    ��������
************************************************************************************/
void IR_SDK_API  IrUsb_SetOwnerDraw(long hUsbVideo,OwnerDrawCB BeforeDrawFunc,OwnerDrawCB AfterDrawFunc,long lPrivate=0);

/**********************************************************************************
* Function:      IrUsb_SetDrawPos
* Description:   ������Ƶ��ʾ��λ��
* Input:         long hUsbVideo     USB�豸���
*                HDC hdc    ��Ƶ���ŵ�DC���
*                long x=0,long y=0   ��Ƶ���ŵ����Ͻǵ�λ��
*                long cx=-1,long cy=-1 ��Ƶ���ŵ���ʾ���ڴ�С���������Ĭ�ϵģ�����Ƶ
*                    ��������ʾ�������ʾ����С��һ������Ƶ���ڴ�����滭
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrUsb_SetDrawPos(long hUsbVideo,HDC hdc,long x=0,long y=0,long cx=-1,long cy=-1);

/**********************************************************************************
* Function:      IrUsb_AutoPlay
* Description:   USB��ʼ�ɼ�
* Input:         long hUsbVideo     USB�豸���
* Output:        ��
* Return:        ���������ŷ���TRUE,���򷵻�FALSE
* Notes:         �ڸò���֮ǰ����������ʾ��λ�ã������ú�������Ƶ�ͻ���ָ���Ĵ��ڿ�ʼ������
*                ���ź�Ҳ�ܶ�̬������ʾ��λ�ã�����IrUsb_SetDrawPos
************************************************************************************/
BOOL IR_SDK_API  IrUsb_AutoPlay(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_Close
* Description:   �ر�USB�豸
* Input:         long hUsbVideo   USB�豸���
* Output:        ��
* Return:        �رճɹ�����0�����򷵻�-1
************************************************************************************/
int IR_SDK_API   IrUsb_Close(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_CapturePic
* Description:   ����Ƶ�нػ�ͼ��
* Input:         long hUsbVideo   USB�豸���
*                char* filepath       Ҫ�����ͼ����
* Output:        ��
* Return:        ����ɹ�������0������Ϊ����
* Usages:        ͼ���ļ���������bmp��jpg,�����bmp�����ܲ��£�ֻ��jpg�ļ��ܽ��в���
************************************************************************************/
int IR_SDK_API   IrUsb_CapturePic(long hUsbVideo,char* filepath);

/**********************************************************************************
* Function:      IrUsb_StartRecord
* Description:   ��ʼ¼��
* Input:         long hUsbVideo   USB�豸���
*                char* FileName   ¼���ļ���
* Output:        ��
* Return:        ����¼��ɹ�����0�����򷵻ظ��������Բ鿴������
************************************************************************************/
int IR_SDK_API   IrUsb_StartRecord(long hUsbVideo, char* FileName);

/**********************************************************************************
* Function:      IrUsb_StopRecord
* Description:   ֹͣ¼��
* Input:         long hUsbVideo   USB�豸���
* Output:        ��
* Return:        �رճɹ�����0�����򷵻�-1
************************************************************************************/
int IR_SDK_API   IrUsb_StopRecord (long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_GetTotalFrame
* Description:   ��ȡ�Ѿ�¼�����֡��
* Input:         long hUsbVideo   USB�豸���
* Output:        ��
* Return:        �Ѿ�¼�����֡��
* Usages:        ����ͨ��֡��������ÿ����Ƶ�ļ���֡��������һ����֡���ش���һ���ļ�¼
************************************************************************************/
int IR_SDK_API   IrUsb_GetTotalFrame(long hUsbVideo);

/**********************************************************************************
* Function:      IrUsb_GetTotalSize
* Description:   ��ȡ�Ѿ�¼���ļ����ܴ�С
* Input:         long hUsbVideo   USB�豸���
* Output:        ��
* Return:        �Ѿ�¼���ļ��Ĵ�С
* Usages:        ����ͨ��֡��������ÿ����Ƶ�ļ����ļ���С������һ���Ĵ�С�ش���һ���ļ�¼
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
* Description:   ͨ��USB�����ƺ��������
* Input:         long hUsbVideo   USB�豸���
*                eIrCmd cmd       �����������
*                int para1=0,int para2=0 ����Ӳ���
* Output:        ��
* Return:        ���Ƴɹ�����0��ʧ�ܷ���-1
* Usages:        ��ҪUSB�ɼ�����֧��USB�ϴ����ù�����ʱû��
************************************************************************************/
int IR_SDK_API IrUsb_Control(long hUsbVideo,eIrCmd cmd,int para1=0,int para2=0);
/****************************USB��Ƶ(END)***********************************************/



/****************************IRͼ����**************************************************/
/**********************************************************************************
* Function:      IrImage_IsIr
* Description:   �ж��Ƿ��Ǻ���ͼ����Ϊ�����ͼ����õ�Ϊͨ��jpg�ļ�����Ҫ��һ��jpg�ļ����ֿ�
* Input:         char *filename  ͼ���ļ���
* Output:        ��
* Return:        ����Ǻ���ͼ�񷵻�TRUE,������Ƿ���FALSE
* Notes:         ֻ��jpg�ļ���Ч
************************************************************************************/
BOOL IR_SDK_API  IrImage_IsIr(char *filename);

/**********************************************************************************
* Function:      IrImage_Open
* Description:   �򿪺���ͼ��
* Input:         char *filename  ͼ���ļ���
* Output:        ��
* Return:        ����򿪳ɹ����򷵻غ���ͼ����������-1
* Notes:         ֻ��jpg�ļ���Ч
************************************************************************************/
long IR_SDK_API  IrImage_Open(char *filename);

/**********************************************************************************
* Function:      IrImage_Save
* Description:   �������ͼ�񣬸��µ�ǰ����ͼ������Ϊ
* Input:         long hIrImage    ����ͼ����
*                char *filename   Ҫ�����ͼ���ļ���
* Output:        ��
* Return:        ����ɹ�������0������Ϊ����
* Usages:        �Բ��²������¶����ߡ����¶����޸��ˣ��Ϳɵ��øú��������£���չ��Ϊjpg
************************************************************************************/
int IR_SDK_API   IrImage_Save(long hIrImage,char *filename);

/**********************************************************************************
* Function:      IrImage_Close
* Description:   �رպ����ļ����ͷ���Ӧ��Դ
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrImage_Close(long hIrImage);

/**********************************************************************************
* Function:      IrImage_DrawIr
* Description:   ��ָ�����ڻ���ͼ��ƽ���ƶ�����
* Input:         long hIrImage    ����ͼ����
*                long hDrawWnd    Ҫ����ͼ��Ĵ��ھ��
* Output:        ��
* Return:        ��
* Notes:         ���Ƶ�ͼ���������������������
************************************************************************************/
void IR_SDK_API  IrImage_DrawIr(long hIrImage,long hDrawWnd);

/**********************************************************************************
* Function:      IrImage_DrawIr
* Description:   ָ����HDC��ָ����λ�û�ͼ
* Input:         long hIrImage    ����ͼ����
*                HDC hdc          Ҫ��ͼ��CDC�ľ��
*                long x,y         ��CDC�ϻ�ͼ����ʼλ��
*                long cx,cy       CDC�ϻ�ͼ�Ŀ�Ⱥ͸߶�
* Output:        ��
* Return:        ��
* Notes:         �����ָ��cx,cy����ͼ����ͼ��ԭʼ��С���ƣ����Գ���CDC�ķ�Χ
************************************************************************************/
void IR_SDK_API  IrImage_DrawIrEx(long hIrImage,HDC hdc, long x=0, long y=0, long cx = -1, long cy = -1);

/**********************************************************************************
* Function:      IrImage_PlayVoice
* Description:   ��������ע��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ���������ע�ͣ����������ţ��򷵻�0�����򷵻ظ���
************************************************************************************/
int IR_SDK_API   IrImage_PlayVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_StopVoice
* Description:   ֹͣ��������ע��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ��
* Notes:         ���������ע���ڲ��ţ���ֹͣ���������κβ���
************************************************************************************/
void IR_SDK_API  IrImage_StopVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_HasVoice
* Description:   �ж�����ͼ���Ƿ��������ע��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ������ע�ͷ���TRUE,���򷵻�FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasVoice(long hIrImage);

/**********************************************************************************
* Function:      IrImage_InsertVoiceComment
* Description:   ������ͼ���в�������ע��
* Input:         long hIrImage    ����ͼ����
*                char *fileName   ����ע���ļ�
* Output:        ��
* Return:        ��������ע�ͳɹ�����TRUE,���򷵻�FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_InsertVoiceComment(long hIrImage,char *fileName);

/**********************************************************************************
* Function:      IrImage_HasTextComment
* Description:   �жϺ���ͼ���Ƿ����ı�ע��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ���ı�ע�ͷ���TRUE,���򷵻�FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasTextComment(long hIrImage);

/**********************************************************************************
* Function:      IrImage_InsertTextComment
* Description:   ������ͼ���в����ı�ע��
* Input:         long hIrImage    ����ͼ����
*                char *pText      �ı�ע��
* Output:        ��
* Return:        �����ı�ע�ͳɹ�����TRUE,���򷵻�FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_InsertTextComment(long hIrImage,char *pText);

/**********************************************************************************
* Function:      IrImage_GetTextComment
* Description:   ��ȡ����ͼ���е��ı�ע��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        ������ı�ע�ͣ��򷵻��ı������򷵻�NULL
************************************************************************************/
char* IR_SDK_API IrImage_GetTextComment(long hIrImage);

/**********************************************************************************
* Function:      IrImage_HasVLImage
* Description:   �жϺ���ͼ���Ƿ��пɼ���ͼ��
* Input:         long hIrImage    ����ͼ����
* Output:        ��
* Return:        �пɼ���ͼ�񷵻�TRUE,���򷵻�FALSE
************************************************************************************/
BOOL IR_SDK_API  IrImage_HasVLImage(long hIrImage);

/**********************************************************************************
* Function:      IrImage_GetVLSize
* Description:   ��ȡ�ɼ���ͼ��Ĵ�С�ߴ�
* Input:         long hIrImage     ����ͼ����
* Output:        int *pImageWidth  �ɼ���ͼ��Ŀ��
*                int *pImageHeight �ɼ���ͼ��ĸ߶�
* Return:        �����ȡ�ɹ����򷵻�0�����򷵻�-1
************************************************************************************/
int IR_SDK_API   IrImage_GetVLSize(long hIrImage,int *pImageWidth,int *pImageHeight);

/**********************************************************************************
* Function:      IrImage_DrawVL
* Description:   ���ƶ����ڻ���ͼ��ƽ���ƶ�����
* Input:         long hIrImage    ����ͼ����
*                long hDrawWnd    Ҫ����ͼ��Ĵ��ھ��
* Output:        ��
* Return:        ��
* Notes:         ���Ƶ�ͼ���������������������
************************************************************************************/
void IR_SDK_API  IrImage_DrawVL(long hIrImage,long hDrawWnd);

/**********************************************************************************
* Function:      IrImage_DrawVL
* Description:   �ƶ���HDC���ƶ���λ�û�ͼ
* Input:         long hIrImage    ����ͼ����
*                HDC hdc          Ҫ��ͼ��CDC�ľ��
*                long x,y         ��CDC�ϻ�ͼ����ʼλ��
*                long cx,cy       CDC�ϻ�ͼ�Ŀ�Ⱥ͸߶�
* Output:        ��
* Return:        ��
* Notes:         �����ָ��cx,cy����ͼ����ͼ��ԭʼ��С���ƣ����Գ���CDC�ķ�Χ
************************************************************************************/
void IR_SDK_API  IrImage_DrawVLEx(long hIrImage,HDC hdc, long x=0, long y=0, long cx = -1, long cy = -1);



/****************************IRͼ����(END)**********************************************/


/****************************IRУ��******************************************************/

/**********************************************************************************
* Function:      IrCorrect_Create
* Description:   ����IRУ��
* Input:         int iWidth    ����ͼ��Ŀ��
*                int iHeight   ����ͼ��ĸ߶�
* Output:        ��
* Return:        �����ɹ�������Correct��������򷵻�-1
************************************************************************************/
long IR_SDK_API  IrCorrect_Create(int iWidth,int iHeight);

/**********************************************************************************
* Function:      IrCorrect_Close
* Description:   �رպ���У��
* Input:         long hCorrect   ����У�����
* Output:        ��
* Return:        ��
************************************************************************************/
void IR_SDK_API  IrCorrect_Close(long hCorrect);

/**********************************************************************************
* Function:      IrCorrect_LoadHData
* Description:   ������±�������
* Input:         long hCorrect  ����У�����
*                char *fileName ���±����ļ� 
* Output:        ��
* Return:        ����ɹ�������TRUE,ʧ�ܷ���FALSE
* Usages:        ���±���ͼ������ÿ��ʮ����ֵ������ʾ����AD
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_LoadHData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_LoadLData
* Description:   ������±�������
* Input:         long hCorrect  ����У�����
*                char *fileName ���±����ļ� 
* Output:        ��
* Return:        ����ɹ�������TRUE,ʧ�ܷ���FALSE
* Usages:        ���±���ͼ������ÿ��ʮ����ֵ������ʾ����AD
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_LoadLData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_CalcK
* Description:   ����У��Kֵ
* Input:         long hCorrect  ����У�����
* Output:        ��
* Return:        �ɹ�������TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_CalcK(long hCorrect);

/**********************************************************************************
* Function:      IrCorrect_SaveKData
* Description:   ����Kֵͼ��
* Input:         long hCorrect  ����У�����
*                char *fileName У���ļ�
* Output:        ��
* Return:        ����ɹ�������TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SaveKData(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_SavetBadPointReport
* Description:   ���滵�㱨��
* Input:         long hCorrect  ����У�����
*                char *fileName ���㱨���ļ�
* Output:        ��
* Return:        ����ɹ�������TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SavetBadPointReport(long hCorrect,char *fileName);

/**********************************************************************************
* Function:      IrCorrect_SavetBadPointData
* Description:   ���滵������
* Input:         long hCorrect  ����У�����
*                char *fileName ���������ļ�
* Output:        ��
* Return:        ����ɹ�������TRUE,ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrCorrect_SavetBadPointData(long hCorrect,char *fileName);

/****************************IRУ��(END)**************************************************/


/****************************���ڿ���****************************************************/

/*��Щ����NetSDK��Ҳʹ�ã������ظ����ã����ú�����*/
#ifndef FPGA_CTRL
#define FPGA_CTRL
#define MAX_FPGA_CTRL_BUF_LEN  2048

#define FPGA_FRAME_START                 0xAA55
#define FPGA_FRAME_END                   0xA5A6

#define FPGA_CTRL_TYPE_REQUEST_REPLY     0      /*��Ϣ������Ҫ��Ӧ*/
#define FPGA_CTRL_TYPE_REQUEST_NO_REPLY  1      /*��Ϣ����,����Ҫ��Ӧ*/
#define FPGA_CTRL_TYPE_REPLY             2      /*��Ϣ��Ӧ*/

#define FPGA_REPLY_SUCCESS               0      /*����ɹ�*/
#define FPGA_REPLY_FAILURE              -1      /*����ʧ��*/
#define FPGA_REPLY_RESEND               -2      /*��Ҫ�ش�,CRC�����֡β�ƻ���*/
#define FPGA_REPLY_INVALID_CMD          -3      /*����ʶ�������*/
#define FPGA_REPLY_INVALID_PARA         -4      /*�Ƿ����������*/
#define FPGA_REPLY_DEV_BUSY             -5      /*�豸��æ����������Ӧ*/

//�����ļ�����
#define FILE_TYPE_K                     (0x00000001)
#define FILE_TYPE_B                     (0x00000002)
#define FILE_TYPE_BPLIST                (0x00000003)
#define FILE_TYPE_POWERON_IMAGE         (0x00000004)
#define FILE_TYPE_CODE_BIT              (0x00000005)  /*���ڴ������ļ�*/
#define FILE_TYPE_FILTER_COEF           (0x00000006)  /*�˲�ϵ��*/
#define FILE_TYPE_CODE_SREC             (0x00000007)  /*SREC*/
#define FILE_TYPE_TEMP_DATA             (0x00000008)  /*�¶�����*/
#define FILE_TYPE_ASCII                 (0x00000009) 
#define FILE_TYPE_HANZI                 (0x0000000A) 






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





typedef enum 
{ 
   FPGA_CTRL_OPEN               = 0  ,  /*��I2C,������SDK����*/
   FPGA_CTRL_INC_BRIGHTNESS     = 1  ,  /*����ֵ����1 */
   FPGA_CTRL_DEC_BRIGHTNESS          ,  /*����ֵ��1*/
   FPGA_CTRL_GET_BRIGHTNESS          ,  /*���ظ������� 4���ֽ������򷵻�����ֵ*/
   FPGA_CTRL_SET_BRIGHTNESS          ,  /*�������ȣ����͸������� 4�ֽ�����������*/
   
   FPGA_CTRL_INC_CONTRAST            ,  /*�Աȶ�*/
   FPGA_CTRL_DEC_CONTRAST            , 
   FPGA_CTRL_GET_CONTRAST            ,  /*���ظ������� 4���ֽ������򷵻ضԱȶ�*/
   FPGA_CTRL_SET_CONTRAST            , 


   FPGA_CTRL_INC_BRIGHT_CONTRAST_MODE, /*���ȶԱȶ�ģʽ*/
   FPGA_CTRL_DEC_BRIGHT_CONTRAST_MODE, 
   FPGA_CTRL_GET_BRIGHT_CONTRAST_MODE, /*���ظ������� 4���ֽ������򷵻����ȶԱȶ�ģʽ*/
   FPGA_CTRL_SET_BRIGHT_CONTRAST_MODE, /*���͸������� 4���ֽ�������0 �ֶ���2�Զ�*/

   
   FPGA_CTRL_INC_PALETTE             , /*��ɫ��*/
   FPGA_CTRL_DEC_PALETTE             , 
   FPGA_CTRL_GET_PALETTE             , /*���ظ������� 4���ֽ������򷵻ص�ɫ������*/
   FPGA_CTRL_SET_PALETTE             , 
   

   FPGA_CTRL_CALIBRATE_B1            , /*���±���У��*/
   FPGA_CTRL_CALIBRATE_B2            , /*���±���У��*/
   FPGA_CTRL_CALIBRATE_INITK         , /*��ʼ��Kֵ*/
   FPGA_CTRL_CALIBRATE_INITB         , 
   FPGA_CTRL_CALIBRATE_SAVEK         ,
   FPGA_CTRL_CALIBRATE_LOADK         ,
   FPGA_CTRL_BADPOINT_REPLACE        , /*ȥ����*/
   FPGA_CTRL_SHARP_DEGREE            , /*�񻯵ȼ�*/
   FPGA_CTRL_GET_SHARP_DEGREE        , /*��ȡ�񻯼���*/
   
   FPGA_CTRL_GET_SHUTTER_STATUS      ,  /*���ظ������� 4���ֽ������򷵻ؿ���״̬*/
   FPGA_CTRL_SET_SHUTTER_STATUS      ,  /*�������*/

   
   FPGA_CTRL_SAVE_BPLIST             ,  /*�����б���ز���*/
   FPGA_CTRL_LOAD_BPLIST             ,
   FPGA_CTRL_CLR_BPLIST              ,

   FPGA_CTRL_GET_MENU_STATUS   = 100 ,  /*���ظ������� 4���ֽ������򷵻ز˵�״̬*/
   FPGA_CTRL_SET_MENU_STATUS         ,  /*���ò˵�״̬*/


   FPGA_CTRL_MENU_RIGHT_MOVE         ,  /*�˵�����*/
   FPGA_CTRL_MENU_LEFT_MOVE          , 
   FPGA_CTRL_MENU_UP_MOVE            , 
   FPGA_CTRL_MENU_DOWN_MOVE          , 
   FPGA_CTRL_UP_CONFIRM              , 
   FPGA_CTRL_DOWN_CONFIRM            ,
   FPGA_CTRL_SHOW_DEBUG              ,

   FPGA_CTRL_SENSOR_VOLT             , /*����̽����ƫ��*/
   FPGA_CTRL_SENSOR_LOCK             , /*ƫѹ����*/
   FPGA_CTRL_COOLER_VOLT			 , /*�����*/    

  //�ϴ��ļ�
   FPGA_CTRL_FILE_SEND_START   = 200 , /*�����ļ���ʼ, ���� �������� 4�ֽ��������ļ�����+4�ֽ��������ļ�����*/
   FPGA_CTRL_FILE_SEND               , /*�����ļ���ÿ���������MAX_SERIAL_DATA_LEN�ֽ�*/   
   FPGA_CTRL_FILE_SEND_END           , /*�ļ����ͽ�����������������*/

   //�����ļ�
   FPGA_CTRL_FILE_REQUEST            ,  /*�����ļ������͸������� 4�ֽ��������ļ����ͣ����ո������� 4�ֽ��������ļ�����*/
   FPGA_CTRL_FILE_GET_NEXT           ,  /*��ȡ�ļ���һ֡�����Ͳ����������ݣ�����Ϊ�����������MAX_SERIAL_DATA_LEN�ֽ�*/

   FPGA_CTRL_SAVE_CFG         = 300  , /*��������*/
   FPGA_CTRL_LOAD_CFG                , /*��������*/

		/*����������*/
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
	FPGA_CTRL_LOAD_DEFAULT_CFG       , /*0 �ָ��������ã�1�ָ����ȶԱȶ�*/               
               
	FPGA_CTRL_SEARCHBP     = 480     ,
	FPGA_CTRL_SETBPTH                ,
	FPGA_CTRL_FOCUSMOTORFRECTRL      , 
	FPGA_CTRL_FOCUSMOTORSPEEDCTRL    , 
	
    FPGA_CTRL_PTZ             = 800  , /*��̨����*/
    FPGA_CTRL_SET_PT          = 801  ,
    FPGA_CTRL_SET_RECT        = 802  ,
    FPGA_CTRL_SET_CIRCLE      = 803  ,
    FPGA_CTRL_SET_POLYGON     = 804  ,
    FPGA_CTRL_GET_RECT_TEMP   = 805  ,  
    FPGA_CTRL_GET_CIRCLE_TEMP = 806  , 
    FPGA_CTRL_GET_POLYGON_TEMP = 807 , /*��ȡ������¶�*/

   	FPGA_CTRL_CLOSE            = 1000 ,  /*�ر�I2C,������SDK����*/
   	FPGA_CTRL_NULL                    ,  /*������*/
   
 } eFpgaCmd;

#pragma  pack(1)
typedef struct __fpga_cmd
{
	unsigned short frameStart; /*֡ͷ*/
	unsigned short cmd;        /*��������*/
	unsigned short type;       /*��������,*/
	short          ret;        /*�����ֵ*/
	unsigned short bufLen;     /*������buf����*/
	unsigned short crc;        /*��short����У��*/	
	unsigned char  buf[1];     /*������������Ӧ�������*/
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

/*���ĸ������ݳ���*/
#define MAX_SERIAL_DATA_LEN     512

/**********************************************************************************
* Function:      IrSerial_Open
* Description:   �򿪴����豸
* Input:         unsigned int portnr   ���ڶ˿ں�
*                unsigned int baud     ������
*                char parity           ��żУ��
*                unsigned int stopsbits ֹͣ��
*                unsigned long dwCommEvents Ҫ������¼�
*                unsigned int nBufferSize ���ڻ�������С
* Output:        ��
* Return:        �򿪳ɹ������ش��ھ�������򷵻�-1
* Usages:        
************************************************************************************/
long IR_SDK_API  IrSerial_Open(unsigned int portnr = 1, unsigned int baud = 19200, char parity = 'N', unsigned int databits = 8, unsigned int stopsbits = 1, unsigned long dwCommEvents = EV_RXCHAR | EV_CTS, unsigned int nBufferSize = 1024);

/**********************************************************************************
* Function:      IrSerial_Close
* Description:   �رմ����豸���ͷ���Ӧ��Դ
* Input:         long hSerial  �����豸���
* Output:        ��
* Return:        �رճɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_Close(long hSerial);


/**********************************************************************************
* Function:      IrSerial_Write
* Description:   �������豸д����
* Input:         long hSerial        �����豸���
*                unsigned char *Buff Ҫ���͵����ݻ����� 
*                int iLen            ���������ݴ�С
*                BOOL bWaitReply     �Ƿ�ȴ��Զ���Ӧ
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_Write(long hSerial,unsigned char *Buff,int iLen,BOOL bWaitReply=FALSE);


/**********************************************************************************
* Function:      IrSerial_SendCmd
* Description:   �������豸��������
* Input:         long hSerial           �����豸���
*                unsigned short cmd     ��������
*                unsigned short cmdType ��������
*                unsigned char* pBuff   �����������������
*                int iBufLen            �������������
*                unsigned char *pRetBuf ����ؽ��ջ�����
*                int *pRetLen           ���ػ������ܳ���
* Output:        unsigned char *pRetBuf �����
*                int *pRetLen           ���ػ���������
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_SendCmd(long hSerial,unsigned short cmd,unsigned short cmdType=FPGA_CTRL_TYPE_REQUEST_REPLY,unsigned char* pBuff=NULL,int iBufLen=0,unsigned char *pRetBuf = NULL,int *pRetLen = NULL);


typedef int (*IrSerial_FileTrans)(long lPrivate, int totalLen, int curLen);

/**********************************************************************************
* Function:      IrSerial_SendFile
* Description:   �������豸�����ļ�
* Input:         long hSerial           �����豸���
*                int fileType           �ļ�����
*                char *fileName         �����ļ���
*                IrSerial_FileTrans pCbFileTrans  �ļ�����״̬�ص�
*                long lPrivate          �ص������Ĳ���
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_SendFile(long hSerial,int fileType,char *fileName,IrSerial_FileTrans pCbFileTrans = NULL,long lPrivate=0 );


/**********************************************************************************
* Function:      IrSerial_RecvFile
* Description:   �Ӵ��ڽ����ļ�
* Input:         long hSerial           �����豸���
*                int fileType           �ļ�����
*                char *fileName         �����ļ���
*                IrSerial_FileTrans pCbFileTrans  �ļ�����״̬�ص�
*                long lPrivate          �ص������Ĳ���
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  IrSerial_RecvFile(long hSerial,int fileType,char *fileName,IrSerial_FileTrans pCbFileTrans = NULL,long lPrivate=0);


/*************************���ڿ���(END)************************************************/


/****************************�������****************************************************/

/*BDB�����ȡ*/
typedef int (*BDB_ReadCb)(long lPrivate,BYTE *pBuf,int iLen);

/**********************************************************************************
* Function:      BDBCtrl_Open
* Description:   �򿪴����豸
* Input:         unsigned int portnr   ���ڶ˿ں�
*                unsigned int baud     ������
*                char parity           ��żУ��
*                unsigned int stopsbits ֹͣ��
*                unsigned long dwCommEvents Ҫ������¼�
*                unsigned int nBufferSize ���ڻ�������С
* Output:        ��
* Return:        �򿪳ɹ������ش��ھ�������򷵻�-1
* Usages:        �������Ҫ��ȡ���ݣ�pCbRead����Ϊ�գ����øú���ʱһ��ֻ��ָ���˿ںźͲ����ʣ�
*                ������Բ���Ĭ��
************************************************************************************/
long IR_SDK_API  BDBCtrl_Open(unsigned int portnr = 1, unsigned int baud = 9600, char parity = 'E', unsigned int databits = 7, unsigned int stopsbits = 1, unsigned long dwCommEvents = EV_RXCHAR | EV_CTS, unsigned int nBufferSize = 1024);

/**********************************************************************************
* Function:      BDBCtrl_Close
* Description:   �رմ����豸���ͷ���Ӧ��Դ
* Input:         long hSerial  �����豸���
* Output:        ��
* Return:        �رճɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_Close(long hSerial);


/**********************************************************************************
* Function:      IrSerial_Write
* Description:   �������豸д����
* Input:         long hSerial        �����豸���
*                unsigned char *Buff Ҫ���͵����ݻ����� 
*                int iLen            ���������ݴ�С
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_Write(long hSerial,unsigned char *Buff,int iLen);

/**********************************************************************************
* Function:      BDBCtrl_SetReadCB
* Description:   ���ô��ڶ�ȡ�ص�����
* Input:         long hSerial        �����豸���
*                BDB_ReadCb ReadCb �������ݶ�ȡ�ص����� 
*                long lPrivate      ˽�����ݣ��ص�����ʹ��
* Output:        ��
* Return:        ���ͳɹ�������TRUE��ʧ�ܷ���FALSE
************************************************************************************/
BOOL IR_SDK_API  BDBCtrl_SetReadCB(long hSerial,BDB_ReadCb ReadCb,long lPrivate=0);

/*************************�������(END)************************************************/

#endif
