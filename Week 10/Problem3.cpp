#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i =0 ; i < n ; i ++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    vector<int> freq(n, 0);
    int max = 0;
    for(auto i : arr){
        freq[i] ++;
        if(freq[i] > max){
            max = freq[i];
        }
    }
    if(max >= n/2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    cout<<arr[n/2];
    return 0;
}