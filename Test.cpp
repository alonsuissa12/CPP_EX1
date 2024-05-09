// 211344015 alonsuissa12@gmail.com

#ifndef DOCTSET
#define DOCTSET
#include "doctest.h"  // Include doctest.h here
#endif

#include "Algorithms.hpp"

using namespace std;


//############################### TESTS FOR ALGORITHMS ##########################################

TEST_CASE("Test isConnected"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isConnected(g) == 1));

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isConnected(g) == 0));
}//v

TEST_CASE("Test isConnected- directed graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 1},
            {0, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isConnected(g) == 0)); // can't get to o from 1

    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isConnected(g) == 1));

    vector<vector<int>> graph3 = {};
    g.loadGraph(graph3);
    CHECK((ariel::Algorithms::isConnected(g) == 1));


}//v

TEST_CASE("Test shortestPath") {
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    vector<int> path = ariel::Algorithms::shortestPath(g, 0, 2);
    CHECK((path == vector<int>{0, 1, 2}));

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path[0] == -1)); // there is no path

    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 1},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 1, 0},
            {0, 0, 0, 1, 0, 0},
            {1, 1, 0, 0, 0, 0}};

    g.loadGraph(graph3);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path == vector<int>{0, 1, 2, 3, 4}));
}//v

TEST_CASE("Test shortestPath - wighted positive") {
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 5},
            {1, 0, 2},
            {0, 1, 0}};
    g.loadGraph(graph);
    vector<int> path = ariel::Algorithms::shortestPath(g, 0, 2);
    CHECK((path == vector<int>{0, 1, 2}));

    vector<vector<int>> graph2 = {
            {0, 3, 2, 0, 0},
            {6, 0, 1, 0, 0},
            {4, 7, 0, 7, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path[0] == -1)); // there is no path

    vector<vector<int>> graph3 = {
            {0,  1, 0, 0, 18, 4},
            {1,  0, 5, 0, 0,  2},
            {0,  5, 0, 6, 7,  0},
            {0,  0, 3, 0, 3,  0},
            {18, 0, 0, 1, 0,  10},
            {4,  2, 0, 0, 10, 0}};

    g.loadGraph(graph3);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path == vector<int>{0, 1, 5, 4}));
}//v

TEST_CASE("Test shortestPath - wighted directed negative") {
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 20, -5},
            {20, 0, 0},
            {0, -2, 0}};
    g.loadGraph(graph);
    vector<int> path = ariel::Algorithms::shortestPath(g, 0, 2);
    CHECK((path == vector<int>{0, 2}));

    vector<vector<int>> graph2 = {
            {0,  -3, 4,  0, -1},
            {0, 0,  -5, 0, 0},
            {4,  0, 0,  7, 0},
            {0,  0,  7,  0, 0},
            {0, 0,  0,  0, 0}};
    g.loadGraph(graph2);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path[0] == -1)); // there is no path (negative cycle)

    vector<vector<int>> graph3 = {
            {0,  -1, 0, 0, -18, -4},
            {2,  0, 5, 0, 0,  -2},
            {0,  5, 0, 6, 7,  0},
            {0,  0, 3, 0, 3,  0},
            {18, 0, 0, 20, 0,  -10},
            {40,  30, 0, 0, 30, 0}};

    g.loadGraph(graph3);
    path = ariel::Algorithms::shortestPath(g, 0, 5);
    CHECK((path == vector<int>{0, 4, 5}));


    vector<vector<int>> graph4 = {
            {0,  1, 0, 0, 18, 4},
            {1,  0, -5, 0, 0,  2},
            {0,  -5, 0, 6, 7,  0},
            {0,  0, 3, 0, 3,  0},
            {18, 0, 0, 1, 0,  10},
            {4,  2, 0, 0, 10, 0}};

    g.loadGraph(graph4);
    path = ariel::Algorithms::shortestPath(g, 0, 4);
    CHECK((path[0] == -1)); // there is no path (negative cycle)

}//v

TEST_CASE("Test isContainsCycle"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isContainsCycle(g) == 0));

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(g) == 1));
}//v

TEST_CASE("Test isContainsCycle -directed"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {0, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((ariel::Algorithms::isContainsCycle(g) == 0));

    vector<vector<int>> graph2 = {
            {0, 0, 0, 0, 3},
            {4, 0, 0, 0, 0},
            {0, 0, 0, 9, 5},
            {1, 0, 0, 0, 7},
            {0, 0, 3, 0, 0}};
    g.loadGraph(graph2);
    CHECK((ariel::Algorithms::isContainsCycle(g) == 1));
}//v

//############################### TESTS FOR GRAPH ##########################################

TEST_CASE("Test numOfVertices"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK((g.numOfVertices() == 3));

    vector<vector<int>> graph2 = {};
    g.loadGraph(graph2);
    CHECK((g.numOfVertices()== 0));
}//v

TEST_CASE("Test negativeCycle"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0,  -1, 0, 4, 0},
            {1,  0,  2, 0, 0},
            {4,  0,  0, 0, 5},
            {0,  1,  0, 0, 11},
            {-8, 4,  0, 1, 0}};
    g.loadGraph(graph);
    vector<int> cycle = ariel::Algorithms::negativeCycle(g);
    CHECK((cycle == vector<int>{4, 0, 1, 2, 4}));

    vector<vector<int>> graph2 = {
            {0,  -1, 0, 4, 0},
            {1,  0,  5, 0, 0},
            {4,  0,  0, 0, -1},
            {0,  1,  0, 0, 11},
            {-1, 4,  0, 1, 0}};
    g.loadGraph(graph2);
    cycle = ariel::Algorithms::negativeCycle(g);
    CHECK((cycle == vector<int>{-1})); // no negative cycle
}//v

TEST_CASE("Test isBipartite"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    pair<vector<int>, vector<int>> groups = ariel::Algorithms::isBipartite(g);
    CHECK((ariel::Algorithms::groupsToString(groups).compare("The graph is bipartite: A={0, 2}, B={1}") == 0));

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    groups = ariel::Algorithms::isBipartite(g);
    cout << ariel::Algorithms::groupsToString(groups) << endl;
    CHECK((ariel::Algorithms::groupsToString(groups).compare("The graph is not bipartite") == 0));

    vector<vector<int>> graph3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 3, 0, 0},
            {2, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    groups = ariel::Algorithms::isBipartite(g);
    CHECK((ariel::Algorithms::groupsToString(groups).compare("The graph is not bipartite") == 0));

    vector<vector<int>> graph4 = {
            {0, 1, 2, 0, -2},
            {1, 0, 0, 0, 0},
            {2, 0, 0, 4, 0},
            {0, 0, -4, 0, -5},
            {0, 0, 0, -1, 0}};
    g.loadGraph(graph4);
    groups = ariel::Algorithms::isBipartite(g);
    CHECK((ariel::Algorithms::groupsToString(groups).compare("The graph is bipartite: A={0, 3}, B={1, 2, 4}") == 0));
}//v

TEST_CASE("Test invalid graph"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 1, 4},
            {0, 0, 4, 0},};
    CHECK_THROWS(g.loadGraph(graph));
}//v

TEST_CASE("Test isDirected"){
    ariel::Graph g1;
    CHECK((g1.isDirected() == false)); // Default graph is undirected

    vector<vector<int>> graph = {
            {0, 1, 1},
            {0, 0, 1},
            {0, 0, 0}};
    ariel::Graph g2(graph);
    CHECK((g2.isDirected() == true));
}//v

TEST_CASE("Test isWeighted"){
    ariel::Graph g1;
    CHECK((g1.isWeighted() == false)); // Default graph is unweighted

    vector<vector<int>> graph = {
            {0, 1, 1},
            {0, 0, 1},
            {0, 0, 0}};
    ariel::Graph g2(graph);
    CHECK((g2.isWeighted() == false)); // The graph is unweighted

    vector<vector<int>> weightedGraph = {
            {0, 1, 5},
            {0, 0, 3},
            {0, 0, 0}};
    ariel::Graph g3(weightedGraph);
    CHECK((g3.isWeighted() == true)); // The graph is weighted
}//v

TEST_CASE("Test includeNegative"){
    ariel::Graph g1;
    CHECK((g1.includeNegative() == false)); // Default graph doesn't have negative edges

    vector<vector<int>> graph = {
            {0, 1, 1},
            {0, 0, 1},
            {0, 0, 0}};
    ariel::Graph g2(graph);
    CHECK((g2.includeNegative() == false)); // The graph doesn't have negative edges

    vector<vector<int>> graphWithNeg = {
            {0, 1, -1},
            {0, 0, 1},
            {0, 0, 0}};
    ariel::Graph g3(graphWithNeg);
    CHECK((g3.includeNegative() == true)); // The graph has negative edges
}//v

TEST_CASE("Test allEdges"){
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 2},
            {1, 0, 3},
            {2, 3, 0}};
    g.loadGraph(graph);
    vector<vector<int>> edges = g.allEdges();
    vector<vector<int>> expected = {{0, 1, 2},
                                    {1, 0, 3},
                                    {2, 3, 0}};
    CHECK((edges == expected));
}//v


