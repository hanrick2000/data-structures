#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool checkIfPalindromeUtil(char *a,int start,int end)
{
	if(start<end)
	{
		//cout<<"start "<<start<<" end "<<end<<" a[start] "<<a[start]<<" a[end] "<<a[end]<<endl;
		return (a[start]==a[end] && checkIfPalindromeUtil(a,start+1,end-1));
	}	
}


bool checkIfPalindrome(char* a,int len)
{
   if(len==0 || len==1)
   	  return true;
   	return checkIfPalindromeUtil(a,0,len-2);
}


int main()
{
	// char a[]="abba";
	//char a[]="abcba";
    char a[]="ababc";
    int len=sizeof(a);
    cout<<len<<endl;
	bool val=checkIfPalindrome(a,len);
	if(val)
		cout<<"Palindrome "<<endl;
	else
		cout<<"Not a palindrome "<<endl;
	return 0;
}