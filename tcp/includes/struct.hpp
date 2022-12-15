# include <iostream>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <unistd.h>
# include <string>
# define PORT 8080

typedef struct OpenConnection
{
    uint8_t start;
    char imei[15];
}OpenConnection;

typedef struct Ping_t
{
    uint8_t start;
    uint8_t workMode;
    uint16_t devVersion;
    uint8_t sim;
    uint8_t conn_sim_1;
    uint8_t conn_sim_2;
    uint16_t battery;
    uint32_t upd_time_NFC;
    uint32_t upd_time_PIN;
}Ping_t;

typedef struct History_t
{
    uint8_t start;
    uint32_t time;
    uint8_t type_NFC_OR_PIN;
    uint64_t value_NFC_OR_PIN;
    uint16_t CRC;
}History_t;

int Connect(sockaddr_in *init);
void MakeHandShake(OpenConnection **handshake, const char *imei_code);
void Ping(Ping_t *ping);
void push_imei(char imeiAddr[], const char *imei);
