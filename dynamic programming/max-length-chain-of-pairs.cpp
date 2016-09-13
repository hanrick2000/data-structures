#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


struct pair1
{
	int a;
	int b;
};

bool comparison(pair1 p1,pair1 p2)
{
	if(p2.a > p1.a)
		return true;
	return false;
}

int count(pair1* arr,int n)
{
	int max_count[n];
	for (int i = 0; i < n; ++i)
	{
			max_count[i]=1;
	}	

	int max_val=1;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if(arr[i].a > arr[j].b && max_count[i] < max_count[j] +1)
			{
				max_count[i]=max_count[j]+1;
				
				if(max_val<max_count[i])
				{
					max_val=max_count[i];
				}	
			}	
		}	
	}	

	return max_val;
}

int main()
{
	struct pair1 arr[] = { {15, 25},{5, 24},{27, 40}, {50, 60} };
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,comparison);      
    // for(int i=0;i<n;i++)
    // {
    // 	cout<<"{"<<arr[i].a<<","<<arr[i].b<<"}"<<endl;
    // } 

    cout<<endl<<"max length chain of pairs "<<count(arr,n)<<endl;

	return 0;
}