#include <iostream>
#include <cstdio>
using namespace std;

class Node
{
	int data;
	Node* next;
public:
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
	~Node()
	{
		if (next)
		{
			delete next;
		}
	}
};

void reverse(Node** head)
{
	if (!(*head))
	{
		return;
	}

	Node* first=*head;
	Node* second=first->next;

	if (second==NULL)
	{
		return;
	}

	reverse(&second);

	first->next->next=first;
	first->next=NULL;
	*head=second;

}
//Assuming ll1>=ll2
Node* subtractLinkedLists(Node* ll1,Node* ll2)
{
	reverse(ll1);
	reverse(ll2);
	int diff,borrow=0;
	Node* subtract=NULL;
	Node* tail=NULL;

	while(ll1)
	{
		diff = ll1->data - borrow-( ll2 ? ll2->data : 0);
		if (diff>=0)
		{
			borrow=0;
		}
		else
		{
			diff=10+diff;
			borrow=1;
		}

		if (!subtract)
		{
			subtract=new Node(diff);
			subtract->next=NULL;
			tail=subtract;
		}	
		else
		{
			tail->next=new Node(diff);
			tail->next->next=NULL;
			tail=tail->next;
		}	

		ll1=ll1->next;
		ll2=ll2?ll2->next:NULL;
	}	

	reverse(subtract);
	return subtract;
}

Node* takeInput()
{
	Node* head=NULL;
	Node* tail=NULL;
	int data;
	cin>>data;
	
	while(data!=-1)
	{	
		Node* new_node=new Node;
		new_node->data=data;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}	

		cin>>data;
	}

	return head;	

}

void printLL(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}	

	cout<<"-1"<<endl;
}

int main()
{

	return 0;
}