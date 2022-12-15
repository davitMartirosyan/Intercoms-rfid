# include "includes/serv_include.h"

int main()
{
    std::thread http_serv_thread(http_serv, 9900); // -> qeri
                // _____
                // |   |   -----> Listener
                // -----
    std::thread socket_serv_thread(socket_serv, 8080); //-> hopar

    http_serv_thread.join();
    socket_serv_thread.join();

    return 0;
}

