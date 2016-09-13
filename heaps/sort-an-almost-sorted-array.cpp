#include <iostream>
#include <cstring>
using namespace std;

/*
 #1 use insertion sort	runs k times,O(nk)
*/
 
/*
1) Create a Min Heap of size k+1 with first k+1 elements. This will take O(k) 
	time (See this GFact)
2) One by one remove min element from heap, put it in result array, and add a new element to
   heap from remaining elements.
   Removing an element and adding a new element to min heap will take Logk time. 
   So overall complexity will be O(k) + O((n-k)*logK)
 */

 class Minheap
   {
   	int* arr;
   	int heap_size;
   public:
   	Minheap(int *a,int size);
   	~Minheap()
   	{
   		delete [] arr;
   	}

   	int left(int i)
   	{
   		return (2*i+1);
   	}

   	int right(int i)
   	{
   		return (2*i+2);
   	}

   	int parent(int i)
   	{
   		return ((i-1)/2);
   	}

   	void minheapify(int i);

   	int extractMin();

   	int replaceMin(int val);
 
   };  


Minheap::Minheap(int a[], int size)
{
    heap_size = size;
    arr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        minheapify(i);
        i--;
    }
}
 


void Minheap::minheapify(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<heap_size && arr[l]<arr[smallest])
	{
		smallest=l;
	}
	if(r<heap_size && arr[r]<arr[smallest])
	{
		smallest=r;
	}

	if(smallest!=i)
	{
		swap(arr[smallest],arr[i]);
		minheapify(smallest);
	}	
}   

int Minheap::extractMin()
{
	int root=arr[0];
	if(heap_size>1)
	{	
		arr[0]=arr[heap_size-1];
		heap_size--;
		minheapify(0);
	}	
	return root;
}

int Minheap::replaceMin(int val)
{
	int root=arr[0];
	arr[0]=val;
	if (root<val)
	{
		minheapify(0);
	}
		
	return root;	
} 

void sortK(int* arr,int n,int k)
{
	int* arr_k=new int[k+1];

	for (int i = 0; i <=k && i<n; ++i)
	{
		arr_k[i]=arr[i];
	}

	Minheap mh(arr_k,k+1);

	for (int i = k+1, ti = 0; ti < n; ++ti)
	{
		if (i<n)
		{
			 arr[ti]=mh.replaceMin(arr[i]);
		}
		else
		{
			arr[ti]=mh.extractMin();
		}	
	}
}

void printArray(int* arr,int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{

	int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    sortK(arr, n,k);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
	return 0;
}

