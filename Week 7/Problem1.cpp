#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
void cascadeParent(vector<int>&parent, int u){
    cout<< u + 1 <<" ";
    if(parent[u] >= 0)
    {
        cascadeParent(parent, parent[u]);
    }
}
void dijkstra(vector<vector<int>> graph, int n, int source){
    vector<int> parent(n, -1), weights(n, INT_MAX);
    priority_queue<pair<int, int> > pQ;
    weights[source] = 0;
    pQ.push(make_pair(weights[source], source));
    while(!pQ.empty())
    {
        int u = pQ.top().second;
        pQ.pop();

        for(int i = 0; i < n; i++)
        {
            if(graph[u][i] != 0)
            {
                if(weights[i] > weights[u] + graph[u][i])
                {
                    weights[i] = weights[u] + graph[u][i];
                    pQ.push(make_pair(weights[i], i));
                    parent[i] = u;
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cascadeParent(parent, i);
        if(weights[i] == INT_MAX){
            cout<<": NO ROUTE\n";
        }
        else{
            cout<<": "<<weights[i]<<"\n";
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        graph[i] = vector<int>(n);
        for(int j = 0 ; j< n; j++)
        {
            cin>>graph[i][j] ;
        }
    }
    int source ;
    cin>>source;
    dijkstra(graph, n, source-1);
}