#include <stdio.h>
union {
    float f;
    unsigned char c[sizeof(float)];
} foo;

int main()
{
    foo.f = 3.141593;
    for(int i=0;i<sizeof(float);i++) printf("%02X",foo.c[i]);
    return 0;
}
