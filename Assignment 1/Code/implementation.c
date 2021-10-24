// PLEASE NOTE : The code's logic written below is not completely written by me, I had to take support from the many websites,
// as I could not get my own code working before the deadline, I have mentioned few used websites/university pdfs in the document design file.

#include <stdio.h>
#include <stddef.h>               //for size_t usage, it is defined in this library
#include <string.h>
#include "implementation.h"

char memory[1024*1024];     // We think of this as memory space given to us, we have taken a value of 1024*1024 chars array
struct memory_block *freeList = (void*)memory;    // We allocate the pointer of freelist to the start of memory array

void split(struct memory_block *fitting_slot,size_t size){

 struct memory_block *new=(void*)((void*)fitting_slot+size+sizeof(struct memory_block));
 new->size = (fitting_slot->size) - size - sizeof(struct memory_block);
 new->free = 1;
 new->next = fitting_slot->next;             // fitting_slot is the memory_block's pointer which we want to split into two parts
 fitting_slot -> size = size;                // size is the value of required space given originally to malloc as pointer
 fitting_slot -> free = 0;                   // We basically create a new memory_block and set it's size in such a way that we meet the size requirements exactly
 fitting_slot -> next = new;                 // the remaining space is present in the other memory_block/ other part

}


void *my_malloc(size_t required_size){

 struct memory_block *curr,*prev;                   // crrent and previous pointers are used to keep track while traversing in the freeList
 void *result;                               // We assign result to the memory_block which has the size equal to the required size passed to my_malloc()

 if(!(freeList->size)){

  //Initializing the freelist
  freeList->size = (1024*1024)-sizeof(struct memory_block);
  freeList->free = 1;
  freeList->next = NULL;
 
 }

 curr = freeList;

 while((((curr->size)<required_size) || ((curr->free) == 0))&&(curr->next != NULL)){
  prev = curr;
  curr = curr -> next;           //This means that current memory_block which we are checking is full, move to next memory_block
  printf("One memory_block checked, not suitable for data allocation, moving on...\n");
 }

 if((curr->size) == required_size){
  curr -> free = 0;
  result = (void*)(++curr);      //This means that the size of current memory_block is exactly what we are looking for, therefore allocate
  printf("Found the exact size of space required, allocating data at this memory_block\n");
  return result;
 }

 else if((curr -> size) > (required_size + sizeof(struct memory_block))){
  split(curr, required_size);    //This means that the size of current memory_block is more than what we need
  result = (void*)(++curr);      //therefore, we split it into two memory_blocks, one with size = what we need, other with the remaining memory_block size   
  printf("Found a memory_block having size more than what is required, therefore splitting the memory_block\n"); 
  return result;
 }
 
 else{
  result = NULL;                 //This means that there is no memory_block having sufficient amount of space
  printf("Sorry. No sufficient memory to allocate\n");
  return result;
 }

}

void my_free(void* ptr){

 if(((void*)memory <= ptr) && (ptr <= (void*)(memory + 1024*1024))){   //Checking if ptr lies in the region of memory array 
  struct memory_block *prev;                                              
  struct memory_block* curr = ptr;      
  curr -= 1;
  curr -> free = 1;                                 //Set the value of free to 1, saying that it is free for data allocation
  curr = freeList;
  while((curr -> next) != NULL){    
   if((curr -> free) && (curr -> next -> free)){    //If the pointer memory_block and the next memory_blocks are free for data allocation, we can merge them
    curr -> size += (curr -> next -> size) + sizeof(struct memory_block);
    curr -> next = curr -> next -> next;
   }
   prev = curr;
   curr = curr -> next;                             //We basically connect the previous ptr to the next ptr, bypassing a struct memory_block
  }
 }
 else printf("Please provide a valid pointer allocated by my_malloc\n");

}


void *my_calloc(size_t nmemb, size_t size)
{

    if(!(freeList->size)){

    //Initializing the freelist
    freeList->size = (1024*1024)-sizeof(struct memory_block);
    freeList->free = 1;
    freeList->next = NULL;
 
    }

    void *ptr;
    ptr = my_malloc (nmemb * size);   // Using malloc for data allocation

    if (ptr == NULL){

      printf("Not enough space to allocate memory");
      return (ptr);
    
    }

    memset(ptr, 0,nmemb * size);    // Initialize all the values to 0's and return the pointer value
    return (ptr);
}

