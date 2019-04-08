#include<iostream>
using namespace std;
bool Found;

int FoundSubstringAB(string s, int l){
    for(int i = l; i<s.length(); i++){
        if(s[i] == 'A' && s[i + 1] == 'B'){
            return i + 2;
        }
    }
    return -1;
}
int FoundSubstringBA(string s, int l){
    for(int i = l; i<s.length(); i++){
        if(s[i] == 'B' && s[i + 1] == 'A'){
            return i + 2;
        }
    }
    return -1;
}
void FoundSubstring(string s){
    int pos1 = FoundSubstringAB(s,0);
    if(pos1 != -1){
        if(FoundSubstringBA(s,pos1) != -1)
            Found = 1;
    }

    int pos2 = FoundSubstringBA(s,0);
    if(pos2 != -1){
        if(FoundSubstringAB(s,pos2) != -1)
        Found = 1;
    }
}
int main(){
    string s;
    cin>>s;
    FoundSubstring(s);
    if(Found)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
