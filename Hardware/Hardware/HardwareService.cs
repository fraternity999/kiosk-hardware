using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace Hardware
{
    public class HardwareService
    {

        [DllImport(@"GGXmlTcp.dll")]
        public static extern int XmlTcp(StringBuilder xmlbuf, int timeout);

        public static string getValue(string param)
        {
            StringBuilder xmlBuff = new StringBuilder(1000);
            xmlBuff.Append(param);
            int ret = XmlTcp(xmlBuff, 1000);
            return xmlBuff.ToString();
        }
    }
}
