#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*
     1,2,3.....n-1
     if n=2 solution:(1,1)
      	n=3 solution:(1,1,1),(1,2),(2,1)
      	n=4 solution: (1,1,1,1),(1,1,2),(1,2,1),(2,1,1),(2,2),(3,1),(1,3)
*/

void printWays(int n,vector<int> &output,bool first=true)
{
	if(n==0)
	{
		for(int i=0;i<output.size();i++)
		{
			cout<<output.at(i)<<",";
		}	
		cout<<endl;
		return;
	}	

 	int end;
    if(first)
    {
    	end=n-1;
    }	
    else
    {
    	end=n;
    }	


	for(int i=1;i<=end;i++)
	{
		output.push_back(i);
		cout<<"pushing "<<i<<endl;
		printWays(n-i,output,false);
		cout<<"entering pop_back"<<endl;
		output.pop_back();//pop out the numbers added.
	}	
}


int main()
{
	vector<int> v;
	printWays(5,v);

	return 0;
}