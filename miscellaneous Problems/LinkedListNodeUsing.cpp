#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include "LinkedListNode.h"
using namespace std;

int listLength(Node* head){
    Node* temp = head;
    if(temp == NULL){
        return 0;
    }
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* insertAtList(Node* head,int i, int data){
    Node *nNode = new Node(data);
    int c = 0;
    Node * temp = head;
    Node * prev = NULL;
    if(i == 0){
        nNode->next = head;
        head = nNode;
    }
    else if(i >= listLength(head)){
        return head;
    }else{
        while(c != i){
            prev = temp;
            temp = temp->next;
            c++;
        }
        nNode->next = prev->next;
        prev->next = nNode;
    }
    return head;
}
Node* deleteAtList(Node* head, int i){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL, *t = NULL;
    int c = 0;
    if(i == 0){
        temp = head->next;
        head = head->next;
        delete temp;
    }
    else if( i >= listLength(head)){
        return head;
    }
    else{
        while(c != i){
            prev = temp;
            temp = temp->next;
            c++;
        }
        t = temp;
        prev->next = temp->next;
        delete t;
    }
    return head;
}
void displayList(Node* head){
    Node* temp = head;
    if(temp == NULL)
        cout<<"Empty"<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* createLL(Node* head){
    int data;
    Node *tail = NULL;
    cout<<"Enter data";
    cin>>data;
    cout<<"Enter -1 to exit"<<endl;
    while(data != -1){
        Node *n = new Node(data);

        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = tail->next;
        }
        cout<<"Enter data: ";
        cin>>data;
        cout<<"Enter -1 to exit"<<endl;
    }

    return head;
}
int listLengthRecursively(Node* head){
    if(head->next == NULL){
        return 1;
    }
    return 1 + listLengthRecursively(head->next);
}
Node* insertNodeRecursively(Node* head, int i, int data){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node* nN = new Node(data);
        nN->next = head;
        head = nN;
        return head;
    }
    Node *x = insertNodeRecursively(head->next, i -1, data);
    head ->next = x;
    return head;
}
Node* deleteNodeRecursively(Node* head, int i){
    if(head == NULL){
        return head;
    }
    if(i == 0){
        Node* nN = head;
        head = head->next;
        delete nN;
        return head;
    }
    Node* x = deleteNodeRecursively(head->next, i -1);
    head->next = x;
    return head;
}
Node* getMidNode(Node* head){
    Node * slow =head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast ->next->next;
    }
    return slow;
}
Node* reverseLinkList(Node* head){
    Node* p = NULL, *n = NULL, *c = head;
    while(c != NULL){
        p = c;
        c = c->next;
        p->next = n;
        n = p;
    }
    return p;
}
bool palindromeCheck(Node* head){
    Node* temp1 = head;
    if(head == NULL){
        return true;
    }
    Node * mid = getMidNode(head);
    Node * temp2 = mid->next;
    mid->next = NULL;
    temp2 = reverseLinkList(temp2);
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
Node* deleteAllNode(Node* head){
    if(head == NULL){
        return head;
    }
    deleteAllNode(head->next);
    delete head;
    return NULL;
}
pair<Node*, Node*> reverseListInPair(Node* head){
    Node* p = NULL, *n = NULL, *c = head;
    while(c != NULL){
        p = c;
        c = c->next;
        p->next = n;
        n = p;
    }
    pair<Node*, Node*>pr;
    pr.first = p;
    pr.second = head;
    head = p;
    return pr;
}
Node* kReverseList(Node* head, int n){
    if(head == NULL){
        return head;
    }
    Node* t1 = head,*h2 = NULL,*h1 = head;
    int c = 1;
    while(c != n){
        t1 = t1->next;
        c++;
    }
    if(t1 != NULL){
        h2 = t1->next;
        t1->next = NULL;
    }
    pair<Node* , Node*> p = reverseListInPair(h1);
    h1 = p.first;
    t1 = p.second;
    h2 = kReverseList(h2,n);
    t1->next = h2;
    return h1;
}
Node* evenAfterOddList(Node* head){
    Node* eH = NULL, *eT = NULL,*oH = NULL, *oT = NULL, *temp = head;
    while(temp != NULL){
        if(temp->data % 2 == 0){
            if(eH == NULL){
                eH = temp;
                eT = temp;
            }
            else{
                eT->next = temp;
                eT = eT->next;
            }
        }
        else{
            if(oH == NULL){
                oH = temp;
                oT = temp;
            }
            else{
                oT->next = temp;
                oT = oT->next;
            }
        }

        temp = temp->next;
    }
    if(eT != NULL && oT != NULL){
        eT->next = NULL;
        oT->next = eH;
        head = oH;
    }else{
        if(oT == NULL){
            eT->next = NULL;
            head = eH;
        }else{
            oT->next = NULL;
            head = oH;
        }
    }
    return head;
}

void AlternateDivideList(Node* head){
    if(head == NULL){
        cout<<"Empty"<<endl;
        return;
    }
    Node* l1H= NULL, *l1T = NULL, *l2H = NULL, * l2T = NULL, *temp = head;
    int c = 1;
    while(temp != NULL){
        if(c % 2 == 0){
            if(l1H == NULL){
                l1H = temp;
                l1T = temp;
            }else{
                l1T->next = temp;
                l1T = l1T->next;
            }
        }else{
            if(l2H == NULL){
                l2H = temp;
                l2T = temp;
            }else{
                l2T->next = temp;
                l2T = l2T->next;
            }
        }
        c++;
        temp= temp->next;
    }
    if(l2T != NULL && l1T != NULL){
            l1T->next = l2T->next = NULL;

    }else{
            if(l2T == NULL){
                l1T->next = NULL;
            }else{
                l2T->next = NULL;
            }
    }
    l1H = reverseLinkList(l1H);
    l2H = reverseLinkList(l2H);
    displayList(l1H);
    cout<<endl;
    displayList(l2H);
}

Node* lastBeTheFirst(Node* head){
    Node* temp =head,*prev = NULL;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    temp->next = head;
    head = temp;
    prev ->next = NULL;
    return head;
}

Node*  deleteLL(Node* head){
  while(head!= NULL){
   Node* t = head;
    delete t;
    head = head->next;
  }
  return head;
}


Node* skipMdelete(Node* head, int M, int N){
    if(M ==0 && N == 0){
      return deleteLL(head);
    }
  	if(N == 0 || M == 0){
      if(N == 0)
        return head;
      else{
        return deleteLL(head);
      }
    }
    int c = 1;
    Node* temp = head,*prevTemp = NULL;
    while(temp != NULL){
        while(c != M && temp != NULL){

            temp = temp->next;
            c++;
        }
        prevTemp = temp;
        c = 1;
        while(c != N && temp != NULL){
            Node* anotherTemp = temp;
            temp = temp->next;
            delete anotherTemp;
            c++;
        }
        if(temp != NULL){
            Node* anotherTemp = temp;
            temp = temp->next;
            delete anotherTemp;
        }
        prevTemp->next = temp;
    }
    return head;
}

int main(){
    int ch,i,data,k,M,N;
    Node* head = NULL;
    while(1){

        cout<<"1.Create Linked List"<<endl;
        cout<<"2.Display Linked List"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"4.Get List Length"<<endl;
        cout<<"5.Insert at ith position"<<endl;
        cout<<"6.Delete at ith position"<<endl;
        cout<<"7.length of list Recursion"<<endl;
        cout<<"8.Insert Node Recursively"<<endl;
        cout<<"9.Delete Node Recursively"<<endl;
        cout<<"10.Palindrome Check of list"<<endl;
        cout<<"11.Reverse List"<<endl;
        cout<<"12.Get middle element of list"<<endl;
        cout<<"13.Delete All Node"<<endl;
        cout<<"14.K Reverse the list"<<endl;
        cout<<"15.Even after Odd list"<<endl;
        cout<<"16.Divide list based on alternate element"<<endl;
        cout<<"17.Make last element The first Element"<<endl;
        cout<<"18.Delete Every N element after Every M element"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;
        system("cls()");
        switch(ch){
        case 1:
            head = createLL(head);
            break;
        case 2:
            displayList(head);
            break;
        case 3:
            exit(0);
        case 4:
            cout<<listLength(head)<<endl;
            break;
        case 5:
            cout<<"Enter position and data: ";
            cin>>i>>data;
            head = insertAtList(head, i, data);
            break;
        case 6:
            cout<<"Enter position : ";
            cin>>i;
            head = deleteAtList(head, i);
            break;
        case 7:
            cout<<listLengthRecursively(head)<<endl;
            break;
        case 8:
            cout<<"Enter data and position:";
            cin>>data>>i;
            head = insertNodeRecursively(head, i, data);
            break;
        case 9:
            cout<<"Enter position: ";
            cin>>i;
            head = deleteNodeRecursively(head, i);
            break;
        case 10:
            cout<<palindromeCheck(head)<<endl;
            break;
        case 11:
            head = reverseLinkList(head);
            break;
        case 12:
            //cout<<getMidNode(head)<<endl;
            break;
        case 13:
            head = deleteAllNode(head);
            break;
        case 14:
            cout<<"Enter the value of k: ";
            cin>>k;
            head = kReverseList(head, k);
            break;
        case 15:
            head = evenAfterOddList(head);
            break;
        case 16:
            AlternateDivideList(head);
            break;
        case 17:
            head = lastBeTheFirst(head);
            break;
        case 18:
            cout<<"Enter M and N: ";
            cin>>M>>N;
            head = skipMdelete(head, M, N);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }

    }
    return 0;
}
