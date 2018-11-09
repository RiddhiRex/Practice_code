
#include <stdio.h>

int main()
{   int x=100;
int *y=x;
int *z=&x;
    printf("%d , %d, %d \n", x, y, z); //prints 100, 100, addr of 100
    printf("%d, \n", *z); //prints 100
    printf("%d \n", *y); //segmentation fault

    return 0;
}
