#include<iostream>
using namespace std;
 template <typename T>
 class Node {
    public:
        T data;
        Node* next;
        Node* prev;

        Node(T data) {
            next = NULL; prev=NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
 };



void pairSum(Node<int>* head, int x) {
	// Write your code here
    Node<int>* first = head,*second= head;
    while(second->next != NULL){
        second = second->next;
    }

   while (first != NULL && second != NULL &&
           first != second && second->next != first)
    {
         // pair found
         if ((first->data + second->data) == x)
         {
              cout << first->data<< " "
                   << second->data  << endl;

              // move first in forward direction
              first = first->next;

              // move second in backward direction
              second = second->prev;
          }
          else
          {
              if ((first->data + second->data) < x)
                 first = first->next;
              else
                 second = second->prev;
          }
      }
}
