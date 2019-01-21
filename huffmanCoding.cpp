#include<iostream>
using namespace std;

int main(){
    int arr[256] = {0};
    string str = "abaaad";
    cout<<str.length()*8<<endl;
    for(int i = 0; i<str.length(); i++){
        arr[int(str[i])]++;
    }
    for(int i = 0; i<256; i++){
        if(arr[i] != 0){
            cout<<i<<" "<<arr[i]<<endl;
        }
    }
    return 0;
}
