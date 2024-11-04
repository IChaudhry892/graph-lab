#include "Graph.h"
#include <iostream>
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

    Graph myGraph;
    
    myGraph.initializeAdjacencyList();
    myGraph.printAdjacencyList();


    return 0;
}