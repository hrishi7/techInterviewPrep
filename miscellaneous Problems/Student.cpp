#include<iostream>
#include<string.h>

using namespace std;
/*
class Student
{
    int age;


public:
    char *name;
    Student(int age, char* name)
    {
        this->age = age;
        //shallow copy
        //this->name = name;

        //deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    Student(Student const &s)
    {
        this->age = s.age;
        //shallow copy
        //this->name = s.name;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }
    void display()
    {
        cout<<age<<" "<<name<<endl;
    }
};*/

class Student{
public:
    int age;
    const int rollno;
    int &x;

    Student(int r, int age): rollno(r), age(age), x(this->age){
    //do the needed operations
    }
};
