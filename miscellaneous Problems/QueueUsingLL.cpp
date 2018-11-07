#include<iostream>
using namespace std;
template<typename T>

class Node{
public:
    T data;
    Node<T>* next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enQueue(T element){
        Node<T>* nN = new Node<T>(element);
        if(head == NULL){
            head = nN;
            tail = nN;
        }
        else{
            tail->next = nN;
            tail = nN;
        }
        size++;
    }
    T front(){
        if(head == NULL){
            return 0;
        }
        return head->data;
    }
    T deQueue(){
        if(head == NULL){
            return 0;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};
