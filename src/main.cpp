#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph.graphml");
    std::ofstream os;
    os.open("../centrality.txt");
    GraphAlgos::girvanNewman(g);
    std::ofstream outf("../output.gv");
    write_graphviz(outf, g);

    return 0;
}