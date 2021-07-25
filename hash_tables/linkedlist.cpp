/*****************************************
 * Name: Hector Solis
 * Coding 06
 * Purpose: Create a Hash Table class/object 
 * with the standard struct using an int and
 * a string for 'data'
 *****************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addNode(int id, string* info){
    
    bool success = false;
    bool valid = id > 0 && *info != "";
    bool done = false;

    if(!head && valid && !done){
        success = newNode(id, info);
        done = success;
    }
    if (id < head->data.id && valid && !done){
        success = newHead(id, info);
        done = success;
    }
    if (id > head->data.id && valid && !done){
        success = insertNewNode(id, info);
    }
    
    return success;
}

bool LinkedList::deleteNode(int id){
    
    Node *current = head;
    bool success = false;

    while(current && !success){
        if(current->data.id == id && !current->prev){
            success = deleteHead(current);

        } else if(current->data.id == id && !current->next){
            success = deleteTail(current);

        } else if(current->data.id == id){
            success = deleteMiddle(current);

        } else {
            current = current->next;
        }
    }

    return success;
}

bool LinkedList::getNode(int id, Data* data){
    
    Node *current = head;
    data->id = -1;
    data->data = "";
    bool success = false;
    bool done = false;
    
    while(current && !done){
        if(current->data.id == id){
            data->id = current->data.id;
            data->data = current->data.data;
            success = true;
            done = true;
        } else {
            current = current->next;
        }
    }

    return success;
}

void LinkedList::printList(bool backwards){
    
    Node *current = head;

    if(!current){
        cout << "\tThere are 0 nodes. " << endl;
    } else {
        if(backwards){
            bool tail = false;
            while(current && !tail){
                if(current->next){
                    current = current->next;
                } else {
                    tail = true;
                }
            }
        }
        while(current){
            if(current && current->next){
                cout << current->data.id << " --> ";
            } else {
                cout << current->data.id;
            }
            
            current = backwards? current->prev: current->next;
        }
    } 
}

int LinkedList::getCount(){
    
    int count = 0;

    Node *current = head;
    while(current){
        current = current->next;
        count++;
    }
    return count;
}

bool LinkedList::clearList(){
    
    bool success = false;
    Node *current = head;
    bool done = false;

    while(current){
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    if(current == NULL){
        head = NULL;
        success = true;
    }
    return success;
}

bool LinkedList::exists(int id){
    
    bool exists = false;
    bool done = false;

    Node *current = head;
    while(current && !done){
        if(current->data.id == id){
            exists = true;
            done = true;
        } 
        current = current->next;
    }
    return exists;
}

/************************
* Private methods
* *********************/


void LinkedList::fillData(Node* new_node, int id, string* info){
    new_node->data.id = id;
    new_node->data.data = *info;
}

bool LinkedList::newNode(int id, string* info){
    Node *new_node = new Node;
    fillData(new_node, id, info);

    head = new_node;
    head->prev = NULL;
    head->next = NULL;
    return true;
}

bool LinkedList::newHead(int id, string* info){
    Node *new_node = new Node;
    fillData(new_node, id, info);

    head->prev = new_node;
    new_node->next = head;
    new_node->prev = NULL;
    head = new_node;
    return true;
}

void LinkedList::newTail(Node* new_node, Node* current){
    new_node->next = NULL;
    new_node->prev = current;
    current->next = new_node;
}

void LinkedList::newMiddle(Node* new_node, Node* current){
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
}

bool LinkedList::insertNewNode(int id, string* info){
    Node *current = head;
    bool issues = false;
    bool success = false;
        
    while(current && !issues && !success){
        if(id == current->data.id){
            issues = true;
            success = false;
        } 
        if(id > current->data.id && !current->next && !issues){
            issues = true;
            Node *new_node = new Node;
            fillData(new_node, id, info);
            newTail(new_node, current);
            success = true;
        }
        if(id > current->data.id  && !issues){
            current = current->next;            
        } else if(!issues){
            Node *new_node = new Node;
            fillData(new_node, id, info);
            newMiddle(new_node, current);
            success = true;
        }
    }
    return success; 
}

bool LinkedList::deleteHead(Node* current){
    if(!current->next && !current->prev){
        delete current;
        head = NULL;
    } else {
        current->next->prev = NULL;
        head = current->next;
        delete current;
    }
    
    return true;
}

bool LinkedList::deleteTail(Node* current){
    current->prev->next = NULL;
    delete current;
    return true;
}

bool LinkedList::deleteMiddle(Node* current){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
}