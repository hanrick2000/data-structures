#include<iostream>
#include<cstdio>
using namespace std;

void printArray(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}


/*
   Partion happens in linear time
   
   This function takes last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot 
*/
int partition(int* arr,int low,int high)
{
    int pivot=arr[high];
    int j=low-1;
    for(int i=low;i<=high-1;i++)
    {
       if(arr[i]<=pivot)
       {
           j++;
           swap(arr[i],arr[j]);
       }	
    }	
    
    
    swap(arr[j+1],arr[high]);
    return j+1;

}

void quicksort(int* arr,int low,int high)
{
	 if(low<high)
	 {	 int p=partition(arr,low,high);
		 /*
		 	Separately sort elements before
	        partition and after partition
		 */
		 quicksort(arr,low,p-1);
		 quicksort(arr,p+1,high);
	}	 
}


int main()
{
	int arr[]={2,4,6,8,10,1,3,5,7,11,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	quicksort(arr,0,size-1);
	printArray(arr,size);
	return 0;
}