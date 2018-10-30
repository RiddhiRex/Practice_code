//Find a missing # from an array 
//solution 1:
#include<stdio.h>
void main(){
int n[]={2,3,4,5,6};
int i;
int l=sizeof(n)/sizeof(n[0]);
int sum=0;
for(i=1;i<=l+1;i++){
    sum=sum+i;
}
for(i=0;i<l;i++){
    sum=sum-n[i];
}
printf("missing number is %d ", sum);
}

//solution 2:

#include<stdio.h>
void main(){
int n[]={1,2,3,5,6};
int i;
int l=sizeof(n)/sizeof(n[0]);
int sum1=0, sum2=0;
for(i=1;i<=l+1;i++){
    sum1=sum1^i;
}
for(i=0;i<l;i++){
    sum2=sum2^n[i];
}
printf("missing number is %d ", sum1^sum2);
}
