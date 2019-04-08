#include<iostream>
typedef long long LL;
using namespace std;

int main(){
    LL n, t;
    bool found = false;
    cin>>n>>t;
    int *a = new int[n - 1];
    for(int i = 1; i<=n - 1; i++){
        cin>>a[i];
    }
    for(LL i = 1; i< n;){
             i += a[i];
            if(i == t){
                found = true;
                break;
            }
    }
    cout<<((found) ? "YES":"NO")<<endl;

    return 0;
}
