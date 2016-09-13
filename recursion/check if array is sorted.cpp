#include<iostream>
#include<cstring>
using namespace std;

bool checkIfSorted(int* arr,int size)
{
	if(size==0 || size==1)
		return true;
   
    if(arr[0]>arr[1])
       return false; 
   
	return(checkIfSorted(arr+1,size));
}
 

int main()
{
	int arr[]={1,2,3,4,5,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	bool val=checkIfSorted(arr,size);
	return 0;
}