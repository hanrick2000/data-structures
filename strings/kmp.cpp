#include <iostream>
#include <cstring>
using namespace std;


void calculate(string pattern,int* arr,int patternLen)
{
	arr[0]=0;
	int i=0,j;
	for(j=1;j<patternLen;)
	{
		//cout<<"i "<<i<<" j "<<j<<endl;
		//cout<<pattern[i]<<" "<<pattern[j]<<endl;
		if(pattern[i] == pattern[j])
		{
			//cout<<"entering"<<endl;
			arr[j]=i+1;
			cout<<arr[j]<<endl;
			i++;
			j++;
		}	
		else
		{
			if(i!=0)
			{
				i=arr[i-1];
			}	
			else
			{
				arr[j]=0;
				j++;
			}	
		}	
	}


}

bool kmp(string text,string pattern)
{
	int patternLen=pattern.length();
	int *arr=new int[patternLen];
	calculate(pattern,arr,patternLen);
	//cout<<"printing the precalculated array"<<endl;
	int i=0,j=0;
	while(i<text.length() && j<pattern.length())
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;

			// if (j == patternLen)
			// {
			// 	cout<<"found pattern at "<<j-patternLen<<endl;
			// 	j=0;
			// }
		}
		else
		{
			if (j!=0)
			{
				j=arr[j-1];
			}
			else
			{
				//j is already zero,move the text ahead
				i++;
			}	
		}	
	}

			if (j == patternLen)
			{
				cout<<"found pattern at "<<j-patternLen<<endl;
				return true;

			}
  	return false;
	 
}

int main()
{ 
	string text = "abcxabcdabcdabcy";
    string pattern = "abcdabcy";
	cout<<kmp(text,pattern);
	return 0;
}