#include<iostream>
#include<stack>
using namespace std;

/*
	enqueue-O(1),dequeue-O(n)
*/

class Queue
{
public:
	stack<int> s1;
	stack<int> s2;
	void enQueue(int data);
	void deQueue();
	int front();
};


void Queue::enQueue(int data)
{
	s1.push(data);
}

void Queue::deQueue()
{
	while(!s1.empty())
	{
		int val=s1.top();
		s1.pop();
		s2.push(val);
	}	

	if(!s2.empty())
	{ 
		s2.pop();
	}	
	else
	{
		cout<<"Queue is empty"<<endl;
	}	
}

int Queue::front()
{
	while(!s1.empty())
	{
		int val=s1.top();
		s1.pop();
		s2.push(val);
	}	

	if(!s2.empty())
	{
		int val=s2.top();
		return val;
	}	
	else
	{
		cout<<"Queue is empty"<<endl;
		return -1;
	}	
}

/*
	enqueue-O(n),dequeue-O(1)
*/

class Queue1
{
	stack<int> s1,s2;
public:
	void enQueue(int data);
	void deQueue();
	int front(); 
	
};


void Queue1::enQueue(int data)
{
	if(s1.empty())
	{
		s1.push(data);
	} 
    else
    {	
		while(!s1.empty())
		{
			int val=s1.top();
			s1.pop();
			s2.push(val);
		}	

		s1.push(data);

		while(!s2.empty())
		{
			int val=s2.top();
			s2.pop();
			s1.push(val);
		}
	}		

}

void Queue1::deQueue()
{
	if(!s1.empty())
		s1.pop();
	else
	{
		cout<<"Queue is empty\n";
	}	
}

int Queue1::front()
{
	if(!s1.empty())
	{	
		int val=s1.top();
		//s1.pop();
		return val;
	}	
	else
	{
		cout<<"Queue is empty\n";
	}	
}


int main()
{
	Queue1 q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	cout<<q.front()<<endl;
	q.deQueue();
	cout<<q.front()<<endl;
	q.deQueue();

	return 0;
}