#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int> &arr, int low, int high){
    if(low > high){
        return;
    }

    int pivot = arr[high];
    int i = low - 1;
    int temp;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot)
        {
            i++;
            temp=arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1;
    arr[i+1] = arr[high];
    arr[high] = temp;
    quicksort(arr, low, i);
    quicksort(arr, i+2, high);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> arr;
        int n, num;
        cin>>n;
        for(int i =0 ; i < n; i++){
            cin>>num;
            arr.push_back(num);
        }
        
        bool flag = false;
        quicksort(arr, 0, n-1);
        for(int i = 0 ; i < n-1; i++){
            if(arr[i] == arr[i+1])
            {
                cout<<"YES\n";
                flag = true
                break;
            }
        }
        if(!flag)
        {
            cout<<"NO\n";
        }
    }
    return 0;
}