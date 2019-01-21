#include<iostream>

using namespace std;
template<typename T>

class Node{
public:
    T data;
    Node* next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }

};

void printList(Node<int>* head){
    Node<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node<int>* deleteMid(Node<int>* head){
    if(head == NULL)
        return head;
    Node<int>* slow = head, *fast = slow->next, *p = NULL;
    while(fast && fast->next){
        p = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    Node<int>* temp = slow;
    p->next = slow->next;
    return head;
}

int main(){
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);
    head->next->next->next->next->next = new Node<int>(6);
    //head->next->next->next->next->next->next = new Node<int>(7);
    head = deleteMid(head);
    printList(head);
    return 0;
}
