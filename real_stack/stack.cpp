/**************************************
 * Name: Hector Solis
 * Coding 04
 * Purpose: Create a stack object that will work
 * with a struct data type called Data
 **************************************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

/*
 * write all your stack methods here
 */

Stack::Stack(){
    top = -1;
}

Stack::~Stack(){
    for(int i=0; i <= top; i++){
        delete stack[i];
    }
}

bool Stack::push(int id, const string &info) {
    bool success = false;

    if(top < STACK_SIZE - 1){
        if(id > 0 && info != ""){
            Data *data = new Data;
            data->id = id;
            data->information = info;
            stack[++top] = data;
            success = true;
        }
    }

    return success;
}

bool Stack::pop(Data *data) {
    bool success = false;

    if(top >= 0){
        data->id = stack[top]->id;
        data->information = stack[top]->information;
        delete stack[top--];
        success = true;
    } else {
        data->id = -1;
        data->information = "";
    }

    return success;
}

bool Stack::peek(Data *data){
    bool success = false;

    if(top >= 0){
        data->id = stack[top]->id;
        data->information = stack[top]->information;
        success = true;
    }

    return success;
}

bool Stack::isEmpty() {
    return top < 0;
}