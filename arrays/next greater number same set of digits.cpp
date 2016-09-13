#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


/*
  Given a number n, find the smallest number that has same set of digits as n and is greater than n. If x is the greatest possible number with its set of digits, then print “not possible”.
*/

 /*
    solution:3 cases considered.
    1)Nums in decreasing order.Next greater not possible.
    2)numbers in increasing order.Simply swap the last two digits.
    3)1432->2134.Basically start from the last digit.As soon as you find num[i-1]<num[i]
      save that,move to the to its right in the array.find min in that part.swap it with found.
      then sort the right part of found.

 */ 


void nextGreater(int* arr,int size)
{
	bool flag=false;
	int i;
		
	for(i=size-1;i>0;i--)
	{
		if(arr[i-1]<arr[i])
		{
			flag=true;
			break;
		}	
	}	

	if(flag==true)
	{
		cout<<i<<endl;
		int current=arr[i-1];
		int smallest=i;

		//find the first number greater than current,but less than the rest.

		for(int j=i+1;j<size;j++)
		{
			if(arr[j]>current && arr[j]<arr[smallest])
			{
				smallest=j;
			}	
		}	
    

		cout<<smallest<<endl;
		swap(arr[i-1],arr[smallest]);
		sort(arr+i,arr+size);
		for(int i1=0;i1<size;i1++)
		{
			cout<<arr[i1]<<" ";
		}
		cout<<endl;	
	}	
	else
	{
		cout<<"not possible"<<endl;
	}	


}      
int main(int argc, char const *argv[])
{
	int arr[]={2,4,3,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	nextGreater(arr,size);
	/* code */
	return 0;
}