#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void fractionalKnapsack(vector<pair<float, float>> items, int cap, int n){
    sort(items.begin(), items.end(), greater<>());
    vector<pair<float, float>> bag;
    float max_val = 0;
    for(auto i : items){
        
        if (cap<= 0)
            break;
        if(i.second < cap){
            bag.push_back(make_pair(i.second, i.second)); // the full object can fit in
            max_val += i.first*i.second;
            cap -= i.second;
        }   
        else{
            bag.push_back(make_pair(cap, i.second));
            max_val += i.first*cap;
            cap -= i.second;
        }

        
    }
    cout<<"Maximum value : " <<max_val;
    cout<<"\nItem- weight : " <<endl;
    for(auto i : bag){
        cout<<i.second<<"-"<<i.first<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<pair<float, float>> items;
    for(int i =0; i < n ; i ++)
    {
        float weight;
        cin>>weight;
        items.push_back(make_pair(0, weight));//weights
    }

    for(int i = 0 ; i < n ; i ++)
    {
        float value;
        cin>>value;
        items[i].first = value/items[i].second;//value by weight
    }
    int capacity;
    cin>>capacity;
    fractionalKnapsack(items, capacity, n);
}