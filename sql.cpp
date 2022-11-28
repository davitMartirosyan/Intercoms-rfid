#include "includes/connections.h"

typedef struct crc{
    uint32_t start; // 287454020
    char   imei[15]; // 352806846270704
    uint8_t sum;
}crc;

uint8_t Sum(char message[], int nBytes)
{
    uint8_t sum = 0;

    while(nBytes-- > 0)
    {
        sum += *(message++);
    }

    return (sum);
}

int main(int argc, const char **argv)
{
    crc *r;
    const char *imei = "352806846270704";
    int i;

    i = -1;
    r = (crc*)malloc(sizeof(crc));
    r->start = 0x11223344;
    while(imei[++i])
        r->imei[i] = imei[i];
    /*
    00000011 -> 3
    00000101 -> 5
    00000010 -> 2
    00001000 -> 8
    00000000 -> 0
    00000110 -> 6
    00001000 -> 8
    00000100 -> 4
    00000110 -> 6
    00000010 -> 2
    00000111 -> 7
    00000000 -> 0
    00000111 -> 7
    00000000 -> 0
    00000100 -> 4
    */
    printf("%c\n", r->imei[0] | r->imei[1]);
    return EXIT_SUCCESS;
}