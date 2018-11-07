#include<iostream>

using namespace std;

void getTotient(int n){
    int *arr = new int[n + 1];
    for(int i = 1; i<=n; i++){
        arr[i] = i;
    }
    for(int i = 2; i<=n; i++){
        if(arr[i] == i){
            arr[i] = i - 1;
            for(int j = i * 2; j<=n;j += i){
                arr[j] = (arr[j] *(i - 1))/i;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout<<i <<" "<<arr[i]<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    getTotient(n);
    return 0;
}
