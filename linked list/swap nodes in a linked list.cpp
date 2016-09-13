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



void swapNodes(node** head,int a,int b)
{
	if(a==b)
		return;
	node* currA=*head,*prevA=NULL,*currB=*head,*prevB=NULL;
	
	while(currA!=NULL && currA->data!=a)
	{
		prevA=currA;
		currA=currA->next;
	}

	while(currB!=NULL && currB->data!=b)
	{
		prevB=currB;
		currB=currB->next;
	}

	if(currA==NULL || currB==NULL)
		return;

	if(prevA==NULL)
	{
		*head=currB;
	}	
	else
	{
		prevA->next=currB;
	}	

	if(prevB==NULL)
	{
       *head=currA;
	}
	else
	{
		prevB->next=currA;
	}	

    node* temp=currA->next; 
	currA->next=currB->next;
	currB->next=temp;

}



int main()
{
	node* head=takeInput();
	int a,b;
	cin>>a>>b;
	swapNodes(&head,a,b);
	printLL(head);
	return 0;
}