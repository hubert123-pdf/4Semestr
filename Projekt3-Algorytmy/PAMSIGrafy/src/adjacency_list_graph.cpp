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
        getline(is,str);
        std::istringstream iss2(str);
        MinimumSpanningEdge new_edge;
        std::pair<int,int> node;
        unsigned start;
        iss2>> start;
        if(iss2){
            iss2>> node.first >> node.second;
            new_edge.v1=start;
            new_edge.v2=node.first;
            new_edge.weight=node.second;
            ALGraph.pqueue.push(new_edge);
            ALGraph.list[start].push_back(node);
        }
        else
        {
         ALGraph.dijkstra_start=start;   
        }
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
bool AdjacencyListGraph::vertexIsNeighbour(int x, int y)
{
    auto iter=list[x].begin();
    for (; iter!=list[x].end(); ++iter)
    {
        if(iter->first==y)
        return true;
    }
    return false;
}
int AdjacencyListGraph::getEdgeValue(int x, int y)
{
    auto iter=list[x].begin();
    for (; iter!=list[x].end(); ++iter)
    {
        if(iter->first==y)
        return iter->second;
    }
    return NULL;
}