/**************************************
 * Name: Hector Solis
 * Coding 03
 * Purpose: Introduction to a simple ADT(abstract data type)
 * and understand the function and purpose of ADTs.
 **************************************/

#include "main.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    Stack stack;
    int peek;

    cout << "verify stack is empty" << endl;
    if(stack.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    cout << "attempt to peek at empty stack" << endl;
    try {
        peek = stack.peek();
        cout << "peek element is " << peek << endl;
    } catch (int e) {
        cout << "error: Stack Underflow" << endl;
    }
    cout << endl;


    cout << "Fill up stack with random integers range from -100 to 100" << endl;
    for(int i=1; i < 11; i++){
        int random_int = (rand() % 201) - 100;

        if(stack.push(random_int)){
            cout << "Element " << random_int << " Inserted" << endl;
            cout << "current peek element " << stack.peek() << endl;
        } else {
            cout << "error: Stack Overflow" << endl;
        }
    }
    cout << endl;


    cout << "verify stack is now filled" << endl;
    if(stack.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    cout << endl;


    cout << "attempt to push 5 additional elements and peek value " << stack.peek() << " should remain unchanged" << endl;

    for(int i=11; i < 16; i++){
        int random_int = (rand() % 201) - 100;
        cout << "attempting to push element " << random_int << endl;
        if(!stack.push(random_int)){
            cout << "error: Stack Overflow" << endl;
        };
        cout << "peek element is " << stack.peek() << endl;
    }
    cout << endl;


    cout << "attempt to pop up to 15 elements until underflows" << endl;
    for(int i=1; i < 16; i++){
        try {
            peek = stack.peek();
            cout << "current top element " << peek << " to be removed" << endl;
            cout << stack.pop() << " has been removed" << endl;
        } catch (int e) {
            cout << "error: Stack Underflow" << endl;
        }
    }

    return 0;
}