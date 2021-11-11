//
// Created by tallb on 11/9/2021.
//

#ifndef PA03_MILLER_SCHMITT_GRAPHALGOS_H
#define PA03_MILLER_SCHMITT_GRAPHALGOS_H

#include "BoostProperties.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class GraphAlgos {
public:
    static Graph read_graphml(std::string const& fileName);
    static void write_dot(std::ostream& os, Graph& graph);
    static void getShortestPath(Graph& graph);
    static void calculateCentrality(Graph &g);

    };


#endif //PA03_MILLER_SCHMITT_GRAPHALGOS_H
