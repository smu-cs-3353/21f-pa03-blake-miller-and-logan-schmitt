//
// Created by tallb on 11/10/2021.
//

#ifndef PA03_MILLER_SCHMITT_BOOSTPROPERTIES_H
#define PA03_MILLER_SCHMITT_BOOSTPROPERTIES_H

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <boost/graph/graphviz.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

//define graph type
struct GraphData {
    std::string Name;
};

struct VertexProperty {
    std::string label;
    int value;
    int node_id;
};

struct EdgeProperty {
    double mutable centrality = 0.0;
};

using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS, VertexProperty, EdgeProperty, GraphData>;
using Vertex = Graph::vertex_descriptor;
using Edge = Graph::edge_descriptor;
using Vertices = std::vector<Vertex>;
using Edges = std::vector<Edge>;
using VertexIterPair = std::pair<Graph::vertex_iterator, Graph::vertex_iterator>;
using EdgeIterPair = std::pair<Graph::edge_iterator, Graph::edge_iterator>;


#endif //PA03_MILLER_SCHMITT_BOOSTPROPERTIES_H
