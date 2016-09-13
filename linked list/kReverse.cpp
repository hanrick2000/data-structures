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

node* kReverse(node* head,int k)
{
	 
	 int n=0;
	 node* prev=NULL;
	 node* curr=head;
	 node* next=NULL;
	 while(curr!=NULL && n<k)
	 {
	 	next=curr->next;
	 	curr->next=prev;
	 	prev=curr;
	 	curr=next;
	 	n++;
	 } 
 
    int len_left=getLength(next);
    //cout<<"len_left "<<len_left;
    if(len_left>=k)
    {	
      if(next!=NULL)
	    head->next=kReverse(next,k);
	
	}
	else
	{
		head->next=next;
	}	

	 return prev;


}


int main()
{
	int n;
	cin>>n;
	node* head=takeInput();
	node* curr=kReverse(head,n);
	printLL(curr);
	return 0;
}