#include<iostream>
#include<vector>

using namespace std;
int memoization(vector<vector<int>>memo , vector<int> arr, int target, int i, int n){
    if(target == 0)
        return 1;
    if (target < 0)
        return 0;
    if(i == n)
        return 0;

    if(memo[i][target] != -1)
        return memo[i][target];
    
    memo[i][target] = memoization(memo, arr, target, i + 1, n) + memoization(memo, arr, target - arr[i], i + 1, n);
    
    return memo[i][target];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0  ; i < n; i++)
        cin>>arr[i];

    int sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum %2 != 0)
    {
        cout<<"no";
        return 0;
    }

    vector<vector<int>> memo(n+1);
    for(int i = 0 ; i < n; i++){
        memo[i] = vector<int>(sum/2 +1 , -1);
    }
    if(memoization(memo, arr, sum/2, 0, n))
        cout<<"yes";
    else cout<<"no";
    return 0;


}