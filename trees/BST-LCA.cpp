#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<stack>
using namespace std;

/*
Find LCA of two elements in a BST.  
*/



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


node* LCA(node* root,int data1,int data2)
{
	if(root==NULL)
		return root;


	if(root->data>data1 && root->data>data2)
	{
		return LCA(root->left,data1,data2);
	}
	 if(root->data<data1 && root->data<data2)
	{
		return LCA(root->right,data1,data2);
	}	

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

 
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	node* root=createBST(arr,0,size-1);
	int num;
	cout<<"Enter the sum "<<endl;
	cin>>num;
	bool val=findPairEqualsGivenSum1(root,num); 
	cout<<val<<endl;
	return 0;
}