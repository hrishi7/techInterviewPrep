#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;



int main(){

    int t;
    cin>>t;
    while(t--){
        ll a, num=0;
        string b;
        cin>>a>>b;
        for(int i = 0; i< b.length(); i++){
                int cur_digit = b[i] - '0';
            num = (   ( (num * 10) % a) + (cur_digit % a) ) % a;
        }
        ll g = __gcd(a,num);
        cout<<g<<endl;
    }
    return 0;
}
