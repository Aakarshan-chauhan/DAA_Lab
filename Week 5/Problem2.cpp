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

int binary_search(int * arr, int l, int r, int x){
    int mid = (l + r) /2 ;
    if (l > r)
    {
        return -1;
    }
    if (arr[mid] == x){
        return mid;
    }

    else if(arr[mid] > x){
        return binary_search(arr, l, mid-1, x);
    }

    else{
        return binary_search(arr, mid+1, r, x);
    }

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
        int sum;
        cin>>sum;
        mergeSort(arr, 0, n);
        bool flag = false;
        for(int i = 0 ; i < n; i++){
            int key = sum - arr[i];
            int idx = binary_search(arr, i, n, key);
            if(idx!=-1)
            {
                cout<<arr[i] << " "<<arr[idx]<<", ";
                flag = true;
            }
        }
        if(!flag){
            cout<<"No such pair exist";
        }
    }
    return 0;
}