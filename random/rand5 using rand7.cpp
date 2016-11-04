#include <iostream>
using namespace std;

int rand5()
{
	int val=rand7();
	if(val<6)
		return val;
	return rand5();
}

int main()
{
	cout<<rand5();
	return 0;
}