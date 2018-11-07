#include<iostream>
#define mod 1000000007
using namespace std;


int alpha_code( string input, int size){
    int * output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;
    for(int i = 2; i<=size; i++){
        if(input[i] != '0')
            output[i] = output[i - 1];
        if((input[i - 2] -'0')*10 + (output[i - 1] - '0') <= 26 ){
            output[i] += output[i - 2];
        }
        output[i] = output[i] % mod;
    }
    int ans = output[size] ;
    delete[] output;
    return ans;
}

int alpha_codes2(string input, int size, int* arr) {
	 if (size == 1) {
		 return 1;
	 }
	 if (size == 0) {
		 return 1;
	 }
	 if (arr[size] > 0) {
		 return arr[size];
	 }

	 int output = alpha_codes2(input, size - 1,arr);
	 if ( ((input[size - 2] - '0') * 10) + (input[size - 1]-'0') <= 26) {
		 output += alpha_codes2(input, size -2, arr);
	 }
	 arr[size] = output % mod;
	 return output;
}

int main(){
   int x,n;
    string s;
    long long int a[1000];
    while(1){
        cin>>s;
        if(s == "0")
            break;
        n = s.size();
        int* arr = new int[n + 1];
        for(int i = 0; i<=n; i++)
            arr[i] = 0;
        cout<<alpha_codes2(s, n, arr)<<endl;
    }
    return 0;
}
