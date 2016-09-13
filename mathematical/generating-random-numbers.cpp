#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

/*
	How to generate random integer between A and B, using an unbiased coin. For ex. 
	If A = 3 and B = 6 then your algorithm should generate 3, 4, 5, 6 with equal probabilities.

*/

/*Check if this works !*/	
/*O(log(b-a))*/	

int coin_toss()
{
	srand(time(NULL));
	int val=rand()%2;/*val b/w 0 and 1*/
	return val;
}

int generateRandomNumbers(int a,int b)
{
	int n=b-a;
	int k=1+log(b-a); //no of bits to represent numbers b/w a and b
	int r=0;
	for(int i=1;i<=k;i++)
	{
		int bit=coin_toss();
		r+=bit;
		r<<=1;
		if(r>n)
			return generateRandomNumbers(a,b);
		return r;
	}	

}

int main()
{

}