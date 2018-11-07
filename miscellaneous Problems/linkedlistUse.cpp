#include<iostream>
#include "Node.cpp"

using namespace std;

class Pair{
public:
    Node* head;
    Node* tail;
};

pair reverseLL(Node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverseLL(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node* insertNode(Node* head, int i, int data){
    Node* newNode = new Node(data);
    int count = 0;
    Node* temp = head;
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(count < i- 1 && temp != NULL){
        temp = temp ->next;
        count++;
    }
    if(temp != NULL){
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
Node* deleteNode(Node* head, int i){
    int count = 0;
    Node* temp = head;
    if(i == 0){
        head = head->next;
        delete temp;
        return head;
    }
    while(count < i- 1 && temp != NULL){
        temp = temp ->next;
        count++;
    }
    if(temp != NULL){
        if(temp->next != NULL){
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
        }
    }
    return head;
}


void print(Node* head){
    Node* temp = head ;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


Node* takeInput(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int main()
{
   // Node n1(1);
    //Node* head = NULL;;
/*
    Node n2(2);



    Node* n3 = new Node(3);
     Node* n4 = new Node(4);
      Node* n5 = new Node(5);
       Node* n6 = new Node(6);
        Node* n7 = new Node(7);
         Node* n8 = new Node(8);
          n1.next = &n2;
        n2.next = n3;
         n3->next = n4;
         n4->next = n5;
         n5->next = n6;
         n6->next = n7;
         n7->next = n8;
    print(head);*/
    Node* head = takeInput();
    int i,data;
    cin>>i;
    //head = insertNode(head, i, data);
    head = deleteNode(head, i);
    print(head);
}
