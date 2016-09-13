#include<iostream>
#include<cmath>
using namespace std;

#define N 8
//This is placing queens in the columns
bool isSafe(char** arr,int row,int col)
{
       
    int x=row,y=col;
    //straight left
    while(y--)
    {
    	if(arr[x][y]=='Q')
    		return false;
    }	
    
    x=row,y=col;
    //up left(diagonal)
     
    while(x>=0 && y>=0)
    {
    	if(arr[x][y]=='Q')
    		return false;
    	x--;
    	y--;
    } 

    x=row,y=col;
    //up right(diagonal)

    while(x>=0 && y<=N-1)
    {

    	if(arr[x][y]=='Q')
    		return false;
    	x--;
    	y++;
    }	
    return true;
       
}


bool nqueen(char** arr,int numOfQueens)  //numQueens indirectly denotes the column.Every column has one queen
{
   if(numOfQueens>=N)
     return true;

    for(int i=0;i<N;i++)
    {	
	    if(isSafe(arr,i,numOfQueens))
	    {
	    	arr[i][numOfQueens]='Q';
	    	if(nqueen(arr,numOfQueens+1))
	    	{
	    		return true;
	    	}	
	    	arr[i][numOfQueens]='*';

	    } 	
	} 

	return false;   
}

//This is placing the queens in the rows
bool isSafe2(char** arr,int row,int col)
{
       
    int x=row,y=col;
    //straight up
    while(x--)
    {
    	if(arr[x][y]=='Q')
    		return false;
    }	
    
    x=row,y=col;
    //up left(diagonal)
     
    while(x>=0 && y>=0)
    {
    	if(arr[x][y]=='Q')
    		return false;
    	x--;
    	y--;
    } 

    x=row,y=col;
    //up right(diagonal)

    while(x>=0 && y<=N-1)
    {

    	if(arr[x][y]=='Q')
    		return false;
    	x--;
    	y++;
    }	
    return true;
       
}

bool nqueen2(char** arr,int numOfQueens)  //numQueens indirectly denotes the row.Every row has one queen
{
   if(numOfQueens>=N)
     return true;

    for(int i=0;i<N;i++)
    {	
	    if(isSafe2(arr,numOfQueens,i))
	    {
	    	arr[numOfQueens][i]='Q';
	    	if(nqueen2(arr,numOfQueens+1))
	    	{
	    		return true;
	    	}	
	    	arr[numOfQueens][i]='*';

	    } 	
	} 

	return false;   
}




void printMatrix(char** arr)
{
	for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++)
  	{
  		cout<<arr[i][j]<<" ";
  	}	
  	cout<<endl;
  }	
}



int main()
{

  char **arr =new char*[N];//allocating memory to rows.
  for(int i=0;i<N;i++)//allocating memory to columns
  {
  	arr[i]=new char[N];
  }	

  for(int i=0;i<N;i++)
  {
  	for(int j=0;j<N;j++)
  	{
  		arr[i][j]='*';
  	}	
  }	

  if(nqueen2(arr,0))
  {
  	cout<<"solution is "<<endl;
  	 printMatrix(arr);
  }	

  delete [] arr;
  //printMatrix(arr);
  return 0;
}