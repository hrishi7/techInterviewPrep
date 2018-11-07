#include<iostream>
#include "QueueUsingLL.cpp"

using namespace std;

int main(){
    Queue<int> q;
    q.enQueue(100);
    q.enQueue(200);
    q.enQueue(300);
    q.enQueue(400);
    q.enQueue(500);

    cout<<q.getSize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.front()<<endl;

}
