
#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include "linkedlist.h"
#include "stack.h"

class Graph {

    public:
        Graph();
        ~Graph();

        bool isEmpty();
        int vertices(); // get count of vertices
        // int edges(); // get count of edges
        // bool edgeExist(vertice, vertice); // See if edge exists between two given vertices
        // bool addVertex(int, *string, int); // Add vertex to graph whose vertices have distinct, different values from new vertex
        bool addEdge(Vertex, Vertex, int); // Add edge between two given vertices
        // bool removeEdge(); // Remove edge between two given vertices
        // bool removeVertex(); // Remove vertex to other vertices
        // bool removeEdge(); // Remove edge to other vertices
        // bool getVertex(); // Retrieve vertex that contains given value
        // maybe sort?
        // maybe shortest path?



    private:
        int count;
        Vertex *vertex;

}

#endif