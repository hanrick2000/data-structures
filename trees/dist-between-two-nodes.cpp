#include <iostream>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

/*
 Dist between any two nodes
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
 dist(node1,node2)=dist(root,node1)+dist(root,node2)-2*dist(root,lca(node1,node2)) 	
*/


int findLevel(BinaryTree* root,int data,int level)
{
	if (root==NULL)
	{
		return -1;
	}

	if (root->data==data)
	{
		return level;
	}

	int l=findLevel(root->left,data,level+1);
	return l!=-1?l:findLevel(root->right,data,level+1);

}
 
 node* findDistUtil(node* root,int& d1,int& d2,int& dist,int n1,int n2,int lvl)
 {
 	if (root==NULL)
 	{
 		return NULL;
 	}

 	if (root->data==n1)
 	{
 		d1=lvl;
 		return root;
 	}

 	if (root->data==n2)
 	{
 		d2=lvl;
 		return root;
 	}

 	node* left_lca=findDistUtil(root->left,d1,d2,dist,n1,n2,lvl+1);
 	node* right_lca=findDistUtil(root->right,d1,d2,dist,n1,n2,lvl+1);

 	if (left_lca && right_lca)
 	{
 		dist=d1+d2-2*lvl;
 		return root;
 	}

 	return left_lca? left_lca:right_lca;
 }
 
 int findDist(node* root,int n1,int n2)
 {
 	if (root==NULL)
 	{
 		return -1;
 	}

 	int d1=0,d2=0,dist;
 	node* lca=findDistUtil(root,d1,d2,dist,n1,n2,0);

 	if (d1!=-1 && d2!=-1)
 	{
 		return dist;
 	}

 	// If n1 is ancestor of n2, consider n1 as root and find level 
    // of n2 in subtree rooted with n1
 	if (d1!=-1)
 	{
 		return findLevel(lca,n2,0);
 	}

 	if (d2!=-1)
 	{
 		return findLevel(lca,n1,0);
 	}

 	return -1;
 }

int main()
{
	BinaryTree* root=takeInput();
	printTree(root);
	cout<<"Enter the node whose level is to be found"<<endl;
	int data;
	cin>>data;
	cout<<findLevel(root,data,1); 
	return 0;
}