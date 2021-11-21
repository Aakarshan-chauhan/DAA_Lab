#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

void cascadingParent(vector<int> parent, int s){
    cout<<s + 1<< " ";
    if(parent[s] >= 0)
        cascadingParent(parent, parent[s]);
}
void dijkstra(map<int, vector<pair<int , int>>> graph, int source, int n){
    vector<int> parent(n, -1), weights(n, 1e9);
    priority_queue<pair<int , int>, vector<pair<int, int>>> minHeap;
    weights[source] = 0;
    minHeap.push(make_pair(weights[source], source));
    while(!minHeap.empty()){
        int u = minHeap.top().second;
        minHeap.pop();

        for(auto v : graph[u]){
            if(weights[v.first] > weights[u] + v.second)
            {
                parent[v.first] =  u;
                weights[v.first] = weights[u] + v.second;
                minHeap.push(make_pair(weights[v.first], v.first));
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cascadingParent(parent, i);
        cout<<" : "<<weights[i]<<endl;
    }
}

int main(){
    map<int, vector<pair<int , int>>> graph;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            int temp;
            cin>>temp;
            if(temp>0)
            {
                graph[i].push_back(make_pair(j, temp));
            }
        }
    }

    dijkstra(graph, 0, n);
    return 0 ;
}