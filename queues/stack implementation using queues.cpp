#include <iostream>
#include <queue>
using namespace std;

/*
	push-O(1),pop-O(n)
*/

class Stack
{
	queue<int> mainQueue;
	queue<int> backQueue;

public:
	 void push(int data);
	 int top();
	 void pop();
	 bool isEmpty();
};

bool Stack::isEmpty()
{
	if(mainQueue.size()==0)
		return true;
	return false;
}

void Stack::push(int data)
{
	mainQueue.push(data);
}

void Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack Empty\n";
		return;
	}	
	else
	{	
		while(mainQueue.size()!=1)
		{
			int data=mainQueue.front();
			mainQueue.pop();
			backQueue.push(data);
		}	

		queue<int> temp=mainQueue;
		mainQueue=backQueue;
		backQueue=temp;

		backQueue.pop(); 
	}	
}

int Stack::top()
{
    if(isEmpty())
	{
		cout<<"Stack Empty\n";
		return -1;
	}	
	else
	{	
		while(mainQueue.size()!=1)
		{
			int data=mainQueue.front();
			mainQueue.pop();
			backQueue.push(data);
		}	

		queue<int> temp=mainQueue;
		mainQueue=backQueue;
		backQueue=temp;

		int data=backQueue.front(); 
		mainQueue.push(data);
		backQueue.pop();
		return data;
	}	
}

/*
	push-O(n),pop-O(1)
*/

class Stack1
{
	queue<int> mainQueue;
	queue<int> backQueue;
public:
	 void push(int data);
	 int top();
	 void pop();
	 bool isEmpty();
	
};

bool Stack1::isEmpty()
{
	if(mainQueue.size()==0)
		return true;
	return false;
}

void Stack1::push(int data)
{
	if(isEmpty())
	{
		mainQueue.push(data);
	}	
	else
	{
		backQueue.push(data);
		while(!mainQueue.empty())
		{
			int data=mainQueue.front();
			mainQueue.pop();
			backQueue.push(data);
		}	

		queue<int> temp=mainQueue;
		mainQueue=backQueue;
		backQueue=temp;
	}	
}

void Stack1::pop()
{
	if(isEmpty())
	{
		cout<<"stack is empty"<<endl;
		return;
	}
	else
	{
		mainQueue.pop();
	}	
}

int Stack1::top()
{
	if(isEmpty())
	{
		cout<<"stack is empty"<<endl;
		return -1;
	}
	else
	{
		int data=mainQueue.front();
		//mainQueue.pop();
		return data;
	}		
}

int main()
{
	Stack1 s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	s.pop();

	return 0;
}