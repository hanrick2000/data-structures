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

bool checkReverse(node* head1,node* head2)
{
	node* rev=reverse(head1);
	int flag=0;
    while(rev!=NULL && head2!=NULL)
    {
    	if(rev->data!=head2->data)
    	{
    		return false;
    	}	
    	rev=rev->next;
    	head2=head2->next;
    }	

    if(head2!=NULL || rev!=NULL)
    	return false;
    return true;

}


 
int main()
{
	node* head=takeInput();
	node* head1=takeInput();
	bool data=checkReverse(head,head1);
	cout<<data;
	//printLL(curr);
	return 0;
}