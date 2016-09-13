#include <iostream>
using namespace std;

/*
	using the funda 
	x=^y
	y=^x
	x=^y
*/


int swapBits(unsigned int n,unsigned int p1,unsigned int p2)
{
	//retrieve bit at position 1
	//rightshift

	unsigned int bit1 = (n >> p1)&1;
	
	//retrieve bit at position 2
	//rightshift
	
	unsigned int bit2 = (n >> p2)&1;


	unsigned int x= (bit1 ^ bit2);

	//put xor bit back to their original position
	x= (x << p1) | (x << p2);

	/*xor x with the original number so that the two sets are swapped */

	unsigned int result=n^x;
	return result;

}

int main()
{

	return 0;
}