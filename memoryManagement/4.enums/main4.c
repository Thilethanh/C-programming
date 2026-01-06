// Sizeof Enum

#include <stdio.h>

typedef enum {
  BIG = 123412341234,
  BIGGER,
  BIGGEST,
} BigNumbers;

typedef enum {
  HTTP_BAD_REQUEST = 400,
  HTTP_UNAUTHORIZED = 401,
  HTTP_NOT_FOUND = 404,
  HTTP_I_AM_A_TEAPOT = 418,
  HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

int main() {
	printf("The size of BigNumbers is %zu bytes \n", sizeof(BigNumbers));
	printf("The size of HttpErrorCode is %zu bytes \n", sizeof(HttpErrorCode));

  return 0;
}

/*
 * Generally, enums in C are the same size as an int. However, 
 * if an enum value exceeds the range of an int, 
 * the C compiler will use a larger integer type to accommodate the value, 
 * such as an unsigned int or a long.

- unsigned int doesn't represent negative numbers, so it can represent larger positive numbers.
- long is just a larger integer type than int, so it can represent larger numbers.
*/

