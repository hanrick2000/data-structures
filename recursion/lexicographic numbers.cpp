#include<iostream>
#include<cstdio>
using namespace std;

/*

Given   a   number   n.   Print   all   numbers   from   1   to   n   in   lexicographical   order.   i.e.  
1,10,100,1000,101,102.....etc.

*/

 
void printPatternHelper(int m,int n)
{
	if(m<=n)
		cout<<m<<endl;

	if(m>n)
	{
		return;
	}
	

	for(int i=0;i<=9;i++)
	{
		printPatternHelper(10*m+i,n);
	}

	 	
}


void printPattern(int n)
{


	for(int i=1;i<=9;i++)
	{
		printPatternHelper(i,n);
	}	
     
}


int main()
{
	int n;
	cin>>n;
	printPattern(n); 
	return 0;
}