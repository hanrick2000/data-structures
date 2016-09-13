#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.*/


//Recursive solution

int minInsertions(string str,int l,int h)
{
	
	if (l>h)
	 {
	 	return INT_MAX;
	 } 
	if (l==h)
	{
		return 0;
	}

	if (l==h-1)
	{
		return str[l]==str[h]?0:1;
	}
	//if(l<h)
		return (str[l] == str[h]) ? (minInsertions(str,l+1,h-1)) : ( 1 + min(minInsertions(str,l+1,h),minInsertions(str,l,h-1)));

}

//DP Approach

void minInsertionsDP(string str)
{
	int dp[str.length()][str.length()];

	memset(dp,0,sizeof(dp));

    //i refers to the gap

	for (int i = 1; i < str.length(); ++i)
	{
		for (int j = 0,	h=i; h < str.length(); ++j,h++)
		{
			if (str[j] == str[h])
			{
				dp[j][h]=dp[j+1][h-1];
			}
			else
			{
				dp[j][h]=min(dp[j][h-1],dp[j+1][h])+1;
			}	
		}
	}

	return dp[0][str.length()-1];
}

int main()
{
	string str="aabc";
	cout<<minInsertions(str,0,str.length()-1);
	return 0;
}