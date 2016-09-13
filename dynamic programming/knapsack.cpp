#include <iostream>
#include <cstring>
using namespace std;


int knapSack(int max_wt,int* wt,int* val,int size)
{
	if(max_wt==0 || size==0)
		return 0;

	if(max_wt<wt[size-1])
		return knapSack(max_wt,wt,val,size-1);

	return max(  (val[size-1]+knapSack(max_wt-wt[size-1],wt,val,size-1)),knapSack(max_wt,wt,val,size-1) );
}


int maxVal(int* wt,int* val,int max_wt,int size)
{
	int dp[size+1][max_wt+1];
	memset(dp,0,sizeof(dp));

	for (int i = 0; i <= size; ++i)
	{
		for (int w = 0; w <= max_wt; ++w)
		{
			 if(i==0 || w==0)
			 {
			 	//if no value has been included(empty subset) or the weight required is zero
			 	dp[i][w]=0;
			 }	
			 else if(wt[i-1]<=w)
			 {						   //dp[i-1] below as the previous item included								
			 	dp[i][w]=max( val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
			 }	
			 else
			 {
			 	dp[i][w]=dp[i-1][w];
			 }	

		}
	}

	return dp[size][max_wt];
}

int main()
{
	int wt[]={1,3,4,5};
	int val[]={1,4,5,7};
	int max_wt=7;
	int size=sizeof(wt)/sizeof(wt[0]);

	cout<<maxVal(wt,val,max_wt,size)<<endl;
	return 0;
}