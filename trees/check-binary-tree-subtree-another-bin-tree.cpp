#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

/*
 Given a binary tree, check whether there are two nodes in it whose sum equals a given 
value. 
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
 

bool isIdentical(BinaryTree* root1,BinaryTree* root2)
{
	if (root1==NULL && root2==NULL)
	{
		return 1;
	}

	if (root1==NULL || root2==NULL)
	{
		return 0;
	}

	return (root1->data == root2->data && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right))
} 
 

bool checkIfSubtree(BinaryTree* root1,BinaryTree* root2)
{
	if (root1==NULL)
	{
		return false;
	}

	if (root2==NULL)
	{
		return true;
	}

	if (isIdentical(root1,root2))
	{
		return true;
	}

	return checkIfSubtree(root1->left,root2) || checkIfSubtree(root1->right,root2)

}

int main()
{
	//cout<<"Enter sum to be found"<<endl;
	int num;
	cin>>num;
	//cout<<"Enter tree"<<endl;
	BinaryTree* root=takeInput();
	//printTree(root);
	
	//findPairEqualsGivenSum1(root,num);
 	 bool val=findPairEqualsGivenSum2(root,num);
 	 cout<<val<<endl;
	 
	return 0;
}