#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int getMaxVal(int W, int wt[], int val[], int n,int** dp){
    if(W == 0 || n == 0){
        return 0;
    }
    if(dp[n][W] > -1)
        return dp[n][W];
    int ans;
    if(wt[n - 1] > W){
       ans =  getMaxVal(W,wt,val, n - 1,dp);
       dp[n][W] = ans;
       return ans;
    }
    else{
        ans =  max(val[n - 1] + getMaxVal(W- wt[n - 1],wt, val, n - 1,dp) ,getMaxVal(W,wt,val, n - 1,dp));
        dp[n][W] = ans;
        return ans;
    }
}



int main(){

    int wt[] = {1,2,4,5};
    int val[] = {5,4,8,6};
    int n = 4;
    int W = 5;
    int **dp = new int*[n + 1];
    for(int i = 0; i<=n; i++){
        dp[i] = new int[W + 1];
        for(int j = 0; j<=W; j++){
            dp[i][j] = -1;
        }
    }
    cout<<getMaxVal(W,wt,val,n, dp)<<endl;
    return 0;
}
