#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    vector<pair<pair<int, int>, int>> activity;
    // activity finish and start
 
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin>>temp;
        activity.push_back(make_pair(make_pair(0, temp), i));
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>activity[i].first.first;
    }

    sort(activity.begin(), activity.end());
    int start= activity[0].first.second;
    int end = activity[0].first.first;
    
    vector<int> sequence;
    sequence.push_back(activity[0].second);
    for(auto i : activity){
        if(i.first.second >= end){
            sequence.push_back(i.second);
            start = i.first.second;
            end = i.first.first;
        }
    }    
    cout<<"max number of tasks : "<<sequence.size()<<endl;
    cout<<"Selected task numbers : ";
    for(auto i : sequence)
        cout<<i+1<<" ";
    return 0;
}