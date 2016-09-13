#include <iostream>
using namespace std;

/*
	Time-O(logn)
	Space-O(1)
*/

int reverse_bits(int num)
{
	int no_of_bits=sizeof(num)*8;
	int rev_num=0,temp;

	for (int i = 0; i < no_of_bits; ++i)
	{
		 temp= num & (1<<i);
		 if (temp)
		 {
		 	rev_num|=(1 << (no_of_bits -1) -i);
		 }
	}
}


/*
	Another method
	Time-O(logn)
	Space-O(1)
*/

int reverse_bits1(int num)
{
	int count=sizeof(num)*8-1;
	int reverse=0;
		
	while(num)
	{
		reverse>>=1;
		reverse|=1&num;
		num<<1;
		count--;
	}	

	reverse<<=count;
	return reverse;
}	
int main()
{

	return 0;
}