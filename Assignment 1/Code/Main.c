#include "implementation.h"

int main(){
 
 // Simply tried to allocate and deallocate memory of type int and char using my_malloc()
 // Also tried to allocate using my_calloc(), deallocate using my_free()

 int *p=my_malloc(50*sizeof(int));
 char *q=my_malloc(300*sizeof(char));
 my_free(p);
 my_free(q);
 int *r = my_calloc(50,sizeof(int));
 my_free(r);

 printf("Data allocation and deallocation is completed without any errors finally!");
 
}