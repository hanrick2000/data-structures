#include <iostream>
#include <stack>
using namespace std;


int knows(int** arr,int i,int j)
{
	return arr[i][j];
}

int	celebrity(int** arr,int n)
{
	stack<int> s;
	
	for (int i = 0; i < n; ++i)
	{
		s.push(i);
	}

	int a=s.top();
	s.pop();
	int b=s.top();
	s.pop();

	while(s.size()>1)
	{
		if (knows(arr,i,j))
		{
			a=s.top();
			s.pop()
		}
		else
		{
			b=s.top();
			s.pop();
		}	
	}	

	//Last person not compared.
	int c=s.top();
	s.pop();
    
    if (knows(c,b))
    {
    	c=b;
    }

    if (knows(c,a))
    {
    	c=a;
    }


    for (int i = 0; i < n; ++i)
    {
    	if (i!=c && ( knows(c,i) || !knows(i,c)))
    	{
    		return -1;
    	}
    }

    return c;


}


int celebrity1(int** arr,int n)
{

	int a=0;
	int b=n-1;

	//Do until a and b become equal
	while(a<b)
	{
		if (knows(arr,a,b))
		{
			a++;
		}
		else
		{
			b--;
		}	
	}	


	for (int i = 0; i < n; ++i)
	{
		if (i!=a && (knows(a,i) || !knows(i,a)) )
		{
			return -1;
		}
	}

	return a;
}


int main()
{
	int n;
	cin>>n;
	int** arr=new *int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]=new int[n];
	}

	cout<<;

	delete [] arr;
	for (int i = 0; i < n; ++i)
	{
		delete arr[i];
	}
	return 0;
}