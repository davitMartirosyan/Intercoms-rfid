#include "includes/struct.hpp"

int main()
{
    OpenConnection *handshake;
    struct sockaddr_in init;
    int sock, snd;
    const char *imei_code;
    
    imei_code = "352806846270704";
    sock = Connect(&init);
    if(sock != -1)
        MakeHandShake(&handshake, imei_code);
    snd = send(sock, handshake, 16, 0);
    if(snd == -1)
    {
        std::cout << "Not Sended" << std::endl;
        return (-3);
    }

}

int Connect(sockaddr_in *init)
{
    int sock, conn, cp;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
        std::cout << "Socket not created" << std::endl;
        return (-1);
    }
    init->sin_family = AF_INET;
    init->sin_port = htons(PORT);
    init->sin_addr.s_addr = INADDR_ANY;
    conn = connect(sock, (struct sockaddr*)&(*init), sizeof(*init));
    if(conn == -1)
    {
        std::cout << "Connection Refused" << std::endl;
        perror("connection refused");
        return (-2);
    }
    return (sock);
}

void MakeHandShake(OpenConnection **handshake, const char *imei_code)
{
    *handshake = (OpenConnection *)malloc(sizeof(OpenConnection));
    if(!handshake)
        return ;
    (*handshake)->start = 0xFE;
    push_imei((*handshake)->imei, imei_code);
}

void Ping(Ping_t *ping)
{
    std::cout << sizeof(ping) << std::endl;
}

void push_imei(char imeiAddr[], const char *imei)
{
    int cp;

    cp = -1;
    while(imei[++cp])
        imeiAddr[cp] = imei[cp];
}