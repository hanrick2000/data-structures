#include<iostream>
using namespace std;

/*
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps or 3
steps at a time. Implement a method to count how many possible ways the child can
run up to the stairs

*/

//solution for 1 or 2 steps at a time

int fib(int n)
{
	if(n<=1)
		return 1;
	return fib(n-1)+fib(n-2);
}


int child-staircase(int n)
{
	return fib(n+1);
}


int countWaysUtil(int n, int m)
{
    int res[n];
    res[0] = 1; res[1] = 1;
    for (int i=2; i<n; i++)
    {
       res[i] = 0;
       for (int j=1; j<=m && j<=i; j++)
         res[i] += res[i-j];
    }
    return res[n-1];
}
 
// Returns number of ways to reach s'th stair
int countWays(int s, int m)
{
    return countWaysUtil(s+1, m);
}

int main(int argc, char const *argv[])
{
	 
	return 0;
}


