#include <iostream>
#include <cmath>
using namespace std;

#define PRIME 5

/*using the rolling hash function*/

int createHash(string str,int len)
{ 
	int hash=0;
	for (int i = 0; i < len; ++i)
	{
		hash+=str[i]*pow(PRIME,i);
		//cout<<hash<<endl;
	}

	return hash;
}

int recalculateHash(string str,int oldIndex,int newIndex,int oldHash,int len)
{
	int newHash=oldHash-str[oldIndex];
	newHash/=PRIME;
	newHash=newHash+str[newIndex]*pow(PRIME,len-1);
	return newHash;
}

bool checkIfEqual(string str1,string str2)
{
	if (str1.compare(str2)!=0)
	{
		return 0;
	}
	return 1;
}

void rabinKarp(string text,string pattern)
{
	int textLen=text.length();
	int patternLen=pattern.length();

	int hashPattern=createHash(pattern,patternLen);
	int hashText=createHash(text,patternLen);
	//cout<<"pattern "<<hashPattern<<endl;
	for(int i=0;i<=textLen-patternLen;i++)
	{
		//cout<<hashText<<endl;
	   if (hashPattern == hashText && checkIfEqual(pattern,text.substr(i,patternLen)))
	   {
	   		cout<<i<<endl;
	   }

	   if (i < textLen-patternLen)
	   {
	   	  hashText=recalculateHash(text,i,i+patternLen,hashText,patternLen);
	   }
	}	
}

int main()
{
	string pattern="aba";
	string text="abcababacabab";
	cout<<text<<endl<<pattern<<endl;
	rabinKarp(text,pattern);
	//cout<<createHash("aba",3);
	return 0;
}