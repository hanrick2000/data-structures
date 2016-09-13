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
	int count=0; 
	for(int i=0;str[i]!='\0';i++)
	{
		//cout<<"str[i] "<<str[i]<<endl;
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
						if(isalpha(s.top()))
							count++;
						s.pop();
						            //count for cases like {a+b+(c)}.Here c has duplicate paranthesis.
					}
					//cout<<count<<endl;
					if(count==1)
						return true;
					count=0;

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
						if(isalpha(s.top()))
							count++;
						s.pop();
						 
					}

					if(count==1)
						return true;
					count=0;

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
						if(isalpha(s.top()))
							count++;
						s.pop();
					}

					if(count==1)
						return true;
					count=0;

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