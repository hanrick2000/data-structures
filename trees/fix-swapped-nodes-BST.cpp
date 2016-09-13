#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

/*
 Two nodes of a BST are swapped, correct the BST
 Two conditions are generated.
 1)Not adjacent 
  For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
  The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
  two pairs are found where order is disturbed,first-pair's first and second-pair's second are swapped
 2)adjacent nodes-simply swap them	

This can be done in two ways 1)convert into an array,sort,recreate BST Time-O(nlogn),Space-O(n)
							 2)O(n),no extra space,simply do inorder traversal,maintain nodes to be swapped	

*/

 

class node
{
public:
	 int data;
	 node* left;
	 node* right;
	 node()
	 {
	 	left=NULL;
	 	right=NULL;
	 }	
};

node* createBST(int* arr,int low,int high)
{
	if(low>high)
		return NULL;

	int mid=(low+high)/2;
	node* root=new node;
	root->data=arr[mid];
	root->left=createBST(arr,low,mid-1);
	root->right=createBST(arr,mid+1,high);

	return root;
}


node* takeInput()
{
	node* root=new node;
	int data;
	//cout<<"Enter the root's data"<<endl;
	cin>>data;

	root->data=data;
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		//cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
		int leftData;
		cin>>leftData;

		if(leftData!=-1)
		{
			temp->left=new node;
			temp->left->data=leftData;
			q.push(temp->left);

		}	
		else
		{
			temp->left=NULL;
		}	
		//cout<<"Enter right child of "<<temp->data<<" or enter -1"<<endl;
		int rightData;
		cin>>rightData;

		if(rightData!=-1)
		{
			temp->right=new node;
			temp->right->data=rightData;
			q.push(temp->right);
		}	
		else
		{
			temp->right=NULL;
		}	
	}

	return root;	
}

void correctBSTUtil(node* root,node** prev,node** first,node** middle,node** last)
{
	if (root)
	{
		correctBSTUtil(root->left,prev,first,middle,last);

		if (*prev && (*prev)->data > root->data)
		{
			
			if(*first==NULL )
			{
				*first=*prev;
				*middle=root;
			}	
			else
			{
				*last=root;
			}	
		}

		*prev=root;

		correctBSTUtil(root->right,prev,first,middle,last);
	}
}

void correctBST(node* root)
{
	if (root==NULL)
	{
		return;
	}

	node* prev,*first,*middle,*last;

	correctBSTUtil(root,prev,first,middle,last);
	if (first && last) //non adjacent
	{
		swap(first->data,last->data);
	}
	else if (first && middle)//adjacent nodes
	{
		swap(first->data,middle->data);
	}


}
 

void printInorder(node* root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

 
int main()
{
	//int arr[]={1,2,3,4,5,6,7,8,9};
	//int size=sizeof(arr)/sizeof(arr[0]);
	//node* root=createBST(arr,0,size-1);
	int num;
	// cout<<"Enter the sum "<<endl;
	cin>>num;
	node* root=takeInput();
	return 0;
}