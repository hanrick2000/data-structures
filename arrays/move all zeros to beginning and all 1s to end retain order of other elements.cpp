#include<iostream>
#include<cstdio>
using namespace std;

/*
   Best TC-O(n),SC-O(1)
   Initially arr={3,2,6,0,1,1,0,8,3,2,6,0}
         Finally={0,0,0,3,2,6,8,3,2,6,1,1}
*/

 

void swap(int arr[], int fi, int si, int d);
 
void leftRotate(int arr[], int d, int n)
{ 
  /* Return If number of elements to be rotated is 
    zero or equal to array size */ 
  if(d == 0 || d == n)
    return;
     
  /*If number of elements to be rotated is exactly 
    half of array size */ 
  if(n-d == d)
  {
    swap(arr, 0, n-d, d);   
    return;
  }  
     
 /* If A is shorter*/             
  if(d < n-d)
  {  
    swap(arr, 0, n-d, d);
    leftRotate(arr, d, n-d);    
  }    
  else /* If B is shorter*/             
  {
    swap(arr, 0, d, n-d);
    leftRotate(arr+n-d, 2*d-n, d); /*This is tricky*/
  }
}
 
 
 
/*This function swaps d elements starting at index fi
  with d elements starting at index si */
void swap(int arr[], int fi, int si, int d)
{
   int i, temp;
   for(i = 0; i<d; i++)   
   {
     temp = arr[fi + i];
     arr[fi + i] = arr[si + i];
     arr[si + i] = temp;
   }     
}         

void change(int* arr,int n)
{
	int countZero=0,count1=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			countZero++;
		}

		else if(arr[i]==1)
		{
			count1++;
		}	
	}	

	int remaining=n-(count1+countZero);
    int counter=0;
    cout<<"zeros "<<countZero<<" count1 "<<count1<<endl;

    /*
      the next loop puts all nos(except zeros and ones in the beginning)
    */ 
	for(int i=0;i<n;i++)
	{
		 //cout<<"updating normal numbers"<<arr[i]<<endl;

         if(arr[i]!=0&&arr[i]!=1)
         {
         	arr[counter]=arr[i];
         	//cout<<"If condition "<<arr[counter]<<endl;
         	counter++;
         } 	
	}
     

    int n1=n-1;
	while(count1--)
	{
         arr[n1--]=1;
	}	
    
    for(int i=counter;i<counter+countZero;i++)
    	arr[i]=0;
    //block swap of 0s and other elements in the front
   leftRotate(arr,counter,countZero+counter);

}

void print(int* arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

int main()
{
    int arr[]={3,2,6,0,1,1,0,8,3,2,6,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Initially"<<endl;
    print(arr,size);
    change(arr,size);
    cout<<"After changes"<<endl;
    print(arr,size);

	return 0;
}


 