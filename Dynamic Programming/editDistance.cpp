#include<iostream>
#include<cstring>
#include <bits/stdc++.h>

using namespace std;

int editDistanceDp(char* s1, char* s2, int m, int n, int** dp){
  if(m == 0 && n == 0)
    return 0;
   if(m == 0 && n != 0)
    return n;
  if(m != 0 && n == 0)
    return m;
  if(dp[m][n] > -1){
    return dp[m][n];
  }
  int ans;
   if(s1[0] == s2[0]){
    ans =  editDistanceDp(s1 + 1, s2 + 1, m - 1, n - 1, dp);
  }else{
    int option1 = 1 + editDistanceDp(s1 + 1, s2 + 1, m - 1, n - 1, dp);
    int option2 = 1 + editDistanceDp(s1, s2 + 1, m, n - 1, dp);
    int option3 = 1 + editDistanceDp(s1 + 1, s2, m - 1, n, dp);
    ans = min(option1, min(option2, option3));
  }
  dp[m][n] = ans;
  return dp[m][n];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;

    int m = s1.length();
    int n = s2.length();
    char str1[m + 1],str2[n + 1];
    strcpy(str1, s1.c_str());
    strcpy(str2, s2.c_str());
    int **dp = new int*[m + 1];
    for(int i = 0; i<=m; i++){
        dp[i] = new int[n + 1];
        for(int j= 0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    cout<<editDistanceDp(str1,str2,m,n,dp)<<endl;
    return 0;
}

















