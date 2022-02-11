#include <iostream>
#include <fstream>
#include "../include/graphs/minimum_spanning_tree_algorithms.hpp"
#include "../include/graphs/shortest_path_algorithms.hpp"
#include "../include/graphs/adjacency_list_graph.hpp"
#include "../include/graphs/adjacency_matrix_graph.hpp"
#include "../include/graphs/graph.hpp"

int main(int argc, char* argv[])
{
    MinimumSpanningTreeResult tree;
    ShortestPathResult path;
    std::ifstream plik;
    plik.open("../sp_data/graph/graphV10D0.5.txt",std::ifstream::in);
   // auto graph=AdjacencyListGraph::createGraph(plik);
    std::unique_ptr<Graph> graph=AdjacencyMatrixGraph::createGraph(plik);
    //graph->operator<<(std::cout);
    //kruskal(*graph,tree);
    //prim(*graph,tree);
    dijkstra(*graph,graph->getSourceIndex(),path);
    printSHR(path);
    //printMST(tree);
    return 0;
}
