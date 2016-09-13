#include<iostream>
#include<cstring>
using namespace std;


/*
   Write a recursive function to convert a String into the number it represents. e.g. for 
input “1231” you should return integer 1231.
*/

int to_int(string str,int len)
{
	if(len==0)
		return 0;

	int val=str[len-1]-'0';

	return 10*to_int(str,len-1)+val;
}

int main()
{

	string s="12321";
	int len=s.size();
	cout<<to_int(s,len)<<endl;
	return 0;
}