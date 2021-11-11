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
/* Doesn't Work on MacOS
void GraphAlgos::write_dot(std::ostream& os, Graph& graph) {
    boost::dynamic_properties dp;
    dp.property("label", boost::get(&VertexProperty::label, graph));
    dp.property("value", boost::get(&VertexProperty::value, graph));
    dp.property("node_id", boost::get(&VertexProperty::node_id, graph));
    boost::write_graphviz_dp(os,graph,dp);
}
*/

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
//    boost::breadth_first_search(g, vdVec[0], boost::vertex_index_map(boost::get(&VertexProperty::node_id, g)).visitor(vis));

    vd vGoal = vertex(0, g);

    std::vector<vd> pr(num_vertices(g));
    std::vector<int> d(num_vertices(g));

    auto idmap = get(boost::vertex_index, g);
    using edgeDescriptor = Graph::edge_descriptor;

    dijkstra_shortest_paths(g, vGoal, boost::predecessor_map(boost::make_iterator_property_map(pr.begin(), idmap))
                                    .distance_map(boost::make_iterator_property_map(d.begin(), idmap))
                                    .weight_map(boost::make_constant_property<edgeDescriptor>(1.0)));

//    boost::dijkstra_shortest_paths(g,vdVec[0], boost::predecessor_map())
}


void GraphAlgos::calculateCentrality(Graph &g) {


    /*
     REPEAT
        LET n BE number of edges in the graph
        FOR i=0 to n-1
            LET B[i] BE betweenness centrality of edge i
            IF B[i] > max_B THEN
                max_B = B[i]
                max_B_edge = i
            ENDIF
        ENDFOR
        remove edge i from graph
    UNTIL number of edges in graph is 0
     */
    int numEdges = boost::num_edges(g);
    std::cout << numEdges << std::endl;

    std::pair<Graph::edge_iterator, Graph::edge_iterator> edgeIterators;
    edgeIterators = boost::edges(g);

    using edgeDescriptor = Graph::edge_descriptor;

    std::vector<edgeDescriptor> edVec(numEdges);
    std::copy(edgeIterators.first, edgeIterators.second, std::begin(edVec));


//    for (int i = 0; i < numEdges; ++i) {
//
//    }

}
