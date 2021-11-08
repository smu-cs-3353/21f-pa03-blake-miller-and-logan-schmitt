#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
using namespace std;
using namespace boost;

struct GraphData { string Name; };
struct VertexProperty {
    string label;
    int value;
    int node_id;
};
struct EdgeProperty { string Name; };

using Graph = adjacency_list<setS, vecS, undirectedS, VertexProperty, EdgeProperty, GraphData>;

Graph ReadGraph(std::string const& fileName) {
    ifstream inFile;
    inFile.open(fileName, std::ifstream::in);
    if(!inFile.is_open()){
        cout<<"File not open."<<endl;
        return 0;
    }

    Graph g;
    dynamic_properties dp(ignore_other_properties);
    dp.property("label", boost::get(&VertexProperty::label, g));
    dp.property("value", boost::get(&VertexProperty::value, g));
    dp.property("node_id", boost::get(&VertexProperty::node_id, g));
    boost::read_graphml(inFile, g, dp);
    return g;
}

void WriteGraph(std::ostream& os, Graph& graph) {
    boost::dynamic_properties dp;
    dp.property("label", boost::get(&VertexProperty::label, graph));
    dp.property("value", boost::get(&VertexProperty::value, graph));
    dp.property("node_id", boost::get(&VertexProperty::node_id, graph));
    boost::write_graphml(os, graph, dp, true);
}

int main() {

    Graph g = ReadGraph("../graph.graphml");
    WriteGraph(std::cout << "==== XML version: ====\n\n", g);
    return 0;
}
