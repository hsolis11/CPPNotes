#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "data.h"
#include "edgelist.h"

using std::cout;
using std::endl;

class Graph {

    public:
        Graph();
        ~Graph();

        bool isEmpty();
        int vertexCount();
        int edgeCount();
        bool edgeExists(int, int);
        bool addVertex(int, string, int weight = -1);
        bool addEdge(Vertex*, Vertex*, int);
        bool removeEdge(int, int);
        bool removeVertex(int); // remove vertex and all its edges
        bool getVertex(int, Data*);

    private:
        Vertex *vertex;
        int vertexcount;
        int edgecount;
};

#endif 

