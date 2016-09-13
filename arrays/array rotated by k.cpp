#include<iostream>
#include<cstdio>
using namespace std;
/*
  A sorted array has been rotated by some number k in clockwise direction. How can we 
  find k efficiently.  

*/

int findK(int *arr,int low,int high)
{
    if(high<low)
	return -1;
     if(low==high)
	return low;	
	 
     int mid=(low+high)/2;//Jo greater return maro

       if(high>mid && arr[mid]>arr[mid+1]);
       {
	  return mid;
       }
       if(mid>low && arr[mid]<arr[mid-1]);
       {
	  return mid-1;
       }
       if(arr[low]<=arr[mid])
       {
          return findK(arr,mid+1,high);
       }
       else
       {
          return findK(arr,low,mid-1);
        }		 			     	
    	
    return -1;

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
	//int arr[]={7,8,1,2,3,4,5,6};
	 int arr[]={4,5,6,7,8,1,2,3};

	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"0 1 2 3 4 5 6 7"<<endl;
	printArray(arr,size);
	int index=findK(arr,0,size-1);
	cout<<"The index is "<<index<<endl;
	return 0;	
}
