#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

/*
On a positive integer, you can perform any one of the following 3 steps. 1.) Subtract
1 from it.(n=n­1) , 2.) If its divisible by 2, divide by 2.( if n%2==0,then n=n/2 ) , 3.) If its
divisible by 3, divide by 3. (if n%3 == 0 , then n = n / 3 ). Now the question is, given a
positive integer n, find the minimum number of steps that takes n to 1 eg:
a. For n = 1 , output: 0
b.For n=4,output:2 (4 /2=2 /2=1)
c. For n=7,output:3 ( 7 ­1=6 /3=2 /2=1)

*/


int min_operations(int num)
{
	int operations[num+1];
	
	operations[0]=0;
	operations[1]=0;
	operations[2]=1;
	operations[3]=1;

	if(num<=3)
	{
		return operations[num];
	}	

	for (int i = 4; i <=num; ++i)
	{
		int val1=i-1,val2=INT_MAX,val3=INT_MAX;
		int oper=operations[i-1];
		if(i%3==0)
		{
			val3=i/3;
			int oper3=operations[val3];
			if(oper3<oper)
				oper=oper3;
		}	
		
		if(i%2==0)
		{
			val2=i/2;
			int oper2=operations[val2];
			if(oper2<oper)
				oper=oper2;
		}	
		
		//int min_val=min(val1,min(val2,val3));
		//cout<<i<<" "<<min_val<<endl;
    	//operations[i]=1+operations[min_val];
    	operations[i]=1+oper;
	}

	// for (int i = 0; i <=num; ++i)
	// {
	// 	cout<<i<<" "<<operations[i]<<endl;
	// }

	return operations[num];

}


int main()
{
	int n;
	cin>>n;
	cout<<min_operations(n);
	return 0;
}