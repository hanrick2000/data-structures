#include<iostream>
#include<cstdio>
using namespace std;

/*
   	Given two sorted arrays such the arrays may have some common elements. Find the sum of the maximum 
    sum path to reach from beginning of any array to end of any of the two arrays. 
    We can switch from one array to another array only at common elements.

    Expected time complexity is O(m+n) where m is the number of elements in ar1[] 
    and n is the number of elements in ar2[].
*/

int maxPathSum(int* arr1,int* arr2,int len1,int len2)
{
	int i=0,j=0,sum1=0,sum2=0,max_sum=0;
	while(i<len1 && j<len2)
    {
    	if(arr1[i]<arr2[j])
    	{
    		sum1+=arr1[i++];
    	}
    	else if(arr1[i]>arr2[j])
    	{
    		sum2+=arr2[j++];
    	}	
    	else
    	{
    		max_sum+=max(sum1,sum2)+arr1[i];
    		i++;
    		j++;
    		sum1=0;
    		sum2=0;
    	}	
    }

    while(i<len1)
    {
    	max_sum+=arr1[i];
    }

    while(j<len2)
    {
    	max_sum+=arr2[j];
    }		

    return max_sum;
}
 int main()
 {
 	int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Maximum sum path is "
         << maxPathSum(ar1, ar2, m, n);
    return 0;
 }   