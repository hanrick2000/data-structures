#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*
  Given two trees, return true if they are structurally identical ​
 they are made of nodes with the same values arranged in the same way.  
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

void preorder(BinaryTree* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


void postorder(BinaryTree* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
 
 // bool checkIfIdentical(BinaryTree* root1,BinaryTree* root2)
 // {
 // 	if(root1==NULL && root2==NULL)
 // 	{
 // 		return true;
 // 	}	

 // 	else if( (root1==NULL && root2!=NULL) && (root2==NULL && root1!=NULL))
 // 		return false;

 //    // if(root1->data!=root2->data)
 //    // 	return false;

 //   else  if(root1->data==root2->data && checkIfIdentical(root1->left,root2->left) && checkIfIdentical(root1->right,root2->right))
 //   	return true;

 //   return false;
 
 // }

 bool checkIfIdentical1(BinaryTree* root1,BinaryTree* root2)
 {
 	if(root1==NULL && root2==NULL)
 	{
 		return true;
 	}	

  	if(root1!=NULL && root2!=NULL)
  	{
  		return root1->data==root2->data && checkIfIdentical1(root1->left,root2->left)&& checkIfIdentical1(root1->right,root2->right);
  	}	

  	return 0;
    
 
 }




int main()
{
	int size1,size2;
	cin>>size1>>size2;
	if(size1!=size2)
	{
		cout<<"0"<<endl;
		return 0;
	}	
	else
	{	BinaryTree* root=takeInput();
		//printTree(root);
		//cout<<endl;
		//cout<<"Enter the second tree"<<endl;
		BinaryTree* root1=takeInput();
		//printTree(root1);
		//cout<<endl;
		// bool val=checkIfIdentical(root,root1);
		// cout<<val<<endl;
		bool val1=checkIfIdentical1(root,root1);
		cout<<val1<<endl; 
	}	
	return 0;
}