#include <iostream>
#include <cstring>
using namespace std;

bool wildCard(string text,string pattern)
{	
	int m=text.length(),n=pattern.length();
	int dp[m+1][n+1];
	
	memset(dp,0,sizeof(dp));
	dp[0][0]=true;

	 // Only '*' can match with empty string
	for (int i = 1; i <= m; ++i)
	{
		if (pattern[i-1] == '*')
		{
			dp[0][i]=dp[0][i-1];
		}
	}


	// for (int i = 1; i <=m ; ++i)
	// {
	// 	dp[i][0]=false;
	// }

	// for (int i = 1; i <= n; ++i)
	// {
	// 	dp[0][i]=false;
	// }

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			if (text[i-1] == pattern[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else if (pattern[j-1] == '?')
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else if(pattern[j-1] == '*')
			{
				dp[i][j]=dp[i][j-1] || dp[i-1][j];
			}	
			else
			{
				dp[i][j]=0;
			}	
		}
	}

	return dp[m][n];
}

int main()
{
	string str = "baaabab";
    //string pattern = "*****ba*****ab";
    // string pattern = "ba*****ab";
    // char pattern[] = "ba*ab";
     string pattern = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";
    cout<<wildCard(str,pattern);
	return 0;
}