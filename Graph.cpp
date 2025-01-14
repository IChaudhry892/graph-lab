/*
Links to External Resources:
https://www.geeksforgeeks.org/walks-trails-paths-cycles-and-circuits-in-graph/#
https://www.geeksforgeeks.org/cpp-program-to-implement-adjacency-list/
https://www.youtube.com/watch?v=dhgKr8942rs&ab_channel=CodingBlocks
https://www.youtube.com/watch?v=3OamzN90kPg&ab_channel=NeetCode
*/
#include "Graph.h"
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    int start = 0; //first vertex index
    int end = walk.size() - 1; //last vertex index

    return walk[start] == walk[end]; //returns true if first and last vertex are same, false otherwise
}

bool Graph::isTrail(const vector<int>& walk){
    //make a set to store the edges we've seen
    set<pair<int, int>> seenEdges;

    for (int i = 0; i < walk.size() - 1; i++){
        int source = walk[i]; //first vertex in edge
        int destination = walk[i + 1]; //second vertex in edge

        //make a pair with the two vertices, the smaller value goes first, the larger goes second
        pair<int, int> edge = {min(source, destination), max(source, destination)};
        if (seenEdges.find(edge) != seenEdges.end()){ // if edge is already in the set
            return false;
        }
        //insert the edge into seenEdges
        seenEdges.insert(edge);
    }
    return true; //no edges were repeated
}

bool Graph::isPath(const vector<int>& walk){
    unordered_map<int, int> seenVertices; //key: vertex in walk, value: number of occurrences
    for (int vertex : walk){ //for every vertex in walk
        if (seenVertices[vertex] >= 1){ //if vertex has occurred once or more already
            return false;
        }
        seenVertices[vertex]++; //add vertex to hash map with value of 1, and increment the value if vertex is already in the hash map
    }
    return true; //no vertices were repeated
}

bool Graph::isCircuit(const vector<int>& walk){
    //return true if the walk is a closed trail, false otherwise
    return (isClosedWalk(walk) && isTrail(walk));
}

bool Graph::isCycle(const vector<int>& walk){
    // if the walk is not a circuit, return false
    if (!isCircuit(walk)){
        return false;
    }

    //if vertices are repeated (excluding first and last), return false
    unordered_set<int> seenVertices;
    for (int i = 0; i < walk.size() - 1; i++){
        if (seenVertices.find(walk[i]) != seenVertices.end()){ //if the vertex is already in the hash set
            return false;
        }
        seenVertices.insert(walk[i]); //insert the vertex into the hash set
    }
    return true; //if no vertices are repeated, return true;
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

void Graph::printWalkProperties(const vector<int>& walk){
    cout << "The Walk Sequence: <";
    for (int i = 0; i < walk.size(); i++){
        cout << walk[i];
        if (i != walk.size() - 1){
            cout << ", ";
        }
    }
    cout << "> has the following properties:\n";
    //check for all 5 properties
    if (isClosedWalk(walk)){
        cout << "CLOSED\n";
    } else{
        cout << "OPEN\n";
    }

    if (isTrail(walk)){
        cout << "TRAIL (No Repeated Edges)\n";
    } else{
        cout << "NOT A TRAIL (Repeated Edges)\n";
    }

    if (isPath(walk)){
        cout << "PATH (No Repeated Vertices\n";
    } else{
        cout << "NOT A PATH (Repeated Vertices)\n";
    }

    if (isCircuit(walk)){
        cout << "CIRCUIT (Closed Trail)\n";
    } else{
        cout << "NOT A CIRCUIT (Not Closed Trail)\n";
    }

    if (isCycle(walk)){
        cout << "CYCLE (Closed Path)\n";
    } else{
        cout << "NOT A CYCLE (Not Closed Path)\n";
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