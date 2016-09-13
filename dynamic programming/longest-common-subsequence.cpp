#include <iostream>
#include <cstring>
using namespace std;


/* output[i][j] represents lcs of last i characters of string s and last j characters of string t */
int lcsRecursive(char* s,char* t,int sLen,int tLen,int** output)
{
	if(s[0]=='\0' || t[0]=='\0')
		return 0;

	if(output[sLen][tLen]>-1)
		return output[sLen][tLen];

	int ans;
	if(s[0]==t[0])
	{
		ans=1+lcsRecursive(s+1,t+1,sLen-1,tLen-1,output);
	}	
	else
	{
		ans=max(lcsRecursive(s+1,t,sLen-1,tLen,output),lcsRecursive(s,t+1,sLen,tLen-1,output));
	}	

	output[sLen][tLen]=ans;
	return ans;
}


int lcsIterative(string s,string t)
{
	 int m=s.length();
	 int n=t.length();

	int** output=new int*[m+1];
	for(int i=0 ; i<m+1 ; i++)
	{
		output[i]=new int[n+1];
		for(int j=0 ; j<n+1 ; j++)
		{
			if( i==0 || j==0 )
			{
				output[i][j]=0;
			}	
			else 
				output[i][j]=-1;
		}	
	}

	for(int i=1; i< m+1; i++)
	{
		for(int j=1; j<n+1; j++)
		{
			if(s[m-i]==t[n-j])
			{
				output[i][j]=1+output[i-1][j-1];
			}	
			else
			{
				output[i][j]=max(output[i-1][j],output[i][j-1]);
			}	

		}
	}	

	//deallocate

	for(int i=0;i<m+1;i++)
	{
		delete [] output[i];
	}	

	delete [] output;

	return output[m][n];


}

 


int main()
{

	// char s[]="abcdef";
	// char t[]="adedef";
	// int slen=strlen(s);
	// int tLen=strlen(t);
	// int** output=new *int[slen+1];
	// for(int i=0;i<sLen+1;i++)
	// {
	// 	output[i]=new int[tLen+1];
	// 	for(int j=0;j<tLen+1;j++)
	// 	{
	// 		output[i][j]=-1;
	// 	}	
	// }

    string s,t;
    cin>>s>>t;

	cout<<lcsIterative(s,t)<<endl;	
	return 0;
}