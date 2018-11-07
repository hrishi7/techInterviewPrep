#include<iostream>
#include "ComplexNumber.cpp"
using namespace std;
int main()
{
   ComplexNumber f1(4,5);
   ComplexNumber f2(6,7);

  /* f1.add(f2);

   f1.print();
   f2.print();*/

   f1.multiply(f2);

   f1.print();



}

