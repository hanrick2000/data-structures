#include<iostream>
using namespace std;

/*
  1) Diving by 10 can cause overflow
  2) No of 2s are more than 5	
	Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....

 we may have extra 5s,therefore divided by 25,125...                  
*/

int trailingzeros(int n)
{
	int i;
	int count=0;
	for(i=5;n/i>=1;i*=5)
		count+=n/i;

	return count;
}


 int main()
 {
 	return 0;
 }