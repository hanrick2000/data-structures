#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

/*
 Given a binary tree, check whether there are two nodes in it whose sum equals a given 
value. 
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
	{
		cout<<"-1"<<endl;	
		return;
	}	

	queue<BinaryTree*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();

		if(q.empty())
		{
			break;
		}	
		else if(temp==NULL)
		{
			cout<<endl;
			q.push(NULL);
		}	
		else
		{	
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
	cout<<endl;	
}

/*  solution 1*/
int findPairEqualsGivenSumHelper(BinaryTree* root,int val)
{
	if(root==NULL)
		return -1;

	if(root->data==val)
		return root->data;

	findPairEqualsGivenSumHelper(root->left,val);
	findPairEqualsGivenSumHelper(root->right,val);
}


void findPairEqualsGivenSum(BinaryTree* root,int sum)
{
	if(root==NULL)
	{	//cout<<"Not found"<<endl;
		return;
	}	

	int val1=root->data;
	int val2=findPairEqualsGivenSumHelper(root->left,sum-val1);
	int val22=findPairEqualsGivenSumHelper(root->right,sum-val1);

	if(val2!=-1)
	{
		cout<<val1<<" "<<val2<<endl;
		//return;
	}	
	else if(val22!=-1)
	{
		cout<<val1<<" "<<val22<<endl;
		//return;
	}	

	findPairEqualsGivenSum(root->left,sum);
	findPairEqualsGivenSum(root->right,sum);

}

/* solution 2 ,a little better!*/

void findPairEqualsGivenSumHelper1(BinaryTree* root,map<int,bool> &my_map)
{
	if(root==NULL)
		return;
	
	my_map[root->data]=true;
	findPairEqualsGivenSumHelper1(root->left,my_map);
	findPairEqualsGivenSumHelper1(root->right,my_map);

}


void findPairEqualsGivenSum1(BinaryTree* root,int sum)
{
	map<int,bool> my_map;
	findPairEqualsGivenSumHelper1(root,my_map);

	 map<int,bool>::iterator it,it1;


	 // for(it=my_map.begin();it!=my_map.end();it++)
	 // {
	 // 	int val=it->first;
	 // 	cout<<val<<endl;

	 // }	

	 for(it=my_map.begin();it!=my_map.end();it++)
	 {
	 	int val=it->first;
	 	if(my_map[sum-val]==true && sum-val!=val)
	 	{
	 		cout<<val<<" "<<sum-val<<endl;
	 		my_map[sum-val]=false;
	 		my_map[val]=false;
	 	}	

	  }

	 //  for(it=my_map.begin();it!=my_map.end();it++)
	 // {
	 // 	int val=it->first;
	 // 	int val2=sum-val;
	 // 	for(it1=it+1,it!=my_map.end();it++)
	 // 	{
	 // 		if(it1->first==val2)
	 // 			return true;
	 // 	}	

	 //  }		

	 //  return false;

}


void findPairEqualsGivenSumHelper2(BinaryTree* root,map<int,bool> &my_map)
{
	if(root==NULL)
		return;
	
	my_map[root->data]=true;
	findPairEqualsGivenSumHelper1(root->left,my_map);
	findPairEqualsGivenSumHelper1(root->right,my_map);

}


bool findPairEqualsGivenSum2(BinaryTree* root,int sum)
{
	map<int,bool> my_map;
	findPairEqualsGivenSumHelper1(root,my_map);

	 map<int,bool>::iterator it,it1;

	  for(it=my_map.begin();it!=my_map.end();it++)
	 {
	 	int val=it->first;
	 	int val2=sum-val;
	 	it1=it;
	 	it1++;
	 	for(;it1!=my_map.end();it1++)
	 	{
	 		if(it1->first==val2)
	 		{	
	 			//cout<<val<<" "<<val2<<endl;
	 			return true;
	 		}	
	 	}	

	  }		

	 return false;

}
 
int main()
{
	//cout<<"Enter sum to be found"<<endl;
	int num;
	cin>>num;
	//cout<<"Enter tree"<<endl;
	BinaryTree* root=takeInput();
	//printTree(root);
	
	//findPairEqualsGivenSum1(root,num);
 	 bool val=findPairEqualsGivenSum2(root,num);
 	 cout<<val<<endl;
	 
	return 0;
}