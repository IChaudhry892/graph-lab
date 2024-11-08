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

    void addEdge(int source, int destination); //adds an edge between source and destination vertices
    bool isValidWalk(const std::vector<int>& walk); //checks if walk is valid
    bool isClosedWalk(const std::vector<int>& walk); //checks if the walk's first and last vertex are the same
    bool isTrail(const std::vector<int>& walk); //checks if there are no repeated edges in the walk
    bool isPath(const std::vector<int>& walk); //checks if there are no repeated vertices in the walk
    bool isCircuit(const std::vector<int>& walk); //checks if the walk is a closed trail
    bool isCycle(const std::vector<int>& walk); //checks if the walk is a closed path

    void promptForWalk(); //gets walk from user until a valid walk is entered, then prints the walk's properties
    void printWalkProperties(const std::vector<int>& walk); //checks for the 5 walk properties then prints them
    void initializeAdjacencyList(); //get number of vertices and their neighbors from user, then store in adjacenyList
    void printAdjacencyList(); //prints the adjacencyList

};

#endif