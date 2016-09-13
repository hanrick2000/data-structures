#include <iostream>
using namespace std;


//O(nlogn) implementation

int countBitsUtil(int n)
{
	if (x<=0)
	{
		return 0;
	}

	return (( x%2 == 0 )? 0 : 1)+countBitsUtil(n/2);
}

int countBits(int n)
{
	int res=0;
	for (int i = 1; i < =n; ++i)
	{
		/* code */
		res+=countBitsUtil(i);
	}
	return res;
}


 
long int setBits(int n)
{
	long int count=0;
	while(n>0)
	{
		count++;
		n=n&(n-1);
	}
	
	return count;
}


//O(logn) approach

int main()
{
	int num;
	cin>>num;
	cout<<countBits(num);
	return 0;
}