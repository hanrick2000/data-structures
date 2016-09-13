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

void sortarray(int* arr,int size)
{
    int low=0,high=size-1;
    int mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[low++],arr[mid++]);
        }    
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[high--],arr[mid]);
        }    
    }    
}

	
int main()
{
    int arr[]={1,0,1,1,0,0,2,0,0,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
	sortarray(arr,size-1);
	printArray(arr,size);
    

	return 0;
}