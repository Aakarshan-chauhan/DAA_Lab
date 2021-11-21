#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr;
        int n, num;
        int n_compare = 0, n_shifts = 0;


        cin>>n;
        for(int i =0 ; i < n; i++){
            cin>>num;
            arr.push_back(num);
        }

        int key;
        for(int i =1; i < n; i++){
            key = arr[i];
            int r = i - 1;
            while(r >-1 && arr[r] > key){
                n_compare ++;
                n_shifts ++;
                arr[r+1] = arr[r];
                r--;
            }
            n_shifts ++;
            arr[r+1] = key;
        }

        for(int i =0 ; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\ncomparisions : "<<n_compare<<"\nshifts : "<<n_shifts<<endl;
    }
    return 0;
}