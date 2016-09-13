#include<iostream>
#include<cstring>
using namespace std;

/*
   Given two Strings check if one is reverse of the other.   
*/


bool checkIfReverse(string str1,string str2,int start,int end)
{
	if(end>0)
	{
		return (str1[start]==str2[end] && checkIfReverse(str1,str2,start+1,end-1));
	}	
}

int main()
{
	string str1="abc",str2="cab";
	int len1=str1.size();
	int len2=str2.size();
	bool check=checkIfReverse(str1,str2,0,len1-1);
	if(check)
		cout<<"Reverse "<<endl;
	else
		cout<<"Not reverse "<<endl;
	return 0;
}