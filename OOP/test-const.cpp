#include<iostream>
#include<cstring>
using namespace std;


int main()
{

    // const int z;   //Cannot do this.error: assignment of read-only variable ‘z’
    // z=1;

    const int z=1;  /*this works fine*/


    const int a1=10;
    //int* b=&a1; /*cannot read only to read-write*/
    //int &b=a1;   /*This is also invalid*/

   
    int val=10;
    const int &b1=val;
    //b1++; /* error: increment of read-only reference ‘b1’*/
    
   
     val++;  /*but we can increment via the rw way! */
     cout<<b1<<endl; 

   
     const int &c=b1;
     //int &c1=b1;  /*This cannot be done,otherwise fails the purpose!*/
   

	int a00=100;
	int * const p=&a00;  /*integer pointer is constant,read and write privileges*/
	cout<<p<<endl;
	cout<<*p<<endl;
	(*p)++;           /*via the rw way I can increment the value*/
	cout<<p<<endl;
	cout<<*p<<endl;

	a00++;
	cout<<*p<<endl;


   
     int a11=1000;
     int const* pc=&a11;/*Integer i am pointing to is constant,read only privilege*/
	 cout<<pc<<endl;
	 cout<<*pc<<endl;
     //(*pc)++;  error: increment of read-only location ‘* pc’ ,cannot change value via the read only way
	 //pc++;
	 a11++;
	 cout<<pc<<endl;
	 cout<<*pc<<endl;

	
	 int a22=2000;
	 int const* const cpc=&a22;
	 //(*cpc)++; cannot do this !
     a22++;
     cout<<*cpc<<endl;




}

