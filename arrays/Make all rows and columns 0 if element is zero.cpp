#include<iostream>
#include<cstdio>
using namespace std;


/* Take two arrays row and column store the indices where there are 
   zeros in the matrices. TC-O(n^2) SC-O(n)
*/
void makeZeros1(int arr[100][100],int n)
{
    int row[n]={0};
    int column[n]={0};

    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
        {
        	if(arr[i][j]==0)
        	{
        		row[i]=-1;
        		column[j]=-1;
        	}	
        }		
    }
 
    
    for(int i=0;i<n;i++)
    {
    	if(row[i]==-1)
    	  for(int i1=0;i1<n;i1++)
    	  {
    	  	 arr[i][i1]=0;
    	  }	

    	if(column[i]==-1)
    	  for(int i1=0;i1<n;i1++)  
    	  {
    	  	arr[i1][i]=0;
    	  }	
    } 	

}
/*
   convert all 1s to -1s whenever a zero is found.
   At last convert all -1s to zeros.
   T.C.-O(n^3) S.C-O(1)
*/

void makeZeros2Util(int arr[100][100],int row,int column,int n)
{
   for(int i=0;i<n;i++)
   {
   	   if(arr[row][i]==1)
   	   	  arr[row][i]=-1;
   	   if(arr[i][column]==1)
   	   	  arr[i][column]=-1;
   }
}   
void makeZeros2(int arr[100][100],int n)
{
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(arr[i][j]==0)
    	    {
    	    	makeZeros2Util(arr,i,j,n);
    	    }		
    	}	
    }  	

    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(arr[i][j]==-1)
    	    {
    	    	 arr[i][j]=0;
    	    }		
    	}	
    }  	
}

void print(int arr[100][100],int n)
{
	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
        {
        	cout<<arr[i][j]<<" ";
        }		
        cout<<endl;
    }		
}

int main()
{
   int arr[][100]={ 
   				    {1,0,0,1,1},
   				    {1,1,1,1,1},
   				    {0,0,0,1,1},
   				    {1,1,0,1,1},
   				    {1,1,0,1,1}
   				};

    cout<<"Initially"<<endl;
    print(arr,5);
   	makeZeros2(arr,5);
   	cout<<"After the operations"<<endl;
   	print(arr,5);			
}