#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph_test.graphml");
    GraphAlgos::getAllShortestPaths(g);

    return 0;
}