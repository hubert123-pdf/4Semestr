#include "../include/graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    AdjacencyListGraph ALGraph;
    std::string str;
    getline(is,str);
    std::istringstream iss(str);
    iss >> ALGraph.num_of_vertexes >> ALGraph.num_of_edges;
    ALGraph.list = new std::list<std::pair<int,int>> [ALGraph.num_of_vertexes];
    while(is)
    {
        MinimumSpanningEdge new_edge;
        std::pair<int,int> node;
        unsigned start;
        is>> start >> node.first >> node.second;
        new_edge.v1=start;
        new_edge.v2=node.first;
        new_edge.weight=node.second;
        ALGraph.pqueue.push(new_edge);
        ALGraph.list[start].push_back(node);
    }
    return std::make_unique<AdjacencyListGraph>(ALGraph);
}
std::ostream& AdjacencyListGraph::operator<<(std::ostream &Strm)
{
    std::list<std::pair<int,int>>::iterator iter;
    for (int i = 0; i < num_of_vertexes; i++)
    {
        Strm<<i<<" ";
        for(iter=list[i].begin();iter!=list[i].end();++iter)
        {
            Strm<<"-> "<< iter->first<<" " <<iter->second<<" ";
        }
        Strm<<"\n";
    }
    
    return Strm;
}
const int AdjacencyListGraph::getEdgeWeight(int i,int j) const 
{
    std::list<std::pair<int,int>>::iterator iter;
    int buff=0;
    for(iter=list[i].begin();iter!=list[i].end();++iter,++buff)
    {
        if(buff==j){
            return (*iter).second;
        }
    }
    return iter->second;
}

std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> AdjacencyListGraph::getAllEdgesPossibleEdgesOfTree(bool possible[])
{
    std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> queue;
    std::list<std::pair<int,int>>::iterator iter;
    for (int i = 0; i < num_of_vertexes; i++)
    {
        if(possible[i]){
            for ( iter=list[i].begin(); iter!=list[i].end(); iter++)
            {
                MinimumSpanningEdge new_edge;
                new_edge.v1=i;
                new_edge.v2=iter->first;
                new_edge.weight=iter->second;
                queue.push(new_edge);
            }
        }
    }
    return queue;
}