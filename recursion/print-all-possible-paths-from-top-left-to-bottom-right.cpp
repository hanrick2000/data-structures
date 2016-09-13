#include <iostream>
#include <cstring>
using namespace std;


void printWays(int mat[2][3],int x,int y,int m,int n,int* path,int pi)
{ 
	if (x == m-1 && y ==n-1)
	{
		path[pi++]=mat[x][y];
		for (int i = 0; i < pi; ++i)
		{
			cout<<path[i]<<" ";
		}
		cout<<endl;
		return;
	}

	path[pi++]=mat[x][y];

	if (x < m)
	{
		printWays(mat,x+1,y,m,n,path,pi);
	}

	if (y < n)
	{
		printWays(mat,x,y+1,m,n,path,pi);
	}
}


int main()
{
	int arr[2][3]={{1,2,3},
				   {4,5,6}};

	int path[50];			   
	printWays(arr,0,0,2,3,path,0);			   
	return 0;
}