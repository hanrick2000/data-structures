#include <iostream>
#include <queue>
using namespace std;

/*
You   have   a   binary   tree   with   non­negative   numeric   values   stored   in   its   nodes,  
you   need  to   find   out   the   maximum   possible   sum   of  
all   the   nodes.   Selection   of   nodes   for   the   sum  
follows   following   constraint:   If   you   have   selected   
any   BinaryTree   for   the   sum,   you   can   not  
select its immediate parent and its children for sum. 
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
 
/*This solution is O(nh)*/

int findMaxSum(BinaryTree* root,bool canInclude=true)
{
	if(root==NULL)
		return 0;

	int maxSum=0;	
	if(!canInclude)
	{	
		return findMaxSum(root->left,true)+findMaxSum(root->right,true);
	}
	else
	{   //option1-cannot consider root and its children
		int option1=root->data+findMaxSum(root->left,false)+findMaxSum(root->right,false);
		int option2=findMaxSum(root->left,true)+findMaxSum(root->right,true);
		return max(option1,option2);
	}	
}

/*O(n) solution*/
pair<int,int> findMaxSum1(BinaryTree* root)
{
	if(root==NULL)
	{
		pair<int,int> p(0,0);
		return p;
	}	

	//pair<include,exclude>
	pair<int,int> p_left=findMaxSum1(root->left);
	pair<int,int> p_right=findMaxSum1(root->right);

	int include=root->data+p_left.second+p_right.second;
	//int exclude=p_left.first+p_right.first;
	int exclude=max(p_left.first,p_left.second)+max(p_right.first,p_right.second);

	pair<int,int> output(include,exclude);
	return output;
}



int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	cout<<findMaxSum(root);

	return 0;
}	