// free() - encounter of malloc, calloc, realloc
#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

int main(){
  const int num_lists = 500;

// leaking memory in a loop
// /*
for (int i = 0; i < num_lists; i++) {
    int *lst = allocate_scalar_list(50000, 2);
    if (lst == NULL) {
      printf("Failed to allocate list\n");
      return 1;
    } else {
      printf("Allocated list %d\n", i);
    }
  }
//*/

// fixing
 /*
  for (int i = 0; i < num_lists; i++) {
    int *lst = allocate_scalar_list(50000, 2);
    if (lst == NULL) {
      printf("Failed to allocate list\n");
      return 1;
    } 
    
    printf("Allocated list %d\n", i);
    free(lst);
  }

*/
  return 0;
}
