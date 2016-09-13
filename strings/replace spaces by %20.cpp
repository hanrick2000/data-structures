#include<iostream>
#include<cstring>
using namespace std;

/*
   Write a method to replace all spaces in a string with ‘%20’.
*/

void replaceSpaces(char* arr,int len)
{

    int noOfSpaces=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==' ')
		{
			noOfSpaces++;
		}	
	}	


	int newLen=noOfSpaces*2+len;

	arr[newLen]='\0';

	for(int i=len-1;i>=0;i--)
	{
		if(arr[i]==' ')
		{
			arr[newLen-1]='%';
			arr[newLen-2]='0';
			arr[newLen-3]='2';
			newLen=newLen-3;

		}
		else
		{
			arr[newLen-1]=arr[i];
			newLen--;
		}	
	}	
}


int main()
{
	char str[]="my name is tanvi";
	int len=strlen(str);
	replaceSpaces(str,len);
	cout<<str<<endl;
	return 0;
}
