#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/*
 Find next largest element in a binary tree. i.e. given a number n find just greater element
 than n.
*/

class BinaryTree 
{
public:	
	int data;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree()
	{	
		left=NULL;
		right=NULL;
	}
	~BinaryTree()
	{/*what we want here is that if we delete root,recursively its children get deleted!*/
		if(left)
			delete left;
		if(right)
			delete right;
	}
};


BinaryTree* takeInput()
{
	BinaryTree* root=new BinaryTree;
	int data;
	//cout<<"Enter the root's data"<<endl;
	cin>>data;

	root->data=data;
	queue<BinaryTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		//cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
		int leftData;
		cin>>leftData;
		
		if(leftData!=-1)
		{
			temp->left=new BinaryTree;
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
			temp->right=new BinaryTree;
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


void printTree(BinaryTree* root)
{
	if(root==NULL)
		return;
	queue<BinaryTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
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
	cout<<endl;
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}

void nextGreater(BinaryTree* root,int data,int &val)
{
	if(root==NULL)
	{
		return ;
	}	
	
	if(root->data>data && root->data<val)
	{
		//cout<<"enternig "<<endl<<root->data<<endl;
		//cout<<"The value is "<<val<<endl;
		val=root->data;
	}	

	nextGreater(root->left,data,val);
	nextGreater(root->right,data,val);

	//return val;
}
 

int main()
{
	int n;
	cin>>n;
	BinaryTree* root=takeInput();
	//printTree(root);
	int x=INT_MAX;
	nextGreater(root,n,x);
	//if(x==INT_MAX)
	cout<<x<<endl;
	return 0;
}