#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* takeInput()
{
	node* head=NULL;
	node* tail=NULL;
	int data;
	cin>>data;
	
	while(data!=-1)
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

		cin>>data;
	}

	return head;	

}

void printLL(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}	

	cout<<"-1"<<endl;
}

int getLength(node* head)
{
	if(head==NULL)
		return 0;
	return 1+ getLength(head->next);
}

node* getNthNode(node* head,int val)
{
	for(int i=0;i<val;i++)
		head=head->next;
	return head;
}

node* getNthNodeFromEnd(node* head,int n)
{
	node* slow=head;
	node* fast=head;
	for(int i=0;i<n;i++)
		fast=fast->next;

	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	//Trying to get prev to slow in this case
	return slow;	
}

node* appendLastNToFirst(node* head,int n)
{
	node* prev=getNthNodeFromEnd(head,n);
	node* current=prev->next;
	prev->next=NULL;
	node* end=current;
	while(end->next!=NULL)
		end=end->next;
	end->next=head;

	return current;
    
}

int main()
{
	
	int n;
	cin>>n;
	node* head=takeInput();
	node* current=appendLastNToFirst(head,n);
	printLL(current);
	//node* current=getNthNodeFromEnd(head,3);
    //cout<<current->data;
	return 0;
}