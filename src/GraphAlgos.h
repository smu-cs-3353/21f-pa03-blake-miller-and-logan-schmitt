//
// Created by tallb on 11/9/2021.
//

#ifndef PA03_MILLER_SCHMITT_GRAPHALGOS_H
#define PA03_MILLER_SCHMITT_GRAPHALGOS_H

#include "BoostProperties.h"

class GraphAlgos {
public:
    static Graph read_graphml(std::string const& fileName);
    static void write_dot(std::ostream& os, Graph& graph);
    static void getShortestPath(Graph& graph);
    static std::map<Vertex, Vertex> predecessorMap;

private:
    static Edges getEdges(Graph& g);
    static Vertices getVertices(Graph& g);
    static std::string edgeToString(Edge& e, Graph& g);

    static void initPredecessorMap(std::map<Vertex, Vertex>);
    struct my_visitor : boost::default_bfs_visitor{
        std::map<Vertex, Vertex> pMap;
        void initialize_vertex(const Vertex &s, const Graph &g) {

        }
        void discover_vertex(const Vertex &s, const Graph &g) {

        }
        void examine_vertex(const Vertex &s, const Graph &g) {

        }
        void examine_edge(const Edge &e, const Graph &g) {
            //std::cout<<"examine"<<std::endl;
        }
        void tree_edge(const Edge &e, const Graph &g) {
            Vertex target = boost::target(e,g);
            Vertex source = boost::source(e,g);
            //std::cout <<g[source].label<<"-->"<<g[target].label << std::endl;
            pMap.insert(std::pair<Vertex, Vertex>(target,source));

        }
        void non_tree_edge(const Edge &e, const Graph &g) {
            //std::cout<<"non-tree"<<std::endl;
        }
        void gray_target(const Edge &e, const Graph &g) const {
            //std::cout<<"gray"<<std::endl;
        }
        void black_target(const Edge &e, const Graph &g) const {

        }
        void finish_vertex(const Vertex &s, const Graph &g) const {
            GraphAlgos::initPredecessorMap(pMap);
        }
    };
};


#endif //PA03_MILLER_SCHMITT_GRAPHALGOS_H
