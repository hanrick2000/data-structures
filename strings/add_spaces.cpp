#include<iostream>
#include<cstring>
using namespace std;
/*
You  are	  given	 a  sentence contained in given	
 string S.Write a function which	will replace all the	
 words within the sentence whose length is even and greater than equal to 4, with a space between the two equal	halves of the word.	
  
Input –	"Men have become the tool of their tools" 
Output- "Men ha ve bec ome the to ol of their tools"

Don't use extra space

*/

void add_spaces(string str)
{
	int len=str.length();
	int curr_len=0,additional=0;

	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			//cout<<curr_len<<endl;
			if(curr_len%2==0 && curr_len>=4)
			{
				additional++;
			}	
			curr_len=0;	
		}
		else
			curr_len++;	
		
	}	

	int current_end=len-1;
	int current_index=len-1;
	int move=additional;
	int new_len=len+additional;
	int word_len=0
	while(current_index>-1)
	{
		
		if(arr[current_index]==' ')
		{
			while(word_len--)
			{
				str[]
			}	

			if(word_len%2==0 && word_len>=4)
			{

			}	
		}
		else
		  word_len++;	

		 current_index--;	
	}	

}



int main()
{

	string str="Men have become the tool of their tools";
	//gets(str);
	//string result=add_spaces(str);
	add_spaces(str);
	return 0;	
}