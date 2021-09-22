#include<iostream>
#include<vector>

using namespace std;
int binary_search(vector<int> arr, int l, int r, int x){
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
    cin >> t;
    while(t--){
        vector<int> arr;
        int n, num;

        cin>>n;
        for(int i =0 ; i < n; i++){
            cin>>num;
            arr.push_back(num);

        }

        int y;
        cin>>y;

        int counter = 0;
        for(int i =0 ; i < n - 1; i++){
            int x = arr[i] - y;
            int idx = binary_search(arr, i+1, n-1, x);
            if(idx != -1){
                counter++;
            }
        }
        if(counter==0){
            cout<<"NO SEQUENCE FOUND\n";
        }
        else{
            cout<<counter<<endl;
        }
    }
    return 0;
}