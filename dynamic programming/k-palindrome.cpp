#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lcs(string str1,string str2)
{
	int size=str1.size();
	int dp[size+1][size+1];

	for (int i = 0; i <= size; ++i)
	{
		for (int j = 0; j <= size; ++j)
		{
			if (i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}	
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}	
		}
	}

	return dp[size][size];
}

bool KPalindrome(string str,int k)
{
	string strRev=str;
	reverse(strRev.begin(),strRev.end());
	int val=lcs(str,strRev);

	if ((str.length()-val)<=k)
	{
		return true;
	}

  return false;	

}

int main()
{
	string str="abcedcba";
	int k=1;
	cout<<KPalindrome(str,k)<<endl;
	return 0;
}