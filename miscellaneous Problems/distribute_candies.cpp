#include<iostream>
#include<algorithm>
using namespace std;

bool isCheck(int candi, long long box[], int n, long long m){
    long long last_position = 0;
    for(int i = 0; i<n; i++){
        last_position += box[i] / m;
    }
    if(last_position >= candi){
        return true;
    }
    return false;
}

long long getCandies(long long a[],int n, int k){
    long long start = 0;
    long long end = a[n - 1];
       long long ans = -1;
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(isCheck(k,a,n,mid)){
                ans = mid;
                start = mid  + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a + n);
        cout<<getCandies(a,n,k)<<endl;
    }

}
