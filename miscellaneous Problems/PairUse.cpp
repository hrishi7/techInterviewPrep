#include<iostream>
#include "Pair.cpp"
using namespace std;

int main(){
    Pair<char, int> p;
    Pair<Pair<char, int>, int> pNew;
    p.setX('A');
    p.setY(100);
    pNew.setX(p);

    pNew.setY(250);

    cout<<pNew.getX().getX()<< " "<<pNew.getX().getY()<<" "<<p.getY()<<endl;
}
