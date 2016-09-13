#include <iostream>
#include <queue>
using namespace std;

/*
	Find LCA of two nodes in a binary tree
	a. You can use up to O(n) extra space
	b. Do it without storing nodes in a Data Structure

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

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
 

// bool findPath(BinaryTree* root,vector<int> 	path,int val)
// {
// 	if(root==NULL)
// 		return false;

// 	path.push_back(root->data);
	
// 	if(root->data==val)
// 	{
// 		return true;
// 	}	


// 	return((root->left && findPath(root->left,path,val)) || (root->right) && findPath(root->right,path,val));

// 	path.pop_back();
// 	return false;
// }


// int LCA(BinaryTree* root,int n1,int n2)
// {
// 	if(root==NULL)
// 		return -1;

// 	vector<int> path1,path2;
// 	if(!findPath(root,path1,n1) || !findPath(root,path2,n2))
// 		return false;

// 	int i;
// 	for(i=0;i<path1.size() && i<path2.size();i++)
// 	{
// 		if(path1[i]!=path2[i])
// 		{
// 			break;
// 		}	
// 	}	

// 	return path1[i-1];

// }


bool findPath(BinaryTree *root, vector<int> &path, int k)
{
	// base case
	if (root == NULL) return false;

	// Store this node in path vector. The node will be removed if
	// not in path from root to k
	path.push_back(root->data);

	// See if the k is same as root's key
	if (root->data == k)
		return true;

	// Check if k is found in left or right sub-tree
	if ( (root->left && findPath(root->left, path, k)) ||
		(root->right && findPath(root->right, path, k)) )
		return true;

	// If not present in subtree rooted with root, remove root from
	// path[] and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1
int findLCA(BinaryTree *root, int n1, int n2)
{
	// to store paths to n1 and n2 from the root
	vector<int> path1, path2;

	// Find paths from root to n1 and root to n1. If either n1 or n2
	// is not present, return -1
	if ( !findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	/* Compare the paths to get the first different value */
	int i;
	for (i = 0; i < path1.size() && i < path2.size() ; i++)
		if (path1[i] != path2[i])
			break;
	return path1[i-1];
}


BinaryTree* LCA1(BinaryTree* root,int n1,int n2)
{
	if(root==NULL)
		return NULL;

	if(root->data==n1 || root->data==n2)
		return root;

	BinaryTree* leftLCA=LCA1(root->left,n1,n2);
	BinaryTree* rightLCA=LCA1(root->right,n1,n2);

	if(leftLCA && rightLCA)
		return root;

	if(leftLCA!=NULL)
		return leftLCA;
	return rightLCA;

}

int main()
{
	int n1,n2;
	cin>>n1>>n2;
	BinaryTree* root=takeInput();
	//printTree(root);
	int val=findLCA(root,n1,n2);
	cout<<val<<endl;
	return 0;
}