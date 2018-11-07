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
class Stack{
    Node<T> * head;
    int size;

public:
    Stack(){
        head = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push(T element){
        Node<T>* n = new Node<T>(element);
        if(head == NULL){
            head = n;
        }
        else{
            n->next = head;
            head = n;
        }
        size++;
    }
    T pop(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        else{
            T temp = head->data;
            Node<T>* n = head;
            head = head->next;
            delete n;
            size--;
            return temp;
        }
    }
     T top(){
        if(head == NULL){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        else{
            return head->data;
        }
    }
};
