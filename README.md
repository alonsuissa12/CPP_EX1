# Graph Algorithms Project

## Overview

This project implements a set of graph algorithms and a graph data structure in C++. It provides functionalities for:

- **Graph Component**: Contains the implementation of the graph data structure and related operations.
- **Algorithms Component**: Contains implementations of various graph algorithms.

## Graph Component

The `Graph` component is responsible for representing graphs and providing methods for graph-related operations. It includes functionalities such as:

- **Graph Construction**: Constructs a graph from an adjacency matrix and provides methods to load a new graph.
- **Graph Properties**: Determines if the graph is directed, weighted, or contains negative edges. Calculates the number of vertices in the graph.
- **Graph Operations**: Prints the graph, retrieves neighbors of a vertex, and retrieves all edges in the graph.

## Algorithms Component

The `Algorithms` component contains various graph algorithms that operate on the graph data structure. It includes functionalities such as:

- **Connectivity**: Determines if the graph is connected and finds connected components.
- **Shortest Paths**: Finds the shortest path between two vertices using Dijkstra/Bellman-Ford algorithm, handling both weighted and unweighted graphs.
- **Cycles**: Determines if the graph contains a cycle and finds negative cycles in directed graphs. 
        Note: a cycle is at least 3 verices long, however in the case of negetive cycle 2 long verices is enough because is still disturbing the shortest path algorithm 
- **Bipartiteness**: Determines if the graph is bipartite and returns the partition of vertices if it is.

## Building and Running

To compile and run the project:

1. Ensure you have a g++ compiler installed.
2. Clone the repository.
3. Navigate to the project directory.
4. Run `make` to compile the project.
5. Execute `./demo` to run the demo program or `./test` to run the tests.


