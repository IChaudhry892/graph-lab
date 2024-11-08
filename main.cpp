#include "Graph.h"
#include <iostream>
#include <set>
using namespace std;

int main(){
    // Graph myGraph(7);

    // myGraph.addEdge(0, 1);
    // myGraph.addEdge(1, 2);
    // myGraph.addEdge(2, 3);
    // myGraph.addEdge(4, 5);
    // myGraph.addEdge(5, 1);
    // myGraph.addEdge(6, 2);

    // myGraph.printAdjacencyList();

    // Graph myGraph;
    
    // myGraph.initializeAdjacencyList();
    // myGraph.printAdjacencyList();

    int numVertices;
    cout << "Enter the number of Vertex objects to create: ";
    cin >> numVertices;

    Graph undirectedGraph(numVertices);
    // undirectedGraph.initializeAdjacencyList();
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(0, 3);
    undirectedGraph.addEdge(0, 4);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(1, 4);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(2, 4);
    undirectedGraph.addEdge(3, 4);
    undirectedGraph.printAdjacencyList();
    undirectedGraph.promptForWalk();


    return 0;
}