#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*

Suppose you have a string made up of only the letters 'a' and 'b'. Write a recursive
function that checks if the string was generated using the following rules:
a. the string begins with an 'a'
b. each 'a' is followed by nothing or an 'a' or "bb"
c. each "bb" is followed by nothing or an 'a

*/


bool checkStringHelper(char* str,int start,int len)
{
	cout<<"start: "<<start<<endl;
	if(str[start]=='\0')
	{
		cout<<"blank condition";
		return true;
	}	

	if(str[start]=='a')
	{
		cout<<"a condition"<<endl;
		if(str[start+1]=='a' || str[start+1]=='\0')
		{
			cout<<"aa condition"<<endl;
			return checkStringHelper(str,start+1,len);
		}
		else if(str[start+1]=='b' && str[start+2]=='b')
		{
			cout<<"abb condition"<<endl;
			return checkStringHelper(str,start+2,len);
		} 	
		else
		{ 
			cout<<"post a false condition"<<endl;
			return false;
		}	

	}
	else if(str[start]=='b')
	{
		cout<<"b condition"<<endl;
		if(str[start+1]=='a'|| str[start+1]=='\0')
		{
			cout<<"ba condition"<<endl;
			return checkStringHelper(str,start+1,len);
		}	
		else
		{	
			cout<<"post b false condition"<<endl;
			return false;
		}
	}		
	else
	{
		cout<<"No condition satisfied\n";
		return false;
	}	

}

bool checkString(char* str,int start,int len)
{	
	if(str[0]!='a')
	{	
		 cout<<"check string\n";
		return false;
	}	

	return checkStringHelper(str,start,len);

	 

}

int main()
{
	char str[]="ba";
	int len=strlen(str);
	bool val=checkString(str,0,len);
	cout<<endl;
	cout<<val<<endl;
	return 0;
}
