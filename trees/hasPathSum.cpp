#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*
 Given a binary tree and a number k, print out all root to leaf paths where the sum of all
nodes value is same as the given number.
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

bool hasPathSum(BinaryTree *root, int sum)
{
   if(root==NULL)
   {
   	  return sum==0;
   }	
   else
   {
	    bool ans=0;
	    sum=sum-root->data;
	    if(!root->left && !root->right && sum==0)
	    {
	    	//cout<<"Entering"<<endl;
	        return true;
	    }
	    if(root->left)
	    	ans=ans || hasPathSum(root->left,sum);
	    if(root->right)
	    	ans=ans || hasPathSum(root->right,sum);
	    
	    return ans;
   }    
} 
 
int main()
{
	int sum;
	cin>>sum;
	BinaryTree* root=takeInput();

	
	cout<<hasPathSum(root,sum); 
	 
	 
	return 0;
}