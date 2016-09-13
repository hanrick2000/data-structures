#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*
 Given a binary tree print all nodes that don’t have a sibling. 
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
 
//Method 1 O(n)

int maxWidth(BinaryTree* root)
{
	int maximum=1;
	if (root==NULL)
	{
		return -1;
	}

	queue<BinaryTree*> q;
	q.push(root);
	q.push(NULL);
	int count=0;
	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		if (q.empty())
		{
			break;
		}
		else if (temp==NULL)
		{
			q.push(NULL);
			if(maximum<count)
			{
				maximum=count;
			}	

			count=0;
		}
		else
		{
			if (temp->left)
			{
				q.push(temp->left);
				count++;
			}

			if (temp->right)
			{
				q.push(temp->right);
				count++;
			}
		}	
	}	

	return maximum;

} 
 

 int height(BinaryTree* root)
 {
 	if (root==NULL)
 	{
 		return 0;
 	}

 	return 1+max(height(root->left),height(root->right));
 }

/*Method 2 (Using Preorder Traversal)
 O(n)
In this method we create a temporary array count[] of size equal to the height of tree. We 
initialize all values in count as 0. We traverse the tree using preorder traversal and fill the 
entries in count so that the count array contains count of nodes at each level in Binary Tree.*/

void getMaxWidthHelper(BinaryTree* root,int* count,int level)
{
	if (root)
	{
		count[level]++;
		getMaxWidthHelper(root->left,count,level+1);
		getMaxWidthHelper(root->right,count,level+1);
	}
}


int getMaxWidth(BinaryTree* root)
{
	if (root==NULL)
	{
		return -1;
	}

	int h=height(root);
	int *count=new int[h];
	memset(count,0,sizeof(count));

	getMaxWidthHelper(root,count,0);

	int max_width=INT_MIN;

	for (int i = 0; i < h; ++i)
	{
		if (count[i]>max_width)
		{
			max_width=count[i];
		}		
	}

	return max_width;

}




int main()
{
	BinaryTree* root=takeInput();
	printTree(root);
	cout<<endl;
	cout<<maxWidth(root);
	 	 
	return 0;
}