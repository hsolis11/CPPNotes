/*****************************************
 * Name: Hector Solis
 * Coding 06
 * Purpose: Create a Hash Table class/object 
 * with the standard struct using an int and
 * a string for 'data'
 *****************************************/

#include "hashtable.h"

HashTable::HashTable(){
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = nullptr;
    }
}

HashTable::~HashTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i]){
            hashtable[i]->clearList();
            delete hashtable[i];
        }
    }
}

bool HashTable::insertEntry(int id, string *data){
    bool valid = id > 0 && *data != "";
    int position = hash(id);
    bool inserted = false;

    if (valid && hashtable[position]){
        if(hashtable[position]->addNode(id, data)){
            count++;
            inserted = true;
        }
    }

    if(valid && !hashtable[position]){
        LinkedList *linkedlist = new LinkedList;
        hashtable[position] = linkedlist;

        if(hashtable[position]->addNode(id, data)){
            count++;
            inserted = true;
        }
    }

    return inserted;
}

string HashTable::getData(int id){
    string data = "";
    
    if(id > 0){
        int position = hash(id);

        for(int i = 0; i < HASHTABLESIZE && data == ""; i++){
            if(hashtable[position] && hashtable[position]->exists(id)){
                Data *temp = new Data;
                hashtable[position]->getNode(id, temp);
                data = temp->data;
            } else {
                if(position == HASHTABLESIZE - 1){
                    position = 0;
                } else {
                    position++;
                }
            }
        }

        for(int i = 0; i < HASHTABLESIZE && data == ""; i++){
            if(hashtable[position] && hashtable[position]->exists(id)){
                Data *temp = new Data;
                hashtable[position]->getNode(id, temp);
                data = temp->data;
            } else {
                if(position == HASHTABLESIZE - 1){
                    position = 0;
                } else {
                    position++;
                }
            }
        }
    }

    return data;
}

bool HashTable::removeEntry(int id){
    bool removed = false;
    int position = hash(id);

    if (id > 0){
        for(int i = 0; i < HASHTABLESIZE && !removed; i++){
            if(hashtable[position] && hashtable[position]->deleteNode(id)){
                
                if(hashtable[position]->getCount() == 0){
                    delete hashtable[position];
                    hashtable[position] = nullptr;
                }
                
                removed = true;
                count--;
            } else {
                if(position == HASHTABLESIZE - 1){
                    position = 0;
                } else {
                    position++;
                }
            }
        }

    }

    return removed;
}

int HashTable::getCount(){
    return count;
}

void HashTable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        cout << "Entry " << i << ": ";
        if(hashtable[i]){
            hashtable[i]->printList();
            cout << endl;
        } else {
            cout << "EMPTY" << endl;
        }
    }
}

/************************
* Private methods
* *********************/

int HashTable::hash(int id){
    return id % HASHTABLESIZE;
}