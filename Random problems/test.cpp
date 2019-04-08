#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    string s;
    unordered_map<char, int>m;
    cin>>s;
    for(int i = 0; i<s.length(); i++){
        m[s[i]]++;
    }
    for(auto i: m){
        if(i.second == 1){
            cout<<i.first<<endl;
        }
    }
}
