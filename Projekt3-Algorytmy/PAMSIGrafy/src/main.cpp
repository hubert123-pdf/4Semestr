#include <iostream>
#include <fstream>
#include "../include/graphs/minimum_spanning_tree_algorithms.hpp"
#include "../include/graphs/adjacency_list_graph.hpp"
#include "../include/graphs/adjacency_matrix_graph.hpp"
#include "../include/graphs/graph.hpp"

int main(int argc, char* argv[])
{
    MinimumSpanningTreeResult tree;
    std::ifstream plik;
    plik.open("../mst_data/graph/graphV10D0.5.txt",std::ifstream::in);
    //auto graph=AdjacencyListGraph::createGraph(plik);
    std::unique_ptr<Graph> graph=AdjacencyMatrixGraph::createGraph(plik);
    graph->operator<<(std::cout);
    kruskal(*graph,tree);
    printMST(tree);
    return 0;
}
