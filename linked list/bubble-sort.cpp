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



void bubblesort(node* head)
{
	int len=getLength(head);

	for(int i=0;i<len;i++)
	{
		node* current=head;
        bool swapped=false;
		for (int j = 0; j < len-i-1; ++j)
		{
			if(current->data > current->next->data)
			{
				swap(current->data,current->next->data);
				swapped=true;
			}

			current=current->next;	
		}

		if(!swapped)
			break;
	}	
}




int main()
{
	node* head=takeInput();
	bubblesort(head); 
	printLL(head);
	return 0;
}