#include "../include/graphs/shortest_path_algorithms.hpp"

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    int n=graph.getNumOfVertexes();
    typedef std::pair<int, int> pi;
    std::vector<pi> Q;
    for (int i = 0; i < n; i++)
    {
        //first - distnace
        //second - previous
        std::pair<int, std::vector<int>> pair;
        if(i==sourceIndex){
            pair.first=0;
        }
        else{
            pair.first=INT16_MAX;
        }
        result[i]=pair;
        Q.push_back(std::make_pair(pair.first,i));
    }
    while(!Q.empty())
    {
        sort(Q.begin(),Q.end());
        int vertex = Q[0].second;
        Q.erase(Q.begin());
        for (int i = 0; i < n; i++) 
        {
            if (graph.vertexIsNeighbour(vertex,i))
            {
                if(result[i].first > result[vertex].first + graph.getEdgeValue(vertex, i)){
                   result[i].first = result[vertex].first + graph.getEdgeValue(vertex, i);
                   result[i].second=result[vertex].second;
                   result[i].second.push_back(vertex);
                   for (int j = 0; j < Q.size(); j++)
                   {
                       if(Q[j].second==i)
                       Q[j].first=result[i].first;
                   }  
                }
            }   
            else if(vertex==i)
            result[i].second.push_back(vertex);

        }

    }
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    return true;
}
void printSHR(ShortestPathResult SHR)
{
    for (int i = 0; i <SHR.size() ; i++)
    {
        std::cout<<i<<" "<<SHR[i].first<<" ";    
        for (int j = 0; j < SHR[i].second.size(); j++)
        {
            std::cout<<SHR[i].second[j]<<" ";
        }
        std::cout<<"\n";
    }
    
}