#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*
  Given preorder and inorder create the tree, given postorder and inorder create the tree. 
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

void preorder(BinaryTree* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


void postorder(BinaryTree* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
 
int search(int *arr,int low,int high,int toBeFound)
{
	 for(int i=low;i<=high;i++)
	 {
	 	if(arr[i]==toBeFound)
	 		return i;
	 }	
	 return -1;
}

/*preorder inorder reference*/
BinaryTree* createTree(int* inorder,int* preorder,int inorderStart,int inorderEnd,int &preorderIndex)
{
	//base cases

	// if(preorderIndex>=len)
	// 	return NULL;
	if(inorderStart>inorderEnd)
		return NULL;

	BinaryTree* node=new BinaryTree; 	
	int rootData=preorder[preorderIndex++];
	//cout<<preorderIndex<<endl;
	node->data=rootData;

	if(inorderStart==inorderEnd)
	{
    	return node;	
	}	
	
	
	
	int index=search(inorder,inorderStart,inorderEnd,rootData);
	cout<<"The current index is "<<index<<endl;

	node->left=createTree(inorder,preorder,inorderStart,index-1,preorderIndex);
	node->right=createTree(inorder,preorder,index+1,inorderEnd,preorderIndex);

	return node;
	
}


/*preorder inorder static*/
BinaryTree* createTree3(int* inorder,int* preorder,int inorderStart,int inorderEnd)
{
	//base cases
	static int preorderIndex=0;
	// if(preorderIndex>=len)
	// 	return NULL;
	if(inorderStart>inorderEnd)
		return NULL;

	BinaryTree* node=new BinaryTree; 	
	int rootData=preorder[preorderIndex++];
	node->data=rootData;

	if(inorderStart==inorderEnd)
	{	//node->left=NULL;
	// 	node->right=NULL;
		return node;	
	}	
	
	
	
	int index=search(inorder,inorderStart,inorderEnd,rootData);
	//cout<<"The current index is "<<index<<endl;

	node->left=createTree3(inorder,preorder,inorderStart,index-1 );
	node->right=createTree3(inorder,preorder,index+1,inorderEnd);

	return node;
	
}

/*postorder inorder reference*/
BinaryTree* createTree2(int* inorder,int* postorder,int inorderStart,int inorderEnd,int &postorderIndex)
{	

	if(inorderStart>inorderEnd)
		return NULL;

	BinaryTree* node= new BinaryTree;
	int rootData=postorder[postorderIndex--];
	node->data=rootData;

	if(inorderStart==inorderEnd)
		return node;

	int index=search(inorder,inorderStart,inorderEnd,rootData);

    node->right=createTree2(inorder,postorder,index+1,inorderEnd,postorderIndex);
	node->left=createTree2(inorder,postorder,inorderStart,index-1,postorderIndex);
	
	return node;

}

/*postorder inorder static*/
BinaryTree* createTree4(int* inorder,int* postorder,int inorderStart,int inorderEnd)
{	

	if(inorderStart>inorderEnd)
		return NULL;

	static int postorderIndex=inorderEnd;

	BinaryTree* node= new BinaryTree;
	int rootData=postorder[postorderIndex--];
	node->data=rootData;

	if(inorderStart==inorderEnd)
		return node;

	int index=search(inorder,inorderStart,inorderEnd,rootData);

	node->right=createTree4(inorder,postorder,index+1,inorderEnd);
	node->left=createTree4(inorder,postorder,inorderStart,index-1);
	return node;

}

/*postorder inorder pointer*/
BinaryTree* createTree5(int* inorder,int* postorder,int inorderStart,int inorderEnd,int *postorderIndex)
{	

	if(inorderStart>inorderEnd)
		return NULL;

	BinaryTree* node= new BinaryTree;
	int rootData=postorder[(*postorderIndex)--];
	node->data=rootData;

	if(inorderStart==inorderEnd)
		return node;

	int index=search(inorder,inorderStart,inorderEnd,rootData);

    node->right=createTree5(inorder,postorder,index+1,inorderEnd,postorderIndex);
	node->left=createTree5(inorder,postorder,inorderStart,index-1,postorderIndex);
	
	return node;

}




int main()
{
	//BinaryTree* root=takeInput();
	//printTree(root);
	//cout<<endl;

	// int preorder[]={1,2,4,5,3,6,7};
	// int inorder[]={4,2,5,1,6,3,7};
	// int postorder[]={4,5,2,6,7,3,1};
	// int size=sizeof(inorder)/sizeof(inorder[0]);
	int size;
	cin>>size;
	int *preorder=new int[size];
	int *inorder=new int[size];
	for(int i=0;i<size;i++)
	{
		cin>>preorder[i];
	}	

	for(int i=0;i<size;i++)
	{
		cin>>inorder[i];
	}	

	int start=0;
	//BinaryTree* root=createTree(inorder,preorder,0,size-1,start);
	int postOrderEnd=size-1;
	//BinaryTree* root1=createTree2(inorder,postorder,0,size-1,postOrderEnd);
	BinaryTree* root=createTree3(inorder,preorder,0,size-1);
	//BinaryTree* root2=createTree5(inorder,postorder,0,size-1,&postOrderEnd);
	printTree(root);

	 
	return 0;
}