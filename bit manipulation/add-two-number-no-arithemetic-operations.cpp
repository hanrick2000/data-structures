#include <iostream>
using namespace std;

/*use the half adder logic    
	^ is used to add bits 
	and & is used to calculate carry */

int add(int x,int y)
{
	while(y!=0)
	{
		int carry = x&y;
		x = x^y;
		y = carry<<1;
	}	

	return x;
}


int main()
{
	int x,y;
	cin>>x>>y;
	cout<<add(x,y);
	return 0;
}