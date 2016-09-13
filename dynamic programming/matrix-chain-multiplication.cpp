#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

// recursive implementation

int matrix_multiplication(int arr,int i,int j)
{
	if(i==j)
		return 0;


	int cost;
	int min=INT_MAX;

	for(int k = i; k < j; k++)
	{
		cost=matrix_multiplication(arr,i,k)+matrix_multiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		if(cost<min)
			min=cost;
	}

	return min;
}


//Using DP

int matrix_multiplicationDP(int arr,int size)
{
	int dp[size][size];



	for(int i = 0; i < size ; i++)
	{
		dp[i][i]=0;
	}	

	for(int l = 2; l < size; l++)
	{
		for (int i = 0; i < size-l; ++i)
		{
			 int j=i+l;
			 dp[i][j]=INT_MAX;
			 for (int k = i+1; k <j; ++i)
			 {
			 	int temp=dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k];
			 	if(temp<dp[i][j])
			 	{
			 		dp[i][j]=temp;
			 	}
			 }
		}
	}	

	return dp[0][size-1];
		
}



// See the Cormen book for details of the following algorithm
// #include<stdio.h>
// #include<limits.h>
 
// // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
// int MatrixChainOrder(int p[], int n)
// {
 
//     /* For simplicity of the program, one extra row and one
//        extra column are allocated in m[][].  0th row and 0th
//        column of m[][] are not used */
//     int m[n][n];
 
//     int i, j, k, L, q;
 
//     /* m[i,j] = Minimum number of scalar multiplications needed
//        to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
//        dimension of A[i] is p[i-1] x p[i] */
 
//     // cost is zero when multiplying one matrix.
//     for (i = 1; i < n; i++)
//         m[i][i] = 0;
 
//     // L is chain length.
//     for (L=2; L<n; L++)
//     {
//         for (i=1; i<=n-L+1; i++)
//         {
//             j = i+L-1;
//             m[i][j] = INT_MAX;
//             for (k=i; k<=j-1; k++)
//             {
//                 // q = cost/scalar multiplications
//                 q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
//                 if (q < m[i][j])
//                     m[i][j] = q;
//             }
//         }
//     }
 
//     return m[1][n-1];
// }
 
// int main()
// {
//     int arr[] = {1, 2, 3, 4};
//     int size = sizeof(arr)/sizeof(arr[0]);
 
//     printf("Minimum number of multiplications is %d ",
//                        MatrixChainOrder(arr, size));
 
//     getchar();
//     return 0;
// } 


int main()
{
	int arr[]={1,2,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	int min_cost=matrix_multiplication(arr,1,size-1);
	return 0;
}