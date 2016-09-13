#include<iostream>
#include<cstdio>
using namespace std;

 /*
    Given a input number in array form. Push all the zeroes to the end maintaining the order 
	of rest of elements. 
	T.C.-O(n) S.C.-O(1)
 */

void printArray(int* arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

void pushZeros(int* arr,int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
    	if(arr[i]==0)
    		count++;
    }	

 	int counter=0;
    for(int i=0;i<size;i++)
    {
         if(arr[i]!=0)
         {
         	arr[counter++]=arr[i];
         }	
    }	

    while(count--)
    {
    	arr[size]=0;
    	size--;
    }	
}

	
int main()
{
    int arr[]={1,0,2,6,0,0,2,6,8,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
	pushZeros(arr,size-1);
	printArray(arr,size);
    

	return 0;
}