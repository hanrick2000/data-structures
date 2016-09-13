#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T> 
class TreeNode
{
	T data;
	vector<TreeNode*> children;

public:
	TreeNode(T data)
	{
		this->data=data;
	}
	~TreeNode()
	{
		for(int i=0;i<children.size();i++)
		{
			delete children.at(i);
		}	
	}

	T getdata()
	{
		return data;
	}

	void setData(T data)
	{
		this->data=data;
	}

	void addChild(TreeNode<int>* child)
	{
		children.push_back(child);
	}

	TreeNode<int>* getChild(int i)
	{
		if(i>children.size()-1)
		{
			throw "out of bound";
		}	

		return children.at(i);
	}

	void setChild(int i,TreeNode<int>* child)
	{
	   if(i>children.size()-1)
		{
			throw "out of bound";
		}	
		
		children[i]=child;	
	}
 
	int numChildren()
	{
		return children.size();
	}
};

/*recursively*/
TreeNode<int>* takeInput()
{
	int rootData;
	cout<<"Enter the root data"<<endl;
	cin>>rootData;
	TreeNode<int> *root=new TreeNode<int>(rootData);
	int numChildren;
	cout<<"Enter the number of children"<<endl;
	cin>>numChildren;
	for(int i=0;i<numChildren;i++)
	{
		root->addChild(takeInput());
	}	

	return root;
}
/*recursive printing*/
void printTree(TreeNode<int>* root)
{
	cout<<root->getdata();
	for(int i=0;i<root->numChildren();i++)
	{
		cout<<root->getChild(i)->getdata()<<",";
	}	
	cout<<endl;
	for(int i=0;i<root->numChildren();i++)
	{
		printTree(root->getChild(i));
	}	
}

/*Level wise input*/

TreeNode<int>* takeInputLevelWise()
{
	int data;
	//cout<<"Enter the root data"<<endl;
	cin>>data;
	queue<TreeNode<int>*> q;
	TreeNode<int>* root=new TreeNode<int>(data);
	q.push(root);

	while(!q.empty())
	{
		TreeNode<int>* temp=q.front();
		q.pop();
		int num;
		//cout<<"Enter the number of children for "<<temp->getdata()<<endl;
		cin>>num;

		for(int i=0;i<num;i++)
		{
			//cout<<"enter the "<<i<<" child of "<<temp->getdata();
			int childData;
			cin>>childData;
			TreeNode<int>* new_node=new TreeNode<int>(childData);
			temp->addChild(new_node);
			q.push(new_node);
		}	

	}	

	return root;
}


void printTreeLevelWise(TreeNode<int>* root)
{
	if(root==NULL)
		return;
	queue<TreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		TreeNode<int>* temp=q.front();
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
			cout<<temp->getdata()<<" ";
			for(int i=0;i<temp->numChildren();i++)
			{
				if(temp->getChild(i))
					q.push(temp->getChild(i));
			}
		}		
	}	
}

/*Generally no base case required*/
int maxDepth(TreeNode<int>* root)
{
	int maxD=0;
	for(int i=0;i<root->numChildren();i++)
	{
		maxD=max(maxD,maxDepth(root->getChild(i)));
	}

	return maxD+1;
}

int largestElement(TreeNode<int>* root)
{
	int largest=root->getdata();
	for(int i=0;i<root->numChildren();i++)
	{
		largest=max(largest,largestElement(root->getChild(i)));
	}	

	return largest;
}

int main()
{
	TreeNode<int>* root=takeInputLevelWise();
	//printTreeLevelWise(root);
	//int val=maxDepth(root);
	int val=largestElement(root);
	cout<<val<<endl;
	return 0;
}