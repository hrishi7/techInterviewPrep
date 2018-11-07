#include<iostream>
using namespace std;
#include "DynamicArray.cpp"

int main()
{
    DynamicArray d1;
    d1.addElement(100);
    d1.addElement(200);
    d1.addElement(300);
    d1.addElement(400);
    d1.addElement(500);
    d1.addElement(600);
    d1.addElement(700);


    d1.print();

    DynamicArray d2(d1);

    d2.print();

    DynamicArray *d3 = new DynamicArray();
    *d3 = d1;
    d3->print();

    cout<<"After D1 Changes"<<endl;
    d1.addAt(2,50);
    d1.print();
    d2.print();
    d3->print();

}
