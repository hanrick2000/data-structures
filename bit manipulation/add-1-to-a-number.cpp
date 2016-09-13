#include <iostream>
using namespace std;

/*
	To add 1 to a number x (say 0011000111), we need to flip all the bits after the rightmost 0 bit (we get 0011000000). 
	Finally, flip the rightmost 0 bit also (we get 0011001000) and we are done.
*/

int addOne(int x)
{
	int one=1;
	/* Flip all the set bits until we find a 0 */
	while(x & one)
	{
		x=x^one;
		one<<1;
	}

	/* flip the rightmost 0 bit */
	x=x^one;
	return x;

}


//method 2

/*
~x = -(x+1) [ ~ is for bitwise complement ]

(x + 1) is due to addition of 1 in 2’s complement conversion

To get (x + 1) apply negation once again. So, the final expression becomes (-(~x)).
*/

int addOne1(int x)
{
	return (-(~x));
}

int main()
{
	int num=10;
	cout<<addOne(num);
	return 0;
}