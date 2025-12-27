// main3.c - Pointer Basics
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

// main4.c - C Arrays
void update_file(int filedata[200], int new_filetype, int new_num_lines){
  // 
  filedata[1] = new_num_lines;
  filedata[2] = new_filetype;
  filedata[199] = 0;
}

// main5.c - Array Casting
#include <stdio.h> 

void dump_graphics(graphics_t gsettings[10]) {
  int *ptr = (int *)gsettings;
  for (int i = 0; i <330; i++) {
    printf("settings[%d] = %d\n", i, ptr[i]);
  }
}

/*
 * In C, pointers are always the same size because they just represent memory addresses. 
 * The size of a pointer is determined by the architecture of the system
 * A pointer's size doesn't depend on the type of data it points to; 
 * it just holds the address of a memory location.
 * 4 bytes - 32-bits, 8 bytes - 64-bits
 */


// main6.c - C string

/*
 * Pointers vs. Arrays
You can declare strings in C using either arrays or pointers:

char str1[] = "Hi";
char *str2 = "Snek";
printf("%s %s\n", str1, str2);
// Output: Hi Snek
*/

/*
Use char[] when:
- You need to modify the string
- Stack/local buffers
- Embedded systems

Use char * when:
- String is constant
- Lookup tables
- Read-only text
*/

void concat_strings(char *str1, const char *str2) {
  // 
      /* 1. Find end of str1 */
    while (*str1 != '\0') {
        str1++;
    }

    /* 2. Copy str2 to the end of str1 */
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }

    /* 3. Add null terminator */
    *str1 = '\0';
}

// main7.c - C string library
#include <string.h>

/*
// strcpy: Copies a string to another.
char src[] = "Hello";
char dest[6];
strcpy(dest, src);
// dest now contains "Hello"

// strncpy: Copies a specified number of characters from one string to another.
char src[] = "Hello";
char dest[6];
strncpy(dest, src, 3);
// dest now contains "Hel"
dest[3] = '\0';
// ensure null termination

// strcat: Concatenates (appends) one string to another.
char dest[12] = "Hello";
char src[] = " World";
strcat(dest, src);
// dest now contains "Hello World"

// strncat: Concatenates a specified number of characters from one string to another.
char dest[12] = "Hello";
char src[] = " World";
strncat(dest, src, 3);
// dest now contains "Hello Wo"

// strlen: Returns the length of a string (excluding the null terminator).
char str[] = "Hello";
size_t len = strlen(str);
// len is 5

// strcmp: Compares two strings lexicographically.
char str1[] = "Hello";
char str2[] = "World";
int result = strcmp(str1, str2);
// result is negative since "Hello" < "World"

// strchr: Finds the first occurrence of a character in a string.
char str[] = "Hello";
char *pos = strchr(str, 'l');
// pos points to the first 'l' in "Hello"

// strstr: Finds the first occurrence of a substring in a string.
char str[] = "Hello World";
char *pos = strstr(str, "World");
// pos points to "World" in "Hello World"
*/

int smart_append(TextBuffer *dest, const char *src)
{
    /* 1. NULL checks
     * If either input is NULL, return 1 (failure).
     * The checks can be done with ptr == NULL or !ptr. */
    if (dest == NULL || src == NULL)
        return 1;

    /* 2. max buffer size 
     * Create a constant to represent the max buffer size of 64*/
    const size_t MAX_SIZE = 64;

    /* 3. src lengthi
     * Get the length of the src string using strlen.*/
    size_t src_len = strlen(src);

    /* 4. Calculate  remaining space.
     * Null terminator doesn't count as part of the length */
    size_t remaining = MAX_SIZE - dest->length - 1;

    /* 5. if not enough space 
     * - partial append
     * - update dest buffer length to max size
     * - Return 1, to indicate the full append failed */
    if (src_len > remaining) {
        strncat(dest->buffer, src, remaining);
        dest->length = MAX_SIZE - 1;   // full buffer, excluding '\0'
        return 1;
    }

    /* 6. enough space 
     * - full append
     * - update the dest buffer length
     * - return 0, the full append success */
    strcat(dest->buffer, src);
    dest->length += src_len;
    return 0;
}

// main8.c - Forward Declaration
#include <stdlib.h>

snekobject_t new_node(char *name) {
  snekobject_t node = {
    .name = name,
    .child = NULL
  };
  return node;

}

// main9.c - Mutual Structs
/*
 * Forward declarations can also be used when two structs reference each other (a circular reference). 
 * For example, a Person has a Computer and a Computer has a Person:

typedef struct Computer computer_t;
typedef struct Person person_t;

struct Person {
  char *name;
  computer_t *computer;
};

struct Computer {
  char *brand;
  person_t *owner;
};
*/

employee_t create_employee(int id, char *name) {
  employee_t emp = {
    .id = id,
    .name = name,
    .department = NULL
  };
  return emp;
}

department_t create_department(char *name) {
  department_t dept = {
    .name = name,
    .manager = NULL
  };
  return dept;
}

void assign_employee(employee_t *emp, department_t *department) {
  emp->department = department;
}

void assign_manager(department_t *dept, employee_t *manager) {
  dept->manager = manager;
}


