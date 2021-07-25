#include "graph.h"


Graph::Graph(){
    vertex = NULL;
    count = 0;
}

Graph::~Graph(){
    // clear();
}

bool Graph::isEmpty(){
    return count < 0;
}

int Graph::vertices(){
    return count;
}

bool Graph::addEdge(Vertex vertexA, Vertex vertexB, int weight){

    // check if VertexA.label or VertexB.label exists already
    // if(vertexA.label && vertexB.label do not exist){
    //     add both or missing vertex then add the edge
    // }
}


/*****************************************
 * Name: Hector Solis
 * Coding 05
 * Purpose: Create a fully functional doubly
 * linked list class
 *****************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addVertex(int id, string* info){
    
    bool success = false;
    bool valid = id > 0 && *info != "";
    bool done = false;

    if(!head && valid && !done){
        success = newVertex(id, info);
        done = success;
    }
    if (id < head->data.id && valid && !done){
        success = newHead(id, info);
        done = success;
    }
    if (id > head->data.id && valid && !done){
        success = insertNewVertex(id, info);
    }
    
    return success;
}

bool LinkedList::deleteVertex(int id){
    
    Vertex *current = head;
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

bool LinkedList::getVertex(int id, Data* data){
    
    Vertex *current = head;
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
    
    Vertex *current = head;

    cout << "printing list..." << endl;

    if(!current){
        cout << "\tThere are 0 Vertexs. " << endl;
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
            cout << "\t" << current->data.id << ": " << current->data.data << endl;
            current = backwards? current->prev: current->next;
        }
    } 
}

int LinkedList::getCount(){
    
    int count = 0;

    Vertex *current = head;
    while(current){
        current = current->next;
        count++;
    }
    return count;
}

bool LinkedList::clearList(){
    
    bool success = false;
    Vertex *current = head;
    bool done = false;

    while(current){
        Vertex *temp = current;
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

    Vertex *current = head;
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


void LinkedList::fillData(Vertex* new_Vertex, int id, string* info){
    new_Vertex->data.id = id;
    new_Vertex->data.data = *info;
}

bool LinkedList::newVertex(int id, string* info){
    Vertex *new_Vertex = new Vertex;
    fillData(new_Vertex, id, info);

    head = new_Vertex;
    head->prev = NULL;
    head->next = NULL;
    return true;
}

bool LinkedList::newHead(int id, string* info){
    Vertex *new_Vertex = new Vertex;
    fillData(new_Vertex, id, info);

    head->prev = new_Vertex;
    new_Vertex->next = head;
    new_Vertex->prev = NULL;
    head = new_Vertex;
    return true;
}

void LinkedList::newTail(Vertex* new_Vertex, Vertex* current){
    new_Vertex->next = NULL;
    new_Vertex->prev = current;
    current->next = new_Vertex;
}

void LinkedList::newMiddle(Vertex* new_Vertex, Vertex* current){
    new_Vertex->next = current;
    new_Vertex->prev = current->prev;
    current->prev->next = new_Vertex;
    current->prev = new_Vertex;
}

bool LinkedList::insertNewVertex(int id, string* info){
    Vertex *current = head;
    bool issues = false;
    bool success = false;
        
    while(current && !issues && !success){
        if(id == current->data.id){
            issues = true;
            success = false;
        } 
        if(id > current->data.id && !current->next && !issues){
            issues = true;
            Vertex *new_Vertex = new Vertex;
            fillData(new_Vertex, id, info);
            newTail(new_Vertex, current);
            success = true;
        }
        if(id > current->data.id  && !issues){
            current = current->next;            
        } else if(!issues){
            Vertex *new_Vertex = new Vertex;
            fillData(new_Vertex, id, info);
            newMiddle(new_Vertex, current);
            success = true;
        }
    }
    return success; 
}

bool LinkedList::deleteHead(Vertex* current){
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

bool LinkedList::deleteTail(Vertex* current){
    current->prev->next = NULL;
    delete current;
    return true;
}

bool LinkedList::deleteMiddle(Vertex* current){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    return true;
}