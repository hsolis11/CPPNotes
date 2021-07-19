/**************************************
 * Name: Hector Solis
 * Coding 07
 * Purpose: Program will create a "list" like object 
 * that behaves similarly to the List object in Python.
 **************************************/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand, atoi */
#include <time.h>       /* time */
// you can add libraries if you need them, but you shouldn't

using std::cout;
using std::endl;

// DO NOT MODIFY THESE DEFINES
#define RMIN 1
#define RMAX 10
#define DEFAULT_SIZE 10

class MyList {
public:
    // DO NOT MODIFY THESES NEXT TWO
    MyList(int); // constructor
    ~MyList(); // destructor

    int getElement(int);
    bool getElement(int, int*);
    int getLength();
    bool getSorted();
    void sort();

    void setArray(int);
    void setRandom(int, int);
    bool setElement(int, int);
    bool resizeArray(int);

    void printArray();

private:
    // these are the only attributes allowed
    // DO NOT ADD OR MODIFY THEM
    int length;
    int *array;
    bool sorted;

    void swap(int*, int*);
};

#endif //MYLIST_H