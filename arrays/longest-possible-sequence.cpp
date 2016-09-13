#include<iostream>
#include<cstdio>
#include<climits>
#include<map>
using namespace std;

int longestSequence(int* a,int size)
{
	map<int,bool> my_map;
	for(int i=0;i<size;i++)
	{
		my_map[a[i]]=true;
	}	

    int max_len=0;
	for(int i=0;i<size;i++)
	{
		int k=a[i];
		int len=1;
		k++;
		while(my_map[k]==true)
		{
			len++;
			k++;
		}	

		if(len>max_len)
		{
			max_len=len;
		}	
	}	
	 
   return max_len;
	 
}

int main()
{
	 
	int n;
	scanf("%d",&n);
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
	   scanf("%d",&a[i]);
	}
	int result=longestSequence(a,n);
	cout<<result<<endl;
	return 0;
}