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

node* reverse(node* head)
 {
 	node* curr=head;
 	node* prev=NULL;
 	node* next;

 	while(curr!=NULL)
 	{
 		next=curr->next;
 		curr->next=prev;
 		prev=curr;
 		curr=next;

 	}	

   return prev;

 }

 
int main()
{
	node* head=takeInput();
	node* curr=reverse(head);
	printLL(curr);
	return 0;
}