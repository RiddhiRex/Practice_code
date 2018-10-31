//Swap two strings

#include<stdio.h>
void main(){
    char * st1="ridd";
    char * st2="riddhi";
    char *tmp;
    tmp=st1;
    st1=st2;
    st2=tmp;
    printf("%s", st1);
}
