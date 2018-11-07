#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
     int withdraw;
    double amount, charge = 0.50;
    cin>>withdraw>>amount;
    double withdrawWithCharge = withdraw + charge, final;

    if (withdraw % 5 == 0.0 && withdrawWithCharge <= amount) {
        final = amount - withdrawWithCharge;
    } else {
        final = amount;
    }
    cout<<final;
    return 0;
}
