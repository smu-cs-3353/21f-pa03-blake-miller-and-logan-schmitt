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

Vertices GraphAlgos::getVertices(Graph& g){
    int numVertices = boost::num_vertices(g);
    VertexIterPair vertecies = boost::vertices(g);
    Vertices vertexVec(numVertices);
    std::copy(vertecies.first, vertecies.second, std::begin(vertexVec));
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
    str = str + std::to_string(g[e].centrality);
    return str;
}

void GraphAlgos::printEdges(Graph& g, std::ostream& os){
    auto edges = getEdges(g);
    for(int i=0; i< edges.size();i++){
        os <<edgeToString(edges[i], g)<<std::endl;
    }
}

void GraphAlgos::getBoostCentrality(Graph &g){
    boost::brandes_betweenness_centrality(g, boost::vertex_index_map(boost::get(&VertexProperty::node_id, g))
    .edge_centrality_map(boost::get(&EdgeProperty::centrality,g)));
//    brandes_betweenness_centrality(g, boost::centrality_map(boost::get(&VertexProperty::centrality,g)),
//                                   boost::edge_centrality_map(boost::get(&EdgeProperty::centrality,g)),
//                                   boost::vertex_index_map(boost::get(&VertexProperty::node_id, g)));
}

Edge GraphAlgos::getEdgeToRemove(Graph& g){
    getBoostCentrality(g);
    Edges edges = getEdges(g);
    float max=0;
    Edge maxEdge;
    for(int i=0; i< edges.size();i++){
        if(g[edges[i]].centrality>max){
            max=g[edges[i]].centrality;
            maxEdge = edges[i];
        }
    }
    return maxEdge;
}

void GraphAlgos::girvanNewman(Graph& g){
    float tolerance = 7.0f;
    Edge edgeToRemove = getEdgeToRemove(g);
    while((g[edgeToRemove].centrality)>tolerance){
        edgeToRemove = getEdgeToRemove(g);
        boost::remove_edge(edgeToRemove, g);
    }
    GraphAlgos::outputGroups(g);
}

void GraphAlgos::outputGroups(Graph& g){
    boost::connected_components(g, boost::get(&VertexProperty::group, g));
    Vertices verts = getVertices(g);
    int totalGroups=0;
    for(int i=0; i<verts.size(); i++){
        if(g[verts[i]].group>totalGroups){
            totalGroups = g[verts[i]].group;
        }
    }
    std::cout<<totalGroups<<std::endl;
    for(int i = 0; i<totalGroups; i++){
        std::cout<<"Group "<<i<<":"<<std::endl;
        for(int j=0; j<verts.size(); j++){
            if(g[verts[j]].group==i){
                std::cout<<"\t"<<g[verts[j]].label<<std::endl;
            }
        }
    }
}