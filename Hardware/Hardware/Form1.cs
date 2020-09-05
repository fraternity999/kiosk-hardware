using Apache.NMS;
using Apache.NMS.ActiveMQ;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Hardware
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //InitProducer();
            //InitConsumer();
           StartServer();//使用静态方法，直接类+方法名
        }
        


        #region socket
        private  Socket serverS;
        static List<Socket> clientlist = new List<Socket>();
        public void StartServer()
        {
            serverS = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                IPAddress ips = IPAddress.Parse("127.0.0.1");
                IPEndPoint ipp = new IPEndPoint(ips, 8899);
                serverS.Bind(ipp);
                serverS.Listen(0);
                textBox3.Text = "socket启动成功";
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
        public void AcceptClient()
        {
            while (true)
            {
                Socket client = serverS.Accept();
                clientlist.Add(client);
                //client.Send(Encoding.Default.GetBytes("你已成功连接服务器"));
                Thread rec = new Thread(receiveMessage);
                rec.IsBackground = true;
                rec.Start(client);
            }
        }
        public void receiveMessage(object client)
        {
            Socket cli = client as Socket;
            try
            {
                byte[] buffs = new byte[1024];
                while (true)
                {
                    int sumBts = cli.Receive(buffs);
                    string param = Encoding.UTF8.GetString(buffs, 0, sumBts);
                    //string result = HardwareService.getValue(param);
                    string result = TestService.test(param);
                    Console.WriteLine(param);
                    SendMessage(result);
                }
            }
            catch (Exception e)
            {
                
                clientlist.Remove(cli);
                cli.Shutdown(SocketShutdown.Both);
            }
        }
        public  void SendMessage(string ss)
        {
            byte[] bb = Encoding.UTF8.GetBytes(ss);
            foreach (Socket me in clientlist)
            {
                me.Send(bb);
            }
        }
        #endregion

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "<invoke name=\"READCARDALLOWCARDIN\"><arguments></arguments></invoke>";
            string ret = HardwareService.getValue("<invoke name=\"READCARDALLOWCARDIN\"><arguments></arguments></invoke>");
            textBox2.Text = ret;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "<invoke name=\"READCARDTESTINSERTCARD\"><arguments></arguments></invoke>";
            string ret = HardwareService.getValue("<invoke name=\"READCARDTESTINSERTCARD\"><arguments></arguments></invoke>");
            textBox2.Text = ret;
        }

    }
}
