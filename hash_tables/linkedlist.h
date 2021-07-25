/*****************************************
 * Name: Hector Solis
 * Coding 06
 * Purpose: Create a Hash Table class/object 
 * with the standard struct using an int and
 * a string for 'data'
 *****************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
#include "data.h"

using std::cout;
using std::endl;

class LinkedList {

    public:
        LinkedList();
        ~LinkedList();

        bool addNode(int, string*);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool=false);
        int getCount();
        bool clearList();
        bool exists(int);

    private:
        void fillData(Node*, int, string*);
        bool newNode(int, string*);
        bool newHead(int, string*);
        void newTail(Node*, Node*);
        void newMiddle(Node*, Node*);
        bool insertNewNode(int, string*);
        bool deleteHead(Node*);
        bool deleteTail(Node*);
        bool deleteMiddle(Node*);
        Node *head;
};

#endif 