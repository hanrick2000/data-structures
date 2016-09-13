#include<iostream>
#include<cstring>
using namespace std;

bool binarySearch(int* arr,int low,int high,int val)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==val)
			return true;
		else if(val<arr[mid])
			return binarySearch(arr,low,mid-1,val);
		else
			return binarySearch(arr,mid+1,high,val);
	}	

	return false;
}

int main()
{
	int arr[]={2,3,5,7,8,9,11,15};
	int len=sizeof(arr)/sizeof(arr[0]);
	int val=11;
	bool value=binarySearch(arr,0,len-1,val);
	cout<<value<<endl;
	return 0;
}