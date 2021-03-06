#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <sstream>
#include <iostream>
#include <list>
#include <vector>
#include <filesystem>
#include <fstream>
#include <queue>

struct MinimumSpanningEdge{
    int v1;
    int v2;
    int weight;
};
struct  compareWeight
{
    bool operator ()(MinimumSpanningEdge const& e1,MinimumSpanningEdge const & e2)
    {
        return e1.weight>e2.weight;
    }
};
using MinimumSpanningTreeResult = std::vector<MinimumSpanningEdge>;
typedef std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> priority_queue;

class Graph
{
  public:
  virtual const int getNumOfVertexes()const =0;
  virtual const int getNumOfEdges() const =0;
  virtual const int getSourceIndex() const =0;
  virtual bool vertexIsNeighbour(int x, int y)=0;
  virtual std::ostream& operator <<(std::ostream &Strm)=0;
  virtual int getEdgeValue(int x, int y)=0;
  virtual const MinimumSpanningEdge getTopQueue()const=0;
  virtual void popTopQueue()=0;
  virtual  std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> getAllEdgesPossibleEdgesOfTree(bool possible[])=0;

};

#endif /* GRAPH_HPP_ */
