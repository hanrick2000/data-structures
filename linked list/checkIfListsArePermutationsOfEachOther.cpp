#include<iostream>
#include<map>
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



bool checkIfPermutation(node* a,node* b)
{
     
    map<int,int> freqA;
    map<int,int> freqB; 
    int count1=0;
    while(a!=NULL)
    {
    	freqA[a->data]++;
    	a=a->next;
    	count1++;
    }	

    int count2=0;
    while(b!=NULL)
    {
    	freqB[b->data]++;
    	b=b->next;
    	count2++;
    }	

    //cout<<"count1 "<<count1<<"count2 "<<count2<<endl;
    if(count1!=count2)
    	return false;

    map<int,int> ::iterator it;
    for(it=freqA.begin();it!=freqA.end();it++)
    {
    	int key=it->first;
    	int val=it->second;
    	//cout<<"key "<<key<<"val "<<val<<endl;
    	if(freqB[key]!=val)
    		return false;
    }	


    return true;
}



int main()
{
	node* head1=takeInput();
	node* head2=takeInput();
	bool val=checkIfPermutation(head1,head2); 
	cout<<val<<endl;
	return 0;
}