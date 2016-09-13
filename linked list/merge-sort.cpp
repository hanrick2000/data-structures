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

void splitIntoHalves(node** head,node** a,node** b)
{
	node* slow=*head;
	node* fast=(*head)->next;

	if(*head==NULL || (*head)->next==NULL)
	{
		*a=*head;
		*b=NULL;
		return;
	}	

	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			slow=slow->next;
			fast=fast->next;
		}	
	}	
	*a=*head;
	*b=slow->next;	
	 slow->next=NULL;

}


node* merge(node* headA,node* headB)
{
    node* result=NULL;
    if(headA==NULL)
    	return headB;
    if(headB==NULL)
    	return headA;


    if(headA->data>headB->data)
    {
    	result=headB;
    	result->next=merge(headA,headB->next);
    }	
    else
    {
    	result=headA;
    	result->next=merge(headA->next,headB);
    }	

    return result;
}

void mergesort(node** head)
{
	if(*head==NULL || (*head)->next==NULL)
		return ;

	node* a;
	node* b;
	splitIntoHalves(head,&a,&b);
	mergesort(&a);
	mergesort(&b);

	*head=merge(a,b);

}


int main()
{
	node* head=takeInput();
	mergesort(&head);
	printLL(head);
	return 0;
}