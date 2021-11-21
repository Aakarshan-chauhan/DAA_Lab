#include<iostream>
using namespace std;

int n_compare =0;

int ksmall (int arr[], int low, int high, int k){
    int p = arr[high];
    int i = low - 1;
    int j = low;

    for(; j<=high; j++){
        n_compare ++;
        if(arr[j] <= p){
            int temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;

        }

    }
    n_compare ++;
    if(i == k)
        return arr[i];

    else if (i < k)
        return ksmall(arr, i+1, high, k);
    
    else return ksmall(arr, low, i - 1, k);
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int *arr = new int [n];
        for(int i =0 ; i < n ; i++){
            cin>>arr[i];
        }

        int k;
        cin>>k;

        int a = ksmall(arr, 0, n-1, k);
        cout<<a<<"\nCOMPARISIONS: "<<n_compare<<"\n";
    }
    return 0;
}