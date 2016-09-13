#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void checkpair(int* a,int n,int sum)
{
   sort(a,a+n);
   int l=0,r=n-1;

   while(l<r)
   {
   	  if((a[l]+a[r])<sum)
   	  	l++;
   	  else if((a[l]+a[r])>sum)
   	    r--;
   	  else
   	  {
   	  	printf("Found\n");
   	  	printf("%d %d\n",a[l],a[r]);
   	  	l++;
   	  	r--;/*This is done as it prints all pairs intead of just one*/
   	  	//break;
   	  }      	
   }	
}

void checkpair1(int* a,int n,int sum)
{ 
	map<int,bool> my_map;
	for(int i=0;i<n;i++)
		my_map[a[i]]=true;

	for(int i=0;i<n;i++)
		if(my_map[sum-a[i]]==true)
			printf("Found %d %d \n",sum-a[i],a[i]);/*This is showing repeated answers*/
}


int main()
{
	int a[]={8,17,1,6,4,3};
	int n=sizeof(a)/sizeof(int);
	int sum=7;
	checkpair1(a,n,sum);
	return 0;
}