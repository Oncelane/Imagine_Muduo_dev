#include "Imagine_Muduo/TcpServer.h"
#include <string>
// #include "imagine_muduo.dir"

//TestConnection会被传入到Tcpserver的msg_conn,
//server执行init的时候就会把msg_conn的DefaultRead/Write Callback赋值给自己的read/wite_callback_成员 
//后续accept创建的新EventChannel的读和写回调函数就会是这里定义的DefaultRead/Write Callback

//这两个回调函数的触发时机是poll后得到的activeChannel，被放入到线程池里面后被线程执行
class TestConnection : public Imagine_Muduo::TcpConnection
{
 public:
    void DefaultReadCallback(Connection* conn) const override
    {
        // 获取收到消息
        const char* data = conn->GetData();
        size_t data_size = conn->GetMessageLen();
        std::string return_msg = "Hello Client!";
        printf("this is Server, Get Client Message \"%s\"\n", data);

        // 将读缓冲区清空, 并设置sockfd监听写事件
        conn->IsClearReadBuffer(true);
        conn->SetRevent(Imagine_Muduo::Connection::Event::Write);
    }

    void DefaultWriteCallback(Connection* conn) const override
    {
        // 设置写缓冲区内容
        std::string return_msg = "Hello Client!";
        conn->AppendData(return_msg.c_str(), return_msg.size());

        // 设置发送完毕后清空写缓冲区, 并设置sockfd监听读事件
        conn->IsClearWriteBuffer(true);
        conn->SetRevent(Imagine_Muduo::Connection::Event::Read);
    }
};

int main()
{
    TestConnection server_conn;
    std::string profilename = "./profile/profile.yaml";
    Imagine_Muduo::TcpServer server(profilename, &server_conn);
    server.Start();
    printf("end of main");
    return 0;
}