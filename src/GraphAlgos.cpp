//
// Created by tallb on 11/9/2021.
//

#include "GraphAlgos.h"

std::map<Vertex, Vertex> GraphAlgos::predecessorMap = std::map<Vertex, Vertex>();

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

void GraphAlgos::getAllShortestPaths(Graph &g) {
    Vertices vertices = getVertices(g);
    std::cout << vertices.size() << std::endl;
    for(int i=0; i<vertices.size(); i++){
//        std::cout << vertices[i] << std::endl;
//        getShortestPaths(vertices[i], g);
        dijkstraNodes(vertices[i], g);
    }
    printEdges(g);
}

void GraphAlgos::getShortestPaths(Vertex& source, Graph &g) {
    Vertices vertices = getVertices(g);
    //create predecessor map
    std::vector<Vertex> pr(num_vertices(g));
    std::vector<int> d(num_vertices(g));
    auto idmap = get(boost::vertex_index, g);

    my_visitor vis;
    boost::breadth_first_search(g, source,boost::vertex_index_map(boost::get(&VertexProperty::node_id, g)).visitor(vis));
//    boost::dijkstra_shortest_paths(g, source,
//                                   boost::predecessor_map(boost::make_iterator_property_map(pr.begin(), idmap))
//                                           .distance_map(boost::make_iterator_property_map(d.begin(), idmap))
//                                           .weight_map(boost::make_constant_property<Edge>(1.0)));

    for(int i=0; i<vertices.size(); i++) {
        auto target = vertices[i];
        while (target != source) {
            auto updateEdge = boost::edge(target, predecessorMap[target], g).first;
            g[updateEdge].centrality+=1;
            //std::cout << g[target].label << "--";
            target = pr[target];

        }
//        std::cout<<g[source].label<<std::endl;
    }

}

void GraphAlgos::dijkstraNodes(Vertex& source, Graph &g){
    Vertices vs = getVertices(g);
//    Vertex vGoal = vertex(0, g);

    std::vector<Vertex> pr(num_vertices(g));
    std::vector<int> d(num_vertices(g));

    auto idmap = get(boost::vertex_index, g);

//    for (int i = 0; i < vs.size(); ++i) {
    boost::dijkstra_shortest_paths(g, source,
                            boost::predecessor_map(boost::make_iterator_property_map(pr.begin(), idmap))
                                    .distance_map(boost::make_iterator_property_map(d.begin(), idmap))
                                    .weight_map(boost::make_constant_property<Edge>(1.0)));
//    }


    for(int i=0; i<vs.size(); i++) {
        auto target = vs[i];
        while (target != source) {
            auto updateEdge = boost::edge(target, pr[target], g).first;
            g[updateEdge].centrality+=1;
            std::cout << g[target].label << "--";
            target = pr[target];

        }
        std::cout<<g[source].label<<std::endl;
    }
//    std::vector< boost::graph_traits< Graph >::vertex_descriptor > path;
//    boost::graph_traits< Graph >::vertex_descriptor current=source;
//    while(current!=pr[0]) {
//        auto updateEdge = boost::edge(current, pr[current], g).first;
//        g[updateEdge].centrality+=1;
//        //std::cout << g[target].label << "--";
//        path.push_back(current);
//        current=pr[current];
//    }
//    path.push_back(pr[0]);

//This prints the path reversed use reverse_iterator and rbegin/rend
//    std::vector< boost::graph_traits< Graph >::vertex_descriptor >::iterator it;
//    for (it=path.begin(); it != path.end(); ++it) {
//
//        std::cout << pr[*it] << " ";
//    }
//    std::cout << std::endl;

}


Vertices GraphAlgos::getVertices(Graph& g){
    int numVertices = boost::num_vertices(g);
    VertexIterPair vertices = boost::vertices(g);
    Vertices vertexVec(numVertices);
    std::copy(vertices.first, vertices.second, std::begin(vertexVec));
    return vertexVec;
}

Edges GraphAlgos::getEdges(Graph& g){
    int numEdges = boost::num_edges(g);
    EdgeIterPair edges = boost::edges(g);
    Edges edgeVec(numEdges);
    std::copy(edges.first, edges.second, std::begin(edgeVec));
    return edgeVec;
}

std::string GraphAlgos::edgeToString(Edge& e, Graph& g){
    std::string str;
    str =       g[boost::source(e,g)].label;
    str = str + "-->";
    str = str + g[boost::target(e,g)].label;
    str = str + "   ";
    str = str + std::to_string(g[e].centrality/2);
    return str;
}

void GraphAlgos::initPredecessorMap(std::map<Vertex, Vertex> map){
    GraphAlgos::predecessorMap = map;
}

void GraphAlgos::printEdges(Graph& g){
    auto edges = getEdges(g);
    for(int i=0; i< edges.size();i++){
        std::cout<<edgeToString(edges[i], g)<<std::endl;
    }
}