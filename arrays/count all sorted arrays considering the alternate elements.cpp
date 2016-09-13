#include<iostream>
#include<cstdio>
#include<cmath>
 
using namespace std;
/*
   Given two sorted arrays count all the sorted arrays considering alternate elements.

   eg arr1={1,2,3}
      arr2={4,5,6}
      result={},{1},{2},{3},{1,4},{2,4},{3,4}.....
*/

int countSortedArrays(int* arr1,int* arr2,int len1,int len2)
{
   int first=0,second=0,empty=1,i=0,j=0;
   while(i<len1 && j<len2)
   {

   	   if(arr1[i]<arr2[j])
   	   {
   	   	    i++;
   	   		first+=second+empty;
   	   }
   	   else if(arr1[i]>arr2[j])
   	   {
   	   	   j++;
   	   	   second+=first+empty;
   	   }	

   }

   if(i<len1)
   {
	   	while(i<len1)
	   	{
	   		i++;
	   		first+=second+empty;
	   	}	
   }	

   if(j<len2)
   {
   	  while(j<len2)
   	  {
   	  	  j++;
   	  	  second+=first+empty;
   	  }	
   }

   cout<<"first "<<first<<endl;
   cout<<"second "<<second<<endl;

   return first+second;
}

/*This solution below is not working for some test cases
  for the question mentioned.
  It works if it we consider solution like:

  For Example 
A = {10, 15, 25}
B = {1, 5, 20, 30}

The resulting arrays are:
  10 20
  10 20 25 30
  10 30
  15 20
  15 20 25 30
  15 30
  25 30

*/


int countSortedArrays2(int* arr1,int* arr2,int len1,int len2,int i,int j,bool flag=true)
{
	if(i<len1 && j<len2)
	{
		cout<<"i "<<i<<" j "<<j<<endl;
		/*flag is true,I wish to include element of A.*/
		if(flag)
		{
			int val1=abs(j-i)+1;
			cout<<"val1 "<<val1<<endl;
			if(arr1[i]<arr2[j])
			{
				// int val1=abs(j-i)+1;
				// cout<<"val1 "<<val1<<endl;
				return val1+countSortedArrays2(arr1,arr2,len1,len2,i+1,j,!flag);
			}	
			else
			{
				return 1+countSortedArrays2(arr1,arr2,len1,len2,i,j+1,flag);
			}	
		}	
	    else
	    {
	    	int val1=abs(j-i)+1;
	    		cout<<"val1 "<<val1<<endl;
	    	if(arr1[i]>arr2[j])
	    	{
	    		// int val1=abs(j-i)+1;
	    		// cout<<"val1 "<<val1<<endl;
	    		return val1+countSortedArrays2(arr1,arr2,len1,len2,i,j+1,!flag);
	    	}	
	    	else
	    	{
	    		return 1+countSortedArrays2(arr1,arr2,len1,len2,i+1,j,flag);
	    	}	
	    }	

	}


	if(i<len1 && j==len2)
	{
		cout<<"Entering second if condition"<<endl;
		cout<<"i "<<i<<" j "<<j<<endl;
		return 1+countSortedArrays2(arr1,arr2,len1,len2,i+1,j,flag);
	}	

	if(j<len2 && i==len1)
	{
		cout<<"Entering third if condition"<<endl;
		cout<<"i "<<i<<" j "<<j<<endl;
		int val=len2-j;
		cout<<"val is "<<val<<endl;
		return (val*i)+countSortedArrays2(arr1,arr2,len1,len2,i,j+val,flag);
	}	
}


 



int main()
{	
	// int arr1[]={1,3};
	// int arr2[]={2,4};
	int arr1[]={1,2,3};
	int arr2[]={4,5,6,7};
	int size1=sizeof(arr1)/4;
	int size2=sizeof(arr2)/4;
	int val=countSortedArrays(arr1,arr2,size1,size2);
	cout<<val<<endl;
	cout<<"second method "<<endl;	
    int val1=countSortedArrays2(arr1,arr2,size1,size2,0,0);
	cout<<val1<<endl;
	 
	 
	return 0;
}