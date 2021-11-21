#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t --){
        vector<int> arr;
        int n, num;
        int n_compare =0 , n_shifts = 0;

        cin>>n;
        for(int i =0 ; i < n; i++){
            cin>>num;
            arr.push_back(num);
        }


        int min;
        for(int i =0 ; i < n-1; i++){
            min = i;
            for(int j = i +1; j < n; j++){
                n_compare ++;

                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            n_shifts ++;
        }
        for(int i =0 ; i < n; i++){
            cout<<arr[i]<<" ";

        }
        cout<<endl;
        cout<<"Comparision : "<<n_compare;
        cout<<"\n shifts : "<<n_shifts;
        cout<<"\n";
    }
    return 0;
}