#include<stdio.h> 
#include<string.h> 
  
void myMemCpy(void *dest, void *src, int len) 
{ 
   // Typecast src and dest addresses to (char *) 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
  
   // Copy contents of src[] to dest[] 
   for (int i=0; i<len; i++) 
       cdest[i] = csrc[i]; 
} 
int main() 
{ 
   char src_st[100] = "asdf"; 
   char dest_st[100];
   myMemCpy(dest_st, src_st, strlen(src_st)+1); 
   printf("%s \n ", dest_st); 
  
   int src_no[] = {10, 20, 30, 40, 50}; 
   int len = sizeof(src_no)/sizeof(src_no[0]); 
   int dest_no[len], i=0;
   myMemCpy(dest_no, src_no,  sizeof(src_no)); 
   for (i=0; i<len; i++) 
     printf("%d ", dest_no[i]); 
   return 0; 
} 
