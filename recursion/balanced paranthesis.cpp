#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void balancedParanthesisHelper(int l,int r,char str[],int count)
{
	//base cases
	if(l<0 || l>r)
	{
		return;
	}	

	if(l==0 && r==0)
	{
		cout<<str<<endl;
		return;
	}	
	//else
	//{	
		if(l>0)
		{
			str[count]='(';
			balancedParanthesisHelper(l-1,r,str,count+1);
		}	
		if(r>0)
		{
			str[count]=')';
			balancedParanthesisHelper(l,r-1,str,count+1);
		}

	//}	
}

void balancedParanthesis(int n)
{
	char str[40];
	balancedParanthesisHelper(n,n,str,0);
}



int main()
{
	balancedParanthesis(6);
	return 0;
}
