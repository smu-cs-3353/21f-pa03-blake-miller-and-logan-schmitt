//
// Created by tallb on 11/9/2021.
//

#ifndef PA03_MILLER_SCHMITT_GRAPHALGOS_H
#define PA03_MILLER_SCHMITT_GRAPHALGOS_H

#include "BoostProperties.h"

class GraphAlgos {
public:
    static Graph read_graphml(std::string const& fileName);
    static void getBoostCentrality(Graph &g);
    static void printEdges(Graph& g, std::ostream& os);
    static Edge getEdgeToRemove(Graph& g);
    static void girvanNewman(Graph& g);
    static void outputGroups(Graph& g);
private:
    static Edges getEdges(Graph& g);
    static Vertices getVertices(Graph& g);
    static std::string edgeToString(Edge& e, Graph& g);
    static void initPredecessorMap(std::map<Vertex, Vertex>);
};


#endif //PA03_MILLER_SCHMITT_GRAPHALGOS_H
