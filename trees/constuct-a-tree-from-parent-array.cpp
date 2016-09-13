#inlclude <iostream>
using namespace std;

class node
{
	int data;
	node* left;
	node* right;
public:
	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~node()
	{
		if (left)
		{
			delete left;
		}

		if (right)
		{
			delete right;
		}
	}

	void createTree(int* parent,int i,node** root,node* created[])
	{
		if (created[i]!=NULL)
		{
			return;
		}

		created[i]=new node;
		if (parent[i]==-1)
		{
			*root=created[i];
			return;
		}

		if (created[parent[i]]==NULL)
		{
			createTree(parent,parent[i],root,created);		
		}

		node* p=created[parent[i]];
		if(!p->left)
		{
			p->left=created[i];
		}	
		else
		{
			p->right=created[i];
		}	
	}
	node* constructTree(int* parent,int n)
	{
		node* created[n];
		for (int i = 0; i < n; ++i)
		{
			created[i]=NULL;
		}

		node* root=NULL;

		for (int i = 0; i < n; ++i)
		{
			createTree(parent,i,&root,created);
		}
	}
	
};



int main()
{
	return 0;
}