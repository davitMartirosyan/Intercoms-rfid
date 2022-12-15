# include <iostream>
# include <thread>
# include <sys/socket.h>
# include <unistd.h>
# include <netinet/in.h>
# include <vector>

void doWork(int serv_sock);
std::vector<std::thread> threads;

void client(int port)
{

    int sock, conn, new_sock;
    struct sockaddr_in addr;
    int len = sizeof(addr);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(!sock)
    {
        perror("Could not create Socket Deskriptor!\n");
        exit (-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port =  htons(port);
    if(bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        perror("Could not bind!\n");
        exit (-2);
    }

    std::cout << "Binded!" << std::endl;

    while(1)
    {
        std::cout << "Listen\n";
        if(listen(sock, 1) < 0)
        {
            perror("Nothing to listen\n");
            exit(-3);
        }

        if((new_sock = accept(sock, (struct sockaddr*)&addr, (socklen_t*)&len)) < 0)
        {
            perror("Not accepted\n");
            exit(-4);
        }
        std::cout << "Accepted\n";
        threads.push_back(std::thread(doWork, new_sock));
    }
}

void doWork(int serv_sock)
{
    std::cout << "New Connection from: " << serv_sock << std::endl;
}

int main()
{
    std::thread client_server(client, 8080);

    client_server.join();
    return (0);
}