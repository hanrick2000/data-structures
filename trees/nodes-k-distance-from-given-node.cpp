#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/*
 Print all nodes at distance k from a given node
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

/*First method  Incomplete*/

bool findLocationOfGivenNodeFromRoot(BinaryTree* root,int data,int &distance)
{
	if(root==NULL)
		return false;

	if(root->data==data|| findLocationOfGivenNodeFromRoot(root->left,data,distance) || findLocationOfGivenNodeFromRoot(root->right,data,distance))
	{
		distance++;
		return true;
	}	
	
	return false;

}


void printNodes(BinaryTree* root,int k)
{
	if(root==NULL)
		return;
	if(k==0)
	{
		cout<<root->data<<" ";
	}

	printNodes(root->left,k-1);
	printNodes(root->right,k-1);	
}

void printNodesAtKDistanceFromGivenNode(BinaryTree* root,int data,int k)
{
	if(root==NULL)
		return;

	if(root->data==data)
	{
		printNodes(root,k);
	}	
	else
	{	
		int distanceLeft=1,distanceRight=1;
		bool locationLeft=findLocationOfGivenNodeFromRoot(root->left,data,distanceLeft);
		bool locationRight=findLocationOfGivenNodeFromRoot(root->right,data,distanceRight);

		if(locationLeft)
		{
			if(k>locationLeft)
			{
				// printNodes(root,->left,k+locationLeft);
				// printNodes(root->right,k-locationLeft);
			}
			else
			{
				
			}	
		}
		else
		{
			cout<<"right "<<distanceRight<<endl;
		}	

	}
		
}
 

int main()
{
	BinaryTree* root=takeInput();
	printTree(root);
	cout<<"Enter the node data to be found"<<endl;
	int data;
	cin>>data;
	cout<<endl<<"Enter k"<<endl;
	int k;
	cin>>k;
	printNodesAtKDistanceFromGivenNode(root,data,k);
	return 0;
}