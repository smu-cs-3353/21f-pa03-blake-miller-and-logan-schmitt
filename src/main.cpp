#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
using namespace std;
using namespace boost;

struct GraphData { string Name; };
struct VertexProperty { string Name; };
struct EdgeProperty { string Name; };

using Graph = adjacency_list<setS, vecS, directedS, VertexProperty, EdgeProperty, GraphData>;

int main() {
    dynamic_properties dp(ignore_other_properties);
    ifstream inFile;
    inFile.open("/Users/loganschmitt/Documents/21f-pa03-blake-miller-and-logan-schmitt/graph.graphml", std::ifstream::in);

    Graph g;

    try {
        boost::read_graphml(inFile, g, dp);
    } catch (boost::exception& xml_parser_error){
        cout << "error caught : xml_parser_error" << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
