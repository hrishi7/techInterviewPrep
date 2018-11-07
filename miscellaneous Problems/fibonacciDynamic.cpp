#include<iostream>
using namespace std;

int fibo(int n){
    if(n == 0 || n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int dpFibo(int n, int* arr){
    if( n == 0 || n == 1)
        return 1;
    if( arr[n] > 0)
        return arr[n];
    int num = dpFibo( n -1, arr) + dpFibo( n - 2, arr);
    arr[n] = num;
    return num;
}
int fiboi(int n){
    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i<=n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int output = arr[n];
    delete[] arr;
    return output;
}

int main()
{
    int n;
    cin>>n;
    //int *arr = new int[n + 1];
    //*arr = {0};
    //cout<<dpFibo(n, arr);
    //cout<<fibo(n);
    cout<<fiboi(n);
}
