#include<iostream>
#define MAX 100000
using namespace std;
typedef long long ll;

int* makeSeive(){
    int* primes = new int[MAX];
    for(int i = 0; i<=MAX; i++){
        primes[i] = 0;
    }
    for(int i = 2; i*i <= MAX; i++){
        if(primes[i] == 0){
            for(int j = i; j<=MAX; j+=i){
                primes[j]++;
            }
        }
    }
    return primes;
}

int** primefactors(int* primes){
    int ** arr = new int*[11];
    for(int i = 0; i<=10; i++){
        arr[i] = new int[MAX + 1];
        for(int j = 0; j<=MAX; j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i<=10; i++){
        for(int j = 0; j<=MAX; j++){
           if(primes[j] == i){
                arr[i][j] = arr[i][j - 1] + 1;
           }
           else{
                arr[i][j] = arr[i][j - 1];
           }
        }
    }
    return arr;
}

ll getNumOfFactors(int** arr,ll a, ll b, ll n){
    return (arr[n][b] - arr[n][a-1]);
}

int main(){
    ll t;
    int* seiveArray = new int[MAX];
    seiveArray = makeSeive();
    int ** arr = new int*[11];
    for(int i = 0; i<=10; i++){
        arr[i] = new int[MAX + 1];
    }
    arr = primefactors(seiveArray);
    cin>>t;
    while(t--){
        ll a, n, b;
        cin>>a>>b>>n;
        cout<<getNumOfFactors(arr,a,b,n)<<endl;
    }

    return 0;
}
