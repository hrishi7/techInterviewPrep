#include<iostream>

using namespace std;

template <typename T>

 class Node {
	public:
	T data;
	Node* next;
	Node(T data) {
        next = NULL;
        this->data = data;
	}
	~Node() {
        if (next != NULL) {
            delete next;
        }
	}
 };


void printList(Node<int>* h){
    Node<int>* t = h;
    while(t != NULL){
        cout<<t -> data<<" ";
        t = t->next;
    }
}
Node<int>* reverseList(Node<int>* head){
    Node<int>* p = NULL, *c = head, *n;
    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}


Node<int>* rearrange(Node<int> *h){
    Node<int>*slow = h, *fast = slow->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast ->next->next;
    }
    Node<int>* h1 = h;
    Node<int> * h2 =slow->next;
    slow ->next = NULL;
    h2 = reverseList(h2);
    Node<int> * curr = h;
    while(h1 || h2){
        if(h1){
            if(curr != h){
                curr ->next = h1;
                curr = curr->next;
            }
            h1 = h1->next;
        }
        if(h2){
            curr->next = h2;
            curr = curr->next;
            h2 = h2->next;
        }
    }
    return h;
}


int main(){

    Node<int>* head = new Node<int>(2);
    head->next = new Node<int>(5);
    head->next->next = new Node<int>(8);
    head->next->next->next = new Node<int>(9);
    head->next->next->next->next = new Node<int>(7);
    head->next->next->next->next->next = new Node<int>(50);
    head->next->next->next->next->next->next = new Node<int>(6);
    //printList(head);
    head = rearrange(head);
    printList(head);
}
