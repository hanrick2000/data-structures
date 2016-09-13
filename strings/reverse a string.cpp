#include<iostream>
#include<cstdio>
using namespace std;

/*Reverse a C-styled string*/


void reverse(char* str)
{
	char* last=str;
	
	while(*last)
	{
		last++;
	}	
	//reaches the null character,thus decreament.	
	last--;

	while(str<last)
	{
		char temp=*str;
		*str++=*last;
		*last--=temp;
	}

}

int main()
{
	reverse(char* str);
	return 0;
}