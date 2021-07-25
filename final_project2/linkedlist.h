/*****************************************
 * Name: Hector Solis
 * Coding 05
 * Purpose: Create a fully functional doubly
 * linked list class
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

        bool addVertex(int, string*);
        bool deleteVertex(int);
        bool getVertex(int, Data*);
        void printList(bool=false);
        int getCount();
        bool clearList();
        bool exists(int);

    private:
        void fillData(Vertex*, int, string*);
        bool newVertex(int, string*);
        bool newHead(int, string*);
        void newTail(Vertex*, Vertex*);
        void newMiddle(Vertex*, Vertex*);
        bool insertNewVertex(int, string*);
        bool deleteHead(Vertex*);
        bool deleteTail(Vertex*);
        bool deleteMiddle(Vertex*);
        Edge *head;
};

#endif 