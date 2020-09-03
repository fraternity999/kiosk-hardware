using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Hardware
{
    public class Severs
    {
        private static Socket serverS;
        static List<Socket> clientlist = new List<Socket>();
        public static void StartServer()
        {
            serverS = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                IPAddress ips = IPAddress.Parse("127.0.0.1");
                IPEndPoint ipp = new IPEndPoint(ips, 8888);
                serverS.Bind(ipp);
                serverS.Listen(0);
                Console.WriteLine("server success");
                Thread acceptThread = new Thread(AcceptClient);
                acceptThread.Start();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
            finally
            {
                //  serverS.Close();
            }
        }
        static void AcceptClient()
        {
            while (true)
            {
                Socket client = serverS.Accept();
                clientlist.Add(client);
                client.Send(Encoding.Default.GetBytes("你已成功连接服务器"));
                Thread rec = new Thread(receiveMessage);
                rec.IsBackground = true;
                rec.Start(client);
            }
        }
        static void receiveMessage(object client)
        {
            Socket cli = client as Socket;
            try
            {
                byte[] buffs = new byte[1024];
                while (true)
                {
                    int sumBts = cli.Receive(buffs);
                    string yy = Encoding.UTF8.GetString(buffs, 0, sumBts);
                    Console.WriteLine(cli.RemoteEndPoint + ":" + yy);
                    SendMessage("收到请求");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("消息接收失败");
                clientlist.Remove(cli);
                cli.Shutdown(SocketShutdown.Both);
            }
        }
        public static void SendMessage(string ss)
        {
            byte[] bb = Encoding.UTF8.GetBytes(ss);
            foreach (Socket me in clientlist)
            {
                me.Send(bb);
            }
        }
    }
}
