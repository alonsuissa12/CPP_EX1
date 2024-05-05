
// 211344015 alonsuissa12@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>


namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
        int numVertices;
        bool directed;
        bool wighted;
        bool negative;
        bool isDirectedSelf();
        bool isWeightedSelf();
        bool includeNegativeSelf();
    public:
        //constructor 1
        explicit Graph();

        // Constructor 2
        explicit Graph(const std::vector<std::vector<int>> &matrix);

        //destructor
        ~Graph();
        // load a new data to the graph
        void loadGraph(const std::vector<std::vector<int>> &a);

        //is the graph directed
        bool isDirected() const;

        //is the graph weighted
        bool isWeighted() const;

        //is the graph include negative edges
        bool includeNegative() const;

        int numOfVertices() const;

        // Method to print the graph
        void printGraph();

        // return array of neighbors of v
        std::vector<int> neighborsOf(int);

        std::vector<std::vector<int>> allEdges();

    };



}

#endif // GRAPH_HPP
