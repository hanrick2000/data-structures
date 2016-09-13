#include <iostream>
#include <stack>
using namespace std;

/*
Given an array, print the Next Greater Element (NGE) for every element. The Next greater 
Element for an element x is the first greater element on the right side 
of x in array. Elements for which no greater element exist, consider next greater element as -1.
*/
//O(n^2)

void printNextGreaterElement(int* arr,int n)
{
	stack<int> s;
    //int current=arr[0];
    //s.push(current);
    for(int i=0;i<n;i++)
    {
    	//cout<<"current val "<<arr[i]<<endl;
    	if(!s.empty() && arr[i]>s.top())
    	{
    		while(arr[i]>s.top())
    		{
    			cout<<s.top()<<" "<<arr[i]<<endl;
    			s.pop();
    			if(s.empty())
    				break;
    		}	
 
    	}
    	 
    	s.push(arr[i]);
    }	


    while(!s.empty())
    {
    	int data=s.top();
    	cout<<data<<" -1"<<endl;
    	s.pop();
    }	
}

int main()
{
	int arr[]={4, 5, 2, 25};
	int n=sizeof(arr)/sizeof(arr[0]);
	printNextGreaterElement(arr,n);
	return 0;
}