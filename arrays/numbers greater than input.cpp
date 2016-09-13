#include<iostream>
#include<cmath>
using namespace std;

/*  2134  */


long long fact[10];

void calculate()
{
	fact[0]=1;
	for(int i=1;i<=10;i++)
	{
		fact[i]=fact[i-1]*i;
		cout<<fact[i]<<endl;
	}	
}


/*
  The function below considers non repeated digits

  TC-O(n^2). 

*/
int numbersGreaterThanInput(int* arr,int size)
{
	int result=0;
	for(int i=0;i<size;i++)
	{
		int greater=0;
		for(int j=i+1;j<size;j++)
		{

			if(arr[i]<arr[j])
				greater++;
		}
		result+=greater*fact[size-i-1];	
	}	
	return result;
}

int main()
{
	int arr[]={2,1,3,4};
	calculate();
	int size=sizeof(arr)/sizeof(arr[0]);
	int result=numbersGreaterThanInput(arr,size);
	cout<<result;
  	return 0;
}