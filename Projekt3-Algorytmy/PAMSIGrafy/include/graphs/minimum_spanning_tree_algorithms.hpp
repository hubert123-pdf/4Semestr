#ifndef MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_
#define MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_

#include "graph.hpp"
#include <vector>
#include <stdio.h>

 

int find(int parent[], int i);
void Union(int parent[], int x, int y);
bool isCycle(MinimumSpanningTreeResult tree,int n);
bool isInTree(MinimumSpanningTreeResult result,int x);
void printMST(MinimumSpanningTreeResult& tree);

void kruskal(Graph& graph, MinimumSpanningTreeResult& result);
void prim(Graph& graph, MinimumSpanningTreeResult& result);
#endif /* MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_ */

