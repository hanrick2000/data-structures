#include<iostream>
#include<cstring>
using namespace std;

/*
	Given arrival and departure times of all trains that reach a railway station,
	find the minimum number of platforms required for the railway station so that no train waits.
*/

/*
	given,sorted according to the arrival time.
	we basically need to find out the number of stations in use at a time
	arr++,dept--;
*/

//O(nlogn) as sorting takes time.

int stationsRequired(int*arr,int* dept,int n)
{
	sort(dept,dept+n);
	int platforms=1,result=1;
	/*similar to merge process in merge sort*/
	int i=0,j=0;
	while(i<n && j<n)
	{
		if(arr[i] < dept[j])
		{
			platforms++;
			i++;
			if(result<platforms)
				result=platforms;
		}	
		else
		{
			j++;
			platforms--;
		}	

	}	

	return result;
}

int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];
	int* dept=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}	

	for(int i=0;i<n;i++)
	{
		cin>>dept[i];
	}	

	int result=stationsRequired(arr,dept,n)

	return 0;
}