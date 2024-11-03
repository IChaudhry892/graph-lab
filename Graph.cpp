#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(){
    V = 0;
}

Graph::Graph(int numVertices){
    V = numVertices;
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int source, int destination){
    adjacencyList[source].push_back(destination);
    adjacencyList[destination].push_back(source);
}

void Graph::initializeAdjacencyList(){

}

void Graph::printAdjacencyList(){
    for (int i = 0; i < adjacencyList.size(); i++){
        cout << "Vertex: " << i << ": ";
        for (const auto& neighbor : adjacencyList[i]){ //const so neighbor isn't modified, auto& to prevent copying the neighbor element
            cout << neighbor << " ";
        }
        cout << endl;
    }
}