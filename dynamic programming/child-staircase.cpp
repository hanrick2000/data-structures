#include <iostream>
#include <cstring>
using namespace std;

/*
A child is running up a staircase with n steps 
and can hop either 1 step, 2 steps or 3 steps 
at a time. Implement a method to count 
how many possible ways the child can run
up to the stairs. 
*/


// int staircaseCount(int* output,int n)
// {
// 	// if(n==0)
// 	// 	return 0;
// 	if(n==1)
// 		return 1;
// 	if(n==2)
// 		return 2;
// 	if(n==3)
// 		return 3;

// 	if(output[n]>-1)
// 		return output[n];

// 	output[n]=staircaseCount(output,n-1)+staircaseCount(output,n-2)+staircaseCount(output,n-3);
// 	return output[n];
// }

int staircaseCount2(int n)
{
	int *result=new int[n+1];
	result[0]=1;
	result[1]=1;
	result[2]=2;

	for(int i=3;i<=n;i++)
	{
		result[i]=result[i-1]+result[i-2]+result[i-3];
	}	

	//cout<<result[7];

	delete [] result;

	return result[n];
}

int main()
{
	int n;
	cin>>n;
	// int n=7;
	// int* output=new int[n];
	// memset(output,-1,sizeof(output));
	// cout<<staircaseCount(output,n);
	cout<<staircaseCount2(n);
	return 0;
}