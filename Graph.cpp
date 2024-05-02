// 211344015 alonsuissa12@gmail.com

#include "Graph.hpp"

#define DEBUG(x) std::cout << x << std::endl
using namespace ariel;
// Constructor 1
Graph::Graph() {
    numVertices = 0;
    directed = false;
    wighted = false;
    negative = false;
}

// Constructor 2
Graph::Graph(const std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) {
        numVertices = 0;
        return;
    }

    if (matrix[0].size() != matrix.size())
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");

    for (unsigned int i = 0; i < matrix.size(); ++i) {
        if(matrix[i][i] != 0 )
            throw std::invalid_argument("Invalid graph: No self Edges allowed.");
    }

    numVertices = static_cast<int>(matrix.size());
    auto iulnumVertices = (unsigned int) numVertices;
    adjacencyMatrix.resize(iulnumVertices, std::vector<int>(iulnumVertices, 0));
    for (unsigned int i = 0; i < iulnumVertices; ++i) {
        for (unsigned int j = 0; j < iulnumVertices; ++j) {
            adjacencyMatrix[i][j] = matrix[i][j];
        }
    }

    negative = includeNegativeSelf();
    directed= isDirectedSelf();
    wighted = isWeightedSelf();
}


void Graph::loadGraph(const std::vector<std::vector<int>> &matrix) {

    if (!matrix.empty() && matrix[0].size() != matrix.size())
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    for (unsigned int i = 0; i < matrix.size(); ++i) {
            if(matrix[i][i] != 0 )
                throw std::invalid_argument("Invalid graph: No self Edges allowed.");
    }
    numVertices = static_cast<int>(matrix.size());
    auto iuNumOfVertices = (int unsigned) numVertices;
    adjacencyMatrix.resize(iuNumOfVertices, std::vector<int>(iuNumOfVertices, 0));
    for (unsigned int i = 0; i < iuNumOfVertices; ++i) {
        for (unsigned int j = 0; j < iuNumOfVertices; ++j) {
            adjacencyMatrix[i][j] = matrix[i][j];
        }
    }
    negative = includeNegativeSelf();
    directed= isDirectedSelf();
    wighted = isWeightedSelf();
}


bool Graph::isDirected() const {
    return directed;
}

bool Graph::isWeighted() const {
    return wighted;
}

bool Graph::includeNegative() const {
    return negative;
}

void Graph::printGraph() {
    if (isDirected()) {
        for (unsigned int i = 0; i < numVertices; ++i) {
            bool vertexPrinted = false;
            for (unsigned int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    vertexPrinted = true;
                    std::cout << i << " --[" << adjacencyMatrix[i][j] << "]--> " << j << "\n";
                }
            }
            if (!vertexPrinted)
                std::cout << i << std::endl;
        }
    } else {
        for (unsigned int i = 0; i < numVertices; ++i) {
            bool vertexPrinted = false;
            for (unsigned int j = 0; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    vertexPrinted = true;
                    if (j > i)
                        std::cout << i << " <--[" << adjacencyMatrix[i][j] << "]--> " << j << "\n";
                }
            }
            if (!vertexPrinted)
                std::cout << i << std::endl;
        }
    }
}

int Graph::numOfVertices() const {
    return numVertices;
}

// return array of neighbors of v
std::vector<int> Graph::neighborsOf(int v) {
    std::vector<int> neighbors;
    for (int unsigned long i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[(int unsigned long) v][i] != 0)
            neighbors.push_back((int) i);
    }
    return neighbors;
}

std::vector<std::vector<int>> Graph::allEdges() {
    std::vector<std::vector<int>> copyMatrix((int unsigned long) numVertices,
                                             std::vector<int>((int unsigned long) numVertices));

    for (int unsigned long i = 0; i < numVertices; ++i) {
        for (int unsigned long j = 0; j < numVertices; ++j) {
            copyMatrix[i][j] = (int) adjacencyMatrix[i][j];
        }
    }
    return copyMatrix;
}

bool Graph::isDirectedSelf() {
    for (unsigned int i = 0; i < numVertices; i++) {
        for (unsigned int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}

bool Graph::isWeightedSelf() {
    for (int unsigned long i = 0; i < numVertices; i++) {
        for (int unsigned long j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != 1)
                return true;
        }
    }
    return false;
}

bool Graph::includeNegativeSelf() {
    for (int unsigned long i = 0; i < numVertices; ++i) {
        for (int unsigned long j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] < 0)
                return true;
        }
    }
    return false;}


//destructor
Graph::~Graph() = default;


