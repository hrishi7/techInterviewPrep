#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
class Triplet{
    public:
        ll gcd;
        ll x,y;
};
Triplet extendedEucluid(ll a, ll b){

    if(b == 0){
        Triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
        return myAns;
    }

    Triplet smallAns = extendedEucluid(b,a%b);
    Triplet Myans;
    Myans.gcd = smallAns.gcd;
    Myans.x = smallAns.y;
    Myans.y = (smallAns.x - ((a/b)*(smallAns.y)));
    return Myans;
}

ll mMI(ll A, ll M){
    ll x = extendedEucluid(A,M).x;
    return (x % M + M) % M;
}

ll gcd(ll a, ll b){
    if(a < b){
        return gcd(b,a);
    }
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){


    int t;
    cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;
        ll g = __gcd(a,b);
        if(d % g){
            cout<<"0"<<endl;
            continue;
        }
        if(d == 0){
            cout<<"1"<<endl;
            continue;
        }


        a /= g;
        b /= g;
        d /= g;
        ll y1 = ((d % a) * mMI(b,a));
        ll firstvalue = d/b;

        if(d < y1*b){
            cout<<"0"<<endl;
            continue;
        }
        ll n = (firstvalue -y1) / a;
        cout<< n + 1<<endl;

    }



    return 0;


}
