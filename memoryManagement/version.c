// Checking what is C standard in use
// gcc -dM -E - < /dev/null | grep STDC_VERSION

#include <stdio.h>

int main(void) {
#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__ >= 202311L
        printf("C23\n");
    #elif __STDC_VERSION__ >= 201710L
        printf("C17\n");
    #elif __STDC_VERSION__ >= 201112L
        printf("C11\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("C99\n");
    #else
        printf("Pre-C99\n");
    #endif
#else
    printf("C90\n");
#endif
    return 0;
}

