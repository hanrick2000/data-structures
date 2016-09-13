#include <iostream>
using namespace std;

int countTrees(int num)
{
	if (num==0 || num==1)
	{
		return 1;
	}

	else
	{	
		int sum=0,left,right;
		for (int root = 1; root < num; ++root)
		{
			left=countTrees(root-1);
			right=countTrees(num-root);
			sum+=left*right;
		}

		return sum;
	}	

}


int countTreesDP(int num)
{
	int dp[num+1];
	dp[0]=1;
	dp[1]=1;
	for (int i = 2; i <= num; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			dp[i]+=dp[j]*dp[i-j-1]; 
		}
	}

	return dp[num];
}
int main()
{
	int num;
	cin>>num;
	cout<<countTrees(num);
	return 0;
}