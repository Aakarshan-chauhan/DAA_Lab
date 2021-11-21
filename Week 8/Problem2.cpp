#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef vector<pair<int, pair<int, int>>> vii;

int find(int u , int * parent){
    if(parent[u]< 0) return u;
    return find(parent[u], parent);
}

void unionByWeight(int u , int v, int * parent){
    int pu = find(u, parent), pv = find(v, parent);
    if(pu != pv)
    {
        if(parent[pu] <= parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else{
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}
vii kruskals(vii g, int V){
    int s, d, w;
    vii res;

    int * parent = new int[V];
    for (int i =0 ; i < V; i++){
        parent[i] = -1;
    }
    sort(g.begin(), g.end());

    int E = g.size();
    for(int i =0 ; i < E; i++){
        s = g[i].second.first;
        d = g[i].second.second;
        w = g[i].first;

        if(find(s, parent)!=find(d, parent))
        {
            res.push_back(make_pair(w, make_pair(s, d)));
            unionByWeight(s, d, parent);
        }
    }

    return res;
}
int main(){
    
    int V;
    cin>>V;
    vii graph, result;
    for(int i = 0 ; i < V; i++)
    {
        for(int j = 0 ; j < V; j++)
        {
            int temp;
            cin>>temp;
            if(temp >0)
            {
                graph.push_back(make_pair(temp, make_pair(i, j)));
            }
        }
    }
    sort(graph.begin(), graph.end());
   
    result = kruskals(graph, V);
    int min_weight = 0;
    for(int i =0 ; i < result.size(); i++)
    {
        min_weight += result[i].first;
        
    }
    cout<<"Minimum spanning weight: "<<min_weight;
    return 0;
}
