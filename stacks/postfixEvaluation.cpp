#include<iostream>
#include<cstring>
#include<stack>
#include<cctype>
using namespace std;


/*
  Evaluating a postfix expression.
*/

int result(string str)
{
    stack<int> s;
    int val1;
    int val2;

    for(int i=0;str[i]!='\0';i++)
    {
    	if(isdigit(str[i]))
    	{
    		s.push(str[i]-'0');
    	}	
    	else
    	{
    		char op=str[i];

    		int val2=s.top();
    		s.pop();
    		int val1=s.top();
    		s.pop();
    		int result;
    		if(op=='+')
    		{
    			result=val1+val2;
    		}	
    		else if(op=='-')
    		{
    			result=val1-val2;
    		}
    		else if(op=='*')
    		{
    			result=val1*val2;
    		}	
    		else if(op=='/')
    		{
    			result=val1/val2;
    		}

    		s.push(result);

    	}	
    }	

    return s.top();
}

int main()
{
	string str="231*+9-";
	int val=result(str);
	cout<<val<<endl;
	return 0;
}