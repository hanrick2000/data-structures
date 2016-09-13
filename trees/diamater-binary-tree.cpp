#include <iostream>
#include <queue>
using namespace std;

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
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}


/*This considers only edges and not the nodes.this works in O(nh)*/
int diameter(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	int ld=diameter(root->left);
	int rd=diameter(root->right);

	return max(max(ld,rd),lh+rh+1);
}

/*This considers O(n),returning both height and diameter*/
pair<int,int> heightDiameter(BinaryTree* root)
{
	if(root==NULL)
	{
		pair<int,int> p(0,0);
		return p;
	}	

	pair<int,int> la=heightDiameter(root->left);
	pair<int,int> ra=heightDiameter(root->right);

	int height=1+max(la.first,ra.first);
	int diameter=max(max(la.second,ra.second),la.first+ra.first);
	pair<int,int> result(height,diameter);
	return result;
}

int main()
{
	BinaryTree* root=takeInput();
	int val=diameter(root);
	cout<<val<<endl;
	//printTree(root);
	return 0;
}