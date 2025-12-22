//main3.c - Pointer Basics

#include "exercise.h"

codefile_t change_filetype(codefile_t *f, int new_filetype){
  codefile_t new_f = *f;
  new_f.filetype = new_filetype;
  return new_f;
}


// Example how it is used
/*
 * 
codefile_t original = { .filetype = 1 };
codefile_t updated  = change_filetype(&original, 2);
*/
