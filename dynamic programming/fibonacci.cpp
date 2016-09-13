#include <iostream>
using namespace std;


int fib(int n,int* output)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;

	if(output[n]>0)
		return output[n];

	output[n]=fib(n-1,output)+fib(n-2,output);
	return output[n];

}


int main()
{

	return 0;
}