#include<iostream>
#include<cstdio>
using namespace std;

int countZeros(int val)
{
	if(val==0)
		return 1;
	if(val<10)
		return 0;
	int rem=val%10;
	if(rem==0)
		return 1+countZeros(val/10);
	else
		return countZeros(val/10);
}


int main()
{
	int a=111;
    cout<<countZeros(a)<<endl;
	return 0;
}