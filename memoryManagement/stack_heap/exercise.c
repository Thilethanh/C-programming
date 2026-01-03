// main4.c - Heap
#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

/*
char *get_full_greeting(char *greeting, char *name, int size) {
  char full_greeting[100];
  snprintf(full_greeting, 100, "%s %s", greeting, name);
  return full_greeting;
}
*/

/*=> allocates memory on the heap and returns a pointer to that memory. 
 * Use the provided size parameter to allocate enough space for the resulting string, 
 * be sure to account for the size of each char.
 */

char *get_full_greeting(char *greeting, char *name, int size)
{
    if (size <= 0)
        return NULL;

    /* allocate exactly `size` chars on the heap */
    char *buffer = malloc(size * sizeof(char));
    if (!buffer)
        return NULL;

    /* write at most size-1 characters + '\0' */
    snprintf(buffer, size, "%s %s", greeting, name);

    return buffer;
}

// main5.c - malloc
/*
 * The malloc function (memory allocation) is a standard library function in C that allocates a specified number of bytes of memory on the heap and returns a pointer to the allocated memory.
This new memory is uninitialized, which means:
- It contains whatever data was previously at that location.
- It is the programmer's responsibility to ensure that the allocated memory is properly initialized and eventually freed using free to avoid memory leaks.

The calloc function, which allocates the specified number of bytes of memory on the heap and returns a pointer to the allocated memory. This memory is initialized to zero (meaning it contains all zeroes).
*/
int *allocate_scalar_array(int size, int multiplier){
	if (size <= 0)
		return NULL; // handle invalid request
	/*
	if ((size_t)size > SIZE_MAX / sizeof(int))
		return NULL, // prevents integer overflow in mall
			     // require #include<limit.h>
	*/			
	
	int *arr = malloc(size * sizeof(int));
	if (!arr)
	       return NULL; // return NULL if the allocation fails
	
	// Initialize each element in the array to the index * multiplier
	for( int i=0; i < size; i++){
		arr[i] = i* multiplier;
	}
	
	return arr;
}

// main6.c - free 
/*
free does not change the value stored in the memory, and it doesn't even change the address stored in the pointer. 
Instead, it simply informs the Operating System that the memory can be used again.

Forgetting to call free leads to a memory leak. 
This means that the allocated memory remains occupied and cannot be reused,even though the program no longer needs it. 
Over time, if a program continues to allocate memory without freeing it, the program may run out of memory and crash.

Memory leaks are one of the most common bugs in C programs, 
and they can be difficult to track down because the memory is still allocated and accessible, even though it is no longer needed.
*/
 int *allocate_scalar_list(int size, int multiplier) {
  int *lst = (int *)malloc(size * sizeof(int));
  if (lst == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; i++) {
    lst[i] = i * multiplier;
  }
  return lst;
}


// ENDIANNESS
// The order in which bytes are stored in memory

// Example: 0x12345678 is a hexadecimal number

// Big Endian: the most significant bytes is stored first,
// at the lowest memory address or the biggest part of the number.
/*
 lower address	 			higher address
 <-----------    			----------->
 0x12		0x34		0x56		0x78
most significant			least significant
*/

// Little Endian: the least significant byte (the "smallest" part of the number)
// is stored first, at the lowest memory address. 
// This is the formattt used by most modern computers
/*
 lower address	 			higher address
 <-----------    			----------->
 0x78		0x56		0x34		0x12
least significant			most significant
*/

/* Note:
little-endian is cheaper for hardware, simpler for compilers, 
and historically locked in by dominant architectures.
*/

/*
big-endian is human-friendly or human-readable
So it is used in
- Network protocols
- File formats
- Some DSPs
- Teaching materials
*/

