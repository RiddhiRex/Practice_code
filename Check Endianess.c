#include<stdio.h> 
#include<string.h> 

int main() 
{ 
   unsigned int i=1;
   char *c = (char *)&i;
   if(*c==1)
    printf("Little Endian");
   else
    printf("Big Endian");
   return 0; 
}
