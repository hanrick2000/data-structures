#include <iostream>
#include <cstring>
using namespace std;

/*
	Given n non-negative integers representing an elevation map where the width of 
	each bar is 1, compute how much water it is able to trap after raining.
*/

//O(n^2) solution is to find the maximum on the left and right.
//The difference between the smaller height and the current element is considered

//O(n) solution
//Store the left and the right heights

int rainWater(int* arr,int size)
{
	int left[size];
	int right[size];

	left[0]=arr[0];

	for (int i = 1; i < size; ++i)
	{
		left[i]=max(left[i-1],arr[i]);
	}

	right[n-1]=arr[size-1];

	for (int i = size-2; i >= 0; --i)
	{
		right[i]=max(right[i+1],arr[i]);
	}

	int result=0;
	for (int i = 0; i < size; ++i)
	{
		result+=min(left[i],right[i])-arr[i];
	}

	return result;
}	


int main()
{

	return 0;
}