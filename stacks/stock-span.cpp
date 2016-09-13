#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

/* 
The span Si of the stock’s price on a given day i is defined as the maximum number 
of consecutive days just before the given day, for which the price 
of the stock on the current day is less than or equal to its price on the given day.
*/

int* stockSpan(int* arr,int size)
{
	int *span=new int[size];
	span[0]=1;
	for(int i=1;i<size;i++)
	{
		int current=arr[i];
		int count=1;
		for(int j=i-1;j>=0 && arr[j]<current;j--)
		{
			count++;
		}	

		span[i]=count;

	}	
	return span;
}

int* stockSpan1(int* arr,int size)
{
	int *span=new int[size];
	
	stack<int> s;
	s.push(0);  //pushing the indices
	span[0]=1;
	
	for(int i=1;i<size;i++)
	{
		while(!s.empty() && arr[s.top()]<=arr[i])
		{
			s.pop();
		}	

		if(s.empty())
		{
			span[i]=i+1;
		}	
		else
		{
			span[i]=i-s.top();
		}	

		s.push(i);
	}	

	return span;
}


int main()
{
	int n;
	cin>>n;
	//int arr[]={100, 80, 60, 70, 60, 75, 85};
	int* arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}	

	//int size=sizeof(arr)/sizeof(arr[0]);
	int *span=new int[n];
	memset(span,0,sizeof(span));
	span=stockSpan1(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}	
	cout<<endl;
	return 0;
}