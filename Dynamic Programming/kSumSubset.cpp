#include<iostream>

using namespace std;


//space optimize solution using xor
bool subsetSum(int* val,int n,int sum){

	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){

			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]];
			}
		}
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	// delete dp array
	return ans;


}


//Iterative
bool getSubsetSumKOrnotIt(int * val, int n, int k){
  bool **dp = new bool*[n + 1];
    for(int i = 0; i<=n; i++){
        dp[i] = new bool[k + 1];
    }

  for(int i = 0; i<=k; i++){
    dp[0][i] = false;
  }
  for(int i = 0; i<=n; i++){
    dp[i][0] = true;
  }

  for(int i = 1; i<=n;i++){
    for(int j = 1; j<=k; j++){
      dp[i][j] = dp[i - 1][j];
      if(j >= val[i - 1]){
        dp[i][j] = dp[i][j] || dp[i - 1][j - val[i - 1]];
      }
    }
  }
  return dp[n][k];
}

//basic recursive solution
bool getSubsetSumKOrnot(int* val, int n, int sum){
    if(n == 0){
        if(sum == 0)
            return true;
        else
            return false;
    }

    if(val[n - 1] > sum){
       return getSubsetSumKOrnot(val, n - 1, sum);
    }
    else{
       return (getSubsetSumKOrnot(val, n - 1, sum) || getSubsetSumKOrnot(val,n - 1, sum - val[n - 1]));
    }
}


int main(){
    int val[] ={1,3,5,7,9};
    int n = 5;
    int sum = 8;
    bool ans = getSubsetSumKOrnot(val,n,sum);
    if(ans == true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;

}
