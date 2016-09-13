#include <iostream>
#include <cstring>
using namespace std;

/*
You have n boxes all with height 1. You have two arrays of size n containing lengths
& widths of boxes. One box can be placed above another one only if its width and
height is less than the other box. Find max height you can obtain by stacking these
boxes over one another.
*/


int stackHeight(int* width,int* height,int size)
{
	int val[size];

	for (int i = 0; i < size; ++i)
	{
		val[i]=1;
	}

	int maxHeight=1;
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
		if(((width[i]>=width[j] && height[i]>=height[j]) || (height[i]>=width[j] && width[i]>=height[j])))&& val[i]<val[j]+1)
			{
				val[i]=val[j]+1;
				if(maxHeight<val[i])
					maxHeight=val[i];
			}
		}
	}

	return maxHeight;
}

int main()
{

	return 0;
}