#include <iostream>
#include <map>
using namespace std;

class Node
{
	int data;
	Node* next;
	Node* random;
public:
	Node()
	{
		next=NULL:
		random=NULL;
	}
	~Node()
	{
		if (next)
		  delete next;
		if(random)
			delete random;
	}

	Node* cloneExtraSpace(Node* n)
	{
		Node* copy=new Node();
		Node* nCurr=n,copyCurr=copy;
		map<Node*,Node*> my_map;

		while(nCurr!=NULL)
		{
			map[nCurr]=copyCurr;
			copyCurr->next=new Node;
			nCurr=nCurr->next;
			copyCurr=copyCurr->next;

		}	

		nCurr=n;
		copyCurr=copy;

		while(nCurr)
		{
			copyCurr->random=my_map[nCurr->random];
			copyCurr=copyCurr->next;
			nCurr=nCurr->next;
		}
		return copy;	

	}


	Node* cloneNoExtraSpace(Node* n)
	{
		Node* nCurr=n;
		while(nCurr)
		{
			Node* temp=new Node;
			temp->next=nCurr->next;
			nCurr->next=temp;
			nCurr=nCurr->next->next;
		}	

		nCurr=n;

		while(nCurr)
		{
			nCurr->next->random=nCurr->random->next;
			nCurr=nCurr->next;
		}

		nCurr=n;
		Node* copy=n->next;

		while(nCurr)
		{
			Node* temp=nCurr->next;
			nCurr->next=temp->next;
			nCurr=temp;
		}

		return copy;	
	}
	
};




int main()
{
	return 0;
}