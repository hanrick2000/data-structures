#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*This function simply checks if a path exists and prints it*/

bool ratInAMaze(int arr[][5],int r,int c,int x,int y,int visited[][5])
{
	/*pay attention to the order in which conditions are written. arr[x][y]==1 at the end*/
	if(x<0 || x>=r || y<0 || y>=c || arr[x][y]==1 || visited[x][y]==1)/*obstacles denoted by 1 and path by zeros*/
	{
		return false;
	}	

	if(arr[x][y]==2)/*cheese denoted by two*/
	{
		visited[x][y]=2;
		return true;
	}	

	visited[x][y]=1;
	if(ratInAMaze(arr,r,c,x+1,y,visited))
	{
		return true;
	}	
	if(ratInAMaze(arr,r,c,x-1,y,visited))
	{
		return true;
	}	
	if(ratInAMaze(arr,r,c,x,y+1,visited))
	{
		return true;
	}	
	if(ratInAMaze(arr,r,c,x,y-1,visited))
	{
		return true;
	}	
	visited[x][y]=0;
   return false;
}
/*The function below prints the path*/
// bool ratInAMaze1(int arr[][5],int r,int c,int x,int y,int &visited[][5])
// {
// 	/*pay attention to the order in which conditions are written. arr[x][y]==1 at the end*/
// 	if(x<0 || x>=r || y<0 || y>=c || arr[x][y]==1 || visited[x][y]==1)/*obstacles denoted by 1 and path by zeros*/
// 	{
// 		return false;
// 	}	

// 	if(arr[x][y]==2)cheese denoted by two
// 	{
// 		return true;
// 	}	

// 	visited[x][y]=1;
// 	if(ratInAMaze1(arr,r,c,x+1,y,visited))
// 	{
// 		return true;
// 	}	
// 	if(ratInAMaze1(arr,r,c,x-1,y,visited))
// 	{
// 		return true;
// 	}	
// 	if(ratInAMaze1(arr,r,c,x,y+1,visited))
// 	{
// 		return true;
// 	}	
// 	if(ratInAMaze1(arr,r,c,x,y-1,visited))
// 	{
// 		return true;
// 	}	
//     visited[x][y]=0;
//    return false;
// }

int main()
{



       int arr[][5]={ 
       			   {0,0,0,0,0},
    			   {0,1,1,1,0},
    			   {0,1,2,1,0},
    			   {1,1,0,0,0}
    			};

   int r=sizeof(arr)/sizeof(arr[0]); 
   int c=sizeof(arr[0])/sizeof(arr[0][0]);
   int visited[][5]={
   					{0,0,0,0,0},
    			   {0,0,0,0,0},
    			   {0,0,0,0.0},
    			   {0,0,0,0,0}
   };
   //memset(visited,0, sizeof(visited[0][0]) * r* c);
   bool val=ratInAMaze(arr,r,c,0,0,visited); 
   cout<<val<<endl;			
   cout<<"printing visited"<<endl;
   for(int i=0;i<r;i++)
   {
   	for(int j=0;j<c;j++)
   	{
   		cout<<visited[i][j]<<" ";
   	}	
   	cout<<endl;

   }

	return 0;
}