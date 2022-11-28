#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>


typedef struct crc{
    uint32_t start; // 287454020
    char   imei[15]; // 352806846270704
    uint8_t crc;
}crc;

int main(int argc, const char **argv)
{
    crc *r;

    r = malloc(sizeof(crc));
    r->start = 0x11223344;
    printf("%d\n", (int)r->start);
    return EXIT_SUCCESS;
}