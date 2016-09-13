#include <iostream>
#include <map>
using namespace std;

class Node
{
public:	
	int data;
	Node* parent;
	int rank;	
};

class disjoint
{
	Node *node;
	map<int,Node*> my_map;
public:

    /**
     * Create a set with only one element.
     */
	void makeSet(int data)
	{
		node=new Node;
		node->data=data;
		node->parent=node;
		node->rank=0;
		my_map[data]=node;
	}

	bool union(int data1,int data2)
	{
		Node* parent1=my_map[data1];
		Node* parent2=my_map[data2];

		if (parent1.data==parent2.data)
		{
			return false; //Both are in the same set
		}

		if (parent1.rank>=parent2.rank)
		{
			parent1.rank=parent1.rank==parent2.rank?1+parent1.rank:parent1.rank;
			parent2.parent=parent1;
		}
		else
		{
			parent1.parent=parent2;
		}

		return true;	
	}

private:
	Node* findSet(Node* node)
	{
		Node* parent=node.parent;
		//node starts pointing to itself
		if (parent==node.parent)
		{
			return parent;
		}	

		node.parent=findSet(node.parent);
		return node.parent;
	}

public:
	int findSet(int data)
	{
		Node* parent=findSet(my_map[data]);
		return my_map[parent];
	}

	
};

int main()
{

	return 0;
}