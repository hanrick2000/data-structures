#include<iostream>
#include<cstring>
using namespace std;

/*
   Design an algorithm and write code to remove the duplicate characters in a string
   without using any additional buffer. NOTE: One or two additional variables are fine.
   An extra copy of the array is not.

*/

void removeDuplicates(char* arr,int len)
{
	int currentIndex=1;
	for(int i=1;i<len;i++)
	{
		char current=arr[i];
		bool flag=true;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]==current)
			{
				flag=false;
				break;
			}	
		}

		if(flag)
		{
			arr[currentIndex++]=current;
		}	
	}	


	for(int i=0;i<currentIndex;i++)
	{
		cout<<arr[i];
	}	

	cout<<endl;
}


int main()
{
	char str[]="aabcdacgsakc";
	int len=strlen(str);
	removeDuplicates(str,len);
	return 0;
}
