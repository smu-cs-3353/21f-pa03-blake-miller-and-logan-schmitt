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

//void WriteSVG(const std::string& dot_filename, const std::string& svg_filename){
//    std::stringstream cmd;
//    cmd << "dot -Tsvg " << dot_filename << " -o " << svg_filename;
//    const int error{ std::system(cmd.str().c_str()) };
//    if (error) {
//        std::cerr << __func__ << ": warning: command '" << cmd.str()
//                  << "' resulting in error " << error;
//    }
//}
