#include<iostream>
#include<cstdio>
using namespace std;


void merge(int* arr,int low,int mid,int high)
{
	int temp[high+1];
	int i=low,j=mid+1,k=low;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			temp[k++]=arr[i++];
		}
		else if(arr[i]>arr[j])
		{
			temp[k++]=arr[j++];
		}		
	}	

	while(i<=mid)
	{
		temp[k++]=arr[i++];
	}	

	while(j<=high)
	{
		temp[k++]=arr[j++];
	}	


	for(i=low;i<=high;i++)
 	{
 		arr[i]=temp[i];
 	}		
}

void mergesort(int* arr,int low,int high)
{
	if(low<high)
	{
		int mid=low+(high-low)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	else
	  return;		
}

void printArray(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

int main()
{
	int arr[]={2,4,6,8,1,3,5,7,9,10};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	mergesort(arr,0,size-1);
	printArray(arr,size);

	return 0;
}