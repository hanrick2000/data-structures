#include<iostream>
#include<queue>
using namespace std;

class Stack
{
	queue<int> q;
public:
	void push(int data);
	void pop();
	int top();	
};

void Stack::push(int data)
{
	q.push(data);

	for(int i=0;i<q.size();i++)
	{
		q.push(q.front());
		q.pop();
	}	
}


void Stack::pop()
{
	q.pop();
}

int Stack::top()
{
	int data=q.front();
	//q.pop();
	return data;
}


int main()
{
	return 0;
}
