#include<iostream>
#include<vector>
#include<climits>
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


node* binTree2ListUtil(node* root)
{
	if(root==NULL)
		return NULL;


	//call on the left subtree
	if(root->left)
	{
		node* left=binTree2ListUtil(root->left);
		//find the inorder predeccessor,since we are considering the left.(who comes pehle)
		while(left->right!=NULL)
			left=left->right;
		left->right=root;
		root->left=left;
		
	}	

	if(root->right)
	{
		node* right=binTree2ListUtil(root->right);
		//find the inorder successor,since here we are considering who comes after
		while(right->left!=NULL)
			right=right->left;	

		right->left=root;
		root->right=right;
		
	}	

	return root;
}


node* binTree2List(node* root)
{
	if(root==NULL)
		return NULL;

	root=binTree2ListUtil(root);


	//now change the head to point to the left most node

	while(root->left!=NULL)
	  root=root->left;

	return root;

}

void printInorder(node* root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}


void printNodesOfDLL(node* root)
{
	if(root==NULL)
		return;

	//-------------------------------Pay attention root!=NULL and not root->right!=NULL
	while(root!=NULL)
	{
		cout<<root->data<<" ";
		root=root->right;
	}	
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	node* root=createBST(arr,0,size-1);
	printInorder(root);
	cout<<endl;
	node* root1=binTree2List(root);
	printNodesOfDLL(root1);
	return 0;
}