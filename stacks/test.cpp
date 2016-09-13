#include<iostream>
#include<stack>
#include<map>
using namespace std;


bool checkForParanthesis(string str)
{
	map<char,bool> my_map;
	my_map[')']=true;
	my_map['}']=true;
	my_map[']']=true;
	stack<char> s;
	int i;
	for(int i=0;str[i]!='\0';i++)
	{
		if(my_map[str[i]]==false)
		{
			s.push(str[i]);
		}	
		else
		{
			//bool first=true;
			if(str[i]==')')
			{
				if(s.top()=='(')
				{
					return true;
				}	
				else
				{	
					while(s.top()!='(')
					{
						s.pop();
					}

					s.pop();
				}		
			}	
			else if(str[i]=='}')
			{
				if(s.top()=='{')
				{
					return true;
				}	
				else
				{	
					while(s.top()!='{')
					{
						s.pop();
					}

					s.pop();
				}		
			}	
			else
			{
				if(s.top()=='[')
				{
					return true;
				}	
				else
				{	
					while(s.top()!='[')
					{
						s.pop();
					}

					s.pop();
				}		
			}	
		}	
	}

	return false;	
}
int main()
{
	//Assume that it is balanced!
	//string str="((a+b)+(b+c))";
	//string str="(a+((b+c))+d)";
	string str;
	cin>>str;
	bool val=checkForParanthesis(str);
	cout<<val<<endl;
	return 0;
}