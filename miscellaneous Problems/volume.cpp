#include<iostream>
using namespace std;
#define pi 3.14
class Volume{
private:
    double l, h, r,volume;

public:
    void calvol(double radius, double height){
        r = radius;
        h = height;
        volume = (pi * r * r * h)/3;
        cout<<"Volume of Cone is: "<<volume<<endl;
    }
    void calvol(double radius){
        r = radius;
        volume = (4/3)*(pi * r * r * r);
        cout<<"Volume of Sphere is: "<<volume<<endl;
    }
    void calvol(double radius, double height){
        r = radius;
        h = height;
        volume = (pi * r * r * h);
        cout<<"Volume of Cylinder is: "<<volume<<endl;
    }
    void calvol(double side){
        l = side;
        volume = (l * l * l);
        cout<<"Volume of Cube is: "<<volume<<endl;
    }


};

int main(){
    double l, h, r,coneVolume, cylinderVolume, cubeVolume, sphereVolume;
    cout<<"Enter length for cube: ";
    cin>>l;
    Volume vCone;
    vCone.calvol(l);
    cout<<endl;
    cout<<"Enter radius and height for cylinder: ";
    cin>>r>>h;
    Volume vCylinder;
    vCylinder.calvol(r,h);
    cout<<endl;
    cout<<"Enter radius for Sphere: ";
    cin>>r;
    Volume vSphere;
    vSphere.calvol(r);
    cout<<endl;
    cout<<"Enter radius and height for Cone: ";
    cin>>r>>h;
    Volume vCone;
    vCone.calvol(r,h);
    cout<<endl;


}
