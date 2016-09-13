#include<iostream>
#include<cstring>
using namespace std;

/*
  concept of inheritance and runtime binding
*/

class shape
{
    int a;

public:

	// int func1()
	// {
	// 	return 10;
	// }	
	int b;

	virtual int func1()
	{
		return 10;
	}	

	int func2()
	{
		return 20;
	}
	int func3()
	{
		return 30;
	}
	 
};

class rect : public shape
{

public:
	int func1()
	{
		return 40;
	}
	 
	
};

class circle:protected shape
 {
 public:
 	 
 	
 }; 

int main()
{
	shape *s1=new rect();
	cout<<s1->func1()<<endl;
	
	/* rect *r1=new shape;   This is illegal */
	/* rect *r=s1; This is illegal */
	rect *r1=(rect*) s1;  /*I know rectangle is a shape,do it for me!*/
	cout<<r1->func1()<<endl;
	return 0;
}