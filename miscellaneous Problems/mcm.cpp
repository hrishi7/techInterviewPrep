#include<bits/stdc++.h>

int helperMcm(int* p, int si, int ei, int** dp){
  if(si == ei)
    return 0;
  if(si == ei - 1)
    return 0;
  if(dp[si][ei] > -1)
    return dp[si][ei];
  int ans = INT_MAX;
  for(int k = si + 1; k<= ei - 1; k++){
    int option = helperMcm(p, si, k, dp) + helperMcm(p, k, ei, dp) + (p[si] * p[k] * p[ei]);
    ans = min(ans, option);
  }
  dp[si][ei] = ans;
  return ans;

}

int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
  int **dp =  new int*[n + 1];
  for(int i = 0; i<=n; i++){
    dp[i] = new int[n + 1];
    for(int j = 0; j<=n; j++){
      dp[i][j] = -1;
    }
  }

	return helperMcm(p, 0, n, dp);

}
