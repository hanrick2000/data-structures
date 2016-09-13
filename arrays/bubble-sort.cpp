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

void bubblesort(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i;j++)
		{
 			if(arr[j]>arr[j+1])
 			  swap(arr[j],arr[j+1]);	
		}	
	}	
}


int main()
{
	int arr[]={2,4,6,8,10,1,3,5,7,11,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	bubblesort(arr,size-1);
	printArray(arr,size);
	return 0;
}