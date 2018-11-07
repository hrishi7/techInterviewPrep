#include<iostream>
#include<cstring>
using namespace std;

string flip(string s, int i, int j){
    for(int k = i; k<= j; k++){
        if(s[k] == 'R')
            s[k] = 'K';
        else
            s[k] = 'R';
    }
    return s;
}

int countR(string s){
    int c = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == 'R')
            c++;
    }
    return c;
}

int getRCount(string s, int n){
    int ans = 0;
    for(int i = 0; i<= n - 1; i++){
        for(int j = 0; j<= n - 1; j++){
            string newS = s;
            //strcpy(&newS,&s);
            newS = flip(newS,i,j);
            int c = countR(newS);
            ans = max(ans, c);
        }
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int n = s.size();
        cout<<getRCount(s, n)<<endl;
    }


}
