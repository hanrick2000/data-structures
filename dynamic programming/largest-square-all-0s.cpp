#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int max_square(int **arr,int row,int col)
{
	int dp[row][col];
	memset(dp,0,sizeof(dp));

	for (int i = 0; i < row; ++i)
	{
		for (int i1 = 0; i1 < col; ++i1)
		{
			arr[i][i1]=abs(1-arr[i][i1]);
		}
	}

	
	for (int i = 0; i < row; ++i)
	 {
	 	dp[i][0]=arr[i][0];
	 } 

	 for (int i = 0; i < col;++i)
	 {
	 	dp[0][i]=arr[0][i];
	 } 


	int maximum=0;

	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			if(arr[i][j]==1)
			{
				int val=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				dp[i][j]=val+1;
			}
			else
			{
				dp[i][j]=0;
			}	
			if(maximum<dp[i][j])
			{
				maximum=dp[i][j];
			}		
		}
	}

	//cout<<endl<<endl;

	// for (int i = 0; i < row; ++i)
	// {	
 
	// 	for (int i1 = 0; i1 < col; ++i1)
	// 	{
	// 		cout<<dp[i][i1]<<" "; 
	// 	}
	// 	cout<<endl;
	// }


	return maximum*maximum;


}

int main()
{

	int row;
	int col;
	cin>>row>>col;
	int **arr=new int*[row];
	for (int i = 0; i < row; ++i)
	{
		arr[i]=new int[col];
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin>>arr[i][j];
		}
	}

	cout<<max_square(arr,row,col);

	for (int i = 0; i < row; ++i)
	{
		delete[] arr[i];
	}

	delete [] arr;
	return 0;
}