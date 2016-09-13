#include<iostream>
#include<cstdio>
using namespace std;

class Stack
{
	int topIndex;
	int* arr;
	int capacity;
public:
	Stack(int capacity)
	{
      this->capacity=capacity;
      topIndex=-1;
      arr=new int[capacity];
	}
	~Stack()
	{
		delete arr;
	}

	void push(int data);
	void pop();
	int top();
	bool isEmpty();

};

bool Stack::isEmpty()
{
	if(topIndex==-1)
		return true;
	return false;
}

void Stack::push(int data)
{
cout<<"push function"<<endl;	

	if(topIndex==capacity-1)
	{
		cout<<"Stack overflow"<<endl;
	}	
	else
	{
		cout<<"pushing "<<data<<endl;
		arr[++topIndex]=data;
	}	
}

void Stack::pop()
{
	cout<<"pop function"<<endl;
	if(!isEmpty())
	{
		cout<<"popping out"<<endl;
		topIndex--;
	}	
	else
	{
		cout<<"Stack is empty"<<endl;
	}	
}

int Stack::top()
{
	cout<<"top function"<<endl;
	if(!isEmpty())
	{

		//cout<<arr[topIndex]<<endl;
		return arr[topIndex];
	}
	else
	{
		cout<<"Stack is empty"<<endl;
		return -1;
	}	
}




int main()
{
	int capacity=10;
	Stack s(capacity);
	s.push(1);
	s.push(2);
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.top()<<endl;

	return 0;
}