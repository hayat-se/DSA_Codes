#include <iostream>
#include "header.h"
using namespace std;


int main() {
    WeightedGraph g(5);   // graph with 5 nodes

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);

    g.printGraph();

    cout << "\nIs there an edge between 1 and 2? ";
    cout << (g.isEdge(1, 2) ? "Yes" : "No") << endl;

    g.removeEdge(1, 2);
    cout << "\nAfter removing edge (1,2):\n";
    g.printGraph();

}