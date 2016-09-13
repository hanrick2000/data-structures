#include <iostream>
#include <string>
using namespace std;


void print(string output,int start,int num)
{
	if (num==0)
	{
		cout<<output<<" ";
	}

	for (int i = start; i <=9; ++i)
	{
		string result=output+ to_string(i); //to_string() function works with c++ 11
		print(result,i+1,num-1);
	}
}

int main()
{
	int num=2;
	string output="";
	print(output,0,num);
	return 0;
}