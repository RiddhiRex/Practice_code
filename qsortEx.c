//EXAMPLE USAGE OF qsort() in C

#include<stdio.h>
#include<stdlib.h>
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a-*(int*)b ); 
} 

void main(){
    int i=0;
    int no[]={1,11,2,14,6,9};
    qsort(no, 6, sizeof(int), compare);
    for(i=0;i<6;i++){
        printf("%d ", no[i]);
    }
}
