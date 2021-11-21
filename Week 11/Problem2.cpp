#include<iostream>
#include<vector>

using namespace std;

int getCoin(vector<int> arr, vector<vector<int>> coinMat, int i, int n, int target){
    if(target == 0)
        return 1;
    if (target < 0)
        return 0 ;

    if (i == n )
    {
        return 0;
    }

    if(coinMat[i][target] != -1)
        return coinMat[i][target];
    
    coinMat[i][target] = getCoin(arr, coinMat, i+1, n, target) + getCoin(arr, coinMat, i, n, target - arr[i]);
    return coinMat[i][target];
    
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> coinMat(n);
    
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
        
    }
    int target ;
    cin>>target;
    for(int i = 0 ; i < n ; i++)
    {
        coinMat[i] = vector<int>(target+1, -1);
    }

    int ways = getCoin(arr, coinMat, 0, n, target);
    cout<<ways;
    return 0;
}