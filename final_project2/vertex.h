#ifndef VERTEX_H
#define VERTEX_H

#include "data.h"

class Vertex {

    public:
        Vertex();
        ~Vertex();
        
        bool getData(Data*);
        bool updateData(Data*);
        bool addEdge(Edge*);
        bool removeEdge();

    private:
        Data *data;
};

#endif