#include <iostream>
#include <cstring>
using namespace std;

//solution 1 Kadane(doesn't work for negative numbers )

int kadane(int* arr,int size)
{
	int current_max=0,max_so_far=0;
	for (int i = 0; i < size; ++i)
	{
		 current_max=current_max+arr[i];
		 
		 if(current_max<0)
		 	current_max=0;

		 if(max_so_far<current_max)
		 {
		 	max_so_far=current_max;
		 }	

	}
	return max_so_far;
}

//solution 2 handles negative numbers as well

int maxSum(int* arr,int size)
{
	int current_max=arr[0],max_so_far=arr[0];
	for (int i = 1; i < size; ++i)
	{
		current_max=max(current_max+arr[i],arr[i]);
		max_so_far=max(current_max,max_so_far);
	}

	return max_so_far;
}


int main()
{
	// int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
	// int size=sizeof(arr)/sizeof(arr[0]);
	int size;
	cin>>size;
	int* arr=new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}
	
	cout<<maxSum(arr,size)<<endl;
	return 0;
}