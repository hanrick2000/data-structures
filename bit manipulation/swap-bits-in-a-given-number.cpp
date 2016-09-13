#include <iostream>
using namespace std;

/*
    Given a number x and two positions (from right side) in binary representation of x, 
    write a function that swaps n bits at given two positions and returns the result. 
    It is also given that the two sets of bits do not overlap.
	
	Let p1 and p2 be the two given positions.

	Example 1
	Input:
	x = 47 (00101111)
	p1 = 1 (Start from second bit from right side)
	p2 = 5 (Start from 6th bit from right side)
	n = 3 (No of bits to be swapped)
	
*/


/*
    1U << 0 = 1	   // binary: 00000000000000000000000000000001
    1U << 1 = 2     //binary: 00000000000000000000000000000010
    1U << 2 = 4    // binary: 00000000000000000000000000000100
	
*/


/*
	1) Move all bits of first set to rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that 
contains last n bits set and other bits as 0. We do & 
with this expression so that bits other than the last 
n bits become 0.
2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
3) XOR the two sets of bits
   xor = (set1 ^ set2) 
4) Put the xor bits back to their original positions. 
   xor = (xor << p1) | (xor << p2)
5) Finally, XOR the xor with original number so 
   that the two sets are swapped.
   result = x ^ xor
*/    

//This is similat to swap individual bits

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* xor contains xor of two sets */
    unsigned int xor = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1);
 
    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ((xor << p1) | (xor << p2));
}   

int main()
{
	int num;
	cin>>num;
	cout<<countBits(num);
	return 0;
}