#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void cascadingParent(vector<int> parent, int i){
    cout<<i + 1<< " ";
    if(parent[i] >=0)
        cascadingParent(parent, parent[i]);
}
void bellman_ford(vector<vector<int>> graph, int n, int source){
    vector<int> distance(n, INT_MAX);
    vector<int> parents(n, -1);

    for(int k = 0; k<n - 1; k++){
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                if(graph[i][j])
                {
                    if(distance[j] > distance [i] + graph[i][j])
                    {
                        distance[j] = distance[i] + graph[i][j];
                        parents[j] = i;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cascadingParent(parents, i);
        cout<<": "<<distance[i]<<"\n";
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n);

    for(int i = 0 ; i  < n; i++){
        graph[i]= vector<int>(3);
        for(int j = 0; j < n; j++){
            cin>>graph[i][j];
        }
    }

    int source;
    cin>>source;
    bellman_ford(graph, n, source - 1);
    return 0;
}