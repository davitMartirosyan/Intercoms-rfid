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
    printf("%d\n", r->imei[0]); // 3 -> ASCII -> 51 -> binary -> 
    return EXIT_SUCCESS;
}