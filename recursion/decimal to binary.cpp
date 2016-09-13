#include<iostream>
using namespace std;


int decimalToBinary(int num)
{
	if(num==0 || num==1)
		return num;

	int val=num%2;
	int majorPart=decimalToBinary(num/2);
	return 10*majorPart+val;
	 
}

int main()
{
   int val=16;	
   int num=decimalToBinary(val);
   cout<<num<<endl;
   return 0;
}