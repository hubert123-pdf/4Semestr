#include "../include/graphs/minimum_spanning_tree_algorithms.hpp"

void kruskal(Graph& graph, MinimumSpanningTreeResult& result)
{
    int n=graph.getNumOfVertexes();    
    while(result.size()<n-1)
    {
        MinimumSpanningEdge possible_edge;
        possible_edge=graph.getTopQueue();
        graph.popTopQueue();
        result.push_back(possible_edge);
        if(isCycle(result,n)){
            result.pop_back();
        }
    }
}

void prim(Graph& graph, MinimumSpanningTreeResult& result)
{
    // TODO: implement
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
} 

void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

bool isCycle(MinimumSpanningTreeResult tree,int n)
{
    int* parent = new int[n];
    for (int i = 0; i < n; i++){
        parent[i]=-1;
    }
    
    for (int i = 0; i < tree.size(); ++i) {
        int x = find(parent, tree[i].v1);
        int y = find(parent, tree[i].v2);
 
        if (x == y){
            return true;
        }
        Union(parent, x, y);
    }
    return false;
}

void printMST(MinimumSpanningTreeResult& tree)
{
    for (int i = 0; i < tree.size();  i++)
    {
        std::cout<<tree[i].v1<<" "<<tree[i].v2<<" "<<tree[i].weight<<"\n";
    }
    
}