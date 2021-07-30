/*
 * Do not modify this file
 */

#ifndef BINTREE_DATA_H
#define BINTREE_DATA_H

#include <string>
using std::string;

// #include "edgelist.h"
class EdgeList;

struct Data {
    int id;
    string information;
};

struct Vertex {
    Data data;
    EdgeList *edge;
    Vertex *nextVertex;
};

struct Edge {
    int weight;
    Vertex *vertex;
    Edge *nextEdge;
};

#endif /* DATA_H */
