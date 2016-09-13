#include <iostream>
#include <algorithm>
using namespace std;

class Job
{
public:
	char id;
	int deadline;
	int profit;	
};

bool comparison(Job a,Job b)
{
	return a.profit>b.profit;
}


void jobSequencing(Job arr[],int n)
{
	sort(arr,arr+n,comparison);

	bool status[n];
	int result[n];

	for(int i=0;i<n;i++)
		status[i]=false;



	for (int i = 0; i < n; ++i)
	{
		int j;
		for(j=min(n,arr[i].deadline)-1;j>=0;j--)
		{
			if(!status[j])
			{
				status[j]=true;
				result[j]=i;
				break;
			}	
		}	
	}


	for (int i = 0; i < n; ++i)
	{
		if (status[i])
		{
			cout<<arr[result[i]].id<<endl;
		}
	}
}

int main()
{
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    jobSequencing(arr, n);
    return 0;
}

