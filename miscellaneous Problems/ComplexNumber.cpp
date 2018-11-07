#include<iostream>
using namespace std;
class ComplexNumber{
private:
    int real;
    int img;

public:
    ComplexNumber(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    void print()
    {
        cout<<real <<" + i"<<img<<endl;
    }

    void add(ComplexNumber const &f2)
    {
        this->real = this->real + f2.real;
        this->img = this->img + f2.img;
    }
    void multiply(ComplexNumber const &f2)
    {
        int p1 = this->real * f2.real;
        int p2 = this->img * f2.img;
        int p3 = this->real * f2.img;
        int p4 = this->img * f2.real;
        this-> real = p1 - p2;
        this->img = p3 + p4;
    }
};




