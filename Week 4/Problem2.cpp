#include<iostream>

using namespace std;

int n_compare = 0;
int n_invert = 0;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Pivot(int arr[], int low, int high){
    int p = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        n_compare ++;

        if(arr[j] <= p){
            i++;
            n_invert ++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    n_invert++;
    return i+1;
}

void Quick_Sort(int arr[], int low, int high){
    int p;
    if(low > high)
    return;

    p = Pivot(arr, low, high);
    Quick_Sort(arr, low, p-1);
    Quick_Sort(arr, p+1, high);
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int []arr = new int[n];
        for(int i =0 ; i < n; i++){
            cin>>arr[i];
        }
        Quick_Sort(arr, 0, n-1);
        for(int i = 0 ; i < n; i++){
            cout<<arr[i] << " ";
        }
        cout<<endl;
        cout<<"COMPARISIONS : "<<n_compare<<endl;
        cout<<"INVERSIONS: "<<n_invert;
        cout<<endl;
    }
    return 0;
}