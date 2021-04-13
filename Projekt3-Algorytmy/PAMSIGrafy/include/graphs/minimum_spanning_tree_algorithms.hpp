#ifndef MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_
#define MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_

#include "graphs/graph.hpp"
#include <vector>

struct MinimumSpanningEdge{
    int v1;
    int v2;
    int weight;
};

using MinimumSpanningTreeResult = std::vector<MinimumSpanningEdge>;

void kruskal(Graph& graph, MinimumSpanningTreeResult& result);
void prim(Graph& graph, MinimumSpanningTreeResult& result);

#endif /* MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_ */

