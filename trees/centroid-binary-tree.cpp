#include <iostream>
#include <queue>
using namespace std;

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
	//	cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
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
	//	cout<<"Enter right child of "<<temp->data<<" or enter -1"<<endl;
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
	{
		cout<<"-1"<<endl;	
		return;
	}	

	queue<BinaryTree*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
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
 
int size(BinaryTree* root)
{
	if(root==NULL)
		return 0
	
	return 1+ size(root->left)+size(root->right);
}

BinaryTree* findCentroidHelper(BinaryTree* root,int maxsize)
{
	if(root==NULL)
		return NULL;

	int left=size(root->left);
	int right=size(root->right);

	if(left>=maxsize/2 && right>=maxsize/2)
		return root;

	if(left>right)
	{
		findCentroidHelper(root->left,maxsize/2);
	}	
	else
	{
		findCentroidHelper(root->right,maxsize/2);
	}	
}


BinaryTree* findCentroid(BinaryTree* root)
{
	if(root==NULL)
		return NULL;
	int size1=size(root);
	return findCentroidHelper(root,size1);
}

 
int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	if(root->left==NULL && root->right==NULL)
	{
		cout<<"-1"<<endl;
	}
	else
	{	
		removeLeaves(root);
		printTree(root);
	}	
	return 0;
}