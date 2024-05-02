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

## Partition between Graph and Algorithms

The decision to separate the Graph and Algorithms components allows for better organization and modularity within the project. Here's why:

- **Graph Component**: The Graph component focuses on the representation and manipulation of graph structures. It provides functionalities to create, load, and operate on graphs, including querying properties and retrieving information about vertices and edges. By keeping the graph-related operations separate, it ensures that the implementation remains clean and focused on graph data management.

- **Algorithms Component**: The Algorithms component is responsible for implementing various graph algorithms, such as connectivity checks, shortest path finding, cycle detection, and bipartiteness determination. By placing these algorithms in a separate module, it promotes code reuse and makes it easier to maintain and extend the project. Additionally, separating algorithms from the graph representation allows for flexibility in choosing different algorithms without modifying the underlying graph structure.

This partitioning approach adheres to the principles of separation of concerns and modular design, making the project more organized, maintainable, and extensible. Users can focus on either the graph representation or the algorithms independently, depending on their requirements, without affecting the other component.



