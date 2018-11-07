#include<iostream>
using namespace std;

int numWays(int n, int* d, int numD, int dp[][100]){
    if(n == 0){
        return 1;
    }
    if(numD == 0){
        return 0;
    }
    if(n < 0){
        return 0;
    }
    if(dp[n][numD] > -1){
        return dp[n][numD];
    }
    int first = numWays(n - d[0], d, numD, dp);
    int second = numWays(n, d + 1, numD - 1, dp);
    dp[n][numD] = first + second;
    return first + second;
}

int main(){
    int n,val;
    cin>>n;
    int *a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cin>>val;
    int dp[val + 1][n + 1] = {{-1}};
    cout<<numWays(val, a, n, dp)<<endl;

    return 0;
}
