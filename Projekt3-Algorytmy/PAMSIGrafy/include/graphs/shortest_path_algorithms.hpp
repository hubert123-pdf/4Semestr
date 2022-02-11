#ifndef SHORTEST_PATH_ALGORITHMS_HPP_
#define SHORTEST_PATH_ALGORITHMS_HPP_

#include "graph.hpp"

#include <map>
#include <utility>
#include <vector>
#include <algorithm>
/*
 * Klucz slownika to indeks wierzchołka końcowego
 * Wartość to std::pair, która zawiera:
 *   first - całkowita długość ścieżki
 *   second - wektor indeksów wierzchołków ze źródła do wirzechołka końcowego
 */
using ShortestPathResult = std::map<int, std::pair<int, std::vector<int>>>;

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result);
bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result);
void printSHR(ShortestPathResult SHR);
#endif /* SHORTEST_PATH_ALGORITHMS_HPP_ */
