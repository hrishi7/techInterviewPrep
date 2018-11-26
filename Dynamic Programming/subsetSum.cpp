#include<iostream>

using namespace std;

int subsetSum(int* val, int n, int sum){

    if(n == 0){
        if(sum == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int ans1 = subsetSum(val,n - 1,sum) || subsetSum(val,n - 1, sum - val[n - 1]);
    return ans1;
}


bool iterativeSubsetSumWithLessSpace(int* val, int n, int s){
    bool** dp = new bool*[2];
    for(int i = 0; i<=1; i++){
        dp[i] = new bool[s + 1];
    }
    for(int i = 0; i<=s; i++){
        dp[0][i] = false;
    }
    dp[0][0] = true;
    int flag = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=s; j++){
            dp[flag][j] = dp[flag ^ 1][j];
            if(j >= val[i - 1]){
                dp[flag][j] = dp[flag ^ 1][j] || dp[flag ^ 1][j - val[i - 1]];
            }
        }
        flag = flag ^1;
    }

    bool ans = dp[flag ^ 1][s];
    //delete dp array
    for(int i = 0; i<=n; i++){
        delete dp[i];
    }
    delete[]dp;
    return ans;
}

bool iterativeSubsetSum(int* val, int n, int s){
    bool** dp = new bool*[n + 1];
    for(int i = 0; i<=n; i++){
        dp[i] = new bool[s + 1];
    }
    for(int i = 0; i<=s; i++){
        dp[0][i] = false;
    }
    for(int i = 0; i<=n; i++){
        dp[0][i] = true;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=s; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= val[i - 1]){
                dp[i][j] = dp[i][j] || dp[i - 1][j - val[i - 1]];
            }
        }
    }
    bool ans = dp[n][s];
    //delete dp array
    for(int i = 0; i<=n; i++){
        delete dp[i];
    }
    delete[]dp;
    return ans;
}

int main(){

    int val[] = {1,3,5,7,9};
    int sum = 8;
    int n = 5;
    cout<<"Simple recursive solution: "<<subsetSum(val, n, sum)<<endl;
    cout<<"Iterative dp solution: "<<iterativeSubsetSum(val,n,sum)<<endl;
    cout<<"Iterative with xor Operator: "<<iterativeSubsetSumWithLessSpace(val,n,sum)<<endl;
    return 0;
}
