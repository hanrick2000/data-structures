#include <iostream>
#include <queue>
using namespace std;

class Node
{
  public:
	int data;
	Node* next;
	Node()
	{
		next=NULL;
	}
};


class BinaryTreeNode
{
public:
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode()
	{
		left=NULL;
		right=NULL;
	}
};

Node* takeInputLL()
{
	Node *head=NULL,*tail=NULL;
	int data;
	cin>>data;
	while(data!=-1)
	{
		Node* new_node=new Node;
		new_node->data=data;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
			tail=new_node;
		}	
		else
		{
			tail->next=new_node;
			tail=new_node;
		}	

		cin>>data;
	}	

	return head;
}


void printTree(BinaryTreeNode* root)
{
	if(root==NULL)
	{
		cout<<"-1";
		return;
	}	

	queue<BinaryTreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		BinaryTreeNode* temp=q.front();
		q.pop();

		if(q.empty())
		{
			cout<<endl;
			break;
		}	
		else if(temp==NULL)
		{
			q.push(NULL);
			cout<<endl;
		}	
		else
		{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}	
	}	
}

//O(n) solution,the construction is done from leaves to root

BinaryTreeNode* sortedLLToBSTHelper(Node** head,int n)
{
	//cout<<"Entering "<<n<<endl;
	if(n<=0)
		return NULL;

	BinaryTreeNode* left=sortedLLToBSTHelper(head,n/2);

	BinaryTreeNode* root=new BinaryTreeNode;
	root->data=(*head)->data;
	//cout<<root->data<<endl;
	root->left=left;
	(*head)=(*head)->next;

	root->right=sortedLLToBSTHelper(head,n-n/2-1);

	return root;
}

BinaryTreeNode* sortedLLToBST(Node* head)
{
	int count=0;
	Node* current=head;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}	

	//cout<<"The count is "<<count;
	//return NULL;
	return sortedLLToBSTHelper(&head,count);
}

void printLL(Node* head)
{
	Node* current=head;
	while(current!=NULL)
	{
		cout<<current->data<<"->";
		current=current->next;
	}	

}

int main()
{
	Node* head=takeInputLL();
	BinaryTreeNode* root=sortedLLToBST(head);
	//printLL(head);
	printTree(root);
	return 0;
}