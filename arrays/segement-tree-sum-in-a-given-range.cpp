#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


/*
	three conditions 
	partial overlap -search left and right
	complete overlap - return pos val
	no overlap-return 0
*/

void updateValueUtil(int* seg,int low,int high,int value,int index,int pos)
{
	if (index > high || index < low)
	{
		return;
	}

	seg[pos]=seg[pos]+value;
	if (high!=low)
	{
		int mid=(low+high)/2;
		updateValueUtil(seg,low,mid,value,index,2*pos+1);
		updateValueUtil(seg,mid+1,high,value,index,2*pos+2);
		/* code */
	}
		


	 
}


void updateValue(int* arr,int* seg,int index,int value,int size)
{
	if (index<0 || index>size-1)
	{
		return;
	}

	int diff=value-arr[index];
	arr[index]=value;
	updateValueUtil(seg,0,size-1,diff,index,0);
}

int getSumUtil(int* seg,int low,int high,int qlow,int qhigh,int pos)
{
	//complate overlap
	if ( qlow <= low && qhigh>=high)
	{
		return seg[pos];
	}

	//no overlap

	if( qlow > high || qhigh < low)
	{
		return 0;
	}	

	//partial overlap
	int mid=(low+high)/2;
	return getSumUtil(seg,low,mid,qlow,qhigh,2*pos+1)+getSumUtil(seg,mid+1,high,qlow,qhigh,2*pos+2);
}



int getSum(int* seg,int size,int qlow,int qhigh)
{
	if (qlow<0 || qhigh>size-1 || qlow > qhigh)
	{
		cout<<"Invalid input"<<endl;
		return -1;
	}

	return getSumUtil(seg,0,size-1,qlow,qhigh,0);
}


int* constructTreeUtil(int* arr,int* seg,int low,int high,int pos)
{
	if (low == high)
	{
		seg[pos]=arr[low];
		return seg[pos];
	}

	int mid=(low+high)/2;
	seg[pos]=constructTreeUtil(arr,seg,low,mid,2*pos+1)+constructTreeUtil(arr,seg,mid+1,high,2*pos+2);
	return seg[pos];
}

int* constructTree(int* arr,int size)
{
	int bits=(int)(ceil(log2(size)));
	int segLen=2*(int)pow(2,bits)-1;
	int* seg=new int[segLen];
	constructTreeUtil(arr,seg,0,size-1,0);
	return seg;
}

int main()
{
	int* arr={1, 3, 5, 7, 9, 11};
	int size=sizeof(arr)/sizeof(arr[0]);
	int* segmentTree=constructTree(arr,size);

	return 0;
}
