#include<iostream>
#include<vector>
#include<map>

class Graph{
    public :
    std::map<int, bool> visited;
    std::map<int, std::vector<int>> adj;

    void add_edge(int source, int destination){
        adj[source].push_back(destination);
    }
    bool hasCycle(int source){
        if(visited[source] == true)
            return true;
        visited[source] = true;
        bool b;
        for(auto i : adj[source])
        {
            b = hasCycle(i);
        }
        visited[source] = false;
        return b;
    }
};

int main(){
    int n;
    std::cin>>n;
    Graph g;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n; j++){
            int temp;
            std::cin>>temp;
            if(temp == 1)
                g.add_edge(i , j);
        }
    }
    bool cycle = false;

    for(auto i : g.adj)
    {
        cycle = cycle || g.hasCycle(i.first); 
    }
    if(cycle){
        std::cout<<"Cycle exists";
    }
    else{
        std::cout<<"Cycle doesn't exist";
    }
    return 0 ;
    
}