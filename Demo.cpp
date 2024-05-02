/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */
// 211344015 alonsuissa12@gmail.com
#include "Algorithms.hpp"
#include "Graph.hpp"

using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    cout << "#########################################  G1 ##############################################\n";
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.
    cout << "print Graph:" << endl;
    g.printGraph();               // Should print: "Graph with 3 vertices and 4 edges."
    cout << "connected:" << endl;
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << "shortestPath:" << endl;
    Algorithms::shortestPath(g, 0, 2);               // Should print: 0->1->2. totalWeight: 2
    cout << "isContainsCycle: ";
    cout << Algorithms::isContainsCycle(g) << endl;  // Should print: "0" (false).
    pair<vector<int>, vector<int>> groups = Algorithms::isBipartite(g);
    printGroups(groups);        // Should print: "The graph is bipartite: A={0, 2}, B={1}."

    cout << "\n#########################################  G2 ##############################################\n";

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout <<"is connected: "<< Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    Algorithms::shortestPath(g, 0, 4);// Should print: there is no path!.
     Algorithms::isContainsCycle(g); // Should print: "The cycle is: 2 --> 1 --> 0 --> 2".
    groups = Algorithms::isBipartite(g);
    printGroups(groups);                            // Should print: "0" (false).

    cout << "\n#########################################  3 ##############################################\n";
    // 5x5 matrix that represents a connected weighted graph.
    vector<vector<int>> graph3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 3, 0, 0},
            {2, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();        // Should print: "Graph with 5 vertices and 10 edges."

    cout << "is connected: " << Algorithms::isConnected(g) << endl;    // Should print: "1" (true).
    Algorithms::shortestPath(g, 0, 4);// Should print: 0->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl; // Should print: "2 --> 1 --> 0 --> 2". "1" (true).
    groups = Algorithms::isBipartite(g);
    printGroups(groups);                            // Should print: "The graph is not bipartite"

    cout << "\n#########################################  G4 ##############################################\n";

    // 5x4 matrix that represents invalid graph.
    vector<vector<int>> graph4 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    try {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
}
