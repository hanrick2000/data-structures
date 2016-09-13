#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*
You are given a string S. Write a function to find the longest substring of the given string S which
contains at most 2 unique characters. If there are more than 1 substrings of max length, then
return any one.
Example:	
S = "abbbcccbcbddeeffffabbbcbc"
Output = ["bbbcccbcb"]
S = "helloworld"
Output = ["ell", "llo", "owo"]
S = " mississippi"
Output = ["ississi"]

s="aaaabbbcccc"

*/

bool isValid(int* count,int k)
{
   int counter=0;
   for(int i=0;i<26;i++)
   {
      if(count[i]!=0)
        counter++;
   } 

   return(counter<=k);
    

}


string printLongestSubstring(string str,int k)
{
  int count[26]={0},counter=0;

  for(int i=0;i<str.size();i++)
  {
     if(count[str[i]-'a']==0)
      counter++;
    count[str[i]-'a']++;
  }  


  if(counter<k)
  {
     cout<<"less than k unique characters "<<endl;
     return NULL;
  } 

  memset(count,0,sizeof(count));
  
  count[str[0]-'a']++;
  int current_end=0,current_start=0,max_win_len=1,max_win_start=0;
  for(int i=1;i<str.size();i++)
  {
      current_end++;
      count[str[i]-'a']++;

      while(!isValid(count,k))
      {
          count[str[current_start]-'a']--;
          current_start++;
      }  

      if(current_end-current_start+1>max_win_len)
      {
          max_win_len=current_end-current_start+1;
          max_win_start=current_start;
      }  
  }

  string longest=str.substr(max_win_start,max_win_len);
  cout<<"In the function "<<endl<<" the string is "<<longest;
  return longest;  

}

int main()
{

    char s[]="helloworld";
    //char s[]="aaaaab";
    cout<<s<<endl;
    int len=strlen(s);
	string temp=printLongestSubstring(s,2);
	cout<<temp;
	return 0;
}