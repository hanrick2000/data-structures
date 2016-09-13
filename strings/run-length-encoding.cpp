#include<iostream>
#include<cstring>
using namespace std;

/*
	No extra space 
*/


void encode2(string str)
{
	int len=str.length();
	char current_char=str[0];
	int unique=1;
	for(int i=1;i<len;i++)
	{
		if(str[i]!=current_char)
		{
			unique++;
			current_char=str[i];
		}	
	}	

	int new_len=len+unique;
	int new_index=new_len-1;
	current_char=str[len-1];
	str[new_len-1]=current_char;
	new_index--;
	int i=len-2;
	while(i>=0)
	{
		if(current_char!=str[i])
		{
			str[new_index]=current_char;
			new_index--;
			current_char=str[i];
			str[new_index]=current_char;
			new_index--;
			i--;
		}	
		else
		{
			str[new_index]=str[i];
			i--;
			new_index--;
		}	
	}

	 new_len=len+unique;
	
	int count=1;
	current_char=str[0];
	int current_index=0;
	for(int j=1;j<=new_len;j++)
	{
		if(current_char !=str[j])
		{
			//cout<<count<<endl;
			str[current_index]=current_char;
			str[current_index+1]=(count-1)+'0';
			current_char=str[j];
			count=1;
			current_index=current_index+2;
		}	
		else
		count++;	
	}	

	for(int j=0;j<current_index;j++)
	{
		cout<<str[j];
	}
	cout<<endl;

}


int main()
{
	string str="abcdefg";
	/*aaabbbccdef*/

	encode2(str);
	return 0;
}