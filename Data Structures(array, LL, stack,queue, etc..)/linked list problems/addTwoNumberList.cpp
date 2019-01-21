#include <iostream>

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

void printList(Node<int>* head){
    Node<int>* t = head;
    while(t != NULL){
        cout<<t->data<<" ";
        t = t->next;
    }
}

Node<int>* reverseList(Node<int>* head){
    Node<int>* p = NULL, *n = NULL,*c = head;
    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}
/*
Node<int>* MakeList(Node<int>* head, int n){
    cout<<"How many Numbers ?"<<endl;
    cin>>n;
    for(int i = 1; i<= n; i++){
        cin>>num;
        if(head == NULL){
        head = new Node<int>(num);
        return head;
    }
    Node<int>* h, *t = head
    while()

    }

    return head;
}
*/

Node<int>* addTwoList(Node<int>* first, Node<int>* second){
    Node<int>*res=NULL, *temp, *prev = NULL;
    int carry = 0,sum;
    while(first != NULL || second != NULL){
        sum = carry + (first? first->data: 0) + (second?second->data:0);
        carry = (sum >= 10) ? 1: 0;
        sum = sum % 10;
        temp = new Node<int>(sum);
        if(res == NULL){
            res = temp;
        }
        else{
            prev->next = temp;
        }
        prev = temp;
        if(first) first = first ->next;
        if(second) second = second ->next;
    }
    if(carry >0){
        temp->next = new Node<int>(carry);
    }
    //printList(res);
    return res;
}

int main()
{
    //1st integer in list form
    Node<int> *head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);
    head = reverseList(head);

    //2nd integer in list form
    Node<int> *head2 = new Node<int>(1);
    head2->next = new Node<int>(2);
    head2->next->next = new Node<int>(3);
    head2->next->next->next = new Node<int>(4);
    head2->next->next->next->next = new Node<int>(5);
    head2 = reverseList(head2);

    //resultant list
    Node<int>* result = addTwoList(head, head2);
    result = reverseList(result);

    printList(result);

}
