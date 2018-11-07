#include<iostream>

#include "StackUsingArray.cpp"
using namespace std;

int main(){
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push('D');
    /*s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);*/

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

}
