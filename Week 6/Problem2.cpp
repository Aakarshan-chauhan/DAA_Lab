#include<iostream>
#include<map>
#include<vector>
#include<queue>

class Graph{
    public :
    // Adjacency list
    std::map<int, std::vector<int>> adj;

    // Set of each vertex
    std::map<int, int> vSet;

    // Add the edge and initialize the set of vertices to -1
    void add_edge(int source, int destination){
        adj[source].push_back(destination);
        vSet[source] = -1;
        vSet[destination] = -1;
    }

    // Check whether the graph is bipartite or not (BFS)
    bool isBipartite(int source){
        
        vSet[source]= 0;
        std::queue<int> q;

        q.push(source);
        while(q.empty() == false){
            int v = q.front();
            q.pop();
            for(auto i : adj[v]){
                if(i == v){
                    // self loop
                    return false;
                }
                if(vSet[i] == -1)
                {
                    // if set of source is 1, make it 0. and vice versa
                    vSet[i] = 1 - vSet[v];
                    q.push(i);
                }

                // if bipartite , the connecting vertices must be from different classes
                else if(vSet[i] == vSet[v])
                    return false;
            }
        }
        return true;
    }
};

int main(){
    int n;
    std::cin>>n;
    Graph g;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            int temp;
            std::cin>>temp;
            if(temp == 1)
                g.add_edge(i , j);
        }
    }
    if(g.isBipartite(0) == true)
    {
        std::cout<<"Yes the graph is bipartite";
    }
    else
    {
        std::cout<<"No . the graph is not bipartite";
    }
    return 0;
}