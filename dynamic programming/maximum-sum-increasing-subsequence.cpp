#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int maxValue(int* arr,int n)
{
	int sum_array[n];
	memcpy(sum_array,arr,sizeof(sum_array));

	int maximum_sum=INT_MIN;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[i]>arr[j] && sum_array[i]<sum_array[j]+arr[i])
			{
				sum_array[i]=sum_array[j]+arr[i];

				if(maximum_sum<sum_array[i])
				{
					maximum_sum=sum_array[i];
				}	

			}
		}
	}

	return maximum_sum;
}


int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxValue(arr,n);
	return 0;
}