#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

/*
 preorder traversal iterative
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

//Root Left Right 
void preOrderIterative(BinaryTree* root)
{
	if(root==NULL)
		return;
	stack<BinaryTree*> s;
	s.push(root);

	while(!s.empty())
	{
		//cout<<"Entering"<<endl;
		BinaryTree* temp=s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right)
		{
			s.push(temp->right);
		}	
		if(temp->left)
		{	
			s.push(temp->left);
		}	
	}	


}


/*The one below is wrong!*/

// void preOrderIterative1(BinaryTree* root)
// {
// 	if(root==NULL)
// 		return;

// 	stack<BinaryTree*> s;
// 	BinaryTree* current=root;
// 	s.push(current);
// 	bool flag=0;
// 	while(1)
// 	{
// 		if(current)
// 		{
// 			cout<<"Enter"<<endl;	 	
// 			cout<<current->data<<" "<<endl;
// 			if(current->left)
// 			{	current=current->left;
// 				s.push(current);

// 			}	
// 			else 
// 				current=NULL;
// 		}	
// 		else
// 		{
// 			if(s.empty())
// 				break;
// 			else
// 			{	
// 				current=s.top();
// 				s.pop();
// 				current=current->right;
// 			}	

// 		}	
// 	}	
// }

 
int main()
{
	BinaryTree* root=takeInput();
	// printTree(root);
	// cout<<endl;
	preOrderIterative(root);
	 
	return 0;
}