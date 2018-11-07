#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int N;
    cin>>N;
    bool* arr = new bool[N];
    for(int i = 0; i<N; i++){
        if(i == 0 || i == 1)
            arr[i] = false;
        else
            arr[i] = true;
    }

    for(int i = 2; i*i<N; i++){
        if(arr[i] == true){
            for(int j = i*i; j<N; j = j + i){
                arr[j] = false;
            }
        }
    }
int count = 0;
    for(int i = 0; i<N; i++){
        if(arr[i] == true)
            count++;
    }
    cout<<count;
}
