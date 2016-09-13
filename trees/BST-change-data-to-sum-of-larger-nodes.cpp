#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<stack>
using namespace std;

/*
 Change data to sum of larger
 nodes in BST 

 see main() for diagram
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

 

void replaceSumHelper(node* root,int& sum)
{
	if(root==NULL)
		return;

	replaceSumHelper(root->right,sum);
	int temp=root->data;
	root->data=sum;
	sum=sum+temp;
	replaceSumHelper(root->left,sum);


}


void replaceSum(node* root)
{
	if(root==NULL)
		return;

	int sum=0;
	replaceSumHelper(root,sum);
	 
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
	int arr[]={1,2,3,4,5,6,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	node* root=createBST(arr,0,size-1);
	printInorder(root);
	replaceSum(root);
	cout<<endl;
	printInorder(root);

	/*		 4								 
			/  \	
		   /    \		------->     		
		   2     6
		  /\     /\
		 /  \   /  \
		 1	 3	5   7

		      18
			/  \	
		   /    \		
		   25     7
		  /\     /\
		 /  \   /  \
		 27	 22	13   0
	


	*/

	return 0;
}