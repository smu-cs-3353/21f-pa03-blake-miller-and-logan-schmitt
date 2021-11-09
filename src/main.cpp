#include <iostream>
#include "GraphAlgos.h"

using namespace std;

int main() {
    Graph g = GraphAlgos::read_graphml("../graph.graphml");
    GraphAlgos::write_dot(std::cout, g);
    return 0;
}
