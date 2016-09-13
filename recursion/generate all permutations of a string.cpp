#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;



/*
    return the permuatations.
*/

vector<string> generatePermutations1(string input)
{
	vector<string> result ;
	if(input.length()<=1)
	{
		result.push_back(input);
		return result;
	}	

	for(int i=0;i<input.length();i++)
	{
		//cout<<"smaller word "<<input.substr(0,i)<<" i+1 "<<input.substr(i+1)<<endl;
		string smallerWord=input.substr(0,i)+input.substr(i+1);
		
		vector<string> smallerPermutation=generatePermutations1(smallerWord);
		//cout<<"permuatations "<<smallerPermutation[0]<<endl;
		
		for(int j=0;j<smallerPermutation.size();j++)
		{
			string longerWord=input[i]+smallerPermutation[j];
			//cout<<" longerWord "<<longerWord<<endl;
		
			result.push_back(longerWord);
		}	
	}	

	return result;
}
    
void printPermutations(vector<string> s)
{
	typename vector<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
		cout<<*it<<endl;
}

void swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}
/*
  This is generating duplicates.Use a map.
*/
void generatePermutations(char* str,int start,int len)
{
	if(start==len)
	{
		cout<<str<<endl;
		return;
	}	

	for(int i=0;i<len;i++)
	{
		swap(str+start,str+i);
		generatePermutations(str,start+1,len);
		swap(str+start,str+i);
	}	
}

 
 bool comparison(char a,char b)
 {
 	if (a<b)
 	{
 		return true;
 	}
 	return false;
 }


int main()
{
	string str="ABC";
	sort(str.begin(),str.end(),comparison);
	//cout<<str;
	// int len=str.size();
	// //generatePermutations(str,0,len);
	
	//generatePermutations1(str);
	vector<string> s=generatePermutations1(str);
	printPermutations(s);
	return 0;
}