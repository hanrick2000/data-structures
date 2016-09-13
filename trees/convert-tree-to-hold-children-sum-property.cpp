#include <iostream>
#include <queue>
using namespace std;

/*
Question: Given an arbitrary binary tree, convert it to a binary tree that holds Children Sum Property. You can only increment data values 
in any node (You cannot change structure of tree and cannot decrement value of any node).
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


void increment(BinaryTree* root,int diff)
{
	// if (root==NULL)
	// {
	// 	return;
	// }

	if (root->left)
	{
		root->left->data+=diff;
		increment(root->left,diff);
	}
	else if(root->right)
	{
		root->right->data+=diff;
		increment(root->right,diff);
	}	

}
 
void convert_tree(BinaryTree* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;
	else
	{
		convert_tree(root->left);
		convert_tree(root->right);

		int left_data=0,right_data=0;

		if (root->left)
		{
			left_data=root->left->data;
		}

		if (root->right)
		{
			right_data=root->right->data;
		}

		int diff=right_data+left_data-root->data;

		if(diff>0)
		{
			root->data+=diff;
		}	
		else if(diff<0)
		{
			increment(root,-diff)
		}	

	}	
} 

int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	bool flag=true;
	printNodesWithoutSibling(root,flag);
	if(flag==true)
		cout<<"-1";
	return 0;
}