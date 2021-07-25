/*****************************************
 * Name: Hector Solis
 * Coding 06
 * Purpose: Create a Hash Table class/object 
 * with the standard struct using an int and
 * a string for 'data'
 *****************************************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include<iostream> //delete
#include "linkedlist.h"
#include "data.h"

#define HASHTABLESIZE 15

using std::cout; // delete
using std::endl; // delete

class HashTable {

    public:
        HashTable();
        ~HashTable();


        bool insertEntry(int, string*);
        string getData(int);
        bool removeEntry(int);
        int getCount();
        void printTable();

    private:
        int hash(int);

        LinkedList *hashtable[HASHTABLESIZE];
        int count;
};


#endif