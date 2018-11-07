#include<iostream>
#include "PriorityQueue.h"
using namespace std;

int main(){
    //Time Complexity nlogn && space Complexity is n
    PriorityQueue p;
    p.insertItem(100);
    p.insertItem(20);
    p.insertItem(350);
    p.insertItem(4);
    p.insertItem(15);
    p.insertItem(5);
    p.printPQ();

    while(!p.isEmpty()){
        cout<<p.removeItem()<<" ";
    }
    return 0;
}
