#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph{
private:
    int V; //number of vertices
    std::vector<std::vector<int>> adjacencyList; //vector of vector to store adjacency list
    bool isDirected; //boolean flag to indicate if the graph is directed

public:
    Graph();
    Graph(int numVertices, bool directed = false);

    void addEdge(int source, int destination);
    bool isValidWalk(const std::vector<int>& walk);
    bool isClosedWalk(const std::vector<int>& walk);
    bool isTrail(const std::vector<int>& walk);

    void promptForWalk();
    void printWalkProperties(const std::vector<int>& walk);
    void initializeAdjacencyList(); //get number of vertices and their neighbors from user, then store in adjacenyList
    void printAdjacencyList(); //print the adjacencyList

};

#endif