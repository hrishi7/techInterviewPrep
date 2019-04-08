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


Node<int>* reverseList(Node<int>* head){
    Node<int>* c = head,*p= NULL,*n = NULL;
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
}
void AlternatingSplit(Node<int>* head) {
	// Write your code here
    Node<int>* h1H = NULL,*h1T ,*h2H = NULL,*h2T,*temp = head;
    bool counter = true;
    while(temp != NULL){
        if(counter){
            //add to first list
            if(h1H == NULL){
                h1H = temp;
                h1T = temp;
            }else{
                h1T->next = temp;
                h1T = h1T ->next;
            }
            counter = false;
        }
        else{
            //add to second list
             if(h2H == NULL){
                h2H = temp;
                h2T = temp;
            }else{
                h2T->next = temp;
                h2T = h2T ->next;
            }
            counter = true;
        }
        temp = temp->next;
    }
    h1T->next = NULL;
    h2T->next = NULL;
    h1H = reverseList(h1H);
    h2H = reverseList(h2H);
    printList(h1H);
    cout<<endl;
    printList(h2H);
}

int main(){
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);
    head->next->next->next->next->next = new Node<int>(6);
    head->next->next->next->next->next->next = new Node<int>(7);
    head->next->next->next->next->next->next->next = new Node<int>(8);

    AlternatingSplit(head);

}
