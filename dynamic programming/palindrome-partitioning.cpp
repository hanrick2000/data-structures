#include <iostream>
#include <cstring>
#include <climits>
using namespace std;


int palindromePartitioning(string str)
{
	if (str.length()==0)
	{
		return -1;
	}

	int size=str.length();
	bool p[size][size];
	int c[size][size];
	memset(p,0,sizeof(p));
	memset(c,0,sizeof(c));

	for (int i = 0; i < size; ++i)
	{
		p[i][i]=1;
		c[i][i]=0;
	}

	for (int len = 2; len <=size; ++len)
	{
		for (int i = 0; i < size-len+1; ++i)
		{
			int j=i+len-1;

			if(str[i]==str[j] && len==2)
			{
				p[i][j]=1;
			}	
			else if (str[i] == str[j])
			{
				p[i][j]=p[i+1][j-1];
			}

			if (p[i][j]==true)
			{
				c[i][j]=0;
			}
			else
			{
				c[i][j]=INT_MAX;
				for (int k = i; k < j; ++k)
				{
					c[i][j]=min(c[i][j],c[i][k]+c[k+1][j]+1);
				}
				
			}	
		}	
	}

	return c[0][size-1];
}


int main()
{

	 //string str = "ababbbabbababa";
	string str;
	cin>>str;
     cout<<palindromePartitioning(str);

	return 0;
}