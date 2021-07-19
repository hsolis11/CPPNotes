/**************************************
 * Name: Hector Solis
 * Final Project
 * Purpose: String class similar to what you find
 * in Python or C++
 **************************************/

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

using std::cout;
using std::endl;

class MyString {
public:
    MyString(const char*);
    MyString();
    ~MyString();

    char * upper(bool=false);
    char * lower(bool=false);
    char * reverse(bool=false);
    void clear();
    void set(const char*);
    int length();
    char * substring(int, int, bool=false);
    void cat(const char*);
    int count(char);
    void printmystring();

private:
    int arraylength;
    char *array;
};

#endif