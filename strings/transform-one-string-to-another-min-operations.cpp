#include <iostream>
#include <cstring>
using namespace std;

/*
Given two strings A and B, the task is to convert A to B if possible. The only operation 
llowed is to put any character from A and insert it at front. 
Find if it’s possible to convert the string. If yes, then output 
minimum no. of operations required for transformation.

Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.

Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD
*/

int minOperations(string str1,string str2)
{
	if (str1.length()!=str2.length())
	{
		return -1;
	}

	int freq[256];
	memset(freq,0,sizeof(freq));
	for (int i = 0; i < str1.length(); ++i)
	{
		freq[str1[i]]++;
	}

	for (int i = 0; i < str2.length(); ++i)
	{
		freq[str2[i]]--;
	}

	for (int i = 0; i < str1.length(); ++i)
	{
		if (freq[i])
		{
			return -1;
		}
	}


	int i=n-1,j=n-1;
	int count=0;
	while(i>=0 && j>=0)
	{
		while(i>=0 && str1[i]!=str2[j])
		{
			i--;
			count++;
		}

		if (i>=0)
		{
			i--;
			j--;
		}
	}	

	return count;
}

int main()
{
	return 0;
}