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

node* addLL(node* a,node* b)
{
	
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	node* aRev=reverse(a);
	node* bRev=reverse(b);
	node* add=NULL;
	node* tail=NULL;
	int carry=0;
	int val=0;
	while(aRev!=NULL && bRev!=NULL)
	{
		//cout<<"addLL"<<endl;
		node* new_node=new node;
		val=aRev->data+bRev->data+carry;
		//cout<<"val initially "<<val<<endl;
		carry=val%10;
		//cout<<"carry "<<carry<<endl;
		val/=10;
		//cout<<"data being added "<<val<<endl;
		new_node->data=carry;
		new_node->next=NULL;
		carry=val;
		if(add==NULL)
		{
			add=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}	

		aRev=aRev->next;
		bRev=bRev->next;

	}	
    while(aRev!=NULL)
	{
		//cout<<"Entering aRev"<<endl;
		val=aRev->data+carry;
		carry=val%10;
		
		node* new_node=new node;
		new_node->data=carry;
		new_node->next=NULL;
		
		val=val/10;		
		carry=val;
		
		tail->next=new_node;
		tail=new_node;
		aRev=aRev->next;
	}

	while(bRev!=NULL)
	{
		//cout<<"Entering bRev"<<endl;

		val=bRev->data+carry;
		carry=val%10;
		node* new_node=new node;
		val=val/10;
		new_node->data=carry;
		carry=val;
		new_node->next=NULL;
		tail->next=new_node;
		tail=new_node;
		bRev=bRev->next;
	}	

	if(carry!=0)
	{
		//cout<<"Entering carry"<<endl;
		node* new_node=new node;
		new_node->data=carry;
		new_node->next=NULL;
		tail->next=new_node;
		tail=new_node;
	}	

   return reverse(add);
}
 



int main()
{
	node* head=takeInput();
	node* head1=takeInput();
	node* result=addLL(head,head1);
	printLL(result);
	return 0;
}