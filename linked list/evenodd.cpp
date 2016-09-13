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

void evenNumbersAfterOdd(node* head)
{
	node* prev=NULL;
	node* end=head;
	node* new_end=head;
    node* curr=head;
    node* new_head=head;

	while(end->next!=NULL)
		end=end->next;

	new_end=end;

	while(((curr->data)%2==0) && curr!=end)
	{
		 new_end->next=curr;
		 new_end=new_end->next;
		 new_end->next=NULL;
		 curr=curr->next;
	}	


	if((curr->data)%2!=0)
	{ 
		new_head=curr;

		while(curr!=end)
		{
			if((curr->data)%2!=0)
			{
				prev=curr;
				curr=curr->next;
			}
			else
			{
				prev->next=curr->next;
				curr->next=NULL;
				new_end->next=curr;
				new_end=curr;
				curr=prev->next;

			}	
		}	

	}
	else
	{
		prev=curr;
	}	

	if(new_end!=end && (curr->data)%2==0)
	{
		prev->next=end->next;
		end->next=NULL;
		new_end->next=end;
	}	

} 


node* evenNumbersAfterOdd1(node* head)
{
	node* headOdd=NULL;
	node* tailOdd=NULL;
	node* headEven=NULL;
	node* tailEven=NULL;
	node* curr=head;

	while(curr!=NULL)
	{
		node* new_node=new node;
		new_node->data=curr->data;
		new_node->next=NULL;
		if((curr->data%2==0))
		{
			if(headEven==NULL)
			{
				headEven=new_node;
				tailEven=new_node;
			}	
			else
			{
				tailEven->next=new_node;
				tailEven=tailEven->next;
			}	
		}
		else
		{
			if(headOdd==NULL)
			{
				headOdd=new_node;
				tailOdd=new_node;
			}	
			else
			{
				tailOdd->next=new_node;
				tailOdd=tailOdd->next;
			}	
		}

		curr=curr->next;	
	}

	tailOdd->next=headEven;	
	//head=headOdd;
	return headOdd;
}

int main()
{
    node* head=takeInput();
    //printLL(head);
    node* new_node=evenNumbersAfterOdd1(head);
    printLL(new_node);
    return 0;
}