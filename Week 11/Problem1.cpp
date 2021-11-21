#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int matrixOrderChain(int dimArr[], int n){
    int operationMatrix[n][n];
    for(int i = 0 ; i < n; i++)
        operationMatrix[i][i] = 0;
    
    for(int numMul = 2; numMul < n ; numMul ++){
        for(int i = 1; i < n - numMul + 1; i++)
        {
            int j = i + numMul - 1;
            operationMatrix[i][j] = INT_MAX;
            for(int k = i ; k <= j - 1 ; k++){
                int q = operationMatrix[i][k] + operationMatrix[k+1][j] + dimArr[i - 1] * dimArr[k] * dimArr[j];
                if(q < operationMatrix[i][j])
                {
                    operationMatrix[i][j] = q;
                }
            }

        }
    }
    
    return operationMatrix[1][n - 1];
}

int main(){
    int n;
    cin>>n;

    int dimArr[n / 2 + 1];
    for(int i =1 ; i < n+1; i++){
        int r, c;
        cin>>r>>c;
        dimArr[i-1] = r;
        dimArr[i] = c;
    }

    cout<<matrixOrderChain(dimArr, n+1);
       
    return 0;
}