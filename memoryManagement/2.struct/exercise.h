//Struct Padding
#pragma once


/*
typedef struct SneklangVar {
  char type;
  char *name;
  int value;
  char is_constant;
  int scope_level;
} sneklang_var_t
*/

// Re-arrange the fileds to optimal padding memory layout
// As a rule of thumb, ordering your fields from largest to smallest
// will help the compiler minimize padding
//

typedef struct SneklangVar {
  int value;
  int scope_level;
  char is_constant;
  char type;
  char *name;
} sneklang_var_t;

