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

void merge(node* head)
{
	int len=getLength(head);
	//cout<<"The len is "<<len<<endl;
	int mid=(len+1)/2-1;
	node* first=head;
	node* midNode=getNthNode(head,mid);
	//cout<<midNode->data<<endl;
	node* second=midNode->next;
	midNode->next=NULL;	
	while(first!=NULL && second!=NULL)
	{
		node* temp=second->next;
    	second->next=first->next;
    	first->next=second ;
    	first=second->next;
    	second=temp;

	}	

}


int main()
{
    node* head=takeInput();
    //printLL(head);
    merge(head);
    printLL(head);
    return 0;
}