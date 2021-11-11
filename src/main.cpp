#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph_test.graphml");
    //GraphAlgos::write_dot(std::cout, g);
    GraphAlgos::getShortestPath(g);
//    GraphAlgos::calculateCentrality(g);

    return 0;
}