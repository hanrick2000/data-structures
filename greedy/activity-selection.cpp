#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;


void printActivities(int* start,int* end,int n)
{
	//sorted on the basis of the finish time
	int i=0;
	cout<<i<<" ";
	for(int j=1;j<n;j++)
	{
		if(start[j]>=end[i])
		{
			cout<<j<<" ";
			i=j;
		}	
	}	
}


int main()
{
	 int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printActivities(s,f,n); 
	return 0;
}