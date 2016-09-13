#include <iostream>
#include <queue>
using namespace std;

/*

Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from
right to left and so on. This means odd levels should get printed from left to right and
even levels should be printed from right to left. Each level should be printed at a new
line.

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

void printNodesAtKDistance(BinaryTree* root,int k,bool flag)
{
	if(root==NULL)
		return;
	
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}	
	if(flag)
	{	
		printNodesAtKDistance(root->left,k-1,flag);
		printNodesAtKDistance(root->right,k-1,flag);
	}
	else
	{
		printNodesAtKDistance(root->right,k-1,flag);
		printNodesAtKDistance(root->left,k-1,flag);
	}	
}

 
void printZigZag(BinaryTree* root)
{
	if(root==NULL)
		return;
	int ht=height(root);
	bool flag=true;
	for(int i=1;i<=ht;i++)
	{
		printNodesAtKDistance(root,i,flag);
		cout<<endl;
		flag=!flag;
	}	
}

int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	printZigZag(root);
	return 0;
}