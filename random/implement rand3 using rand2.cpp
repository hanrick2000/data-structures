#include<iostream>
using namespace std;

//Given a function rand2() that returns 0 or 1 with equal probability, implement rand3() using rand2() that returns 0, 1 or 2 with equal probability. Minimize the number of calls to rand2() method. 
//Also, use of any other library function and floating point arithmetic are not allowed.

int rand2()
{
	return rand()&1;
}

int rand3()
{
	int r=2*rand2()*rand2();
	if(r<3)
		return r;
	return rand3();
}


int main()
{
	cout<<rand3();
	return 0;
}