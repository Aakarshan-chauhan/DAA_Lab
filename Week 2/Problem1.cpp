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
    int n;
    cin >> t;
    while(t--){
        vector<int> arr;
        cin>>n;
        int num;

        for(int i =0 ; i < n; i++){
            cin>>num;
            arr.push_back(num);

        }
        int x;
        cin>>x;
        int index = binary_search(arr, 0, arr.size() - 1, x);
        if(index ==-1){
            cout<<"ELEMENT NOT IN ARRAY\n";
        }
        else{
            int count = 0;
            while(int element : arr){
                if(element==arr[index])
                {
                    count++;
                }
            }
            cout<<"ELEMENT FOUND AND ITS OCCURANCE IS "<<count<<"\n";
        }
    }
    return 0;
}