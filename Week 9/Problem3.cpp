#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    priority_queue<int, vector<int>, greater<int>> pQ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    
    for(auto i : arr){
        pQ.push(i);
    }
    int sum = 0;
    while(pQ.size() > 1){
        int a=pQ.top();
        pQ.pop();
        int b=pQ.top();
        pQ.pop();
        pQ.push(a + b);
        sum += a + b;
    }
    cout<<sum<<" ";
    return 0;
}