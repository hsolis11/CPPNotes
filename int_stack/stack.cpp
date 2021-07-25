/**************************************
 * Name: Hector Solis
 * Coding 03
 * Purpose: Introduction to a simple ADT(abstract data type)
 * and understand the function and purpose of ADTs.
 **************************************/

#include "stack.h"

Stack::Stack(){
    top = EMPTY;
    a = new int[SIZE];
}


Stack::~Stack(){
    delete[] a;
}


bool Stack::push(int x){
    bool success = false;

    if(top < SIZE-1){
        a[++top] = x;
        success = true;
    }

    return success;
}


int Stack::pop(){

    if(top <= EMPTY){
        throw 0;
    }

    return a[top--];
}


bool Stack::isEmpty(){
    return top <= EMPTY;
}


int Stack::peek() {

    if(top <= EMPTY){
        throw 0;
    }

    return a[top];
}