#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <memory>

#include "graph.hpp"

class AdjacencyMatrixGraph : public Graph
{

  unsigned num_of_vertexes,num_of_edges;
  int **matrix;
  std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight > pqueue;
  public:
  const int getEdgeWeight(int i,int j) const;
  const int getNumOfVertexes() const{ return num_of_vertexes; }
  const int getNumOfEdges() const{ return num_of_edges; }
  const MinimumSpanningEdge getTopQueue() const{   return pqueue.top(); }
  void popTopQueue() {   pqueue.pop(); }
  std::ostream& operator <<(std::ostream &Strm);
  static std::unique_ptr<Graph> createGraph(std::istream& is);
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
