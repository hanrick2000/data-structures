#include<iostream>
#include<cstdio>
using namespace std;


float computesum(int k,int a)
{
	if(k==0)
		return 1;

    a*=2;  
	return (float)1/a+(computesum(k-1,a));
}

int main()
{
	int k=18;
	float result=computesum(k,1);
	cout<<result<<endl;
	return 0;
}