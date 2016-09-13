#include<iostream>
#include<cstring>
using namespace std;

void printSubstring(char *s,int start,int len)
{
	for(int i=start;i<=len;i++)
	{
		cout<<s[i];
	}	

	cout<<endl;
}


void generateSubstrings(char* s,int start,int len)
{
	if(start==len)
	{
		return;
	}	

    for(int i=start;i<len;i++)
    {
         
         printSubstring(s,start,i);
    }	

    generateSubstrings(s,start+1,len);
	 
}


int main()
{
	char str[]="abcde";
	int len=strlen(str);
	generateSubstrings(str,0,len);
	return 0;
}