//Graph Represenation using Adjacency Matrix
#ifndef G_INTERFACE
#define G_INTERFACE

#include <iostream>

class InterfaceGraph
{
public:
    // virtual ~InterfaceGraph() { }
    virtual bool isEmpty() = 0;
    virtual bool isDirected() = 0;
    virtual void addVertex() = 0;
    virtual void addEdge(int, int) = 0;
    virtual void removeSpecificVertex(int v_to_delete) = 0;
    virtual void removeEdge(int, int) = 0;
    virtual int numVertices() = 0;
    virtual int numEdges() = 0;
    virtual int indegree(int v) = 0;
    virtual int outdegree(int v) = 0;
    virtual int degree(int v) = 0;
    virtual std::string neighbours(int v) = 0;
    virtual bool neighbour(int, int) = 0;
};

#endif