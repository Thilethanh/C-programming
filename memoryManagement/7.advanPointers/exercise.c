#include "stdlib.h"

#include "exercise.h"

void allocate_int(int **pointer_pointer, int value) {
  // ?
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        return;  // allocation failed; caller tests do not require handling beyond this
    }

    *p = value;          // set the integer value
    *pointer_pointer = p; // update caller's pointer
}

