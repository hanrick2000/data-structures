#include <iostream>
#include <cstring>
using namespace std;


/*
  The longest Increasing Subsequence (LIS) problem is to find 
  the length of the longest subsequence of a given sequence such that all elements of 
  the subsequence are sorted in increasing order. For example, length of 
  LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.	 		
*/

// Recursive solution 

// int _lis(int* arr,int size,int* max_ref)
// {
// 	if(size==1)
// 	{
// 		return 1;
// 	}		

// 	int current_max=1;

// 	for (int i = 1; i < size; ++i)
// 	{
// 		 int res=_lis(arr,i,max_ref);
// 		 if(arr[i-1] < arr[size-1] && res +1>current_max)
// 		 {
// 		 	current_max=res+1;
// 		 }	
// 	}

// 	if (current_max>*max_ref)
// 	{
// 		*max_ref=current_max;
// 	}

// 	return *max_ref;
// }


// int lis(int* arr,int n)
// {
// 	int max=1;
// 	_lis(arr,n,&max); 
// 	return max;
// }

//dp solution
//The solution below might be incorrect
int count(int* arr,int size)
{
	int dp[size][size];
	memset(dp,0,sizeof(dp));

	for(int i=0;i<size;i++)
	{
		dp[i][i]=1;
	}	

	int maximum=1;
	int i,j;
	for (i = 0; i < size; ++i)
	{
		int max_val=arr[i];
		
		for (j = i+1; j <size; ++j)
		{
			if(arr[j]>max_val)
			{
				dp[i][j]=dp[i][j-1]+1;
				max_val=arr[j];
			}	
			else
			{
				dp[i][j]=dp[i][j-1];
			}	

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
		if(dp[i][j-1]>maximum)
			maximum=dp[i][j-1];
	}

	return maximum;
}


//correct solution
//dp
int count1(int* arr,int n)
{
	int val[n];
	for (int i = 0; i < n; ++i)
	{
		val[i]=1;
	}

	int maximum=1;
	for(int i = 1; i < n; i++)
	{
		for (int j = 0; j< i; ++j)
		{
			if( arr[i] > arr[j] && val[i] < val[j]+1)
			{
				val[i]=val[j]+1;
				//cout<<val[i]<<" ";
				if(maximum<val[i])
				{
					maximum=val[i];
				}	
			}	
		}
	}

	return maximum;	
}

int main()
{
	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60,80 };
	int arr[]={2, 5, 3, 1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<count1(arr,n);
	return 0;
}