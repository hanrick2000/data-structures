#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;


char returnRelevantChar(int val)
{
	if(val==10)
		return 'a';
	else if(val==11)
		return 'b';
	else if(val==12)
		return 'c';
	else
		return 'd';
}


int returnRelevantNum(char val)
{
	if(val=='a')
		return 10;
	else if(val=='b')
		return 11;
	else if(val=='c')
		return 12;
	else
		return 13;
}

string addBase14Numbers(string str1,string str2)
{
	string resultantString="";
	int len1=str1.length(),len2=str2.length();
	len1--;
	len2--;
	cout<<"len1 "<<len1<<" len2 "<<len2<<endl;
	int val1=0,val2=0,result=0,carry=0;
	while(len1>=0 && len2>=0)
	{
		if(isdigit(str1[len1]))
		{
			val1=str1[len1]-'0';
		}	
		else
		{
			val1=returnRelevantNum(str1[len1]);
		}	

		if(isdigit(str2[len2]))
		{
			val2=str2[len2]-'0';
		}	
		else
		{
			val2=returnRelevantNum(str2[len2]);
		}	

		result=val1+val2+carry;
		int append=result%14;
		if(append>=0 && append<=9)
		{
			resultantString+=(append+'0');
		}
		else
		{
			resultantString+=returnRelevantChar(append);
		}	

		carry=result/14;

		len1--;
		len2--;
	}	


	while(len1>=0)
	{
		if(isdigit(str1[len1]))
		{
			val1=str1[len1]-'0';
		}	
		else
		{
			val1=returnRelevantNum(str1[len1]);
		}	

		result=val1+carry;
		int append=result%14;
		if(append>=0 && append<=9)
		{
			resultantString+=(append+'0');
		}
		else
		{
			resultantString+=returnRelevantChar(append);
		}	

		carry=result/14;
		len1--;

	}	

	while(len2>=0)
	{
		if(isdigit(str2[len2]))
		{
			val2=str2[len2]-'0';
		}	
		else
		{
			val2=returnRelevantNum(str2[len2]);
		}	

		result=val2+carry;
		int append=result%14;
		if(append>=0 && append<=9)
		{
			resultantString+=(append+'0');
		}
		else
		{
			resultantString+=returnRelevantChar(append);
		}	

		carry=result/14;
		len2--;
	}	

	if(carry)
	{
		if(carry>=0 && carry<=9)
		{
			resultantString+=(carry+'0');
		}
		else
		{
			resultantString+=returnRelevantChar(carry);
		}	

	}	

	reverse(resultantString.begin(), resultantString.end());
	return resultantString;

}

int main()
{
	string str1,str2;
	//cin>>str1>>str2;
	str1="aaaa";
	str2="a";
	 
    string result=addBase14Numbers(str1,str2);
    //strrev(result);
    cout<<result<<endl;
	return 0;
}