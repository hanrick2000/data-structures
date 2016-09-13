#include<iostream>
#include<cstring>
using namespace std;

void subsetSumK(int* arr,int* temp,int startIndex,int tempIndex,int sum,int len)
{
	if(startIndex==len && sum==0)
	{
        cout<<"[ ";
        for(int i=0;i<tempIndex;i++)
        	cout<<temp[i]<<" ";
        cout<<"]"<<endl;
        return;
	}	

    if(startIndex==len && sum!=0)
    	return;

	temp[tempIndex]=arr[startIndex];
	subsetSumK(arr,temp,startIndex+1,tempIndex+1,sum-arr[startIndex],len);
	subsetSumK(arr,temp,startIndex+1,tempIndex,sum,len);

}


int main()
{
	int arr[]={1,2,3,4,5};
    int temp[5];
    int size=sizeof(arr)/sizeof(arr[0]);
    int sum=9;
    subsetSumK(arr,temp,0,0,sum,size);

	return 0;
}
