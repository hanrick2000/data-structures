#include<iostream>
#include<cstring>
using namespace std;

/*
Given   a   string,   compute   recursively   a   new   string   where   identical   chars   that   are  
adjacent in the original string are separated from each other by a "*". 
pairStar("hello") → "hel*lo" 
pairStar("xxyy") → "x*xy*y" 
pairStar("aaaa") → "a*a*a*a" 

*/

string changeToStars(string str,int start,int len)
{
	if(start==len)
		return str;

	if(str[start]==str[start+1])
	{
       string str1=str.substr(0,start+1);
       string str2=str.substr(start+1,len);
       str=str1+'*'+str2;
       len++;
	}	

	return changeToStars(str,start+1,len);

}

int main()
{   
	string str="aaaaa";
	int len=str.size();
	cout<<changeToStars(str,0,len)<<endl;
	return 0;
}