#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

/*
Find LCA of two elements in a BST.  
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

void printTree(node* root)
{
	if(root==NULL)
	{
		cout<<"-1"<<endl;	
		return;
	}	

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();

		if(q.empty())
		{
			break;
		}	
		else if(temp==NULL)
		{
			cout<<endl;
			q.push(NULL);
		}	
		else
		{	
			cout<<temp->data<<" ";
			if(temp->left)
			{
				q.push(temp->left);
			}	

			if(temp->right)
			{
				q.push(temp->right);
			}
		}		
	}
	cout<<endl;	
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
	int size;
	cin>>size;
	int* arr=new int[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	node* root=createBST(arr,0,size-1);
	printTree(root);
	 
	return 0;
}