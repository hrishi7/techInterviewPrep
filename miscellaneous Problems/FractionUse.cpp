#include<iostream>
#include "Fraction.cpp"
using namespace std;
int main()
{
   Fraction f1(10,2);
   Fraction f2(15,4);

   f1 += f2;
   f1.print();
   f2.print();

   cout<<endl;
   (f1+=f2) +=f2;
   f1.print();
   f2.print();

   /*Fraction f3 = f1 + f2;
   f3.print();
   Fraction f4 = f1 * f2;
   f4.print();
   Fraction f5 = ++(++f4);
   f5.print();
   f4.print();*/
   /*if(f3 == f4)
    cout<<"Equal"<<endl;
   else
    cout<<"Not Equal"<<endl;
    */

}
