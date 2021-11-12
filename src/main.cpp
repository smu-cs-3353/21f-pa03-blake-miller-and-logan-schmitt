#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph.graphml");
    std::ofstream os;
    os.open("centrality.txt");
    GraphAlgos::girvanNewman(g);
    return 0;
}