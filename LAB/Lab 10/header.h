#include<iostream>
using namespace std;

class WeightedGraph {
private:
    int adj[50][50];      // adjacency matrix (max 50 nodes)
    int nodes;            // number of nodes

public:
    // Constructor
    WeightedGraph(int n) 
    {
        nodes = n;
        // initialize matrix with 0 (meaning no edge)
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                adj[i][j] = 0;
            }
        }
    }

    // Add an edge with weight
    void addEdge(int u, int v, int weight) {
        if (u < 0 || v < 0 || u >= nodes || v >= nodes) {
            cout << "Invalid node index!" << endl;
            return;
        }

        adj[u][v] = weight;   // directed graph
        adj[v][u] = weight;   // remove this line to make it directed only
    }

    // Remove edge
    void removeEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= nodes || v >= nodes) {
            cout << "Invalid node index!" << endl;
            return;
        }

        adj[u][v] = 0;
        adj[v][u] = 0;
    }

    // Check if edge exists
    bool isEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= nodes || v >= nodes)
            return false;

        return adj[u][v] != 0;
    }

    // Print adjacency matrix
    void printGraph() {
        cout << "\nWeighted Graph (Adjacency Matrix):\n";
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                cout << adj[i][j] << "  ";
            }
            cout << endl;
        }
    }
};
