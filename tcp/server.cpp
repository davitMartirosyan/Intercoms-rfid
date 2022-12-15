#include "includes/struct.hpp"

int main()
{
    OpenConnection CRV;
    int srv, cli;
    struct sockaddr_in server, client;
    socklen_t cli_len = sizeof(client);

    srv = socket(AF_INET, SOCK_STREAM, 0);
    if(srv == -1)
    {
        perror("Socket");
        return (-1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(srv, (struct sockaddr*)&server, sizeof(server)) != 0)
    {
        perror("Bind");
        return (-2);
    }
    if(listen(srv, 5) != 0)
    {
        perror("Listen");
        return (-3);
    }

    while(1)
    {
        cli = accept(srv, (struct sockaddr*)&server, &cli_len);
        if(cli < 0)
        {
            perror("Accept");
            return (-4);
        }
        read(cli, &CRV, sizeof(CRV));
        std::cout << (int)CRV.start << std::endl;
        std::cout << CRV.imei << std::endl;
    }
}