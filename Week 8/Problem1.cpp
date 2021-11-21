#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int prim(vector<vector<int>>& v, int n){
    vector<bool> visited;
    vector<int> weights;

    priority_queue<pair<int , int > , vector<pair<int, int>>, greater<pair<int , int>>> priorityQ;
    for(int i = 0 ; i < n ; i++)
    {
        visited.push_back(false);
        weights.push_back(INT_MAX);
    }
    int source = 0;
    weights[source] = 0;

    priorityQ.push(make_pair(weights[source], source));
    while(!priorityQ.empty()){
        int i = priorityQ.top().second;
        priorityQ.pop();

        if(!visited[i]){
            visited[i] = true;
            for(int j = 0 ; j < n ; j ++)
            {
                if(!visited[j] && v[i][j] != 0 && v[i][j] < weights[j])
                {
                    weights[j] = v[i][j];
                    priorityQ.push(make_pair(weights[j], j));
                }
            }
        }
    }

    int totalWeight = 0;
    for(auto i : weights)
        totalWeight += i;
    return totalWeight;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    vector<int> vec;
    for(int i = 0; i < n ; i ++)
    {
        vec.clear();
        for(int j = 0 ; j < n; j++)
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        v.push_back(vec);
    }
    
    cout << "Minimum spanning weight : " << prim(v, n);
}