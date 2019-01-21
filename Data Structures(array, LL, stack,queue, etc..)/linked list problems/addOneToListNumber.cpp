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

void printList(Node<int>* head){
    Node<int>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
/*
Node<int>* addOne(Node<int>* head){
    Node<int>* temp = head;
    if(head == NULL)
        return head;
    if(temp->data == 9){
        int i = 1;
        temp = temp->next;
        while(temp->data == 9){
            i++;
            temp = temp->next
        }
    }
    head = reverseList(head);
    while(head){
        if(head->data+1 <=9){
            head->data += 1;
            break;
        }
        //int no = head->data + 1;
        head->data = 0;
        head = head ->next;
    }
    head = reverseList(head);
    return head;
}*/

Node<int>* addOneTOList(Node<int> *head)
{
    if(head == nullptr)
        return head;

    Node<int> *cur, *prev;
    prev = nullptr;
    cur = head;

    while(cur->next != nullptr)
    {
        if(cur->data != 9)
            prev = cur;
        cur = cur->next;
    }

    if(cur->data != 9)
    {
        cur->data += 1;
    } else if(prev == nullptr) //If all the node have 9
    {
        Node<int> *temp = new Node<int>(1);
        temp->next = head;
        while(head)
        {
            head->data = 0;
            head = head->next;
        }
        return temp;
    } else {
        prev->data += 1;
        prev = prev->next;
        while(prev)
        {
            prev->data = 0;
            prev = prev->next;
        }
    }
    return  head;
}

int main(){
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head = addOneTOList(head);
    printList(head);
    return 0;
}
