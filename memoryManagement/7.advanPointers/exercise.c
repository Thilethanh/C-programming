#include "stdlib.h"
#include "exercise.h"

// main1.c
void allocate_int(int **pointer_pointer, int value) {
  
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        return;  // allocation failed; caller tests do not require handling beyond this
    }

    *p = value;          // set the integer value
    *pointer_pointer = p; // update caller's pointer
}

// main2.c - Array of pointer
/*create_token_pointer_array allocates an array of token pointers on the heap
 * but the addresses it's adding to each index are the addresses of the stack-allocated inputs.
 */
/*
token_t **create_token_pointer_array(token_t *tokens, size_t count) {
  token_t **token_pointers = malloc(count * sizeof(token_t *));
  if (token_pointers == NULL) {
    exit(1);
  }
  for (size_t i = 0; i < count; ++i) {
    token_pointers[i] = &tokens[i];
  }
  return token_pointers;
}
*/
/*
-Update the create_token_pointer_array's loop to allocate new space for each token on the heap.
-Store the address of the new space in the array instead of the stack address.
pdate the create_token_pointer_array's loop to allocate new space for each token on the heap.
Store the address of the new space in the array instead of the stack address.
Copy the members of the input struct into the newly allocated one.-Copy the members of the input struct into the newly allocated one.
*/

token_t **create_token_pointer_array(token_t *tokens, size_t count) {
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    if (token_pointers == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < count; ++i) {
        token_pointers[i] = malloc(sizeof(token_t));
        if (token_pointers[i] == NULL) {
            /* cleanup already allocated tokens */
            for (size_t j = 0; j < i; ++j) {
                free(token_pointers[j]);
            }
            free(token_pointers);
            return NULL;
        }

        /* copy struct contents */
        *token_pointers[i] = tokens[i];
    }

    return token_pointers;
}


