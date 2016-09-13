#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

void printSubstrings(string str,int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<str[i]<<endl;
		for(int j=i+1;j<=len;j++)
		{
			string str1=str.substr(i,j);
			cout<<str1<<endl;
			 //print(str,i,j)
		}	
	}	
}


int main()
{
	string str="abcdef";
    int len=str.size();
	printSubstrings(str,len);
	return 0;
}