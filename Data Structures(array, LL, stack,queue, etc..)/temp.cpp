#include<iostream>
using namespace std;

 template <typename T>
 class Node
 {
	public:
    T data;
    Node<T>* next, *arbit;
    Node(T data)
    {
        this->data=data;
        next=NULL;
        arbit=NULL;
    }
 };
/* function prototypes */
Node<int>* SortedMerge(Node<int>* a, Node<int>* b);
void FrontBackSplit(Node<int>* source, Node<int>** frontRef, Node<int>** backRef);

/* sorts the linked list formed by arbit pointers
(does not change next pointer or data) */
void MergeSort(Node<int>** headRef)
{
	Node<int>* head = *headRef;
	Node<int>* a, *b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->arbit == NULL))
		return;

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b);

	/* Recursively sort the sublists */
	MergeSort(&a);
	MergeSort(&b);

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b);
}

/* See https://www.geeksforgeeks.org/?p=3622 for details of this
function */
Node<int>* SortedMerge(Node<int>* a, Node<int>* b)
{
	Node<int>* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b==NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->arbit = SortedMerge(a->arbit, b);
	}
	else
	{
		result = b;
		result->arbit = SortedMerge(a, b->arbit);
	}

	return (result);
}

/* Split the nodes of the given list into front and back halves,
and return the two lists using the reference parameters.
If the length is odd, the extra node should go in the front list.
Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node<int>* source, Node<int>** frontRef, Node<int>** backRef)
{
	Node<int>* fast, *slow;

	if (source==NULL || source->arbit==NULL)
	{
		/* length < 2 cases */
		*frontRef = source;
		*backRef = NULL;
		return;
	}

	slow = source, fast = source->arbit;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL)
	{
		fast = fast->arbit;
		if (fast != NULL)
		{
			slow = slow->arbit;
			fast = fast->arbit;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->arbit;
	slow->arbit = NULL;
}

/* Function to insert a node at the beginging of the linked list */
void push(Node<int>** head_ref, int new_data)
{
	/* allocate node */
	Node<int>* new_node =
		(Node<int>*) malloc(sizeof(Node<int>));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	new_node->arbit = NULL;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// This function populates arbit pointer in every node to the
// next higher value. And returns pointer to the node with
// minimum value
Node<int>* arbit(Node<int> *head)
{
	// Copy next pointers to arbit pointers
	Node<int> *temp = head;
	while (temp != NULL)
	{
		temp->arbit = temp->next;
		temp = temp->next;
	}

	// Do merge sort for arbitrary pointers
	MergeSort(&head);

	// Return head of arbitrary pointer linked list
	return head;
}
int main(){
    Node<int>* head = new Node<int>(12);
    head->next = new Node<int>(5);
    head->next->next = new Node<int>(2);
    head->next->next->next = new Node<int>(8);

    head = arbit(head);

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->arbit;
    }
    return 0;
}
