#include<iostream>
#include<cmath>
using namespace std;

bool checkBox(int grid[9][9],int row,int col,int num)
{
	int boxRow=row/3,boxCol=col/3;
	int rowStart=boxRow*3,colStart=boxCol*3;
    for(int i=rowStart;i<rowStart+3;i++)
    {
    	for(int j=colStart;j<colStart+3;j++)
    	{
    		if(grid[i][j]==num)
    			return true;
    	}	
    }	

    return false;
}

 

bool checkColumn(int grid[9][9],int col,int num)
{
		for(int i=0;i<9;i++)
		{
			if(grid[i][col]==num)
				return true;
		}	

	return false;	
}
bool checkRow(int grid[9][9],int row,int num)
{
   for(int i=0;i<9;i++)
		{
			if(grid[row][i]==num)
				return true;
		}	

	return false;
}

bool isSafe(int grid[9][9],int row,int col,int num)
{
	if(!checkRow(grid,row,num) && !checkColumn(grid,col,num) &&   !checkBox(grid,row,col,num))
		return true;	
	return false;
}

bool noUnassignedValues(int grid[9][9],int &i,int &j)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(grid[i][j]==0)
				return true;
		}	
	}	

	return false;
}

bool solveSudoku(int grid[9][9] )
{
	int row,col;

    if(!noUnassignedValues(grid,row,col))
    	return true;


	for(int i=1;i<=9;i++)
	{
		if(isSafe(grid,row,col,i))
		{
			grid[row][col]=i;
			cout<<"value assigned: num "<<i<<" row "<<row<<" column "<<col<<endl;
			if(solveSudoku(grid))
				return true;
			cout<<"backtracking"<<endl;
			grid[row][col]=0;

		}	
	}

	return false;

}


 void printSolution(int grid[9][9])
 {
 	for(int i=0;i<9;i++)
 	{
 		for(int j=0;j<9;j++)
 		{
 			cout<<grid[i][j]<<" ";
 		}	
 		cout<<endl;
 	}	
 }

int main()
{
	 int N=9;
	 int grid[9][9] = {
	 				  {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},	
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    bool val=solveSudoku(grid);     
    cout<<"The value is "<<val<<endl; 
    printSolution(grid);           
	return 0;
}