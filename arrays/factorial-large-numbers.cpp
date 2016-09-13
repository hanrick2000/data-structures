#include <iostream>
using namespace std;

#define MAX 500


int calculate(int n,int* res,int res_size)
{
	int carry=0;
	for (int i = 0; i < res_size; ++i)
	{
		int val=res[i]*n+carry;
		res[i]=val%10;
		carry=val/10;
	}

	while(carry)
	{
		res[res_size]=carry%10;
		carry=carry/10;
		res_size++;
	}	

	return res_size;

}

void factorial(int n)
{
	int res[MAX];
	int res[0]=1;
	int res_size=1;

	for (int i = 2; i <= n; ++i)
	{
		res_size=calculate(i,res,res_size)
	}

	//calculated in the reverse order
	for (int i = res_size-1; i >=0; --i)
	{
		cout<<res[i];
	}
	cout<<endl;
}


int main()
{

	return 0;
}