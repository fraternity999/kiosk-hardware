/////////////////////////////////////////////////////////////////
//////////////////// DLL内部错误索引/////////////////////////////
//CommOpen(101-104)
#define Bad_CommOpen -101//端口打开错.
#define Bad_CommSet -102//端口参数设置错,(102)还代表CommSet函数错

#define Bad_CommTimeouts -999
#define Bad_CommQueue -998
//CommClose(105)
#define Bad_CommClose -105//端口关闭错.

//Send(106)
#define Bad_SendByte -106
#define Bad_SendData_Len -107

//Receive(106-107)
#define Bad_ReceiveData_ReadFile -103
#define Bad_ReceiveData_Len -104

// 公共错误
#define Bad_Parameter -200//传入参数错误(超越定义)

/**************************************************************
	M100 动态库 标准版 版本号 M100DLL_V2.3
	返回错误信息
	作者：张杰				08 10 21
**************************************************************/
//######################################################//
//==================函数说明===========================//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++//
HANDLE __stdcall M100_CommOpen(char *Port);
HANDLE __stdcall M100_CommOpenWithBaud(char *Port, unsigned int _data);
int __stdcall M100_CommClose(HANDLE ComHandle);
int __stdcall M100_GetSysVerion(HANDLE ComHandle, char *strVerion);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_SetCommBaud(HANDLE ComHandle, unsigned int _Baud);
int __stdcall M100_Reset(HANDLE ComHandle, BYTE _PM,BYTE _VerCode[20]);
int __stdcall M100_CheckCardPosition(HANDLE ComHandle, BYTE *_Position);
int __stdcall M100_CheckSensorStates(HANDLE ComHandle, BYTE _States[7]);
int __stdcall M100_CheckSensorVoltage(HANDLE ComHandle, BYTE _Valtage[12]);
int __stdcall M100_EnterCard(HANDLE ComHandle,BYTE EnterType,DWORD WaitTime);
int __stdcall M100_EnterCardUntime(HANDLE ComHandle, BYTE EnterType);//;;;进卡立即返回
int __stdcall M100_MoveCard(HANDLE ComHandle, BYTE _PM);
int __stdcall M100_AutoTestICCard(HANDLE ComHandle, BYTE *_IcCardType);
int __stdcall M100_AutoTestRFIDCard(HANDLE ComHandle, BYTE *_RFIDCardType);
int __stdcall M100_PowerOn(HANDLE ComHandle);
int __stdcall M100_PowerOff(HANDLE ComHandle);
int __stdcall M100_Led1Control(HANDLE ComHandle, BYTE _PM);
int __stdcall M100_SetLedFlickerRate(HANDLE ComHandle, BYTE _PM, BYTE _Rate);
int __stdcall M100_Led2Control(HANDLE ComHandle, BYTE _PM);
int __stdcall M100_ReadBarcode(HANDLE ComHandle, BYTE *szData);
int __stdcall M100_Eot(HANDLE ComHandle);
//++++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_ReadMagcardDecode(HANDLE ComHandle, BYTE _track, DWORD *_DataLen,BYTE _BlockData[]);
int __stdcall M100_ReadMagcardUNDecode(HANDLE ComHandle,BYTE _track, DWORD *_DataLen,BYTE _BlockData[]);
int __stdcall M100_ClearMagCardData(HANDLE ComHandle);
//++++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_S50DetectCard(HANDLE ComHandle);
int __stdcall M100_S50GetCardID(HANDLE ComHandle, BYTE _CardID[4]);
int __stdcall M100_S50LoadSecKey(HANDLE ComHandle, BYTE _BlockAddr, BYTE _KEYType, BYTE _KEY[6]);
int __stdcall M100_S50ReadBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_S50WriteBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_S50InitValue(HANDLE ComHandle, BYTE _Block, BYTE _Data[16]);
int __stdcall M100_S50Increment(HANDLE ComHandle, BYTE _Block, BYTE _Data[4]);
int __stdcall M100_S50Decrement(HANDLE ComHandle, BYTE _Block, BYTE _Data[4]);
int __stdcall M100_S50Halt(HANDLE ComHandle);
int __stdcall M100_S70DetectCard(HANDLE ComHandle);
int __stdcall M100_S70GetCardID(HANDLE ComHandle, BYTE _CardID[4]);
int __stdcall M100_S70LoadSecKey(HANDLE ComHandle, BYTE _BlockAddr, BYTE _KEYType, BYTE _KEY[6]);
int __stdcall M100_S70ReadBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_S70WriteBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_S70InitValue(HANDLE ComHandle, BYTE _Block, BYTE _Data[16]);
int __stdcall M100_S70Increment(HANDLE ComHandle, BYTE _Block, BYTE _Data[4]);
int __stdcall M100_S70Decrement(HANDLE ComHandle, BYTE _Block, BYTE _Data[4]);
int __stdcall M100_S70Halt(HANDLE ComHandle);
int __stdcall M100_ULDetectCard(HANDLE ComHandle);
int __stdcall M100_ULGetCardID(HANDLE ComHandle, BYTE _CardID[7]);
int __stdcall M100_ULReadBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_ULWriteBlock(HANDLE ComHandle, BYTE _Block, BYTE _BlockData[16]);
int __stdcall M100_ULHalt(HANDLE ComHandle);
int __stdcall M100_15693GetUid(HANDLE ComHandle,BYTE UID[8]);
int __stdcall M100_15693ReadData(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE BlockAddr, BYTE BlockLen, BYTE _BlockData[],BYTE* ReadBlockLen);
int __stdcall M100_15693WriteData(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE BlockAddr, BYTE BlockLen, BYTE _BlockData[],BYTE *WriteBlockLen);
int __stdcall M100_15693ChooseCard(HANDLE ComHandle,bool bUid,BYTE Uid[8]);
int __stdcall M100_15693GetMessage(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE Message[15]);
int __stdcall M100_15693ReadSafeBit(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE BlockAddr, BYTE BlockLen,BYTE* ReadBlockLen,BYTE BlockLockStatus[]);
int __stdcall M100_15693WriteDSFID(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE WriteBit);
int __stdcall M100_15693WriteAFI(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE WriteBit);
int __stdcall M100_15693LockBlock(HANDLE ComHandle,bool bUid,BYTE Uid[8],BYTE LockAddress);
int __stdcall M100_15693LockAFI(HANDLE ComHandle,bool bUid,BYTE Uid[8]);
int __stdcall M100_15693LockDSFID(HANDLE ComHandle,bool bUid,BYTE Uid[8]);

int __stdcall M100_GetIdCardNo(HANDLE ComHandle, char Id[10]);  


//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_IcCardPowerOn(HANDLE ComHandle);
int __stdcall M100_IcCardPowerOff(HANDLE ComHandle);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_CpuCardColdReset(HANDLE ComHandle, BYTE *_CPUType,BYTE _RstData[], BYTE *_RstdataLen);
int __stdcall M100_CpuCardPowerOff(HANDLE ComHandle);
int __stdcall M100_CpuCardWarmReset(HANDLE ComHandle, BYTE _VOLTAGE,BYTE *_CPUType, BYTE _RstData[], BYTE *_RstdataLen);
int __stdcall M100_CPUT0APDU(HANDLE ComHandle, int _dataLen, BYTE _APDUData[], BYTE _exData[], int *_exdataLen);
int __stdcall M100_CPUT1APDU(HANDLE ComHandle, int _dataLen, BYTE _APDUData[], BYTE _exData[], int *_exdataLen);
int __stdcall M100_ReadInfoPOP(HANDLE ComHandle, BYTE _exData[], int *_exdataLen);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_SimColdReset(HANDLE ComHandle, BYTE *_SIMTYPE,BYTE _exData[], int *_exdataLen);
int __stdcall M100_SimCardPowerOff(HANDLE ComHandle);
int __stdcall M100_SimT0APDU(HANDLE ComHandle,  int _dataLen, BYTE _APDUData[], BYTE _exData[], int *_exdataLen);
int __stdcall M100_SimT1APDU(HANDLE ComHandle,  int _dataLen, BYTE _APDUData[], BYTE _exData[], int *_exdataLen);
int __stdcall M100_SimSelect(HANDLE ComHandle, BYTE SIMNo);
int __stdcall M100_SimWarmReset(HANDLE ComHandle,BYTE _VOLTAGE, BYTE *_SIMTYPE,BYTE _exData[], int *_exdataLen);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_AT24CXXRead(HANDLE ComHandle, BYTE _CardType, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT24CXXWrite(HANDLE ComHandle, BYTE _CardType, int _Address, BYTE _dataLen, BYTE _BlockData[]);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_AT45DB041Reset(HANDLE ComHandle);
int __stdcall M100_AT45DB041Read(HANDLE ComHandle, int  _Address, BYTE _BlockData[]);
int __stdcall M100_AT45DB041Write(HANDLE ComHandle, int  _Address, BYTE _BlockData[264]);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_AT88SC102Reset(HANDLE ComHandle);
int __stdcall M100_AT88SC102VerifyPWD(HANDLE ComHandle, BYTE _PWData[2]);
int __stdcall M100_AT88SC102Read(HANDLE ComHandle, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC102Security1Erasure(HANDLE ComHandle, BYTE _Address, BYTE _dataLen);
int __stdcall M100_AT88SC102Security2ErasureApp1(HANDLE ComHandle,BYTE _Security2App1PW[6]);
int __stdcall M100_AT88SC102Security2ErasureApp2(HANDLE ComHandle,BYTE _EC2, BYTE _Security2App2PW[4]);
int __stdcall M100_AT88SC102Write(HANDLE ComHandle, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC102WritePWD(HANDLE ComHandle, BYTE _PWType,BYTE _PWData[]);
int __stdcall M100_AT88SC102SetMode(HANDLE ComHandle, BYTE _CtrlMode);
int __stdcall M100_AT88SC102DisableEC2(HANDLE ComHandle);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_AT88SC1604Reset(HANDLE ComHandle);
int __stdcall M100_AT88SC1604VerifyPWD(HANDLE ComHandle, BYTE _PWType, BYTE _PWData[]);
int __stdcall M100_AT88SC1604Read(HANDLE ComHandle,  int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC1604Erasure(HANDLE ComHandle, int _Address, BYTE _dataLen);
int __stdcall M100_AT88SC1604Write(HANDLE ComHandle, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC1604WritePWD(HANDLE ComHandle, BYTE _PWType,BYTE _PWData[]);
int __stdcall M100_AT88SC1604Personalization(HANDLE ComHandle,BYTE _PM);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_AT88SC1608Reset(HANDLE ComHandle);
int __stdcall M100_AT88SC1608VerifyPWD(HANDLE ComHandle, BYTE _PWType, BYTE _PWData[]);
int __stdcall M100_AT88SC1608Read(HANDLE ComHandle, BYTE _Index, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC1608Write(HANDLE ComHandle, BYTE _Index, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_AT88SC1608ReadFUSE(HANDLE ComHandle, BYTE * _FAB, BYTE * _CMA, BYTE * _PER);
int __stdcall M100_AT88SC1608WriteFUSE(HANDLE ComHandle);
int __stdcall M100_AT88SC1608InitAuth(HANDLE ComHandle, BYTE _DATA[8]);
int __stdcall M100_AT88SC1608VerifyAuth(HANDLE ComHandle, BYTE _DATA[8]);
int __stdcall M100_AT88SC1608WritePWD(HANDLE ComHandle, BYTE _PWType,BYTE _PWData[]);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_SLE4442Reset(HANDLE ComHandle);
int __stdcall M100_SLE4442VerifyPWD(HANDLE ComHandle, BYTE _PWData[3]);
int __stdcall M100_SLE4442Read(HANDLE ComHandle, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_SLE4442ReadProtectBit(HANDLE ComHandle, BYTE _BlockData[32]);
int __stdcall M100_SLE4442ReadSafety(HANDLE ComHandle, BYTE _BlockData[4]);
int __stdcall M100_SLE4442Write(HANDLE ComHandle, BYTE _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_SLE4442WriteProtectBit(HANDLE ComHandle, BYTE _Address,BYTE _DataLen,BYTE _BlockData[32]);
int __stdcall M100_SLE4442ChangePWD(HANDLE ComHandle, BYTE _PWData[3]);
//+++++++++++++++++++++++++++++++++++++++++++++++++++//
int __stdcall M100_Sle4428Reset(HANDLE ComHandle);
int __stdcall M100_Sle4428VerifyPWD(HANDLE ComHandle, BYTE _PWData[2]);
int __stdcall M100_Sle4428Read(HANDLE ComHandle, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_Sle4428ReadProtectBit(HANDLE ComHandle, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_Sle4428Write(HANDLE ComHandle, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_Sle4428WriteP(HANDLE ComHandle, int _Address, BYTE _dataLen, BYTE _BlockData[]);
int __stdcall M100_Sle4428ChangePWD(HANDLE ComHandle, BYTE _PWData[2]);
//++++++++++++++++++++++++++++++++++++++++++++++++++//

int __stdcall M100_CPUTypeACardPowerOn(HANDLE ComHandle, BYTE szATR[16]);
int __stdcall M100_CPUTypeAAPDU(HANDLE ComHandle, BYTE SCH, int _dataLen, BYTE _APDUData[], BYTE* RCH,BYTE _exData[], int *_exdataLen);
int __stdcall M100_GetMachineIDNum(HANDLE ComHandle, BYTE *length, BYTE IDNum[]);
int __stdcall M100_SetMachineIDNum(HANDLE ComHandle, BYTE length, BYTE IDNum[]);
int __stdcall M100_TestCmd(HANDLE ComHandle);


int __stdcall M100_SelectPSE(HANDLE ComHandle);
int __stdcall M100_ReadPSEDirFile(HANDLE ComHandle);
int __stdcall M100_SelectADFFile(HANDLE ComHandle);
int __stdcall M100_GPOCMD(HANDLE ComHandle);
int __stdcall M100_ReadRecordFile(HANDLE ComHandle,int *len,BYTE *CardID);
int __stdcall M100_ReadICCardNum(HANDLE ComHandle,int *len,BYTE *CardID);

int __stdcall M100_CPUTypeASelectPSE(HANDLE ComHandle);
int __stdcall M100_CPUTypeAReadPSEDirFile(HANDLE ComHandle);
int __stdcall M100_CPUTypeASelectADFFile(HANDLE ComHandle);
int __stdcall M100_CPUTypeAGPOCMD(HANDLE ComHandle);
int __stdcall M100_CPUTypeAReadRecordFile(HANDLE ComHandle,int *len,BYTE *CardID);
int __stdcall M100_CPUTypeAReadICCardNum(HANDLE ComHandle,int *len,BYTE *CardID);
int __stdcall M100_CPUTypeAReadICCardNum(HANDLE ComHandle,int *len,BYTE *CardID);
int __stdcall M100_ReadRetainCount(HANDLE ComHandle, int *Count);
int __stdcall M100_ClearRetainCount(HANDLE ComHandle);

int __stdcall M100_SelectSocialSecurityApp(HANDLE ComHandle);
int __stdcall M100_SelectSocialSecurityBasicFile(HANDLE ComHandle);
//int __stdcall M100_LNSelectSocialSecurityBasicFile(HANDLE ComHandle);
//int __stdcall M100_LNSelectSocialSecurityDataFile(HANDLE ComHandle);
int __stdcall M100_ReadSocialSecurityCardID(HANDLE ComHandle,BYTE IDNum[9]);
int __stdcall M100_ReadSocialSecurityIDNum(HANDLE ComHandle,BYTE IDNum[18]);
int __stdcall M100_ReadSocialSecurityName(HANDLE ComHandle,BYTE Name[30]);
int __stdcall M100_ReadSocialSecurityGender(HANDLE ComHandle,BYTE *Sex);
int __stdcall M100_ReadSocialSecurityNation(HANDLE ComHandle,BYTE *Nation);
int __stdcall M100_ReadSocialSecurityRegional(HANDLE ComHandle,BYTE Regional[3]);
int __stdcall M100_ReadSocialSecurityBirthDay(HANDLE ComHandle,BYTE BirthDay[4]);
int __stdcall M100_ReadSocialSecurityInfo(HANDLE ComHandle,BYTE IDNum[18],BYTE Name[30],BYTE *Sex,BYTE *Nation,BYTE Regional[3],BYTE BirthDay[4]);
int __stdcall M100_AutoReadSocialSecurityInfo(HANDLE ComHandle,BYTE IDNum[18],BYTE Name[30],BYTE *Sex,BYTE *Nation,BYTE Regional[3],BYTE BirthDay[4]);
//int __stdcall M100_LNAutoReadSocialSecurityInfo(HANDLE ComHandle,BYTE IDNum[18],BYTE Name[30],BYTE *Sex,BYTE *Nation,BYTE Regional[3],BYTE BirthDay[4]);
int __stdcall M100_AutoReadSocialSecurityCardID(HANDLE ComHandle,BYTE CardID[9]);
int __stdcall M100_AutoReadSocialSecurityInfoAndCardID(HANDLE ComHandle,BYTE IDNum[18],BYTE Name[30],BYTE *Sex,BYTE *Nation,BYTE Regional[3],BYTE BirthDay[4],BYTE CardID[9]);
int __stdcall M100_PBOCGet55FieldData(HANDLE ComHandle, BYTE szField55[]);

/****************************************民泰专用******************************************/
int __stdcall M100_CPUCardPowerOn(HANDLE ComHandle, BYTE szATR[16]);
int __stdcall M100_CPUAPDU(HANDLE ComHandle, BYTE SCH, int _dataLen, BYTE _APDUData[], BYTE* RCH,BYTE _exData[], int *_exdataLen);
int __stdcall M100_ReadSerialNumber(HANDLE ComHandle, BYTE szSerialNumber[16]);