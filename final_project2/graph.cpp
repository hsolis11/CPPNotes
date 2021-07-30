#include "edgelist.h"

EdgeList::EdgeList(){
    edge = NULL;

}

EdgeList::~EdgeList(){
    clearList();
}

bool EdgeList::addEdge(Vertex* newVertex, int weight){
    bool success = false;
    bool issues = false;
    Edge *current = edge;

    if(!edge){
        // If there are no edges. Add a new edge.
        Edge *newEdge = new Edge;
        newEdge->nextEdge = NULL;
        newEdge->weight = weight;
        newEdge->vertex = newVertex;
        edge = newEdge;
        success = true;
    }
    while(current && !issues){
        if (current && current->vertex->data.id == newVertex->data.id){
            issues = true;
        } else if(!success && !current->nextEdge){
            // if it is tail. Then add a new Edge
            Edge *newEdge = new Edge;
            newEdge->nextEdge = NULL;
            newEdge->weight = weight;
            newEdge->vertex = newVertex;
            current->nextEdge = newEdge;
            success = true;
        } else {
            // else keep going through nextEdge
            current = current->nextEdge;
        }
    }

    return success;
}

bool EdgeList::deleteEdge(int id){
    Edge *current = new Edge;
    current = edge;
    bool success = false;

    while(current && !success){
        // cout << current->vertex->data.id;

        if(edge->vertex->data.id == id){
            // if its head being deleted
            
            if(!edge->nextEdge){
                delete current;
                edge = NULL;
                success = true;
            } else {
                edge = current->nextEdge;
                delete current;
                success = true;
            }
            
        } 
        if(current->nextEdge){
            if (current->nextEdge->vertex->data.id == id && !current->nextEdge->nextEdge){
                // if its tail being deleted. Checking one step ahead
                delete current->nextEdge;
                current->nextEdge = NULL;
                success = true;
            } else if (current->nextEdge->vertex->data.id == id){
                // if its anything else being deleted
                Edge *temp = new Edge;
                temp = current->nextEdge->nextEdge;
                delete current->nextEdge;
                current->nextEdge = temp;
                success = true;
            }
        }
        current = current->nextEdge;
    }

    return success;
}

bool EdgeList::exists(int id){
    bool exists = false;
    bool done = false;

    Edge *current = edge;
    while(current && !done){
        if(current->vertex->data.id == id){
            exists = true;
            done = true;
        }
        current = current->nextEdge;
    }

    return exists;
}

bool EdgeList::clearList(){
    bool success = false;
    Edge *current = edge;
    bool done = false;

    while(current){
        Edge *temp = current;
        current = current->nextEdge;
        delete temp;
    }
    if(current == NULL){
        edge = NULL;
        success = true;
    }

    return success;
}
