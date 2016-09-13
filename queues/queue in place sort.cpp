#include <iostream>
#include <queue>
#include <climits>
using namespace std;



//This function just returns the minimum in the window 0 to k

int findMin(queue<int> &q,int k,int n)
{
	int min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		int current=q.front();
		q.pop();
		if(current<min && i<k)
		{
			min=current;
		}	
		q.push(current);
	}	
	return min;
}

void reorder(queue<int> &q,int min,int n)
{
	for(int i=0;i<n;i++)
	{
		int current=q.front();
		q.pop();
		if(current!=min)
		{
			q.push(current);
		}	
	}	

	q.push(min);
}

void sort(queue<int> &q)
{
	int n=q.size();
	for(int i=0;i<n;i++)
	{
		int min=findMin(q,n-i,n);
		reorder(q,min,n);
	}	
}

int main()
{
   queue<int> q;
   q.push(7);
   q.push(8);
   q.push(3);
   q.push(1);
   q.push(2);
   sort(q);

   while(!q.empty())
   {
   	  int val=q.front();
   	  cout<<val<<" ";
   	  q.pop();
   }

   cout<<endl;

}