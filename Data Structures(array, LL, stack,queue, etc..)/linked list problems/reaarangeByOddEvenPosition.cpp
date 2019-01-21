#include<iostream>
using namespace std;
template<typename T>
class Node{
public:
    int data;
    Node* next;
    Node(T data){
        next = NULL;
        this->data = data;
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }

};

void printList(Node<int>* head){
    Node<int>* t = head;
    while(t != NULL){
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

Node<int>* rearrangeEvenOdd(Node<int>* head){
    if(head == NULL)
        return head;
    Node<int>* temp = head;
    Node<int>* evenH = NULL,*evenT = NULL, *oddH = NULL, *oddT = NULL;
    int i = 1;
    while(temp != NULL){
        if(i %2 == 0){
            if(evenH == NULL){
                evenH = temp;
                evenT = temp;
            }else{
                evenT->next = temp;
                evenT = evenT->next;
            }

        }else{
             if(oddH == NULL){
                oddH = temp;
                oddT = temp;
            }else{
                oddT->next = temp;
                oddT = oddT->next;
            }

        }
        temp = temp->next;
        i++;
    }
    oddT->next = evenH;
    head = oddH;
    return head;
}


int main(){

    Node<int>*head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);
    head->next->next->next->next->next = new Node<int>(6);
    head->next->next->next->next->next->next = new Node<int>(7);
    head->next->next->next->next->next->next->next = new Node<int>(8);

    printList(head);

    head = rearrangeEvenOdd(head);

    printList(head);
    return 0;
}
