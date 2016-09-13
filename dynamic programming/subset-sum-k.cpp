#include <iostream>
#include <cstring>
using namespace std;

bool subsetSum(int* arr,int n,int k)
{
	bool dp[sum+1][n+1];

//sum is zero and the set is empty the result is true
	for(int i=0; i <= n; i++)
	{
		dp[0][i]=true;
	}	

// sum is not zero and the set is empty then it is false   
	for (int i = 1; i <=sum; ++i)
	{
		dp[i][0]=false;	
	}

	for (int i = 1; i <= sum; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			 dp[i][j]=dp[i][j-1];
			 if(i>arr[j-1])
			 {
			 	dp[i][j]=dp[i][j]||dp[i-arr[j-1]][j-1];
			 }	

		}
	}

	return dp[sum][n];


}

int main()
{

	return 0;
}		