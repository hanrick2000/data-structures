#include <iostream>
using namespace std;

/*
	Input:  str[] = "ABC"
	Output: ABC
        AB C
        A BC
        A B C
*/

void printStrings(char* str,char* buff,int i,int j,int n)
{
	if (i == n)
	{
		buff[j]='\0';
		cout<<buff<<endl;
	}

	buff[j]=str[i];
	printStrings(str,buff,i+1,j+1,n);

	buff[j]=' ';
	buff[j+1]=str[i];
	printStrings(str,buff,i+1,j+2,n);

}

 int main()
 {
 	char str[]="ABC";
 	int len=strlen(str);
 	char buff[2*len];
 	buff[0]=str[0];
 	printStrings(str,buff,1,1,len);
 	return 0;
 }       