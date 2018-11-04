#include <stdio.h>
#include <stdint.h>

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

int main()
{
    //uint32_t i = 123; //same behavior as int i=123
    int i=123;
    //printf("%d \n", sizeof(i));  //4, so go for 32 bits version of swap.
    printf("%d \n",SWAP_UINT32(i));
    return 0;
}
