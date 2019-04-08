#include<iostream>
using namespace std;
const int N = 1e6+3;
bool vis[N];
int dp[N];

void calculateSuffix(int* a, int n){
    dp[n-1] = 1;
    vis[a[n-1]] = 1;
    for(int i = n-2; i>=0; i--){
        int newV = 0;
        if(vis[a[i]] == 0){
            newV = 1;
            vis[a[i]] = 1;
        }
        dp[i] = dp[i+1] + newV;
    }
}

int main(){
    //freopen("inpdp1.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    int* a = new int[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    calculateSuffix(a,n);
    for(int i = 0; i<m; i++){
        int x;
        cin>>x;
        cout<<dp[x-1]<<endl;
    }

    return 0;
}
