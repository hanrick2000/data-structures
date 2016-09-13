#include <iostream>
#include <cstring>
using namespace std;

/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change?
The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: 
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5
*/


/*
	recursive solution.
*/

int coinChange(int* arr,int size,int sum)
{
	if (sum==0)
	{
		return 1;
	}
	if(sum<0)
	{
		return 0;
	}
		
	if(size<=0 && sum>=1)
	{
		return 0;
	}	

	//include and don't include
	return coinChange(arr,size-1,sum-arr[size-1])+coinChange(arr,size-1,sum);
}


/*
   DP solution
*/

int coinChangeDP(int* arr,int size,int sum)
{
	int dp[sum+1][size];
	memset(dp,0,sizeof(dp));


	//sum = 0,empty subsets, one way
	for(int i=0;i<size;i++)
	{
		dp[0][i]=1;
	}	

	for (int i = 1; i <=sum; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			int x=0,y=0;
			//count of solutions including arr[j]
			 if(i-arr[j]>=0)
			 {
			 	x=dp[i-arr[j]][j];
			 }
			 //count of solutions excluding arr[j]
			 if(j>0)
			 {
			 	y=dp[i][j-1];
			 }

			 dp[i][j]=x+y;	
		}
	}

	for (int i = 0; i <=sum; ++i)
	{
		for (int j = 0; j <size ; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return dp[sum][size-1];

}   

int main()
{
	// int arr[]={1,2,3};
	// int size=sizeof(arr)/sizeof(arr[0]);
	// int sum=5;

	int size,sum;
	cin>>size>>sum;
	int *arr=new int[size];

	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}

	cout<<coinChangeDP(arr,size,sum);
	
	delete[] arr;	

	return 0;
}