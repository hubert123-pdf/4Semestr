#include "../include/graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    AdjacencyMatrixGraph AMGraph;
    std::string str;
    getline(is,str);
    std::istringstream iss(str);
    iss >> AMGraph.num_of_vertexes >> AMGraph.num_of_edges;
    AMGraph.matrix = new int *[AMGraph.num_of_vertexes];
    for (int i = 0; i < AMGraph.num_of_vertexes; i++)
    {
        AMGraph.matrix[i]=new int[AMGraph.num_of_vertexes];
    }
    
    while(is)
    {
        MinimumSpanningEdge new_edge;
        int cost;
        unsigned start,end;
        is >> start >> end >> cost;
        new_edge.v1=start;
        new_edge.v2=end;
        new_edge.weight=cost;
        AMGraph.pqueue.push(new_edge);
        AMGraph.matrix[start][end]=cost;
    }
    return std::make_unique<AdjacencyMatrixGraph>(AMGraph);
}
std::ostream& AdjacencyMatrixGraph::operator<<(std::ostream &Strm)
{
    for (int i = 0; i < num_of_vertexes; i++){
        for (int j = 0; j < num_of_vertexes; j++){
            Strm<< matrix[i][j]<<" ";       
        }        
        Strm<<"\n";
    }
    return Strm;
}
const int AdjacencyMatrixGraph::getEdgeWeight(int i,int j) const 
{
    return matrix[i][j];
}
std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> AdjacencyMatrixGraph::getAllEdgesPossibleEdgesOfTree(bool possible[])
{
    std::priority_queue<MinimumSpanningEdge,MinimumSpanningTreeResult,compareWeight> queue;
    for (int i = 0; i < num_of_vertexes; i++)
    {
        if(possible[i]){
            for (int j = 0; j < num_of_vertexes; j++)
            {
                if(matrix[i][j]!=0){
                    MinimumSpanningEdge edge;
                    edge.v1=i;
                    edge.v2=j;
                    edge.weight=matrix[i][j];
                    queue.push(edge);
                }
            }
        }
    }
    return queue;
}
