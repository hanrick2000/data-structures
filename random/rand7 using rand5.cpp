#include <iostream>
using namespace std;

int rand7()
{
	int r=5*rand5()+rand5()-5;

	if(r<22)
	{
		return (r%7)+1;
	}

	return rand7();

}


int main()
{
	cout<<rand7();
	return 0;
}