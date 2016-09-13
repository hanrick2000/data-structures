#include <iostream>
using namespace std;

/*
  we start from arr1 run for every element.
  every element of arr2 is compared with arr2;
  size of dp array is arr2's size
*/

int lcis(int* arr1,int* arr2,int len1,int len2)
{
	int dp[len2];

	for (int i = 0; i < len2; ++i)
	{
		dp[i]=0;
	}


	for (int i = 0; i < len1; ++i)
	{
		int current=0;
		for (int j = 0; j < len2; ++j)
		{
			 // If both the array have same elements.
            // Note that we don't break the loop here.
			if (arr1[i] == arr2[j])
			{
				if (dp[j] < current+1)
				{
					dp[j]=current+1;
				}


            /* Now seek for previous smaller common
               element for current element of arr1 */
				if (dp[i] >dp[j])
				{
					if (current<dp[j])
					{
						current=dp[j];
					}
				}
			}
		}
	}

	int max=dp[0];
	for (int i = 1; i < len2; ++i)
	{
		if (dp[i]>max)
		{
			max=dp[i];
		}
	}
}




int main()
{
	int* arr1={3,4,9,1};
	int* arr2={5,3,8,9,10,2,1};
	return 0;
}