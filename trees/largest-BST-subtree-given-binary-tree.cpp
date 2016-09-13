#include <iostream>
#include <queue>
#include <climits>
using namespace std;

/*
 Given a Binary tree find the largest BST subtree.
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

/*First method */

bool checkIfBSTHelper(BinaryTree* root,int min_val,int max_val)
{
	if(root==NULL)
		return true;

	if(root->data < min_val || root->data > max_val)
		return false;

	return checkIfBSTHelper(root->left,min_val,root->data) && checkIfBSTHelper(root->right,root->data,max_val);
}



bool checkIfBST(BinaryTree* root)
{
	if(root==NULL)
		return true;
	return checkIfBSTHelper(root,INT_MIN,INT_MAX);
}


int size(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+ size(root->left)+size(root->right);
}

int largestBSTInGivenBinaryTree(BinaryTree* root)
{
	if(checkIfBST(root))
		return size(root);
	else 
		return max(largestBSTInGivenBinaryTree(root->left),largestBSTInGivenBinaryTree(root->right));

}

/*second method efficient*/

/*
  Do postorder traversal.
  and for every node return isBST,size,min,max

*/

 //returning the current size and maintaining the maxsize as a reference 
int largestBSTInGivenBinaryTree1Util(BinaryTree* root,int *min_ref,int *max_ref,bool *is_bst,int *max_size)
{
	if (root==NULL)
	{
		is_bst=true;
		return 0;
	}


	int min=INT_MAX;
	bool left_flag=false;
	bool right_flag=false;
	int ls,rs;

	*max_ref=INT_MIN;


  /* Following tasks are done by recursive call for left subtree
    a) Get the maximum value in left subtree (Stored in *max_ref)
    b) Check whether Left Subtree is BST or not (Stored in *is_bst_ref)
    c) Get the size of maximum size BST in left subtree (updates *max_size) */

	ls=largestBSTInGivenBinaryTree1Util(root->left,min_ref,max_ref,is_bst,max_size);

	
	if (is_bst && root->data > *max_ref)
	{
	 	left_flag=true;   
	}	


	min=*min_ref;

	*min_ref=INT_MAX;

	rs=largestBSTInGivenBinaryTree1Util(root->right,min_ref,max_ref,is_bst,max_size);

	if (is_bst && root->data < *min_ref);
	{
		right_flag=true;
	}


	//changing min and max values for the parent recursive calls

	if (min < *min_ref)
	{
		*min_ref=min;
	}

	if (*min_ref > root->data)
	{
		*min_ref=root->data;
	}

	if (root->data > *max_ref)
	{
		*max_ref=root->data;
	}


	/* If both left and right subtrees are BST. And left and right
     subtree properties hold for this node, then this tree is BST.
     So return the size of this tree */
	if (left_flag && right_flag)
	{
		if (ls+rs+1 > *max_size)
		{
			*max_size=ls+rs+1;
		}

		return ls+rs+1;
	}
	else
	{
		is_bst=false;
	}	
}

int largestBSTInGivenBinaryTree1(BinaryTree* root)
{
	int min_ref=INT_MAX;
	int max_ref=INT_MIN;
	bool is_bst=false;
	int size=0;

	largestBSTInGivenBinaryTree1Util(root,&min_ref,&max_ref,&is_bst,size);

}

int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	bool val=checkIfBalanced(root);
	cout<<val<<endl;
	return 0;
}