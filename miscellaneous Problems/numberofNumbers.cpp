#include<iostream>
using namespace std;

int numRepetetive(int* input, int n, int* fact, int* freq, int denominator){
    if(n == 0 || n == 1){
        return 0;
    }
    int ans = 0;
    for(int i = input[0] +1; i< 10; i++)
    {
        if(freq[i] > 0){

            int temp = (fact[n - 1] /denominator)* freq[i];
            ans += temp ;
        }
    }
    denominator = denominator / freq[input[0]];
    freq[input[0]]--;
    //change denominator

    ans += numRepetetive(input+1, n-1, fact, freq, denominator);
    return ans;
}


int num(int* input, int n, int* fact, int* freq){
    if(n == 0 || n == 1){
        return 0;
    }
    int ans = 0;
    for(int i = input[0] +1; i< 10; i++)
    {
        if(freq[i] > 0){
            ans += fact[n - 1] ;
        }
    }
    freq[input[0]]--;
    ans += num(input+1, n-1, fact, freq);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int *input = new int[n];

    int *fact = new int[n +1 ];
    int freq[10] = {0};
    fact[0] = 1;
    for(int i = 0; i<n; i++){
        cin>>input[i];
        freq[input[i]]++;
        fact[i + 1] = (i+1) * fact[i];
    }
    int denominator = 1;
    for(int i = 0; i < n; i++)
    {
        if(freq[i] > 0)
        {
          denominator = denominator*fact[freq[i]];
        }
    }
    //cout<< num(input, n, fact, freq) <<endl;
    cout<< numRepetetive(input, n, fact, freq, denominator) <<endl;
    delete [] input;
    delete [] fact;
    delete [] freq;
}
