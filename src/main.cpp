#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph.graphml");
    GraphAlgos::getAllShortestPaths(g);
    std::ofstream o1;
    o1.open("my-centrality.txt");
    GraphAlgos::printEdges(g, o1);
    Graph g2 = GraphAlgos::read_graphml("../graph.graphml");
    GraphAlgos::getBoostCentrality(g2);
    std::ofstream o2;
    o2.open("centrality.txt");
    GraphAlgos::printEdges(g2, o2);
    return 0;
}