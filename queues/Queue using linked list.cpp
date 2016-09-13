#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	
};

class Queue
{
	node* head,*tail;
public:
	Queue()
	{
		head=NULL;
		tail=NULL;
	}
	void enqueue(int data);
	void dequeue();
	bool isEmpty();
	int front();


};

bool Queue::isEmpty()
{
	if(head==NULL)
		return true;
	return false;
}

void Queue::enqueue(int data)
{
	node* new_node=new node;
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
}

void Queue::dequeue()
{
	if(!isEmpty())
	{
		head=head->next;
	}	
	else
	{
		cout<<"Queue is empty"<<endl;
	}	
}

int Queue::front()
{
	if(!isEmpty())
	{
		int data=head->data;
		head=head->next;
		return data;
	}	
	else
	{
		cout<<"Stack empty"<<endl;
		return -1;
	}	
}


int main()
{
	return 0;
}