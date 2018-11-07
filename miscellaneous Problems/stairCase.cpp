#include<iostream>
using namespace std;

int getSteps(int num){
    if(num < 0)
        return 0;
    if(num ==0)
        return 1;
    return getSteps(num - 1) +getSteps(num - 2) + getSteps(num - 3);

}
int main(){
int n;
cin>>n;
cout<< getSteps(n);


return 0;
}
