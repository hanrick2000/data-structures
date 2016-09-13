#include "Node.h"
#include<iostream>
using namespace std;
/*
   Given a Linked List a1àa2àa3….àanàb1àb2à…..àbn.Convert it to a1àb1àa2àb2…àanàbn

*/
Node<int>* createLL()
{
   Node<int>* head=NULL;
   Node<int>* tail=NULL;

   cout<<"Enter the first element";
   int data;
   cin>>data;
   while(data!=-1)
   {
   	   Node<int>* new_node=new Node<int>(data);
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

void printLL(Node<int>* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head=head->next;
	}	
	cout<<endl<<endl;
}

int getLength(Node<int>* head)
{
	if(head==NULL)
		return 0;
	return 1+getLength(head->next);
}

Node<int>* getNthNode(Node<int>* head,int n)
{
	for(int i=0;i<n;i++)
		head=head->next;
	return head;
}

void merge(Node<int>* head)
{
    int len=getLength(head);
    int mid=(len)/2-1;
    Node<int>* midNode=getNthNode(head,mid);
    Node<int>* second=midNode->next;
    midNode->next=NULL;
    Node<int>* first=head;
    while(first!=NULL)
    {
    	Node<int>* temp=second->next;
    	second->next=first->next;
    	first->next=second ;
    	first=second->next;
    	second=temp;

    }	
 


}


int main()
{
	Node<int>* head= createLL();
	printLL(head);
	merge(head);
	printLL(head);
	return 0;
}