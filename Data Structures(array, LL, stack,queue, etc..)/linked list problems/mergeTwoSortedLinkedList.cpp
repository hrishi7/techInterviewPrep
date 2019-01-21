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


void printList(Node<int>*head){
    Node<int>* t = head;
    while(t != NULL){
        cout<<t -> data<<" ";
        t = t->next;
    }
}


Node<int>* reverseList(Node<int>* h){
    Node<int>* p = NULL, *c = h, *n;
    while(c != NULL){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    h = p;
    return h;
}

 Node<int>* mergeTwoSortedList(Node<int>* h1, Node<int>* h2){
        Node<int>* tH = NULL, *tT = NULL;
        while(h1 != NULL && h2 != NULL){
            if(h1->data < h2->data){//list 1 element is < list 2
                if(tH == NULL){ //if new list is empty
                    tH = h1;
                    tT = h1;
                }
                else{
                    tT->next = h1;
                    tT = tT->next;
                }
                h1 = h1->next;
            }
            else{
                if(tH == NULL){
                    tT = h2;
                    tT = h2;
                }else{
                    tT->next = h2;
                    tT = tT->next;
                }
                h2 = h2->next;
            }
        }
        if(h1 == NULL){
            tT->next = h2;
        }
        else{
            tT->next = h1;
        }
        return reverseList(tH);
    }

/*
o(1) space solution with single traversal for both list. This is best approach
comparing data of both list along with making reverse order linked list which is needed
*/
Node<int>* merge_reverse(Node<int>* head1,Node<int>* head2)
{
	Node<int>* a=head1,* b=head2,*temp=NULL,*newhead=NULL,*pre=NULL,*x=NULL;
	while(a!=NULL && b!=NULL)
	{
		if(a->data<b->data)
		{
			temp=a->next;
			if(newhead==NULL || a->data>=newhead->data)
			{
				a->next=newhead;
				newhead=a;
				a=temp;
			}
			else
			{
				x=newhead;
				while(newhead!=NULL && newhead->data>a->data)
				{
					pre=newhead; newhead=newhead->next;
				}
				pre->next=a;
				a->next=newhead;
				a=temp;
				newhead=x;
			}
		}
		else
		{
			temp=b->next;
			if(newhead==NULL || b->data>=newhead->data)
			{
				b->next=newhead;
				newhead=b;
				b=temp;
			}
			else
			{
				x=newhead;
				while(newhead!=NULL && newhead->data>b->data)
				{
					pre=newhead; newhead=newhead->next;
				}
				pre->next=b;
				b->next=newhead;
				b=temp;
				newhead=x;
			}
		}
	}

	while(a!=NULL)
	{
			temp=a->next;
			if(newhead==NULL || a->data>=newhead->data)
			{
				a->next=newhead;
				newhead=a;
				a=temp;
			}
			else
			{
				x=newhead;
				while(newhead!=NULL && newhead->data>a->data)
				{
					pre=newhead; newhead=newhead->next;
				}
				pre->next=a;
				a->next=newhead;
				a=temp;
				newhead=x;
			}
	}
	while(b!=NULL)
	{
			temp=b->next;
			if(newhead==NULL || b->data>=newhead->data)
			{
				b->next=newhead;
				newhead=b;
				b=temp;
			}
			else
			{
				x=newhead;
				while(newhead!=NULL && newhead->data>b->data)
				{
					pre=newhead; newhead=newhead->next;
				}
				pre->next=b;
				b->next=newhead;
				b=temp;
				newhead=x;
			}
	}
	return newhead;
}



//end


int main(){
    Node<int>* head = new Node<int>(2);
    head->next = new Node<int>(5);
    head->next->next = new Node<int>(8);
    head->next->next->next = new Node<int>(12);
    printList(head);
    cout<<endl;

    Node<int>* head2 = new Node<int>(3);
    head2->next = new Node<int>(6);
    head2->next->next = new Node<int>(9);

    printList(head2);
    cout<<endl;

    //Node<int>*r = mergeTwoSortedList(head, head2);
    Node<int>*r = merge_reverse(head, head2);
    printList(r);



    return 0;
}
