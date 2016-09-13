#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

/*
 Given a binary tree print max sum path between two leaf nodes
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

/*
We can find the maximum sum using single traversal of binary tree. The idea is to maintain two values in recursive calls
1) Maximum root to leaf path sum for the subtree rooted under current node.
2) The maximum path sum between leaves (desired output).

For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, and compare the sum with maximum path sum found so far.

Following is the implementation of the above O(n) solution.
*/

int maxSumPathBetweenLeavesHelper(BinaryTree* root,int& res)
{
	if (root==NULL)
	{
		return 0;
	}
	
	if (!root->left && !root->right)
	{
		return root->data;	
	}	

	int ls=maxSumPathBetweenLeavesHelper(root->left,res)
	int rs=maxSumPathBetweenLeavesHelper(root->right,res);

	if (root->left && root->right)
	{
	   res=max(res,ls+rs+root->data);

	   return max(ls,rs)+root->data;

	}

	return (!root->left)?rs+root->data:ls+root->data;
}

int maxSumPathBetweenLeaves(BinaryTree* root)
{
	int res=INT_MAX;
	maxSumPathBetweenLeavesHelper(root,res);

}
 
 
int main()
{
	BinaryTree* root=takeInput();
	printTree(root);
	printPaths(root);  
	return 0;
}