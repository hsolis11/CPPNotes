/**************************************
 * Name: Hector Solis
 * Coding 03
 * Purpose: Introduction to a simple ADT(abstract data type)
 * and understand the function and purpose of ADTs.
 **************************************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define SIZE 10
#define EMPTY -1

class Stack
{
public:
    Stack();
    ~Stack();

    bool push(int x);
    int pop();
    bool isEmpty();
    int peek();

private:
    int top;
    int *a;
};

#endif //STACK_STACK_H