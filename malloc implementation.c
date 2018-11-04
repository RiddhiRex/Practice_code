#include<stdio.h>
#include<stdlib.h>
#include "include/mem.h" //for using sbrk() function
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h> //for using bool data type

typedef struct page
{
  size_t size;
  bool free;
  struct page* next;
  struct page* prev;
} page_t;

page_t* global; //maintain global free store
page_t* last; //pointer of last node in used space linked list

page_t* allocate(size_t size)
{
  page_t* node = sbrk(0); //Calling sbrk() with an increment of 0 can be used to find the current location of the program break.
  void* pointer = sbrk(size + sizeof(page_t)); //increment the sbrk pointer to fit data and meta-data. Incrementing the program break. Here we allocated needed memory
  if(pointer == SBRK_ERROR)
    return NULL;
  if(last != NULL) //used space linked-list has some used space already. First time of execution, it will be NULL
    last-> next = node;
  last = node; //make the newly allocated node as last node
  last-> size = size;
  last-> free = false;
  last-> next = NULL;
  return last; //return pointer to the newly allocated space which is at the end of last linked-list
}

void* search(size_t size)
{
  page_t* node = global; //look for big enough free space in global free-list
  while(node != NULL){ //check if global free space is available
    if(node-> size >= size && node->free){ //look for big enough free space
        return node;
    }
    node = node-> next; //traverse till we find big enough free space
  }
  return NULL;
}

void* memalloc(size_t size)
{
  page_t* result = NULL;
  if(size >= 0){
    /*
    keep a linked list of free block. if the global free space list is not empty,
    you search for a block large enough to satisfy the request and return it.
    If the list is empty or if no such block can be found, 
    you call sbrk to allocate some memory from the operating system.*/
    if(global != NULL){ //check if any space in global free space
      result = search(size); //search for free space
      if(result == NULL) //there are some free space but they are not big enough for the request
        result = allocate(size); //then call allocate to borrow memory from sbrk
    }
    else { //no space in  global free space linked list
      global = allocate(size); //call allocate to borrow and allocate new memory from sbrk
      result = global;
    }
  }
  return result != NULL ? (result + 1) : NULL;
}

page_t* to_page(void* pointer){
  return pointer - sizeof(page_t); //subtract the data from the starting addr of pointer
}

void memfree(void* pointer)
{
  if(pointer != NULL) {
    page_t* page = to_page(pointer);
    page-> free = true; //mark that page free
  }
}

int main(int argc, char** argv)
{
  char* pointer = memalloc(5);
  memfree(pointer);
  return 1;
}
