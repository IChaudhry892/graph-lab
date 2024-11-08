#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph(){
    V = 0;
    isDirected = false;
}

Graph::Graph(int numVertices, bool directed/*= false*/){
    V = numVertices;
    adjacencyList.resize(numVertices);
    isDirected = directed;
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

bool Graph::isValidWalk(const vector<int>& walk){
    for (int i = 0; i < walk.size() - 1; i++){
        int current = walk[i];
        int next = walk[i + 1];

        //check if next is a neighbor of current
        cout << "Checking if Vertex " << next << " is a direct neighbor of Vertex " << current << endl;
        bool isNeighbor = false;
        for (int neighbor : adjacencyList[current]){ //for every neighbor of the current vertex
            if (neighbor == next){
                isNeighbor = true;
                cout << "YES!\n";
                break;
            }
        }

        //if next is not a neighbor of current, return false;
        if (!isNeighbor){
            cout << "NO!\n"; //Vertex " << next << " is not a neighbor of Vertex " << current << endl;
            return false;
        }
    }
    return true;
}

bool Graph::isClosedWalk(const std::vector<int>& walk){
    int start = 0;
    int end = walk.size() - 1;
    if (walk[start] == walk[end]){
        // cout << "CLOSED\n";
        return true;
    }
    return false;
}

void Graph::promptForWalk(){
    vector<int> walk;
    while (true){
        walk.clear();
        cout << "Enter walk sequence: (-1 to stop input):\n";
        int vertex;
        while (cin >> vertex && vertex != -1){
            if (vertex >= 0 && vertex < V){
                walk.push_back(vertex);
            } else{
                cout << "Invalid vertex " << vertex << ". Must be between 0 and " << V - 1 << " (Inclusive)." << endl;
            }
        }

        cout << "Entered Walk Sequence: <";
        for (int i = 0; i < walk.size(); i++){
            cout << walk[i];
            if (i != walk.size() - 1){
                cout << ", ";
            }
        }
        cout << ">" << endl;
        
        if (!walk.empty() && isValidWalk(walk)){
            cout << "WALK IS VALID!\n";
            printWalkProperties(walk);
            break;
        } else{
            cout << "WALK NOT VALID! PLEASE TRY AGAIN!\n";
        }
    }
}

void Graph::printWalkProperties(const std::vector<int>& walk){
    cout << "The Walk Sequence: <";
    for (int i = 0; i < walk.size(); i++){
        cout << walk[i];
        if (i != walk.size() - 1){
            cout << ", ";
        }
    }
    cout << "> has the following properties:\n";
    if (isClosedWalk(walk)){
        cout << "CLOSED\n";
    } else{
        cout << "OPEN\n";
    }
}

void Graph::initializeAdjacencyList(){
    // cout << "Enter the number of Vertex objects to create: ";
    // cin >> V;
    // adjacencyList.resize(V);

    for (int i = 0; i < V; i++){
        int neighbor;
        cout << "Enter the neighbors of Vertex " << i << " (-1 to stop input):\n";
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