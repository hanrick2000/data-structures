#include <iostream>
#include <cstring>
using namespace std;



void generatePermutationsHelper(char* s,string prefix,int sLen,int k)
{
	if(k==0)
	{
		cout<<prefix<<endl;
		return;
	}	

	for(int i=0;i<sLen;i++)
	{
	    string newPrefix=prefix+s[i];
	    generatePermutationsHelper(s,newPrefix,sLen,k-1);
	}	

}


void generatePermutations(char* s,int k)
{
	int len=strlen(s);
	generatePermutationsHelper(s," ",len,k);
}

int main()
{
	char s[]="abc";
	int k=2;
	generatePermutations(s,k);
	return 0;
}