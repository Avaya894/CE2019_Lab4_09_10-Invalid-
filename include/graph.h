#pragma once
#include "Interface.h"

class Graph:InterfaceGraph
{
public:
    ~InterfaceGraph();
    virtual bool isEmpty();
    virtual bool isDirected();
    virtual void addVertex(char v);
    virtual void addEdge(char v1, char v2);
    virtual void removeVertex(char v);
    virtual void removeEdge(v1, v2);
    virtual int numVertices();
    virtual int numEdges();
    virtual int indegree(char v);
    virtual int outdegree(char v);
    virtual int degree(char v);
    virtual std::string neighbours(char v);
    virtual bool neighbour(char v1, char v2);

};