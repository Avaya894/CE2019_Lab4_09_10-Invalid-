#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

#include "Interface.h"
#include <iostream>
#include <string>

class AdjacencyMatrix : public InterfaceGraph
{
private:
//addEdge
//addVertices
//removeEdge
//remove Vertices
//traverse vertices
    int **matrix;
    int numberOfVertices;
public:
    AdjacencyMatrix() { }
    AdjacencyMatrix(int n_vertices) : numberOfVertices(n_vertices) 
    { 
        matrix = new int*[numberOfVertices];
        for (int i=0; i<numberOfVertices; i++)
        {
            matrix[i] = new int[numberOfVertices];
            for (int j=0; j<numberOfVertices; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    ~AdjacencyMatrix()
    {
        delete [] matrix;
    }

    void addEdge(int i, int j);
    void removeEdge(int i, int j);
    void addVertex();
    void removeVertex();
    void removeSpecificVertex(int v_to_delete);
    bool isEmpty();
    bool isDirected();
    int numVertices();
    int numEdges();
    int indegree(int v);
    int outdegree(int v);
    int degree(int v);
    std::string neighbours(int v);
    bool neighbour(int v1, int v2);


    void traverse();
    
};


#endif