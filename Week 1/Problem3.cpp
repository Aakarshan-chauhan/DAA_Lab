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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0 ; i < n; i++)
            cin>>arr[i];

        int key;
        cin>>key;

        int comparisions = 0;
        bool flag = false;

        if(arr[0] == key)
        {
            cout<<"Present "<<1<<endl;
            break;    
        }
        
        int i;
        for(i = 1 ; i < n; i*=2)
        {
            
            comparisions ++;
            if(arr[i] > key)
                break;

        }
        //linear search from i/2
        for(int j = i/2; j < i && j < n ; j++){
            if(key == arr[j])
            {
                cout<<"Present "<<j+1<<endl;
                flag = true;
                comparisions++;
                break;
            }
        }
        if(!flag)
            cout<<"Not Present" << comparisions + 1<<endl;
    }
     return 0;
}