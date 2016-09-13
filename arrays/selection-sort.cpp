#include<iostream>
#include<cstdio>
using namespace std;


/*
   The selection sort algorithm sorts an array by repeatedly
   finding the minimum element (considering ascending order) from unsorted part 
   and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
   In every iteration of selection sort, the minimum element (considering ascending order) 
   from the unsorted subarray is picked and moved to the sorted subarray.
   
*/
void printArray(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

void selectionsort(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		int minElement=arr[i];
		int correspondingIndex=i;
		for(int j=i+1;j<size;j++)
		{
 			if(arr[j]<minElement)
 			{ 
 				minElement=arr[j];	
 				correspondingIndex=j;
 			}	
		}	

		swap(arr[i],arr[correspondingIndex]);
	}	
}


int main()
{
	int arr[]={2,4,6,8,10,1,3,5,7,11,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	selectionsort(arr,size-1);
	printArray(arr,size);
	return 0;
}