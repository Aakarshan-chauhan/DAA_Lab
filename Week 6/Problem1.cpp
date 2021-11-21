#include<iostream>
#include<vector>
#include<map>
class Graph{
    public:
    std::map<int, bool> visited;
    std::map<int , std::vector<int>> adj;

    void addEdge(int s, int d){
        adj[s].push_back(d);
    }

    void search(int s, int d){
        if(s == d)
        {
            std::cout<<"Yes there is a path";
            exit(0);
        }
        if(visited[s] == true)
            return;
        visited[s] = true;
        int result = false;
        for(auto i : adj[s]){
            if(visited[i] == false){
                search(i, d);
            }
        }
    }
};

int main(){
    int n;
    std::cin>>n;
    Graph g;
    for(int i = 0 ; i < 5; i++){
        for(int j = 0 ; j < 5; j++)
        {
            int temp;
            std::cin>>temp;
            if(temp==1)
            {
                g.addEdge(i, j);
            }
        }
    }
    int source, destination;
    std::cin>>source>>destination;
    g.search(source-1, destination-1);
    std::cout<<"NO, there is no path";
    return 0;
}

