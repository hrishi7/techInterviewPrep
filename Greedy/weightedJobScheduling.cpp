#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Job{
    int start,finish,profit;
};


bool compare(Job a, Job b){
    return a.finish<b.finish;
}

int fMax(Job a[], int n){
    sort(a,a+n,compare);
    int* dp = new int[n];
    dp[0] = a[0].profit;
    for(int i = 1; i<n; i++){
        int including = a[i].profit;
        int lNCon = -1;
        for(int j = i; j>=0; j--){
            if(a[j].finish <=a[i].start){
                lNCon = j;
                break;
            }
        }
        if(lNCon != -1){
            including += dp[lNCon];
        }
        dp[i] = max(including, dp[i - 1]);
    }
    int ans = dp[n - 1];
    delete[] dp;
    return ans;

}

int main(){
    Job a[] = {{2,5,50},{1,2,20},{6,9,50},{2,50,500}};

    cout<<"Maximum job Profit can be achieved is: "<<fMax(a,4)<<endl;
    return 0;
}
