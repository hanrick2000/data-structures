#include <iostream>
#include <queue>
using namespace std;

/*
a. insert 
b. remove 
c. search 
d. size 
e. isEmpty 

*/

struct node	
{
	int data;
	node* left;
	node* right; 
 
};


class BinarySearchTree 
{
public:
	 node* root;
	 bool isEmpty(node* root);
	 int size(node* root);
	 node* insert(node* root,int data);
	 bool search(node* root,int data);
	 node* remove(node* root,int data);
	 void printInorder(node* root);
	
};


bool BinarySearchTree::isEmpty(node* root)
{
	if(root==NULL)
		return true;
	return false;
}

int BinarySearchTree::size(node* root)
{
	if(root==NULL)
		return 0;
	return 1+size(root->left)+size(root->right);
}

node* BinarySearchTree::insert(node* root,int data)
{
	//count++;
	if(root==NULL)
	{
		 
		node* node1=new node;
		
		node1->data=data;
		node1->left=NULL;
		node1->right=NULL; 
		 
		return node1;
	}	
	else
	{ 

		if(root->data>data)
		{
			root->left=insert(root->left,data);
		}
		else
		{
			root->right=insert(root->right,data);
		}	
	}	

	return root;
}


bool BinarySearchTree::search(node* root,int data)
{
	if(root==NULL)
		return false;


	if(root->data==data)
	{
		return true;
	}	

	if(data < root->data)
	{
		return search(root->left,data);
	}	

	if(root->data <data)
	{
		return search(root->right,data);
	}	
}


node* inorderSuccessor(node* root)
{
	if(root==NULL)
		return root;
	
	while(root->left!=NULL)
		root=root->left;

	return root;
}

node* BinarySearchTree::remove(node* root,int data)
{
	if(root==NULL)
		return root;

	
    if(root->data>data)
	{
		root->left=remove(root->left,data);
		//return root;
	}	
	else if(root->data<data)
	{
		root->right=remove(root->right,data);
		//return root;
	}
   
    else
	{

		//0 or 1 children
		if(root->left==NULL)
		{
			node* temp=root->right;
			delete root;
			return temp;
		}	
		else if(root->right==NULL)
		{
			cout<<"Entering"<<endl;
			node* temp=root->left;
			delete root;
			return temp;
		}	
		
		node* temp=inorderSuccessor(root->right);
		cout<<temp->data<<endl;
		root->data=temp->data;
		root->right=remove(root->right,temp->data);
		 
	}	
	return root;	

}

void BinarySearchTree::printInorder(node* root)
{
	if(root==NULL)
	{
		//cout<<"No root"<<endl;
		return;
	}

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}



int main()
{
    node* root=NULL;
	BinarySearchTree *b=new BinarySearchTree();
	root=b->insert(root,4);
	root=b->insert(root,2);
	root=b->insert(root,3);
	root=b->insert(root,1);
	b->printInorder(root);
	cout<<endl;
	b->remove(root,4);
	b->printInorder(root);
	//cout<<root->data<<endl;
	cout<<endl;
	b->remove(root,3);
	b->printInorder(root);
	cout<<endl;
	delete b;
	return 0;
}