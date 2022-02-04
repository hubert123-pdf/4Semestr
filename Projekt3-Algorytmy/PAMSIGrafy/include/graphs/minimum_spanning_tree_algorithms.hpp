#ifndef MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_
#define MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_

#include "graph.hpp"
#include <vector>

#include <stdio.h>

 

int find(int parent[], int i);
void Union(int parent[], int x, int y);
bool isCycle(MinimumSpanningTreeResult tree,int n);
bool isInTree(MinimumSpanningTreeResult result,int x);
void kruskal(Graph& graph, MinimumSpanningTreeResult& result);
void prim(Graph& graph, MinimumSpanningTreeResult& result);

void printMST(MinimumSpanningTreeResult& tree);
#endif /* MINIMUM_SPANNING_TREE_ALGORITHMS_HPP_ */

