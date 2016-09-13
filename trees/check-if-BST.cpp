
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;


class node
{
public:
	 int data;
	 node* left;
	 node* right;
	 node()
	 {
	 	left=NULL;
	 	right=NULL;
	 }	
};



node* takeInput()
{
	node* root=new node;
	int data;
	//cout<<"Enter the root's data"<<endl;
	cin>>data;

	root->data=data;
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		//cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
		int leftData;
		cin>>leftData;

		if(leftData!=-1)
		{
			temp->left=new node;
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
			temp->right=new node;
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


node* createBST(int* arr,int low,int high)
{
	if(low>high)
		return NULL;

	int mid=(low+high)/2;
	node* root=new node;
	root->data=arr[mid];
	root->left=createBST(arr,low,mid-1);
	root->right=createBST(arr,mid+1,high);

	return root;
}

bool checkIfBSTHelper(node* root,int minVal,int maxVal)
{
	if(root==NULL)
		return true;

	if(root->data>maxVal || root->data<minVal)
		return false;

	return(checkIfBSTHelper(root->left,minVal,root->data)&&checkIfBSTHelper(root->right,root->data,maxVal));

}

bool checkIfBST(node* root)
{
	if(root==NULL)
		return true;
	return checkIfBSTHelper(root,INT_MIN,INT_MAX);

}


/*
	write 2 more methods	
*/

void printInorder(node* root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}


int main()
{
	//int arr[]={1,2,3,4,5,6,7,8};
	//int size=sizeof(arr)/sizeof(arr[0]);
	//node* root=createBST(arr,0,size-1);
	//printInorder(root);
	//cout<<endl;
	node* root=takeInput();
	bool val=checkIfBST(root);
	cout<<val<<endl;
	return 0;
}