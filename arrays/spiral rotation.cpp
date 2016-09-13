#include<iostream>
using namespace std;

void spiralRotation(int arr[][3],int r,int c)
{
	
}

int main()
{
     int arr[][5]={ {1,2,3,4,5},
     				{6,7,8,9,10},
     				{11,12,13,14,15}
     			  };

    int r=sizeof(arr)/sizeof(arr[0]);
    int c=sizeof(arr[0])/sizeof(arr[0][0]);
    spiralRotation(arr,r,c); 			  
	return 0;
}