#include<stdio.h>
#include<stddef.h>      // For size_t usage, it is defined in this library

struct memory_block{
 size_t size;           // Contains size of block in bytes
 int free;              // Tells if it is free or not, if free -> 1, else 0
 struct memory_block *next;    // Pointer to next block struct
};

// Declarations of functions

void split(struct memory_block *fitting_slot,size_t size);
void *my_malloc(size_t noOfBytes);
void *my_calloc(size_t nmemb, size_t size);
void my_free(void* ptr);
size_t my_heap_free_space(void);

