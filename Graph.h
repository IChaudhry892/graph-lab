#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph{
private:
    int V; //number of vertices
    std::vector<std::vector<int>> adjacencyList; //vector of vector to store adjacency list

public:
    Graph();
    Graph(int numVertices);

    void addEdge(int source, int destination);

    void initializeAdjacencyList(); //get number of vertices and their neighbors from user, then store in adjacenyList
    void printAdjacencyList(); //print the adjacencyList

};

#endif