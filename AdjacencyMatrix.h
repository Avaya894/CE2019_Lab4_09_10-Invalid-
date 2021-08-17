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

void AdjacencyMatrix::addEdge(int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void AdjacencyMatrix::removeEdge(int i, int j)
{
    matrix[i][j] = 0;
    matrix[j][i] = 0;
}

void AdjacencyMatrix::addVertex() 
{
    this->numberOfVertices++;
    int **copy;
    copy = matrix;
    matrix = new int*[numberOfVertices];
    for (int i=0; i<numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
        for (int j=0; j<numberOfVertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i=0; i<numberOfVertices - 1; i++)
    {
        for (int j=0; j<numberOfVertices - 1; j++)
        {
            matrix[i][j] = copy[i][j];
        }
    }
}

void AdjacencyMatrix::removeVertex()
{
    this->numberOfVertices--;
    int **copy;
    copy = matrix;
    matrix = new int*[numberOfVertices];
    for (int i=0; i<numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
        for (int j=0; j<numberOfVertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i=0; i<numberOfVertices; i++)
    {
        for (int j=0; j<numberOfVertices; j++)
        {
            matrix[i][j] = copy[i][j];
        }
    }
}

void AdjacencyMatrix::traverse()
{
    for (int i=0; i<numberOfVertices; i++)
    {
        for (int j=0; j<numberOfVertices; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void AdjacencyMatrix::removeSpecificVertex(int v_to_delete)
{
    this->numberOfVertices--;
    int **copy;
    copy = matrix;
    matrix=new int*[numberOfVertices];
    for (int i=0; i<numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
        int a, b;
        if (i >= v_to_delete)
            a=i+1;
        else
            a=i;
        for(int j=0; j<numberOfVertices; j++)
        {
            if (j >= v_to_delete)
                b=j+1;
            else
                b=j;
        
            matrix[i][j] = copy[a][b];
        }
    }
}

bool AdjacencyMatrix::isEmpty() 
{
    for (int i=0; i<numberOfVertices; i++)
    {
        for (int j=0; j<numberOfVertices; j++)
        {
            if (matrix[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool AdjacencyMatrix::isDirected()
{
    for (int i=0; i<numberOfVertices; i++)
    {
        for (int j=0; j<numberOfVertices; j++)
        {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}

int AdjacencyMatrix::numVertices()
{
    return numberOfVertices;
}

int AdjacencyMatrix::numEdges()
{
    int numEdge = 0;
    for (int i=0; i<numberOfVertices; i++)
    {
        for (int j=0; j<numberOfVertices; j++)
        {
            if (matrix[i][j] == 1)
                numEdge++;
        }
    }
    if (isDirected())
        return (numEdge / 2);
    else 
        return numEdge;
}

int AdjacencyMatrix::indegree(int v)
{
    int indegree = 0;
    for (int i=0; i<numberOfVertices; i++)
    {
        if (matrix[i][v] == 1)
            indegree++;
    }
    return indegree;
}

int AdjacencyMatrix::outdegree(int v)
{
    int outdegree = 0;
    for (int i=0; i<numberOfVertices; i++)
    {
        if (matrix[v][i] == 1)
            outdegree++;
    }
    return outdegree;
}

int AdjacencyMatrix::degree(int v)
{
    int indeg, outdeg;
    indeg = indegree(v);
    outdeg = outdegree(v);
    if (isDirected())
        return (indeg + outdeg) / 2;
    else 
        return indeg + outdeg;
}

std::string AdjacencyMatrix::neighbours(int v)
{
    std::string neighbour = "";
    for (int i=0; i<numberOfVertices; i++)
    {
        if (matrix[v][i] == 1)
            neighbour = neighbour + std::to_string(i) + ", ";
    }
    return neighbour;
}


bool AdjacencyMatrix::neighbour(int v1, int v2)
{
    return matrix[v1][v2] == 1;
}

#endif