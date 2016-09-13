#include <iostream>
#include <cstring>
using namespace std;

int fact(int n)
{
	if(n<=1)
		return 1;
	return n*fact(n-1);
}

int smallerRight(string str,int low)
{
	int len=str.length();
	int count=0;

	for (int i = low+1; i < len; ++i)
	{
		if (str[low]>str[i])
		{
			count++;
		}
	}

	return count;
}


int findRank(string str)
{
	int len=str.length();
	int rank=1;
	for (int i = 0; i < len; ++i)
	{
		int places=fact(len-i-1);
		int charSmallerThanCurrentChar=smallerRight(str,i);
		rank+=places*charSmallerThanCurrentChar;
	}

	return rank;
}

int main()
{
	string str="STRING";
	cout<<findRank(str);
	return 0;
}