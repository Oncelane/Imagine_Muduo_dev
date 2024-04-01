#include <arpa/inet.h>
#include <string>
#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1) {
        struct sockaddr_in addr;
        std::string ip("192.168.134.128");
        std::string port("9999");
        std::string send_content("Hello Server!");
        char recv_content[1024];
        int ret = inet_pton(AF_INET, &ip[0], &addr.sin_addr.s_addr);

        addr.sin_port = htons(atoi(&port[0]));
        addr.sin_family = AF_INET;

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        int reuse = 1;
        setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse));
        ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        write(sockfd, &send_content[0], send_content.size());
        ret = read(sockfd, recv_content, 1024);
        printf("This is Client, Receive Server Message \"%s\"\n", recv_content);
        close(sockfd);
        sleep(1);
    }

    return 0;
}