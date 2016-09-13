#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

struct interval
{
	int start,end;
};

int comparison(interval a,interval b)
{
	return (a.start < b.start);
}	

void mergedIntervals(interval* arr,int len)
{
	sort(arr,arr+len,comparison);

	stack<interval> s;
	s.push(arr[0]);

	for (int i = 1; i < len; ++i)
	{
		interval topVal=s.top();

		if (arr[i].start > topVal.end)
		{
			s.push(arr[i]);
		}
		else if (arr[i].start < topVal.end)
		{
			if (topVal.end < arr[i].end)
			{
				topVal.end=arr[i].end;
				s.pop();
				s.push(topVal);	
			}
		}
	}


	while(!s.empty())
	{
		interval topVal=s.top();
		cout<<"{"<<topVal.start<<","<<topVal.end<<"}"<<endl;
		s.pop();
	}	
}


void mergedIntervals1(interval* arr,int len)
{
	sort(arr,arr+len,comparison);

	int index=0;

	for (int i = 1; i < len; ++i)
	{
		//cout<<"loop"<<endl;
		if (arr[i].start > arr[index].end)
		{
			//cout<<"Entering"<<endl;
			index++;
		}
		else if (arr[i].start < arr[index].end)
		{
			//cout<<"Entering 2"<<endl;
			if (arr[index].end < arr[i].end)
			{
				arr[index].end=arr[i].end;
			}
		}
	}

	for (int i = 0; i <=index; ++i)
	{
		cout<<"{"<<arr[i].start<<","<<arr[i].end<<"}"<<endl;
	}
}

int main()
{
	interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergedIntervals1(arr, n);
	return 0;
}