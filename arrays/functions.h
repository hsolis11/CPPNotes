/**********************************************************************************
 * Name: Hector Solis
 * Coding 04
 * Purpose: Accept one-and-only-one parameter from the command line, which must
 * be a positive (above 0) integer, and will create two integer arrays of that
 * size, randomly fill them, display them, add them, and get thier sum and average.
 **********************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
 put all your includes and directives form main here
 */
#include<iostream>
#include<stdlib.h>
#include<cstring>

using std::cout;
using std::endl;
using std::strlen;

// use these defines in your fill random function
#define MIN 1
#define MAX 100

// do not modify these prototypes, use them as is in your cpp
int sum_array(int*, const int);
float avg_array(int*, const int);
void add_arrays(int*, int*, int*, const int);
void display_array(int*, const int);
void fill_random(int*, const int);
bool is_positive_integer(char*);

#endif /* FUNCTIONS_H */