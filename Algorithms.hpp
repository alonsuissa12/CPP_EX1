// 211344015 alonsuissa12@gmail.com

#ifndef ALGO_H
#define ALGO_H

#include "Graph.hpp"
#include <queue>
#include <limits>
#include <unordered_set>
#include <vector>
#include <unordered_set>
#include <sstream>




int isContainsCycleRec( ariel::Graph& ,int ,int* , std::vector<int> *, std::vector<int>* ,std::vector<int>*,std::vector<int>*,int*);
void printCycle(const std::vector<int> &cycle);
void printCycle(const int *startEnd,const std::vector<int>* prev);
void printPath(std:: vector<int> &path);
void printGroups(std::pair<std::vector<int>,std::vector<int>> &groups);
std::string groupsToString(const std::pair<std::vector<int>, std::vector<int>> &groups);


namespace ariel{

    class Algorithms {
    public:
        static int isConnected(ariel::Graph &g);

        static std::vector<int> shortestPath(ariel::Graph &, int, int);

        static int isContainsCycle(ariel::Graph &);

        static std::vector<int> negativeCycle(ariel::Graph &g);

        static std::pair<std::vector<int>, std::vector<int>> isBipartite(ariel::Graph &g);
    };
}
#endif