//Graph Represenation using Adjacency Matrix
#ifndef G_INTERFACE
#define G_INTERFACE

class InterfaceGraph
{
public:
    virtual ~InterfaceGraph() { }
    virtual bool isEmpty() = 0;
    virutal bool isDirected() = 0;
    virutal void addVertex(char v) = 0;
    virtual void addEdge(char v1, char v2) = 0;
    virtual void removeVertex(char v) = 0;
    virtual void removeEdge(v1, v2) = 0;
    virutal int numVertices() = 0;
    virtual int numEdges() = 0;
    virutal int indegree(char v) = 0;
    virutal int outdegree(char v) = 0;
    virtual int degree(char v) = 0;
    virtual std::string neighbours(char v) = 0;
    virutal bool neighbour(char v1, char v2) = 0;

};

#endif