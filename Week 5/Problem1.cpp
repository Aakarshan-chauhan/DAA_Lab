#include <iostream>
#include<climits>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c;
        int idx = -1;
        int max = INT_MIN;
        int arr[26]={0};
        for (int i = 0; i < n; i++)
            {
                
                cin >> c;
                arr[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] > max)
                {
                    idx = i;
                    max = arr[i];
                }
            }
            if (max>1)
                cout << char('a' + idx) << " with occurance: " << arr[idx] << endl;
            else
                cout << "DUPLICATES NOT FOUND" << endl;
    }
}