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

void printArray(int* arr,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}	

	cout<<endl;
}


void printPathsRecur(BinaryTree* root,int* path,int pathLen,int k,bool &flag)
{
	if(root==NULL)
		return;

	path[pathLen++]=root->data;
	k=k-root->data;

	if(root->left==NULL && root->right==NULL && k==0)
	{
		flag=true;
		printArray(path,pathLen);
	}
	else
	{
		printPathsRecur(root->left,path,pathLen,k,flag);
		printPathsRecur(root->right,path,pathLen,k,flag);
	}	
}

//The code below doesn't print all paths

// bool printPathsRecur1(BinaryTree* root,int* path,int pathLen,int sum)
// {
// 	if (root==NULL)
// 	{
// 		return false;
// 	}

// 	path[pathLen++]=root->data;
// 	sum=sum-root->data;

// 	if (sum == 0 && !root->left && !root->right)
// 	{
// 		for (int i = 0; i < pathLen; ++i)
// 		{
// 			cout<<path[i]<<" ";
// 		}
// 		cout<<endl;
// 		return true;
// 	}

// 	if (printPathsRecur1(root->left,path,pathLen,sum) || printPathsRecur1(root->right,path,pathLen,sum))
// 	{
// 		return true;
// 	}

// 	return false;

// }

void printPaths(BinaryTree* root,int k)
{
	int path[1000];
	int pathLen=0;
	bool flag=false;
	printPathsRecur(root,path,pathLen,k,flag);
	if(flag==false)
		cout<<"-1"<<endl;
	//cout<<printPathsRecur1(root,path,pathLen,k);

}
 
int main()
{
	int sum;
	cin>>sum;
	BinaryTree* root=takeInput();
	//printTree(root);
	// cout<<"Enter the sum"<<endl;
	
	printPaths(root,sum); 
	 
	 
	return 0;
}