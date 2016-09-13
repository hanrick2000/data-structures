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

void insertionsort(int* arr,int size)
{
	for(int i=1;i<size;i++)
	{ 
		int current=arr[i];
		int j=i;

		while(j>0 && arr[j-1]>current)
		{
			arr[j]=arr[j-1];
			j--;
		}	

		arr[j]=current;
	}	
}


int main()
{
	int arr[]={2,4,6,8,10,1,3,5,7,11,12};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	insertionsort(arr,size-1);
	printArray(arr,size);
	return 0;
}