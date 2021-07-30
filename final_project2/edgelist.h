#ifndef EDGE_LIST_H
#define EDGE_LIST_H

#include<iostream>
#include "data.h"

using std::cout;
using std::endl;

class EdgeList {

    public:
        EdgeList();
        ~EdgeList();

        bool addEdge(Vertex*, int);
        bool deleteEdge(int);
        bool clearList();
        bool exists(int);

    private:
        Edge *edge;
};

#endif 
