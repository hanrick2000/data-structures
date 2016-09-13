#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

char returnRelevant(char a)
{
	if(a==')')
		return '(';
	else if(a=='}')
		return '{';
	else 
		return '[';
}

bool checkBalancedParanthesis(string str)
{
	stack<char> s;
	for(int i=0;str[i]!='\0';i++)
	{
		//cout<<str[i]<<endl;
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
		{
			s.push(str[i]);
		}	
		else if(str[i]==')' || str[i]==']' || str[i]=='}')
		{
			char x=returnRelevant(str[i]);
			bool found=false;
			if(s.empty())
			{
				return false;
			}	
			else if(s.top()==x)
			{	
				found=true;
			//	cout<<"directly found "<<s.top()<<endl;
				s.pop();
			} 
			if(!found)
			{	
				return false;	
			} 
		} 	
	}

	if(!s.empty())
		return false;
	return true;

}


int main()
{
	// string str="()(())";
	// string str1="[{(})]";
	// string exp1 = "[()]{}{[()()]()}";
	string str;
	cin>>str;
	bool val=checkBalancedParanthesis(str);
	cout<<val<<endl;
	return 0;
}