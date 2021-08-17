#include "AdjacencyMatrix.h"

int main()
{
    //Only Directed Graph Considered
    // int a[5][5];
    //a[5][5]
    //a[0][0] a[0][1] a[0][2]
    //a[1][0] a[1][1] a[1][2]
    //a[2][0] a[2][1] a[2][2]
    // a = AdjacencyMatrix[5];
    AdjacencyMatrix a(5);
    a.addEdge(1, 2);
    a.addEdge(1, 4);
    a.addEdge(1, 3);
    a.addEdge(2, 1);
    a.addEdge(3, 1);
    a.addEdge(2, 3);
    // a.removeEdge(2 , 3);
    // a.addVertex();
    // a.removeVertex();
    // a.removeSpecificVertex(1);
    a.traverse();
    std::cout << a.neighbour(1, 1);
}