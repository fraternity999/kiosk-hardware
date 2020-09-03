////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2008-2012 HiTi Digital, Inc.  All Rights Reserved.
//
// $Revision: 1.5.3.740 $
// $Date: 2012-11-30 $
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __PAVOAPI_H__
#define __PAVOAPI_H__

#ifdef __cplusplus
extern "C" {
#endif


//Messages sent by printer driver
#define WM_PAVO_PRINTER						0x5555

//possible WPARAM values for WM_PAVO_PRINTER
#define MSG_JOB_BEGIN						1			//Driver begin to process job
#define MSG_PRINT_ONE_PAGE					3			//Driver process one page
#define MSG_PRINT_ONE_COPY					4			//Driver send one copy of one page data to printer
#define MSG_JOB_END							6			//Driver process job end
#define MSG_DEVICE_STATUS					7			//Status of printer
#define MSG_JOB_CANCELED					12			//Driver cancel the job
#define MSG_JOB_PRINTED						24			//Printer print out the job completely

//HiTi defined Device Status Code used for PAVO_CheckPrinterStatus
#define PAVO_DS_BUSY						0x00080000	//Printer is busy
#define PAVO_DS_OFFLINE						0x00000080	//Printer is not connected
#define PAVO_DS_PRINTING					0x00000002	//Printer is printing
#define PAVO_DS_PROCESSING_DATA				0x00000005	//Driver is processing print data
#define PAVO_DS_SENDING_DATA				0x00000006	//Driver is sending data to printer
#define PAVO_DS_CARD_MISMATCH				0x000100FE	//Card mismatch
#define PAVO_DS_CMD_SEQ_ERROR				0x000301FE	//Command sequence error
#define PAVO_DS_SRAM_ERROR					0x00030001	//SRAM error
#define PAVO_DS_SDRAM_ERROR					0x00030101	//SDRAM error
#define PAVO_DS_ADC_ERROR					0x00030201	//ADC error
#define PAVO_DS_NVRAM_ERROR					0x00030301	//NVRAM R/W error
#define PAVO_DS_SDRAM_CHECKSUM_ERROR		0x00030302	//Check sum error - SDRAM
#define PAVO_DS_FW_WRITE_ERROR				0x00030701	//Firmware write error
#define PAVO_DS_COVER_OPEN					0x00050001	//Cover or door open or Ajar
#define PAVO_DS_COVER_OPEN_SLAVE			0x00050201	//Cover or door open or Ajar in slave printer
#define PAVO_DS_REJECT_BOX_MISSING			0x00050301	//Rejected box missing
#define PAVO_DS_REJECT_BOX_FULL				0x00050401	//Rejected box full
#define PAVO_DS_CARD_OUT					0x00008000	//Card out or feeding error
#define PAVO_DS_CARD_LOW					0x00008001	//Card low
#define PAVO_DS_RIBBON_MISSING				0x00080004	//Ribbon missing
#define PAVO_DS_OUT_OF_RIBBON				0x00080103	//Out of ribbon
#define PAVO_DS_RIBBON_IC_RW_ERROR			0x000804FE	//Ribbon IC R/W error
#define PAVO_DS_UNSUPPORT_RIBBON			0x000806FE	//Unsupported ribbon
#define PAVO_DS_UNKNOWN_RIBBON				0x000808FE	//Unknown ribbon
#define PAVO_DS_RIBBON_MISSING_SLAVE		0x00080204	//Ribbon missing in slave printer
#define PAVO_DS_OUT_OF_RIBBON_SLAVE			0x00080303	//Out of ribbon in slave printer
#define PAVO_DS_RIBBON_IC_RW_ERROR_SLAVE	0x000805FE	//Ribbon IC R/W error in slave printer
#define PAVO_DS_UNSUPPORT_RIBBON_SLAVE		0x000807FE	//Unsupported ribbon in slave printer
#define PAVO_DS_UNKNOWN_RIBBON_SLAVE		0x000809FE	//Unknown ribbon in slave printer
#define PAVO_DS_CARD_JAM1					0x00030000	//Card jam in card path
#define PAVO_DS_CARD_JAM2					0x00040000	//Card jam in flipper
#define PAVO_DS_CARD_JAM3					0x00050000	//Card jam in eject box
#define PAVO_DS_CARD_JAM4					0x00030100	//Card jam in card path of slave printer
#define PAVO_DS_CARD_JAM5					0x00040100  //Card jam in flipper of slave printer
#define PAVO_DS_CARD_JAM6					0x00050100  //Card jam in eject box of slave printer
#define PAVO_DS_CARD_JAM7					0x00060100	//Card jam between master and slave
#define PAVO_DS_CARD_JAM8					0x00070100	//Card jam in end of master
#define PAVO_DS_WRITE_FAIL					0x0000001F	//Send command to printer fail
#define PAVO_DS_READ_FAIL					0x0000002F	//Get response from printer fail
#define PAVO_DS_CARD_THICK_WRONG			0x00008010	//Card thickness selector is not placed in the right position
#define PAVO_DS_NO_FLIPPER_MODULE			0x1100000D	//The flipper module is not attached

//following errors are used for CS-200e
#define PAVO_DS_0100_COVER_OPEN				0x00000100	//0100 Cover open
#define PAVO_DS_0101_FLIPPER_COVER_OPEN		0x00000101	//0101 Flipper cover open
#define PAVO_DS_0200_IC_MISSING				0x00000200	//0200 IC chip missing
#define PAVO_DS_0201_RIBBON_MISSING			0x00000201	//0201 Ribbon missing
#define PAVO_DS_0202_RIBON_MISMATCH			0x00000202	//0202 Ribbon mismatch
#define PAVO_DS_0203_RIBBON_TYPE_ERROR		0x00000203	//0203 Ribbon type error
#define PAVO_DS_0300_RIBBON_SEARCH_FAIL		0x00000300	//0300 Ribbon search fail
#define PAVO_DS_0301_RIBBON_OUT				0x00000301	//0301 Ribbon out
#define PAVO_DS_0302_PRINT_FAIL				0x00000302	//0302 Print fail
#define PAVO_DS_0303_PRINT_FAIL				0x00000303	//0303 Print fail
#define PAVO_DS_0304_RIBBON_OUT				0x00000304	//0304 Ribbon out
#define PAVO_DS_0400_CARD_OUT				0x00000400	//0400 Card out
#define PAVO_DS_0500_CARD_JAM				0x00000500	//0500 Card jam
#define PAVO_DS_0501_CARD_JAM				0x00000501	//0501 Card jam
#define PAVO_DS_0502_CARD_JAM				0x00000502	//0502 Card jam
#define PAVO_DS_0503_CARD_JAM				0x00000503	//0503 Card jam
#define PAVO_DS_0504_CARD_JAM				0x00000504	//0504 Card jam
#define PAVO_DS_0505_CARD_JAM				0x00000505	//0505 Card jam
#define PAVO_DS_0506_CARD_JAM				0x00000506	//0506 Card jam
#define PAVO_DS_0507_CARD_JAM				0x00000507	//0507 Card jam
#define PAVO_DS_0600_CARD_MISMATCH			0x00000600	//0600 Card mismatch
#define PAVO_DS_0700_CAM_ERROR				0x00000700	//0700 Cam error
#define PAVO_DS_0800_FLIPPER_ERROR			0x00000800	//0800 Flipper error
#define PAVO_DS_0900_NVRAM_ERROR			0x00000900	//0900 NVRAM error
#define PAVO_DS_1000_RIBBON_ERROR			0x00001000	//1000 Ribbon error
#define PAVO_DS_1100_RBN_TAKE_CALIB_FAIL	0x00001100	//1100 RBN Take Calibration Failed
#define PAVO_DS_1101_RBN_SUPPLY_CALIB_FAIL	0x00001101	//1101 RBN Supply Calibration Failed
#define PAVO_DS_1200_ADC_ERROR				0x00001200	//1200 ADC error
#define PAVO_DS_1300_FW_ERROR				0x00001300	//1300 FW error
#define PAVO_DS_1400_POWER_SUPPLY_ERROR		0x00001400	//1400 Power supply error

#ifndef SCARD_E_NO_SMARTCARD
#define SCARD_E_NO_SMARTCARD				0x8010000C	//The operation requires a Smart Card, but no Smart Card is currently in the device.
#endif

//possible return value of PAVO_ReadMagTrackData() and PAVO_WriteMagTrackData()
#define ERROR_MAGCARD_CONNECT_FAIL			1850		//Cannot connect COM port of magnetic module
#define ERROR_MAGCARD_READ_FAIL				1851		//Read track data fail
#define ERROR_MAGCARD_WRITE_FAIL			1852		//Write track data fail
#define ERROR_MAGCARD_NO_TRACK_SELECTED		1853		//No track is specified to be read/write
#define ERROR_MAGCARD_EMPTY_TRACK_DATA		1855		//One of the track data is empty

//HiTi defined ribbon type used for PAVO_QueryRibbonInfo()
#define PAVO_RIBBON_TYPE_YMCKO				0
#define PAVO_RIBBON_TYPE_K					1
#define PAVO_RIBBON_TYPE_KO					3
#define PAVO_RIBBON_TYPE_YMCKOK				4
#define PAVO_RIBBON_TYPE_HALF_YMCKO			5


//HiTi defined card type used for setting PAVO_JOB_PROPERTY.dwCardType
#define PAVO_CARD_TYPE_BLANK_CARD			0			//Blank Card
#define PAVO_CARD_TYPE_SMART_CHIP_6PIN		1			//Smart Chip Card 6-pin
#define PAVO_CARD_TYPE_SMART_CHIP_8PIN		2			//Smart Chip Card 8-pin
#define PAVO_CARD_TYPE_MAG_STRIP			3			//Magnetic Stripe Card
#define PAVO_CARD_TYPE_CHIP_MAG_STRIP		4			//Chip/Magnetic Card
#define PAVO_CARD_TYPE_ADHESIVE_CARD		5			//Adhesive Card


//used for setting PAVO_JOB_PROPERTY.dwFlags
#define PAVO_FLAG_NOT_SHOW_ERROR_MSG_DLG		0x00000001	//Not show error message dialog
#define PAVO_FLAG_WAIT_MSG_DONE					0x00000002	//Make driver to wait until AP process the message ok
#define PAVO_FLAG_NOT_SHOW_CLEAN_MSG			0x00000100	//Not popup clean message
#define PAVO_FLAG_WATCH_JOB_PRINTED				0x00000400	//Indicate driver to notify AP when print card completely
#define PAVO_FLAG_NOT_EJECT_CARD_AFTER_PRINTED	0x00008000	//Not eject card after printing finished


//used for setting PAVO_JOB_PROPERTY.dwDataFlag
#define PAVO_DATAFLAG_RESIN_FRONT			0x00000002
#define PAVO_DATAFLAG_RESIN_BACK			0x00000010

//used for dwType of PAVO_SetExtraDataToHDC
#define PAVO_DATA_RESIN_FRONT				2
#define PAVO_DATA_RESIN_BACK				5

//used for setting PAVO_JOB_PROPERTY.byDuplex
#define PAVO_DUPLEX_PRINT_FRONT_SIDE		0x01
#define PAVO_DUPLEX_PRINT_BACK_SIDE			0x02


//PAVO_JOB_PROPERTY.dwFieldFlag
#define FF_CARD_TYPE						0x00000001
#define FF_FLAGS							0x00000002
#define FF_DATA_FLAG						0x00000004
#define FF_PARENT_HWND						0x00000008
#define FF_ORIENTATION						0x00000020
#define FF_COPIES							0x00000040
#define FF_CUSTOM_INDEX						0x00000080
#define FF_DUPLEX							0x00000100
#define FF_RIBBON_TYPE						0x00000200
#define FF_PRINT_COLOR						0x00000400
#define FF_DITHER_K							0x00000800
#define FF_LAMIN							0x00001000
#define FF_LAMIN_TYPE						0x00002000
#define FF_ROTATE180						0x00004000
#define FF_CARD_THICK						0x00010000
#define FF_ALL_FIELDS						0xFFFFFFFF


//Position definition for PAVO_MoveCard()
#define MOVE_CARD_TO_IC_ENCODER				1			//Move Card to Contact Encoder Station
#define MOVE_CARD_TO_RFID_ENCODER			3			//Move Card to Contactless Encoder Station
#define MOVE_CARD_TO_REJECT_BOX				4			//Move Card to Reject Box
#define MOVE_CARD_TO_HOPPER					5			//Move Card to Output Hopper
#define MOVE_CARD_TO_FLIPPER				6			//Move Card to Flipper
#define MOVE_CARD_TO_PRINT_FROM_FLIPPER     7           //Move Card to Print Position from Flipper


//used for PAVO_ApplyJobSetting
typedef struct tagPAVO_JOB_PROPERTY
{
	DWORD		dwSize;				//=80
	DWORD		dwCardType;
	DWORD		dwFlags;
	DWORD		dwDataFlag;

	HWND		hParentWnd;
	HWND		hReserved1;

	LPTSTR		pReserved1;
	LPTSTR		pReserved2;
	LPTSTR		pReserved3;
	LPTSTR		pReserved4;

	short		shOrientation;		//1=Portrait,2=Landscape
	short		shCopies;
	short		shReserved1;
	short		shReserved2;

	DWORD		dwCustomIndex;
	DWORD		dwFieldFlag;
	DWORD		dwReserved3;
	DWORD		dwReserved4;

	WORD		wReserved1;
	WORD		wReserved2;
	WORD		wReserved3;
	BYTE		byReserved1;
	BYTE		byCardThick;		//0=0.3mm;1=0.5mm;2=0.8mm;3=1.0mm

	BYTE		byDuplex;			//Print side: 0x01=front side, 0x02=back side
	BYTE		byRibbonType;		//0=YMCKO;1=K;2=YMCO;3=KO;4=YMCKOK;5=1/2YMCKO;6=Gold;7=Silver;8=White
	BYTE		byPrintColor;		//Print YMCO: 0x01=front side, 0x02=back side
	BYTE		byDitherK;			//Print K with dither: 0x01=front side, 0x02=back side
	BYTE		byLamin;			//Print lamination: 0x01=front side, 0x02=back side
	BYTE		byReserved6;
	BYTE		byLaminType;		//Lamination ribbon type, 0x00=HiTi Standard Overlay, 0x01=HiTi Standard Patch
	BYTE		byRotate180;		//Rotate 180: 0x00=Not rotate, 0x01=front side, 0x02=back side, 0x03=both sides

}PAVO_JOB_PROPERTY;


//used for PAVO_ReadMagTrackData(), PAVO_WriteMagTrackData()
typedef struct tagMagTrackData2
{
	char			szTrack1[256];	//78 characters max, allowed characters are between {}, { !"#$&'()*+,-./0123456789:;<=>@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_}. Start Sentinel is '%', End Sentinel is '?', both will be auto added by encoder.
	char			szTrack2[256];	//39 characters max, allowed characters are between {}, {0123456789:<=>}. Start Sentinel is ';', End Sentinel is '?', both will be auto added by encoder.
	char			szTrack3[256];	//105 characters max, allowed characters are between {}, {0123456789:<=>}. Start Sentinel is ';', End Sentinel is '?', both will be auto added by encoder.

	unsigned char	byTrackFlag;	//0x01=track1, 0x02=track2, 0x04=track3, 0x10=raw format
	unsigned char	byEncodeMode;	//not used
	unsigned char	byCoercivity;	//0=Lo-Co, 1=Hi-Co
	unsigned char	byT2BPI;		//75 or 210, if not set it, will use 75

	unsigned char	byRawLenT1;
	unsigned char	byRawLenT2;
	unsigned char	byRawLenT3;

	unsigned char	byReserve[25];

}MAG_TRACK_DATA2;

//used for PAVO_PrintOneCard()
typedef struct tagHITI_CARD_PRINT_PARAMETER
{
	unsigned long		dwSize;
	unsigned long		dwReserve1;
	unsigned long		dwReserve2;
	unsigned long		dwReserve3;

	unsigned char		byOrientation;	//1=portrait;2=landscape
	unsigned char		byCardThickness;//0=0.3mm;1=0.5mm;2=0.8mm;3=1.0mm
	unsigned char		byReserve3;
	unsigned char		byReserve4;
	unsigned char		byReserve5;
	unsigned char		byReserve6;
	unsigned char		byReserve7;
	unsigned char		byReserve8;

	BITMAP				*lpFrontBGR;	//24-bits, BGRBGR...
	BITMAP				*lpFrontK;		//8-bits, each pixel with value 0x00 will be transfer to card by ribbon K
	BITMAP				*lpFrontO;		//8-bits, each pixel with value 0xFF will be transfer to card by ribbon O

	BITMAP				*lpBackBGR;		//24-bits, BGRBGR...
	BITMAP				*lpBackK;		//8-bits, each pixel with value 0x00 will be transfer to card by ribbon K
	BITMAP				*lpBackO;		//8-bits, each pixel with value 0xFF will be transfer to card by ribbon O

	unsigned char		*lpReserve1;
	unsigned char		*lpReserve2;

}HITI_CARD_PRINT_PARAMETER;

typedef struct tagHITI_HEATING_ENERGY
{
	//Heating Energy, value range of following fields are -127 ~ 127
	//same as driver UI Heating Energy tab
	//Density Adjustment ------------------------
	//Front side
	char				chFrontDenYMC;
	char				chFrontDenK;
	char				chFrontDenO;
	char				chFrontDenResinK;

	//Back side
	char				chBackDenYMC;
	char				chBackDenK;
	char				chBackDenO;
	char				chBackDenResinK;

	//Sensitivity Adjustment --------------------
	//Front side
	char				chFrontSenYMC;
	char				chFrontSenK;
	char				chFrontSenO;
	char				chFrontSenResinK;

	//Back side
	char				chBackSenYMC;
	char				chBackSenK;
	char				chBackSenO;
	char				chBackSenResinK;

}HITI_HEATING_ENERGY;


//Export functions definitions, used for LoadLibrary
typedef	DWORD (__stdcall * pfnPAVO_ApplyJobSetting)			(LPTSTR szPrinterName, HDC hDC, BYTE* lpInDevMode, BYTE* lpInJobProp);
typedef	DWORD (__stdcall * pfnPAVO_CheckPrinterStatus)		(TCHAR* szPrinter, DWORD* lpdwStatus);
typedef DWORD (__stdcall * pfnPAVO_DoCommand)				(TCHAR* szPrinter, DWORD dwCommand);
typedef DWORD (__stdcall * pfnPAVO_FindMatchedComPort)		(TCHAR* szPrinter, DWORD* lpdwMagPort, DWORD* lpdwRFPort);
typedef DWORD (__stdcall * pfnPAVO_FindSCardReader)			(TCHAR* szPrinter, LPTSTR szReaderName);
typedef	DWORD (__stdcall * pfnPAVO_GetCardPosition)			(TCHAR* szPrinter, DWORD* lpdwCardPos);
typedef DWORD (__stdcall * pfnPAVO_GetDeviceInfo)			(TCHAR* szPrinter, DWORD dwInfoType, BYTE *lpInfoData, DWORD *lpdwDataLen);
typedef	DWORD (__stdcall * pfnPAVO_MoveCard)				(TCHAR* szPrinter, DWORD dwPosition);
typedef DWORD (__stdcall * pfnPAVO_PrintOneCard)			(TCHAR* szPrinter, HITI_CARD_PRINT_PARAMETER *lpJobPara, HITI_HEATING_ENERGY *lpHeatEnergy, unsigned char* lpReserved);
typedef	DWORD (__stdcall * pfnPAVO_QueryPrintCount)			(TCHAR* szPrinter, DWORD *lpdwCount);
typedef DWORD (__stdcall * pfnPAVO_QueryRibbonInfo)			(TCHAR* szPrinter, BYTE *lpbyType, DWORD* lpdwRemainCount);
typedef DWORD (__stdcall * pfnPAVO_ReadMagTrackData)		(TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData);//lpTrackData is the pointer of MAG_TRACK_DATA2
typedef DWORD (__stdcall * pfnPAVO_ResetPrinter)			(TCHAR* szPrinter, DWORD dwMode);//dwMode=1
typedef	DWORD (__stdcall * pfnPAVO_SetExtraDataToHDC)		(HDC hDC, DWORD dwType, DWORD x, DWORD y, BITMAP* lpBmp);
typedef DWORD (__stdcall * pfnPAVO_SetPassword)				(TCHAR* szPrinter, LPTSTR szCurrentPasswd, LPTSTR szNewPasswd);
typedef DWORD (__stdcall * pfnPAVO_SetSecurityMode)			(TCHAR* szPrinter, LPTSTR szCurrentPasswd, long nSecurityMode);
typedef DWORD (__stdcall * pfnPAVO_WriteMagTrackData)		(TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData);//lpTrackData is the pointer of MAG_TRACK_DATA2
typedef DWORD (__stdcall * pfnPAVO_EncodeMagTrack)		    (TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData,DWORD dwRetry);//lpTrackData is the pointer of MAG_TRACK_DATA2


#ifdef __cplusplus
}
#endif


//Export functions definitions, used for linking to PavoApi.lib
DWORD __stdcall PAVO_ApplyJobSetting		(LPTSTR szPrinterName, HDC hDC, BYTE* lpInDevMode, BYTE* lpInJobProp);
DWORD __stdcall PAVO_CheckPrinterStatus		(TCHAR* szPrinter, DWORD *lpdwStatus);
DWORD __stdcall PAVO_DoCommand				(TCHAR* szPrinter, DWORD dwCommand);
DWORD __stdcall PAVO_FindMatchedComPort		(TCHAR* szPrinter, DWORD* lpdwMagPort, DWORD* lpdwRFPort);
DWORD __stdcall PAVO_FindSCardReader		(TCHAR* szPrinter, LPTSTR szReaderName);
DWORD __stdcall PAVO_GetCardPosition		(TCHAR* szPrinter, DWORD *lpdwCardPos);
DWORD __stdcall PAVO_GetDeviceInfo			(TCHAR* szPrinter, DWORD dwInfoType, BYTE *lpInfoData, DWORD *lpdwDataLen);
DWORD __stdcall PAVO_MoveCard				(TCHAR* szPrinter, DWORD dwPosition);
DWORD __stdcall PAVO_PrintOneCard			(TCHAR* szPrinter, HITI_CARD_PRINT_PARAMETER *lpJobPara, HITI_HEATING_ENERGY *lpHeatEnergy, unsigned char* lpReserved);
DWORD __stdcall PAVO_QueryPrintCount		(TCHAR* szPrinter, DWORD *lpdwCount);
DWORD __stdcall PAVO_QueryRibbonInfo		(TCHAR* szPrinter, BYTE *lpbyType, DWORD* lpdwRemainCount);
DWORD __stdcall PAVO_ReadMagTrackData		(TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData);//lpTrackData is the pointer of MAG_TRACK_DATA2
DWORD __stdcall PAVO_ResetPrinter			(TCHAR* szPrinter, DWORD dwMode);//dwMode=1
DWORD __stdcall PAVO_SetExtraDataToHDC		(HDC hDC, DWORD dwType, DWORD x, DWORD y, BITMAP* lpBmp);
DWORD __stdcall PAVO_SetPassword			(TCHAR* szPrinter, LPTSTR szCurrentPasswd, LPTSTR szNewPasswd);
DWORD __stdcall PAVO_SetSecurityMode		(TCHAR* szPrinter, LPTSTR szCurrentPasswd, long nSecurityMode);
DWORD __stdcall PAVO_WriteMagTrackData		(TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData);//lpTrackData is the pointer of MAG_TRACK_DATA2
DWORD __stdcall PAVO_EncodeMagTrack	        (TCHAR* szPrinter, DWORD dwCOM, BYTE* lpTrackData,DWORD dwRetry);//lpTrackData is the pointer of MAG_TRACK_DATA2


#endif //__PAVOAPI_H__
