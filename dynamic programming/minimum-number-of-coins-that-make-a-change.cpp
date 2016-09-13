#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

/*
 Given a value V, if we want to make change for V cents, and we have 
 infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the 
 minimum number of coins to make the change?

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 
*/


//recursive solution
//exponential solution,as it considers all the possible cases


int count(int* arr,int size,int sum)
{
	if(sum==0)
	{
		return 0;
	}	

	int res=INT_MAX;


   for (int i = 0; i < size; ++i)
   	{
   		if(sum>=arr[i])
		{
			int sub_res=count(arr,size,sum-arr[i]);

			if(sub_res+1<res && sub_res!=INT_MAX)
			{
				res=sub_res+1;
			}	
		}	
   	}	

   	return res;

}


int countDP(int* arr,int size,int sum)
{
	int dp[sum+1];
	//memset(dp,INT_MAX,sizeof(dp));

	for (int i = 0; i < sum+1; ++i)
	{
		dp[i]=INT_MAX;
	}
	dp[0]=0;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<size;j++)
			{
				if(arr[j]<=i)
				{	
					int sub_res=dp[i-arr[j]];
					//cout<<sub_res<<endl;
					if(sub_res!=INT_MAX && sub_res+1<dp[i])
					{
						//cout<<"Entering"<<endl;
						dp[i]=sub_res+1;
					}
				}		
		}	
	}

	return dp[sum];	
}

 

int main()
{
	// int coins[] = {25, 10, 5};
	// int sum = 30;
	int size,sum;
	cin>>size>>sum;
	int *arr=new int[size];

	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}

	cout<<countDP(arr,size,sum);

	
	delete[] arr;	
	//int size=sizeof(coins)/sizeof(coins[0]);
	return 0;
}