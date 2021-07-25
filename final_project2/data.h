

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;

};

struct Vertex {
    Data data;
    Vertex *next;
};

struct Edge {
    int weight;
    Vertex** vertex;
    Edge* nextEdge;
};

#endif /* DATA_H */