#include<iostream>
#include<climits>
#include<vector>

using namespace std;
#define INF 1e9

void floyd_warshall(vector<vector<int>> graph, int n){
    vector<vector<int>> dist(n);
    for(int i = 0; i < n ; i++)
        dist[i] = vector<int>(n);
    

    vector<int> parent(n, -1);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++)
        {   
            dist[i][j] = graph[i][j];
            parent[j] = i;
            
        }
        
    }
    for(int k = 0 ; k < n; k++)
    {
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[k] = i;
                        parent[j] = k;
                    }

            }
        }
    }

    cout<<"Shortest distance matrix: \n";
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] == INF)
            {
                cout<<"INF ";
            }
            else
                cout<<dist[i][j] << " ";
        }
        cout<<endl;
    }

}
int main(){
    int n;
    cin>>n;

    vector<vector<int>>graph(n);
    for(int i = 0 ; i < n; i++)
    {
        graph[i] = vector<int>(n);
        for(int j = 0 ; j < n; j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]<0)
                    graph[i][j] = INF;
            }
    }

    floyd_warshall(graph, n);
    return 0;
}