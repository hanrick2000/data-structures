#include <iostream>
#include <queue>
using namespace std;

/*
  Method 2 ( Tricky ) 
The Method 1 uses sum() to get the sum of nodes in left and right subtrees. The method 2 uses following rules to 
get the sum directly.
1) If the node is a leaf node then sum of subtree rooted with this node is 
equal to value of this node.
2) If the node is not a leaf node then sum of subtree rooted with this node is 
twice the value of this node (Assuming that the tree rooted with this node is SumTree).

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


bool isLeaf(BinaryTree* root)
{
	if (root==NULL)
	{
	   return 0;
	}

	if (root->left==NULL && root->right==NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}	

}
 

bool sumTree(BinaryTree* root)
{
	int ls=0,rs=0;
	if (root==NULL || isLeaf(root))
	{
		return 1;
	}

	if (sumTree(root->left) && sumTree(root->right))
	{
		if (root->left==NULL)
		{
			ls=0;
		}
		else if (isLeaf(root->left))
		{
			ls=root->left->data;
		}
		else
		{
			ls=2*(root->left->data);
		}


		if (root->right)
		{
			rs=0;
		}	
		else if (isLeaf(root->right))
		{
			rs=root->right->data;
		}
		else
		{
			rs=2*(root->right->data);
		}


		if (root->data==ls+rs)
		{
				return true;
		}	

		return false;
	}

	return false;
}


int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	int val=height(root);
	cout<<val<<endl;
	return 0;
}