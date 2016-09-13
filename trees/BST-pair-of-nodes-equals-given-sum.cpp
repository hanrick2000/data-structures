#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

/*
Given a binary search tree and a int s, find pair of nodes in the BST which sum to s. 
a. Find a solution for which time complexity is O(n) 
b. Find a solution which uses maximum O(logn) extra space.  
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



/*O(n)-Time ,O(n)-Extra Space*/


void findPairEqualsGivenSumHelper(node* root,int* arr,int& size)
{
	if(root==NULL)
		return;
	findPairEqualsGivenSumHelper(root->left,arr,size);
	arr[size++]=root->data;
	findPairEqualsGivenSumHelper(root->right,arr,size);
}
 

void findPairEqualsGivenSum(node* root,int sum)
{
	if(root==NULL)
		return;

	int* arr=new int[20];
	memset(arr,0,sizeof(arr));
	int size=0;
	findPairEqualsGivenSumHelper(root,arr,size); 
	cout<<"The size is "<<size<<endl;
	int start=0,end=size-1;

	while(start<end)
	{
		int current_sum=arr[start]+arr[end];
		if(current_sum<sum)
		{ 
			start++;
		}
		else if(current_sum>sum)
		{
			end--;
		}
		else
		{
			cout<<arr[start]<<" "<<arr[end]<<endl;
			start++;
			end--;
		}	
	}	
}

/*O(logn) extra space */

bool findPairEqualsGivenSum1(node* root,int sum)
{
	if(root==NULL)
		return false;

    node* current1=root,*current2=root; 
	stack<node*> s1,s2;
	bool done1=false,done2=false;
	int val1=0,val2=0;
	while(1)
	{
		while(done1==false)
		{
			if(current1)
			{
				s1.push(current1);
				current1=current1->left;
			}	
			else
			{
				current1=s1.top();
				s1.pop();
				val1=current1->data;
				current1=current1->right;
				done1=true;
			}	
		}	

		while(done2==false)
		{
			if(current2)
			{
				s2.push(current2);
				current2=current2->right;
			}	
			else
			{
				current2=s2.top();
				s2.pop();
				val2=current2->data;
				current2=current2->left;
				done2=true;
			}	
		}	

		if(val1+val2==sum && val1!=val2)
		{
			cout<<val1<<" "<<val2<<endl;
			return true;
		}
		else if((val1+val2)>sum)
		{
			done2=false;
		}
		else if((val1+val2)<sum)
		{
			done1=false;
		}	


		if(val1>=val2)
			return false;

	}	

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
	//int arr[]={1,2,3,4,5,6,7,8,9};
	//int size=sizeof(arr)/sizeof(arr[0]);
	//node* root=createBST(arr,0,size-1);
	int num;
	// cout<<"Enter the sum "<<endl;
	cin>>num;
	node* root=takeInput();
	bool val=findPairEqualsGivenSum1(root,num); 
	if(!val)
	{
		cout<<"-1 -1"<<endl;
	}	
	//cout<<val<<endl;
	return 0;
}