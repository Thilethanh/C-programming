// Memory Layout
/*Unions store their value in the same memory location, 
 * no matter which field or type is actively being used. 
 * That means that accessing any field apart from the one you set is generally 
 * A BAD IDEA.
 */
#include <stdio.h>
#include "limits.h"
#include "munit.h"

typedef union {
  int value;
  unsigned int err;
} val_or_err_t;

int main() {
  val_or_err_t lanes_score = {
    .value = -420
  };
  printf("value (set): %d\n", lanes_score.value);
  printf("err (unset): %u\n", lanes_score.err);
  
  val_or_err_t teejs_score = {
    .err = UINT_MAX
  };
  printf("value (unset): %d\n", teejs_score.value);
  printf("err (set): %u\n", teejs_score.err);
}
