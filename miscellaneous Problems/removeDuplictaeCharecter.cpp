#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;


string getWithoutDuplicate(string str){
unordered_set<char> s;
string res;
for(int i = 0; i<str.size(); i++){
    if(s.find(str[i]) == s.end()){
        s.insert(str[i]);
        res += str[i];
    }
    else{

    }
}
return res;

}

int main(){

    string str;
    cin>>str;
    string newstr = getWithoutDuplicate(str);
    cout<<newstr<<endl;

}
