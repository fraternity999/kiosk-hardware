using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Hardware
{
    public class TestService
    {
        public static string test(string param)
        {
            if (param.IndexOf("READCARDALLOWCARDIN")>0)
            {
                return allowCardIn();
            }else if (param.IndexOf("READCARDTESTINSERTCARD")>0)
            {
                return checkCard();
            }else if (param.IndexOf("READCARDMOVECARDTORF")>0)
            {
                return move();
            }

            return "";
        }

        public static string allowCardIn()
        {

            return @"<return name=""READCARDALLOWCARDIN""><arguments><string id = ""ERROR"">SUCCESS</string></arguments></return>";

        }

        public static string checkCard()
        {
            return @"<return name=""READCARDTESTINSERTCARD""><arguments><string id =""ERROR"">SUCCESS</string><string id =""CARDSTACKSTATE"">1</string></arguments></return>";
        }

        public static string move()
        {
            return @"<return name=""READCARDMOVECARDTORF""><arguments><string id = ""ERROR"">SUCCESS</string></arguments></return>";
        }
    }
}
