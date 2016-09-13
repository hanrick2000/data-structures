#include<iostream>
#include<cstring>
using namespace std;

/*
  Write a function that returns the sum of the digits of an integer.
*/

int calculateSum(int a)
{
	if(a==0)
		return 0;
	return a%10+calculateSum(a/10);
}


int main()
{
	int a=1002;
	cout<<calculateSum(a)<<endl;
	return 0;
}