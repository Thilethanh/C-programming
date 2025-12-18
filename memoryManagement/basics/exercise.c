#include "exercise.h"

#include <stdio.h> // use for main5.c

// Assigment 1 respones to main1.c
// Take 3 integers and return the average in float 
float get_average(int x, int y, int z){
  
  return (x + y + z) / 3.0f;
}


// Assignment 2 - main2.c
float snek_score(
  int num_files,
  int num_contributors,
  int num_commits,
  float avg_bug_criticality
) {
  // 
  int size_factor = num_files * num_commits;
  int complexity_factor = size_factor + num_contributors;

  return (float)complexity_factor * avg_bug_criticality;
}

// main3.c
char *get_temperature_status(int temp){

    if (temp < 70) return "too cold";
    if (temp > 90) return "too hot";
    return "just right";
}

// logical operator - main4.c

int can_access_registry(int is_premium, int reputation, int has_2fa)
{
    if (is_premium)
        return 1;

    if (reputation >= 100 && has_2fa)
        return 1;

    return 0;
}

// Tenary
/*
 *
 *
 *
int a = 5;
int b = 10;
int max = a > b ? a : b;
printf("max: %d\n", max);
// max: 10 

a > b ? a : b  - If a > b, max = a else max = b

a > b is the condition
? begins the "then" value
a is the final value if the condition is true
: separates the "else" value
b is the final value if the condition is false
The entire expression (a > b ? a : b) evaluates to either a or b, 
which is then assigned to max in our example.

 */


// For loop -  main5.c
void print_numbers(int start, int end){
  for ( ;start <= end; start++) {
    printf("%d\n", start);
  }
  
}

// While loop and Do while loop - main6.c
void print_numbers_reverse(int start, int end){
	
	do {
		printf("%d\n", start);
		start--;
	}while ( start >= end );
}

/*
 *
 
#pragma once
prevent a header file from being included more than once,
avoiding redefinition errors.

// Header Guards
#ifndef MY_HEADER_H
#define MY_HEADER_H

// some cool code

#endif

defining a unique macro for the header file. 
If it’s already been included, the guard prevents it
from being processed again.

*/





