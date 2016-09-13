#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;

/*
   find the minimum length substring(order of characters doesn't matter)
   s="this is a test string"
   t="tist"
   result: "t stri"

*/


void findMinLengthSubstring(string s,string t,int slen,int tlen)
{
	int freq[256]={0},i;
	int uniqueChar=0;
	for(i=0;i<tlen;i++)
	{
		freq[t[i]]++;
		if(freq[t[i]]==1)
			uniqueChar++;
	}	

	i=0;
	int j=0,minLen=INT_MAX,start=-1;
	while(i<slen && j<slen)
	{

		if(uniqueChar>0)
		{	
			cout<<"current char "<<s[j]<<endl;
				
				freq[s[j]]--;

				if(freq[s[j]]==0)
				{
					uniqueChar--;

				}	
				//cout<<"unique characters "<<uniqueChar<<endl;
				j++;
		}			
		
		if(uniqueChar==0)
		{
			int len=j-i;
			//cout<<" len "<<len<<" minlen "<<minLen<<endl;
			if(len<minLen)
			{
				minLen=len;
				start=i;
			}	
			freq[s[i]]++;
			if(freq[s[i]]==1)
				uniqueChar++;
			i++;
		}	
	}
	

	if(start==-1)
	{
	   cout<<"Doesn't exist\n"<<endl; 
	   return;
	}
    //string str(s); 
    string resultantString=s.substr(start,minLen);
	cout<<resultantString<<endl;	


}


int main()
{
	string a="this is a test string";
	string b="tist";
	int len1=a.size(),len2=b.size();
	findMinLengthSubstring(a,b,len1,len2);
	return 0;
}