#include<stdio.h> 
#include<string.h> 
  
// A function to copy block of 'n' bytes from source 
// address 'src' to destination address 'dest'. 
void myMemMove(void *dest, void *src, int len) 
{ 
   // Typecast src and dest addresses to (char *) 
   char *csrc = (char *)src; 
   char *cdest = (char *)dest; 
   char *temp = (char *)malloc(sizeof(len));
  
   // Copy data from csrc[] to temp[] 
   for (int i=0; i<len; i++) 
       temp[i] = csrc[i]; 
  
   // Copy data from temp[] to cdest[] 
   for (int i=0; i<len; i++) 
       cdest[i] = temp[i]; 
  
   free(temp);
} 

int main() 
{ 
   char src_st[100] = "asdf"; 
   myMemMove(src_st+10, src_st, strlen(src_st)+1); 
   printf("%s", src_st); 
   return 0; 
}
