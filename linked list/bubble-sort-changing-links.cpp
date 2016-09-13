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

 
void swap(node** head,node* prev,node* currA,node* currB)
{
     if(prev==NULL)
     {
     	*head=currB;
   	     node* temp=currB->next;
   	     currB->next=currA;
   	     currA->next=temp;
     	 
     }	
     else
     {
     	node* temp=currB->next;
     	prev->next=currB;
     	currB->next=currA;
     	currA->next=temp;

     }
}


void bubblesort(node** head)
{
	//int len=getLength(head);
    bool swapped=false;
    node* curr=*head;
    //node* end=*head;
    node* end=NULL;
    node* prev=NULL;

    // while(end->next!=NULL);
    //    end=end->next;	

    do
    {
    	cout<<"Entering"<<endl;
    	swapped=false;
    	curr=(*head);
    	while(curr->next!=end)
    	{
    		if(curr->data>curr->next->data)
    		{
    			cout<<curr->data<<" "<<curr->next->data<<endl;
    			cout<<"swapping "<<endl;
    			swap(head,prev,curr,curr->next);
    			swapped=true;
    		}	
    		prev=curr;
    		curr=curr->next;
    	}	

    	end=curr;

    }while(swapped);

}




int main()
{
	node* head=takeInput(); 
	 
	//node* head=takeInput();
	//swapNodes(&head,head->next,head->next->next);
	 bubblesort(&head); 
	 printLL(head);
	return 0;
}