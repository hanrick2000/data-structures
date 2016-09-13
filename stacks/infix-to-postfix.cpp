#include<iostream>
#include<cstring>
#include<cctype>
#include<stack>
using namespace std;


int precedance(char a)
{
	switch(a)
	{
		case '+':
		case '-':
		    return 1;
		case '*':
		case '/':
			return 2;
		case '^':	    
			return 3;
	}

	return -1;
}

bool isOperator(char x)
{
	if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
		return true;
	return false;
}

void infixToPostfix(string &str)
{
	stack<char> s;
	int count=0;
	for (int i = 0; i < str.length(); ++i)
	{
		//cout<<str[i]<<endl;
		if(isalpha(str[i]))
		{
			//cout<<"Entering alpha "<<endl;
			//str[count]=str[i];
			cout<<str[i];
			count++;
		}
		else
		{
			//cout<<"entering else loop "<<endl;

			if(str[i]=='(')
			{
				s.push(str[i]);
			}	
			else if(isOperator(str[i]))
			{
				//cout<<"operator encountered\n";

				if(s.empty())
				{
					//cout<<"stack empty,simply push\n";
					s.push(str[i]);
				}	
				else if(precedance(str[i])>=precedance(s.top()))
				{
					//cout<<"precedance in string is greater than the stack top\n";
					s.push(str[i]);
				}	
				else
				{
					//cout<<"precedance in string is less than the stack top\n";
					while( (precedance(str[i])<precedance(s.top())))
					{
						//cout<<"Entering loop"<<endl;
						cout<<s.top();

						char val=s.top();
						str[count++]=val;
						s.pop();

						if(s.empty())
						   break;
					}	

					s.push(str[i]);

				}	
			}	
			else if(str[i]==')')
			{
				while(s.top()!='(')
				{
					char val=s.top();
					cout<<val;
					str[count++]=val;
					s.pop();
				}

				s.pop();	
			}	
		}		
	}

	while(!s.empty())
	{
		//cout<<"finally emptying the stack"<<endl;
		char val=s.top();
		cout<<val;
		str[count++]=val;
		s.pop();
	}	
	cout<<endl;
	//cout<<"the size of string is "<<count<<endl;

	//str[count]='\0';
}

int main()
{
	string str="(A + B)*C-(D-E)*(F+G)";
	//string str="(A + B) * (C + D)";
	infixToPostfix(str);
	//cout<<str<<endl;	
	return 0;
}