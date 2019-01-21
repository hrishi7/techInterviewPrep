#include<iostream>
using namespace std;

 template <typename T>
 class Node
 {
	public:
    T data;
    Node<T>* next, *arbit;
    Node(T data)
    {
        this->data=data;
        next=NULL;
        arbit=NULL;
    }
 };

 Node<int>* getMidOfLL(Node<int>* head){
    if(head == NULL){
        return head;
    }
    Node<int>* f = head, *s = head;
    while(f->next != NULL && f->next->next != NULL){
        f = f->next->next;
        s = s->next;
    }
    return s;
 }

 Node<int>* merge(Node<int>* h1, Node<int>* h2){
    if(h1 == NULL)  return h2;
    if(h2 == NULL)  return h1;
    Node<int>* fH = NULL, *fT = NULL;
    if(h1->data < h2->data){
        fH = h1;
        fT = h1;
        h1 = h1->next;
    }else{
        fH = h2;
        fT = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            fT->next = h1;
            fT = h1;
            h1 = h1->next;
        }else{
            fT->next = h2;
            fT = h2;
            h2 = h2->next;
        }
    }
    while(h1 != NULL){
        fT->next = h1;
        h1 = h1->next;
    }
    while(h2 != NULL){
        fT->next = h2;
        h2 = h2->next;
    }
    return fH;
 }

 Node<int>* mergeSort(Node<int>* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node<int>*mid = getMidOfLL(head);
    Node<int>* half1 = head, * half2 = mid->next;
    mid->next = NULL;
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);

    Node<int>* finalHead = merge(half1, half2);
    return finalHead;
 }

int main(){
    Node<int>* head = new Node<int>(20);
    head->next = new Node<int>(5);
    head->next->next = new Node<int>(2);
    head->next->next->next = new Node<int>(8);
    head->next->next->next->next = new Node<int>(81);
    head->next->next->next->next->next = new Node<int>(18);

    head = mergeSort(head);

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    return 0;
}
