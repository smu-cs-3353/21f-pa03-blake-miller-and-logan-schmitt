//
// Created by tallb on 11/9/2021.
//

#include "GraphAlgos.h"

Graph GraphAlgos::read_graphml(std::string const& fileName){
    std::ifstream inFile;
    inFile.open(fileName, std::ifstream::in);
    if(!inFile.is_open()){
        std::cout<<"File not open."<<std::endl;
        return 0;
    }

    Graph g;
    boost::dynamic_properties dp(boost::ignore_other_properties);
    dp.property("label", boost::get(&VertexProperty::label, g));
    dp.property("value", boost::get(&VertexProperty::value, g));
    dp.property("node_id", boost::get(&VertexProperty::node_id, g));
    boost::read_graphml(inFile, g, dp);
    return g;
}

void GraphAlgos::write_dot(std::ostream& os, Graph& graph) {
    boost::dynamic_properties dp;
    dp.property("label", boost::get(&VertexProperty::label, graph));
    dp.property("value", boost::get(&VertexProperty::value, graph));
    dp.property("node_id", boost::get(&VertexProperty::node_id, graph));
    boost::write_graphviz_dp(os,graph,dp);
}

void GraphAlgos::getShortestPath(Graph &g) {
    int numVerticies = boost::num_vertices(g);
    //get vertex iterators
    std::pair<Graph::vertex_iterator, Graph::vertex_iterator> vertexIterators;
    vertexIterators = boost::vertices(g);
    using vd = Graph::vertex_descriptor;
    //copy all vertex descriptors in graph to a vector
    std::vector<vd> vdVec(numVerticies);
    std::copy(vertexIterators.first, vertexIterators.second, std::begin(vdVec));
    //create predecessor map
    my_visitor vis;
    boost::breadth_first_search(g, vdVec[0], boost::vertex_index_map(boost::get(&VertexProperty::node_id, g)).visitor(vis));
}
