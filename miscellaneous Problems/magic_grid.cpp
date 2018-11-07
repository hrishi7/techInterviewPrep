#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int getHealth(int** hm, int si, int sj, int m, int n){
  if(si == m && sj == n){
    return 1;
  }
  if(si < m && sj== n){
    int lowerSide = getHealth(hm, si + 1, sj, m, n) - hm[si + 1][sj];
    if(lowerSide <1){
      lowerSide = abs(lowerSide) + 1;
    }
    return lowerSide;
  }
  else if( si == m && sj < n){
    int rightSide = getHealth(hm, si, sj + 1, m, n) - hm[si][sj + 1];
    if(rightSide < 1){
      rightSide = abs(rightSide) + 1;
    }
    return rightSide;
  }
  else{
    int ans = min( (getHealth(hm, si + 1, sj, m, n) - hm[si + 1][sj]), (getHealth(hm, si, sj + 1, m, n) - hm[si][sj + 1])	);
    if(ans < 1){
      ans =  abs(ans) + 1;
    }
    return ans;
  }
}




int getHealth2(int** hm, int m, int n){
  int ** dp = new int*[m];
    for(int i = 0; i < m; i++){
        dp[i] = new int[n];
    }
  dp[m - 1][n - 1] = 1;
  dp[m - 2][n - 1] = 1;
  dp[m - 1][n - 2] = 1;

  for(int i = m - 3; i >= 0; i--){
    int ans = dp[i + 1][n - 1] - hm[i + 1][n - 1];
    if(ans < 1){
      ans = abs(ans) + 1;
    }
    dp[i][n - 1] = ans;
  }
  for(int j = n - 3; j >= 0; j--){
    int ans = dp[m - 1][j + 1] - hm[m - 1][j + 1];
    if(ans < 1){
      ans = abs(ans) + 1;
    }
    dp[n - 1][j] = ans;
  }
  for(int i = m - 2; i >= 0; i--){
    for(int j = n - 2; j >= 0; j--){
      if(dp[i + 1][j] < dp[i][j + 1]){
        int ans = dp[i + 1][j] - hm[i + 1][j];
        if(ans < 1){
      	  ans = abs(ans) + 1;
    	}
    	dp[i][j] = ans;
      }else if (dp[i + 1][j] > dp[i][j + 1]){
        int ans = dp[i][j + 1] - hm[i][j + 1];
        if(ans < 1){
      	  ans = abs(ans) + 1;
    	}
    	dp[i][j] = ans;
      }
      else{

      }
    }
  }
  return dp[0][0];
}

int main()
{
  /*int T;
  cin>>T;
  while(T){*/
    int R,C;
    cin>>R>>C;
    int** hm = new int*[R];
    for(int i = 0; i<R; i++){
      hm[i] = new int[C];
    }
    for(int i = 0; i<R; i++){
      for(int j = 0; j<C; j++){
        cin>>hm[i][j];
      }
      cout<<endl;
    }

  cout<<getHealth2(hm, R, C)<<endl;
   	/* //cout<<getHealth(hm, 1, 1, R, C)<<endl;

   /*T--;
  }*/
    return 0;
}
