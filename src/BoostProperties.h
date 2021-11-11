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
#include <boost/graph/dijkstra_shortest_paths.hpp>
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
    double centrality = 0.0;
};
using Graph = boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS,
        VertexProperty, EdgeProperty, GraphData>;

struct my_visitor : boost::default_bfs_visitor{

    void initialize_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {
        std::cout << "Initialize: " << g[s].label << std::endl;
    }
    void discover_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {

    }
    void examine_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {

    }
    void examine_edge(const Graph::edge_descriptor &e, const Graph &g) const {
        
    }
    void tree_edge(const Graph::edge_descriptor &e, const Graph &g) const {
        std::cout <<g[boost::source(e,g)].label<<"-->"<<g[boost::target(e,g)].label << std::endl;
    }
    void non_tree_edge(const Graph::edge_descriptor &e, const Graph &g) const {

    }
    void gray_target(const Graph::edge_descriptor &e, const Graph &g) const {

    }
    void black_target(const Graph::edge_descriptor &e, const Graph &g) const {

    }
    void finish_vertex(const Graph::vertex_descriptor &s, const Graph &g) const {

    }
};
#endif //PA03_MILLER_SCHMITT_BOOSTPROPERTIES_H
