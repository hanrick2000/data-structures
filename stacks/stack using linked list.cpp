#include<iostream>
using namespace std;

struct node
{
	node* next;
	int data;
};

class Stack
{
	node* head;
public:
	Stack()
	{
		head=NULL;
	}
	void push(int data);
	int top();
	void pop();
	bool isEmpty();
};


bool Stack::isEmpty()
{
	if(head==NULL)
		return true;
	return false;
}

void Stack::push(int data)
{
	node* new_node=new node;
    new_node->data=data;
    if(head==NULL)
    {
    	new_node->next=NULL;
    	head=new_node;
    }	
    else
    {
    	new_node->next=head;
    	head=new_node;
    }	
}

int Stack::top()
{
	if(!isEmpty())
		return head->data;
	return -1;
}

void Stack::pop()
{
	if(!isEmpty())
	{
		head=head->next;
	}
	else
	{
		cout<<"Stack isEmpty"<<endl;
	}	

}

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	s.pop();
	s.push(1);
	s.push(2);
	s.pop();
	cout<<s.top()<<endl;
	return 0;
}