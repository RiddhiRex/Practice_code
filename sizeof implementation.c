#include<stdio.h> 
#include<string.h> 

#define mysizeof(x) (char *)&x +1 - (char *)&x
int main() 
{ 
   int i=1;
    printf("%d", mysizeof(i));
   return 0; 
}
