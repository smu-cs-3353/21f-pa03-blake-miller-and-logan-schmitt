//
// Created by tallb on 11/9/2021.
//

#ifndef PA03_MILLER_SCHMITT_GRAPHALGOS_H
#define PA03_MILLER_SCHMITT_GRAPHALGOS_H

#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/graphviz.hpp>
#include <sstream>
#include <string>


//define graph type
struct GraphData { std::string Name; };
struct VertexProperty {
    std::string label;
    int value;
    int node_id;
};
struct EdgeProperty { std::string Name; };
using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS,
        VertexProperty, EdgeProperty, GraphData>;

class GraphAlgos {
public:

    static Graph read_graphml(std::string const& fileName);
    static void write_dot(std::ostream& os, Graph& graph);
    static void getShortestPath();
};


#endif //PA03_MILLER_SCHMITT_GRAPHALGOS_H
