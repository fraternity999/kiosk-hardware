using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace SunRise.HOSP.Hardware
{
    
    public class RDDF1EF05Model
    {

        public string oKLB { get; set; }//卡类别代码 
        public string oGFBB { get; set; }//规范版本 
        public string oFKJGMC { get; set; }//发卡机构名称 
        public string oFKJGDM { get; set; }//发卡机构代码 
        public string oFKJGZS { get; set; }//发卡机构证书 
        public string oFKSJ { get; set; }//发卡时间 D8格式 
        public string oKH { get; set; }//卡号，与居民身份证号或者证件号码一致 
        public string oAQM { get; set; }//安全码 
        public string oXPXLH { get; set; }//芯片序列号 
        public string oYYCSDM { get; set; }//应用城市代码

    }

    public class RDDF1EF06Model
    {
        public string oXM { get; set; }//姓名 
        public string oXB { get; set; }//性别代码 
        public string oMZ { get; set; }//民族代码 
        public string oCSRQ { get; set; }//出生日期D8格式 
        public string oSFZH { get; set; }//居民身份证号 
        public string oerrMsg { get; set; }//操作失败时，返回的具体错误提示信息。
    }

    public class RDDF1EF07Model
    {
        public byte[] oZHAOPIAN { get; set; }//照片数据(十六进制返回) （照片文件存放方式为4字节照片数据长度+照片数据）
    }
    public class RDF01EF05Model
    {
        public string oDZLB1 { get; set; }//地址类别1 
        public string oDZ1 { get; set; }//地址1 户籍地址 
        public string oDZLB2 { get; set; }//地址类别2 
        public string oDZ2 { get; set; }//地址2 居住地址 
    }
    public class RDDF1EF08Model
    {
        public string oKYXQ { get; set; }//卡有效期D8格式 
        public string oBRDH1 { get; set; }//本人电话1 
        public string oBRDH2 { get; set; }//本人电话2 
        public string oYLFYZFFS1 { get; set; }//医疗费用支付方式1 
        public string oYLFYZFFS2 { get; set; }//医疗费用支付方式2 
        public string oYLFYZFFS3 { get; set; }//医疗费用支付方式3 
    }
    public class SS728M05Model
    {
        public RDDF1EF05Model MRDDF1EF05Item { get; set; }
        public RDDF1EF06Model RDDF1EF06Item { get; set; }
        public RDDF1EF07Model RDDF1EF07Item { get; set; }
        public RDF01EF05Model RDF01EF05Item { get; set; }
        public RDDF1EF08Model RDDF1EF08Item { get; set; }
    }

    public class SS728M05API
    {
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_ResetID2Card(int icdev);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_read_card(int icdev, Int16 Flag = 0);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_name(int icdev, byte[] _Name);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_sex(int icdev, byte[] _Sex);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_sexL(int icdev, byte[] _Sex);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_folk(int icdev, byte[] _Folk);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_folkL(int icdev, byte[] _Folk);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_birth(int icdev, byte[] _Date);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_address(int icdev, byte[] _Addr);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_number(int icdev, byte[] _Number);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_organ(int icdev, byte[] _Organ);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_termbegin(int icdev, byte[] _Date);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_termend(int icdev, byte[] _Date);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_photo_data(int icdev, int _Format, byte[] ImageData, ref int ImageLen);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int ss_id_query_photo_file(int icdev, int _Format, string ImagePath);

        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_AHSLYY_A6Init(int ReaderHandle, int Port, int BaudRate);

        /*参数：ReaderHandle[in]：调用A6SAPI.dll打开设备函数返回的设备句柄。
返回值：0代表成功，其他代表失败。*/
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_AHSLYY_A6Init(uint ReaderHandle);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_OpenDevice();
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_CloseDevice();
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_PowerOn(int iReaderHandle, int islot, StringBuilder oATR, ref int atrlen, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_VerifyPIN(int iReaderHandle, Int16 iindexPsam, string iszPIN, ref byte[] opwdRetry, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_RDDF1EF05(int ihDev, StringBuilder oKLB, StringBuilder oGFBB, StringBuilder oFKJGMC,
            StringBuilder oFKJGDM, StringBuilder oFKJGZS, StringBuilder oFKSJ, StringBuilder oKH, StringBuilder oAQM,
            StringBuilder oXPXLH, StringBuilder oYYCSDM, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_RDDF1EF06(int ihDev, StringBuilder oXM, StringBuilder oXB, StringBuilder oMZ,
            StringBuilder oCSRQ, StringBuilder oSFZH, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_RDDF1EF07(int ihDev, byte[] oZHAOPIAN, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_RDDF1EF08(int ihDev, StringBuilder oKYXQ, StringBuilder oBRDH1, StringBuilder oBRDH2, StringBuilder oYLFYZFFS1,
            StringBuilder oYLFYZFFS2, StringBuilder oYLFYZFFS3, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_RDF01EF05(int ihDev, StringBuilder oDZLB1, StringBuilder oDZ1, StringBuilder oDZLB2, StringBuilder oDZ2, StringBuilder oerrMsg);
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_WSB_CloseDevice(int iReaderHandle, StringBuilder oerrMsg);





        /*
         函数说明：三合一读卡
参数：
ReaderHandle[int]：函数句柄。
CardType[out]：卡类型，二代证=1，居民健康卡=2，磁条卡=3，其他=-1。
CardInfo[out]：卡信息，格式为：磁条卡=二轨道信息|三轨道信息|，二代证及居民健康卡=姓名|性别|民族|出生日期|身份证号码|联系电话|，由于身份证中并没有存储联系电话，因此从二代证读取的联系电话均为空。
ErrMsg[out]：函数执行失败是，返回的错误信息。
         */
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_AHSLLY_ReaderCard(long ReaderHandle, ref int CardType, StringBuilder CardInfo, StringBuilder ErrMsg);
        /*
         函数说明：白卡读卡
参数：
ReaderHandle[int]：函数句柄。
CardInfo[out]：读取的卡信息，格式为：发卡机构名称|发卡机构编码|姓名|性别|民族代码|出生日期|身份证号码|照片数据|联系电话|。
ErrMsg[out]：函数执行失败是，返回的错误信息。
         */
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_AHSLYY_HC_Read(long ReaderHandle, StringBuilder CardInfo, StringBuilder ErrMsg);
        /*
         函数说明：白卡写卡
 参数：
 ReaderHandle[int]：函数句柄。
 CardInfo[out]：写入的卡信息，格式为：发卡机构名称|发卡机构编码|姓名|性别|民族代码|出生日期|身份证号码|照片数据|联系电话|。
 ErrMsg[out]：函数执行失败是，返回的错误信息。
         */
        [DllImport(@"ReadCard\SS728M05\SS728M05_SDK.dll")]
        public static extern int SS_AHSLYY_HC_Write(long ReaderHandle, StringBuilder CardInfo, StringBuilder ErrMsg);
    }
}
