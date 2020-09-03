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


        public void InitConsumer()
        {
            //创建连接工厂
            IConnectionFactory factory = new ConnectionFactory("tcp://127.0.0.1:61616");
            //通过工厂构建连接
            IConnection connection = factory.CreateConnection();
            //这个是连接的客户端名称标识
            connection.ClientId = "Z1";
            //启动连接，监听的话要主动启动连接
            connection.Start();
            //通过连接创建一个会话
            ISession session = connection.CreateSession();
            //通过会话创建一个消费者，这里就是Queue这种会话类型的监听参数设置
            IMessageConsumer consumer = session.CreateConsumer(new Apache.NMS.ActiveMQ.Commands.ActiveMQQueue("ClientReceive1"));
            //注册监听事件
            consumer.Listener += new MessageListener(consumer_Listener);
        }

        void consumer_Listener(IMessage message)
        {
            ITextMessage msg = (ITextMessage)message;
            //异步调用下，否则无法回归主线程
            textBox3.Invoke(new DelegateRevMessage(RevMessage), msg);

        }

        public delegate void DelegateRevMessage(ITextMessage message);

        public void RevMessage(ITextMessage message)
        {
            textBox3.Text += string.Format(@"接收到:{0}{1}", message.Text, Environment.NewLine);


            //发送消息
            //通过工厂建立连接
            using (IConnection connection = factory.CreateConnection())
            {
                //通过连接创建Session会话
                using (ISession session = connection.CreateSession())
                {
                    //通过会话创建生产者，方法里面new出来的是MQ中的Queue
                    IMessageProducer prod = session.CreateProducer(new Apache.NMS.ActiveMQ.Commands.ActiveMQQueue("ClientSend1"));
                    //创建一个发送的消息对象
                    ITextMessage message1 = prod.CreateTextMessage();
                    //给这个对象赋实际的消息
                    message1.Text = HardwareService.getValue(message.Text);
                    //设置消息对象的属性，这个很重要哦，是Queue的过滤条件，也是P2P消息的唯一指定属性
                 
                    //生产者把消息发送出去，几个枚举参数MsgDeliveryMode是否长链，MsgPriority消息优先级别，发送最小单位，当然还有其他重载
                    prod.Send(message1, MsgDeliveryMode.NonPersistent, MsgPriority.Normal, TimeSpan.MinValue);
                }
            }
        }




        private IConnectionFactory factory;

        public void InitProducer()
        {
            try
            {
                //初始化工厂，这里默认的URL是不需要修改的
                factory = new ConnectionFactory("tcp://127.0.0.1:61616");

            }
            catch
            {
                textBox3.Text = "初始化失败!!";
            }
        }

        /// <summary>
        /// 获取本机ip
        /// </summary>
        public string GetAddressIP()
        {
            ///获取本地的IP地址
            string AddressIP = string.Empty;
            foreach (IPAddress _IPAddress in Dns.GetHostEntry(Dns.GetHostName()).AddressList)
            {
                if (_IPAddress.AddressFamily.ToString() == "InterNetwork")
                {
                    AddressIP = _IPAddress.ToString();
                }
            }
            return AddressIP;
        }


        #region socket
        private  Socket serverS;
        static List<Socket> clientlist = new List<Socket>();
        public  void StartServer()
        {
            serverS = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                IPAddress ips = IPAddress.Parse("127.0.0.1");
                IPEndPoint ipp = new IPEndPoint(ips, 8888);
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
                    string result = "hello";
                 
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
