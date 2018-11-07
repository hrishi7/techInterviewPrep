#include<iostream>
#include<cstring>
#include<string.h>

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
int editDistance(string s1, string s2){

   int m1 = s1.size();
   int n1 = s2.size();

    char str1[m1 + 1];
  	char str2[n1 + 1];
  strcpy(str1, s1.c_str());
  strcpy(str2, s2.c_str());

  int m = strlen(str1);
  int n = strlen(str2);


  int ** dp = new int*[m + 1];
    for(int i = 0; i<=m; i++){
        dp[i] = new int[n + 1];
        for(int j = 0; j<=n; j++){
            dp[i][j] = -1;
        }
    }

  int ans = editDistanceDp(str1, str2, m, n, dp);


    for(int i = 0; i<=n; i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1, s2);
}
