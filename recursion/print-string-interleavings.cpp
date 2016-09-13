#include <iostream>
#include <cstring>
using namespace std;

/*
Given two strings, print all the inter-leavings of the Strings in which characters from two strings should be in same order as they were in original strings. 

e.g. 
for "abc", "de", print all of these: 
adebc, abdec, adbce, deabc, dabce, etc, etc
*/

void printPermutations(string str1,string str2,int start1,int start2,string temp)
{
	if (start1==str1.length() && start2==str2.length())
	{
		cout<<temp<<endl;
		return;
	}

	if(start1 < str1.length())
	{	
		printPermutations(str1,str2,start1+1,start2,temp+str1[start1]);
	}	

	if(start2 < str2.length())
	{	
		printPermutations(str1,str2,start1,start2+1,temp+str2[start2]);
	}			

}
int main()
{
	string str1="abc",str2="de";
	string temp="";
	printPermutations(str1,str2,0,0,temp);
	return 0;
}