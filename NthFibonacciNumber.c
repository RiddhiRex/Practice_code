//Nth fibonacci number
#include<stdio.h>
void main(){
    int a=-1;
    int b=1;
    int c=0, i;
    int n=6;
    for(i=0;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    printf("%d ", c);
}
