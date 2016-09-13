#include<iostream>
#include<stack>
using namespace std;

class TwoStacks
{
	int *arr;
	int topIndex1,topIndex2,size;
public:
	TwoStacks(size)
	{
		arr=new int[size];
		topIndex1=-1;
		topIndex2=size;
		this->size=size;
	}
	~TwoStacks()
	{
		delete [] arr;
	}
	
	void push1(int data);
	void push2(int data);
	int top1();
	int top2();
	void pop1();
	void pop2();
};

void TwoStacks::push1(int data)
{
   if(topIndex1<topIndex2-1)
   {
   		arr[++topIndex1]=data;
   }
   else
   {
   	cout<<"stack overflow"<<endl;
   }	
}

void TwoStacks::push2(int data)
{
    if(topIndex1<topIndex2-1)
   {
   		arr[--topIndex2]=data;
   }
   else
   {
   	cout<<"stack overflow"<<endl;
   }	
}

int TwoStacks::top1()
{
	if(topIndex1==-1)
	{
		cout<<"stack empty"<<endl;
		return -1;
	}	
	else
	{
		int val=arr[topIndex1];
		topIndex1--;
		return val;
	}	
}

int TwoStacks::top2()
{
	if(topIndex2==size)
	{
		cout<<"stack empty"<<endl;
		return -1;
	}	
	else
	{
		int val=arr[topIndex2];
		topIndex2++;
		return val;
	}	
}

void TwoStacks::pop1()
{
	if(topIndex1==-1)
	{
		cout<<"stack empty"<<endl;
		//return -1;
	}	
	else
	{
		//int val=arr[topIndex1];
		topIndex1--;
		//return val;
	}	
}

void TwoStacks::pop2()
{
	if(topIndex2==size)
	{
		cout<<"stack empty"<<endl;
		//return -1;
	}	
	else
	{
		//int val=arr[topIndex2];
		topIndex1++;
		//return val;
	}	
}

int main()
{
	return 0;
}