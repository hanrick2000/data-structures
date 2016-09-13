#include <iostream>
#include <cstring>
using namespace std;

/*--------------------------------Recursive Solution--------------------*/

int lpsHelper(string str,int i,int j)
{
	if(i==j)
		return 1;

	if(str[i]==str[j] && i+1==j)
		return 2;

	if(str[i]==str[j])
		return lpsHelper(str,i+1,j-1)+2;

	return max(lpsHelper(str,i+1,j),lpsHelper(str,i,j-1));
}

int lps1(string arr)
{	
	int size=arr.length();
	return lpsHelper(arr,0,size-1);
}


/*---------------------DP Solution-------------------------------------*/
 
int lpsDP(string str)
{
	int n = str.size();
	int i, j, cl;
	int L[n][n]; // Create a table to store results of subproblems

	for (i = 0; i < n; ++i)
		L[i][i] = 1;
 
	for (cl=2; cl<=n; ++cl)
	{
		for (i=0; i<n-cl+1; ++i)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}


int main()
{		
	string seq;
	cin>>seq;
	//string seq = "GEEKS FOR GEEKS";
    //int n = strlen(seq);
    cout<<lpsDP(seq);
	return 0;
}