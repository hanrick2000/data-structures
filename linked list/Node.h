#include<iostream>
using namespace std;
template<typename T>

class Node
{
public:
	T data;
	Node* next;
	Node(T data)
	{
		this->data=data;
		next=NULL;
	}
	~Node()
	{
		if(next)            /*This is behaves like a recursive call*/
			delete next;
	}
	
};