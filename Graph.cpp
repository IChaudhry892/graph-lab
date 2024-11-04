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
    // adjacencyList[source].push_back(destination);
    // adjacencyList[destination].push_back(source);

    //check if edge already exists
    bool edgeExists = false;
    for (int neighbor : adjacencyList[source]){
        if (neighbor == destination){
            cout << "Edge already exists." << endl;
            return;
        }
    }

    //add edge if it doesn't exist
    if (!edgeExists){
        adjacencyList[source].push_back(destination);
        //for self-loops, only add the edge once
        if (source != destination){
            adjacencyList[destination].push_back(source);
        }
    }
}

void Graph::initializeAdjacencyList(){
    cout << "Enter the number of Vertex objects to create: ";
    cin >> V;
    adjacencyList.resize(V);

    for (int i = 0; i < V; i++){
        int neighbor;
        cout << "Enter the neighbors of Vertex " << i << " (-1 to stop inquiry): ";
        while (cin >> neighbor && neighbor != -1){
            if (neighbor >= 0 && neighbor < V){
                addEdge(i, neighbor);
            } else{
                cout << "Invalid neighbor vertex " << neighbor << ". Must be between 0 and " << V - 1 << " (Inclusive)." << endl;
            }
        }
    }
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