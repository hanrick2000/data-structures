#inlcude<iostream>
#include<calgorithm>
using namespace std;

/*
    cases:1)all 999s.This case to be dealt separately,as the number of digits increase by one.
    	  2)even digits.
    	  3)odd digits.
    	  also check if already it is palindrome

*/

bool checkIfPalindrome(int* arr,int size,int mid)
{
	if(size%2==0)
	{
		int i=mid-1,j=mid;
		while(i>=0 && j<size)
		{
			if(arr[i]!=arr[j])
				return false;
			i--;
			j++;
		}

		return true;	
	}
	else
	{
		int i=mid-1,j=mid+1;
		while(i>=0 && j<size)
		{
			if(arr[i]!=arr[j])
				return false;
			i--;
			j++;
		}

		return true;		
	}	
}

void nextPalindrome(int* arr,int size)
{
	//checks if all 9s.
	bool all9s=true;
	for(int i=0;i<size;i++)
	{
		if(arr[i]!=9)
			all9s=false;
	}	

	if(all9s)
	{
		cout<<"1";
		for(int i=1;i<size;i++)
			cout<<"0";
		cout<<"1";
	}	
	else
	{
		/*even*/
		int mid=size/2;
		bool alreadyAPalindrome=checkIfPalindrome(arr,size,mid);
		if(size%2==0)
		{
			if(alreadyAPalindrome)
			{
				arr[mid-1]+=1
				arr[mid]+=1;
			}	

		}
		else  /*odd*/
		{
			if(alreadyAPalindrome)
			{
				arr[mid]+=1
				arr[mid+1]+=1;
			}	
		}	
	}	
}

int main()
{
	int arr[]={1,3,4,1};
	int arr1[]={1,3,4,4,1};
	int arr2[]={9,9,9};
	int size=sizeof(arr)/sizeof(arr[0]);

	nextPalindrome()
	return 0;
}