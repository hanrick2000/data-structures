#include <iostream>
#include <cstring>
using namespace std;

/*
Assume   that   value   of   a=1,   b=2,   c=3,   d=4,   ....   z=26.   You   are   given   a   numeric   string  
S.   Write   a   program   to   find   and   print   list   of   all   possible   codes   that   can   be   generated  
from the given string. E.g. 1123  aabc, kbc, alc, aaw, kw  
*/

int decoder(string input)
{
	int dp[input.length()+1];
	
	dp[0]=1;
	dp[1]=1;

	for (int i = 2; i <=input.length(); ++i)
	{
		
	}

}

int main()
{
	return 0;
}