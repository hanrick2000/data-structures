#include<iostream>
#include <cstring>
using namespace std;

/*
  Naive recursive solution O(3^m)

*/

// int NaiveEditDistance(string str1,string str2,int sLen,int tLen)
// {
// 	if(sLen==0)
// 		return tLen;
// 	if(tLen==0)
// 		return sLen;

// 	if(str1[sLen-1]==str2[tLen-1])
// 		NaiveEditDistance(str1,str2,sLen-1,tLen-1);

// 	return min(1+NaiveEditDistance(str1,str2,sLen-1,tLen-1),min(1+NaiveEditDistance(str1,str2,sLen-1,tLen),1+NaiveEditDistance(str1,str2,sLen,tLen-1));

// }



int editdistance(string str1,string str2)
{
	int m=str1.length(),n=str2.length();

	// int **result=new int*[m+1];
	// for(int i=0; i<m+1 ;i++)
	// {
	// 	result[i]=new int[n+1];

	// 	for(int j=0 ;j<m+1 ;j++)
	// 	{ 
	// 		result[i][j]=0;
	// 	}	

	// }

	int result[m+1][n+1];
	memset(result,0,sizeof(result));

	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			//cout<<i<<" "<<j<<endl;
			if(i==0)
			{
				result[i][j]=j;
			}
			else if(j==0)
			{
				result[i][j]=i;
			}	
			else if(str1[i-1]==str2[j-1])
			{
				result[i][j]=result[i-1][j-1];		
			}	
			else 
			{
				// cout<<"Entering"<<endl;
				// int val=min(result[i-1][j-1],min(result[i][j-1],result[i-1][j]));
				// cout<<val<<endl;
				result[i][j]=1+min(result[i-1][j-1],min(result[i][j-1],result[i-1][j]));
			}	
		}	
	}	

	// for (int i = 0; i < m+1; ++i)
	// {
	// 	for (int j = 0; j < n+1; ++j)
	// 	{
	// 		cout<<result[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// for(int i=0;i<n+1;i++)
	// 	delete [] result[i];
	// delete[] result;

	return result[m][n];


}


int main()
{
	// string str1="abcd";
	// string str2="dabc";
	string str1,str2;
	cin>>str1>>str2;
	cout<<editdistance(str1,str2);

	return 0;
}