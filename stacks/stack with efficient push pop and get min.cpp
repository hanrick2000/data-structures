#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

/*using a main stack and an auxillary stack
  Basically try and keep both the heights equal!
*/

class Efficient
{
	stack<int> mainStack;
	stack<int> auxStack; /*this maintains the min*/
public:
 	void push(int data);
 	int pop();
 	int getMin();
};


void Efficient::push(int data)
{
	if(mainStack.empty())
	{
		mainStack.push(data);
		auxStack.push(data);
	}	
	else
	{
		if(data<auxStack.top())
		{
			auxStack.push(data);
		}
		else
		{
			auxStack.push(auxStack.top());
		}	

		mainStack.push(data);
	}	
}

int Efficient::pop()
{
	if(!mainStack.empty())
	{	
		int data=mainStack.top();
		mainStack.pop();
		auxStack.pop();
		return data;
	}	
	else
	{
		cout<<"Stack empty"<<endl;
		return -1;
	}	
	 
}

int Efficient::getMin()
{	
	if(!auxStack.empty())
	{
		int val=auxStack.top();
		return val;
	}
	else
	{
		cout<<"stack empty"<<endl;
		return -1;
	}	
}



/*
   without using an auxillary stack.
*/

   

int main()
{
	//18, 19, 29, 15 and 16

	Efficient s;
	s.push(18);
	s.push(19);
	s.push(29);
	s.push(15);
	s.push(16);

	cout<<s.getMin()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.getMin()<<endl;
	return 0;
}