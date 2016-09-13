#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
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
	cout<<endl;
}


 

int maxValue(BinaryTree* root)
{
	if(root==NULL)
		return -1;

	int max=root->data;

	if(root->left)
	{
		int leftMax=maxValue(root->left);
		if(max<leftMax)
			max=leftMax;
	}	

	if(root->right)
	{
		int rightMax=maxValue(root->right);
		if(max<rightMax)
		   max= rightMax;	
	}	

	return max;
} 


int secondMaxHelper(BinaryTree* root,int maxVal)
{
	if(root==NULL)
		return -1;

	int secondMax=root->data;
	if(root->left)
	{
		int leftSecondMax=secondMaxHelper(root->left,maxVal);
		if(secondMax<leftSecondMax && leftSecondMax<maxVal)
		{
			cout<<"updating leftSecondMax "<<leftSecondMax;
			secondMax=leftSecondMax;
		}	
	}	

	if(root->right)
	{
		int rightSecondMax=secondMaxHelper(root->right,maxVal);
		if(secondMax<rightSecondMax && rightSecondMax<maxVal)
		{
			cout<<"updating rightSecondMax "<<rightSecondMax;

			secondMax=rightSecondMax;
		}	
	}

	return secondMax;	
}


void secondMax(BinaryTree* root)
{
	if(root==NULL)
		return ;

	vector<int> v;
	
	int rootVal=root->data;
	cout<<rootVal<<endl;
	v.push_back(rootVal);
	
	int maxValLeft=maxValue(root->left);
	cout<<maxValLeft<<endl;
	v.push_back(maxValLeft);
	
	int secondMaxLeftVal=secondMaxHelper(root->left,maxValLeft);
	cout<<secondMaxLeftVal<<endl;
	v.push_back(secondMaxLeftVal);
	
	//cout<<"calculating"<<endl;

	int maxValRight=maxValue(root->right);
	cout<<maxValRight<<endl;
	v.push_back(maxValRight);
	
	int secondMaxValRight=secondMaxHelper(root->right,maxValRight);
	cout<<secondMaxValRight<<endl;
	v.push_back(secondMaxValRight);

	sort(v.begin(),v.end());

	cout<<v[3]<<endl;



}

int secondMaxTry(BinaryTree* root)
{
	if(root==NULL)
		return -1;

	queue<BinaryTree*> q;
	vector<int> v;

	q.push(root);
	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		v.push_back(temp->data);

		if(temp->left)
		{
			q.push(temp->left);
		}	

		if(temp->right)
		{
			q.push(temp->right);
		}	
	
	}	

	sort(v.begin(),v.end());
	int size=v.size();
	cout<<v[size-2]<<endl;

} 
 

int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	//secondMax(root);
	//cout<<val<<endl;
	secondMaxTry(root);
	return 0;
}