#include<iostream>
#include<cstring>
#include<queue>
using namespace std;


/*
A deque is a data structure consisting of a list of items, on which the following
operations are possible:
a. push(x,d): Insert item x on the front end of deque d.
b. pop(d): Remove the front item from deque d and return it.
c. inject(x,d): Insert item x on the rear end of deque d.
d. eject(d): Remove the rear item from deque d and return it. Write routines to
support the deque that take constant time per operation

*/

struct node
{
	int data;
	node* next;
	node* prev;
};

class Dequeue
{
	 node* head;
	 node* tail;
	 int count;
public:
	Dequeue()
	{
		head=NULL;
		tail=NULL;
		count=0;
	}
	bool isEmpty();
	void push(int data);//front end
	int pop();//front end
	void inject(int data);//rear end
	int eject();//rear end
};


bool Dequeue::isEmpty()
{
	if(count==0)
		return true;
	return false;
}
void Dequeue::push(int data)
{
	node* new_node=new node;
	new_node->data=data;
	new_node->prev=NULL;
	if(isEmpty())
	{
		new_node->next=NULL;
		head=new_node;
		tail=new_node;
	}
	else
	{
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
	}	

	count++;
}

void Dequeue::inject(int data)
{
    node* new_node=new node;
	new_node->data=data;
	new_node->next=NULL;
	if(isEmpty())
	{ 
		new_node->prev=NULL;
		head=new_node;
		tail=new_node;
	}
	else
	{
		tail->next=new_node;
		new_node->prev=tail;
		tail=new_node; 
	}	
	count++;
}

int Dequeue::pop()
{
	if(!isEmpty())
	{
		int data=head->data;
		
		node* temp=head;
		if(head->next!=NULL)
		{
			head=head->next;
			head->prev=NULL;
		} 
		else
		{
		    head=NULL;
		}	
		delete temp;
		count--;
		return data;
	}	
	else
	{
		cout<<"Dequeue empty\n";
		return -1;
	}	
}

int Dequeue::eject()
{
	if(!isEmpty())
	{
		int data=tail->data;
		node* temp=tail;
		if(tail->prev!=NULL)
		{
			tail=tail->prev;
			tail->next=NULL;
		}
		else
		{
			tail=NULL;
		}	
		delete temp;
		count--;
		return data;
	}
	else
	{
		cout<<"Dequeue empty"<<endl;
		return -1;
	}	
}

int main()
{
	Dequeue d;
	d.push(1);
	d.push(2);
	cout<<d.pop()<<endl;
	d.inject(3);
	cout<<d.pop()<<endl;
	cout<<d.pop()<<endl;
	cout<<d.pop()<<endl;
	// cout<<d.eject()<<endl;
	// cout<<d.eject()<<endl;
	// cout<<d.eject()<<endl;

	return 0;
}