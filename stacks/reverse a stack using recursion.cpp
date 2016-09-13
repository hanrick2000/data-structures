#include<iostream>
#include<stack>
using namespace std;


/*reverse a stack without using another stack*/
//Indirectly using stack of the function call
void insertAtBottom(stack<int> &s1,int data)
{
	if(s1.empty())
	{
		s1.push(data);
	}	
	else
	{
		int temp=s1.top();
		s1.pop();
		insertAtBottom(s1,data);
		s1.push(temp);
	}	
}


void reverseStack1(stack<int> &s1)
{
	if(!s1.empty())
	{
		int topVal=s1.top();
		s1.pop();
		reverseStack1(s1);
		insertAtBottom(s1,topVal);
	}	
}	


/*reverse a stack using another stack*/
void reverseStack(stack<int> &s1,stack<int> s2)
{
	if(s1.empty())
		return;

	int topVal=s1.top();
	s1.pop();
	reverseStack(s1,s2);

	while(!s1.empty())
	{
		int val=s1.top();
		s1.pop();
		s2.push(val);
	}	

	s1.push(topVal);

	while(!s2.empty())
	{
		int val=s2.top();
		s2.pop();
		s1.push(val);
	}	

}


int main()
{
	stack<int> s1;
	stack<int> s2;

	// int i=6;
	// while(i--)
	// {
	// 	s1.push(i);
	// }

	s1.push(1);
	s1.push(2);
	s1.push(3);	

	//reverseStack(s1,s2);
	reverseStack1(s1);

	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}	

	return 0;
}