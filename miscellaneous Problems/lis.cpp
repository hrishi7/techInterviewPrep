#include<iostream>
using namespace std;

int lis(int* input, int n){
    int *output = new int[n];
    output[0] = 1;
    for(int i = 1; i<n; i++){
        output[i] = 1;
        for(int j = i - 1; j >=0; j--){
            if(input[j] > input[i]){
                continue;
            }
            int pans = output[j] + 1;
            if(output[i] < pans){
                output[i] = pans;
            }
        }
    }

    int best = output[0];
    for(int i = 1; i<n; i++){
        if(best < output[i]){
            best = output[i];
        }
    }
    delete[] output;
    return best;
}

int main(){
    int n,*input;
    cin>>n;
    input = new int[n];
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    cout<<lis(input, n)<<endl;
    delete[] input;
    return 0;

}
