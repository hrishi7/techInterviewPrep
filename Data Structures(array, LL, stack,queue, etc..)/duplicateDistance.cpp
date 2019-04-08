#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;


int maxDistance(vector<int> input){

  // Write your code here
    unordered_map<int,int>m;
    for(int i = 0; i< input.size(); i++){
        m[input[i]] = i;
    }
    int h = 0;
    for(int i = 0; i< input.size(); i++){
        int x = m[input[i]];
        h = max(h,x - i);
    }
    return h;
}
int main(){
    vector<int> v;
    for(int i = 0; i<10; i++){
        v.push_back(i);
    }
    cout<< maxDistance(v)<<endl;
}



