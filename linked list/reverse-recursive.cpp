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

void reverse(node** head)
 {
 	 

 	 if(*head==NULL)
 	 	return;

 	 node* first=(*head);
 	 node* rest=first->next;
 	 if(rest==NULL)
 	 	return ;

 	 reverse(&rest);

 	 first->next->next=first;
 	 first->next=NULL;

 	 *head=rest;

 }

 
int main()
{
	node* head=takeInput();
	 reverse(&head);
	printLL(head);
	return 0;
}