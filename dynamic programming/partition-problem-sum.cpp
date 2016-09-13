#include <iostream>
#include <cstring>
using namespace std;


bool findSubsetSum(int* arr,int size,int sum)
{
	if(sum==0)
		return true;

	if(size==0 && sum!=0)
		return false;

	if(arr[size-1]>sum)
		return findSubsetSum(arr,size-1,sum);

	return findSubsetSum(arr,size-1,sum-arr[size-1]) || findSubsetSum(arr,size-1,sum);
}

bool findPartition(int* arr,int size)
{
	int sum=0;
	for (int i = 0; i < size; ++i)
	{
		sum+=arr[i];	
	}

	if(sum%2==1)
		return false;

	return  findSubsetSum(arr,size,sum/2);
}


bool findPartitionDP(int * arr,int size)
{
	int sum=0;
	for (int i = 0; i < size; ++i)
	{
		sum+=arr[i];	
	}

	if(sum%2==1)
		return false;

	bool dp[sum/2+1][size+1];

	for (int i = 0; i <=sum/2; ++i)
	{
		dp[i][0]=0;
	}

	for (int i = 1; i <=size ; ++i)
	{
		dp[0][i]=1;
	}


	for (int i = 1; i <=sum/2; ++i)
	{
		//cout<<i<<endl;
		for (int j = 1; j <=size; ++j)
		{
			dp[i][j]=dp[i][j-1];
			if(i>=arr[j-1])
			{
				dp[i][j]=dp[i][j]||dp[i-arr[j-1]][j-1];
			}	

			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cout<<"returning";
	return dp[sum/2][size];


}

int main()
{
	int size;
	cin>>size;
	int* arr=new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}
	cout<<findPartitionDP(arr,size);
	delete	[] arr;

	return 0;
}