#ifndef GRAPHAPP_HPP
#define GRAPHAPP_HPP

#include "Graph.hpp"

namespace GraphSpace{
    void Demo()
    {
        Graph *g = Graph::create_graph(
            "C:/Users/azhar/Downloads/ADA_301/Graph/graph_desc.txt"

        );
        if (g != nullptr) {
            g->print();
            g->bfs(0); // BFS from vertex 0
            g->dfs(0); // DFS from vertex 0
            delete g;
        }
    }
}

#endif