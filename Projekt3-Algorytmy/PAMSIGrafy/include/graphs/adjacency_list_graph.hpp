#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>
#include "graph.hpp"

class AdjacencyListGraph : public Graph
{
  unsigned num_of_vertexes,num_of_edges;
  std::list<std::pair<int,int>> *list;
  std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> pqueue;

  public:
  const int getEdgeWeight(int i,int j) const;
  const int getNumOfVertexes() const{ return num_of_vertexes; }
  const int getNumOfEdges() const{ return num_of_edges; }
  const MinimumSpanningEdge getTopQueue() const{   return pqueue.top(); }
  void popTopQueue() {   pqueue.pop(); }
  std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> getAllEdgesPossibleEdgesOfTree(bool possible[]);

  std::ostream& operator <<(std::ostream &Strm);
  static std::unique_ptr<Graph> createGraph(std::istream& is);
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
