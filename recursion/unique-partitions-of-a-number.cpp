#include <iostream>
#include <cstring>
using namespace std;

/*
  Create sorted list of all unique partitions of given number 5 = { {4, 1}, {3, 2}, {3, 1, 1} …. }
*/


void printPartitions(int start,int n,int index,int* path)
{
	if (n==0)
	{
		for (int i = 0; i < index; ++i)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
	}

	for (int i = start; i >0; --i)
	{
		 if (i <= n)
		 {
		    path[index]=i;
		    printPartitions(i,n-i,index+1,path);
		 }
	}

}

void printPartitions(int n)
{
	int path[n];
	printPartitions(n,n,0,path);
}

int main()
{
	int n=4;
	printPartitions(n);
	return 0;
}