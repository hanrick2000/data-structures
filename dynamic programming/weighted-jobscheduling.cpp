#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
	int start;
	int finish;
	int profit;
};


bool comparision(Job a,Job b)
{
	return a.finish<b.finish;
}

int findNonConflictingIndex(Job* arr,int i)
{
	for(int j=i-1;j>=0;j--)
	{
		if (arr[j].finish <=arr[i].start)
		{
			return j;
		}
	}	

	return -1;
}

int maxProfit(Job* arr,int n)
{
	int* table=new int[n];
	table[0]=arr[0].profit;

	for(int i=1;i<n;i++)
	{	
		int includeProfit=arr[i].profit;
		int index=findNonConflictingIndex(arr,i);
		if(index!=-1)
		{
			includeProfit+=arr[index];
		}		

		table[i]=max(table[i-1],includeProfit);
	}	

   int result= table[n-1];
   delete [] table;
   return result;

}

int main()
{

}