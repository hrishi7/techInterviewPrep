#include<iostream>
using namespace std;
#define MAX 1000000
typedef long long ll;

int* makeCubeArray(){
    int* isCube = new int[MAX];
    for(int i = 0; i<= MAX; i++){
        isCube[i] = 0;
    }
    for(int i = 2; i<=100;i++){
        for(int j = (i*i*i);j <= MAX; j+=i*i*i){
            isCube[j] = -1;
        }
    }
    int k = 1;
    for(int i = 1;i<=MAX; i++){
        if(isCube[i] != -1){
            isCube[i] = k;
            k++;
        }
    }
    return isCube;
}

ll findCubes(int n, int* isCube){

    return isCube[n];
}

int main(){
    int t,c = 1;
    cin>>t;
    int *isCube = new int[MAX];
    isCube = makeCubeArray();
    while(c <= t){
        int n;
        cin>>n;
        ll ans = findCubes(n,isCube);
        cout<<"Case "<<c<<":";
        if(ans == -1){
            cout<<"Not Cube Free"<<endl;
        }
        else{
            cout<<ans<<endl;
        }

        c++;
    }

}
