#include <iostream>
#include <cstring>
using namespace std;

int longestPalindromeSubstring(string str)
{
	int n=str.length();
	int dp[n][n];
	
	memset(dp,0,sizeof(dp));
	
	for (int i = 0; i < n; ++i)
	{
		dp[i][i]=1;
	}

	int startIndex=0;
	int maxLen=1;

	for (int i = 1; i < n; ++i)
	{
		if(str[i]==str[i-1])
		{
			dp[i-1][i]=1;
			startIndex=i-1;
			maxLen=2;
		}	
	}

	for (int i = 3; i <=n; ++i)	
	{

		for (int j = 0; j < n-i+1; ++j)
		{
			 int index=i+j-1;

			if(str[index]==str[j] && dp[j+1][index-1])
			{
				dp[j][index]=1;
				if(i>maxLen)
				{
					startIndex=j;
					maxLen=i;
				}	
			}		
 		}
	}

	// cout<<"longest palidrome substring is "<<endl;
	// for (int i = startIndex; i <=maxLen+startIndex; ++i)
	// {
	// 	cout<<str[i];
	// }

	return maxLen;

}

int main()
{
	string str;
	cin>>str;
	cout<<longestPalindromeSubstring(str);
	return 0;
}