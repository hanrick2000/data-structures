#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

/*
	remove all balanced paranthesis.Then ceil('{')/2 + ceil('}')/2

*/

int calculateReversals(string str)
{
	stack<char> s;
	int countL=0;
	int countR=0;
    if(str.length()%2!=0)
    	return -1;

	for(int i=0;str[i];i++)
	{
		cout<<str[i]<<endl;
		if(str[i]=='{')
		{
			s.push(str[i]);
			
		}
		else
		{
			if(!s.empty())
			{	
				if(s.top()=='{')
				{
					s.pop();
					cout<<"popped"<<endl;
				}
				else
				{
					s.push(str[i]);
				}	
			}	
			else
			{
				cout<<"pushing"<<endl;
				s.push(str[i]);
			}	
		}	
	}	

	while(!s.empty())
	{
		if(s.top()=='{')
			countL++;
		else
		    countR++; 	
		s.pop();    	
	}	
    

	return ceil(countR/2)+ceil(countL/2);

}

int main()
{
	string str="}}}}{{";
	cout<<str<<endl;
	int val=calculateReversals(str);
	cout<<val<<endl;
	return 0;
}