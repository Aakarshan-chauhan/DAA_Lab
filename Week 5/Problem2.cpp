#include<iostream>
using namespace std;


void merge(int arr[], int begin, int mid, int end){
    int LeftSize = mid - begin + 1;
    int RightSize = end - mid;

    int *LeftArr = new int [LeftSize], * RightArr = new int[RightSize];
    for(int i =0 ; i < LeftSize; i++){
        LeftArr[i] = arr[begin + i];
    }
    for (int i =0 ; i < RightSize; i++){
        RightArr[i] = arr[mid + 1 + i];
    }

    int l= 0, r = 0, i = begin;
    while(l < LeftSize && r < RightSize)
    {
        if(LeftArr[l]< RightArr[r]){
            arr[i] = LeftArr[l];
            l++;
        }
        else{
            arr[i] = RightArr[r];
            r++;
        }
        i++;
    }

    while (l< LeftSize){
        arr[i] = LeftArr[l];
        i++; l++;
    }
    while(r< RightSize){
        arr[i] = RightArr[r];
        r++; i++;
    }

}

void mergeSort(int arr[], int begin, int end){
    if(begin>= end)
        return;
    int mid = begin + (end - begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        int *arr = new int [n];
        for(int i =0 ; i < n; i++){
            cin>>x;
            arr[i] = x;

        }
        mergeSort(arr, 0, n);
        for(int i =0 ; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";

    }
    return 0;
}