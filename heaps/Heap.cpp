#include <iostream>
#include <climits>
using namespace std;

//Min heap

class Heap
{
	int capacity;
	int *arr;
	int heap_size;
public:
	Heap(int capacity)
	{
		this->capacity=capacity;
		arr=new int[capacity];
		heap_size=0;
	}
	~Heap()
	{
		delete [] arr;
	}
	int parent(int i)
	{
		return (i-1)/2;
	}

	int left(int i)
	{
		return (2*i+1);
	}

	int right(int i)
	{
		return (2*i+2);
	}

	int extractMin();

	int getMin()
	{
		return arr[0];
	}

	void insertKey(int val);

	void deleteKey(int i);

	void decreaseKey(int i,int val);

	void minheapify(int i);

};

void Heap::insertKey(int val)
{
	if(heap_size==capacity)
	{
		cout<<"heap overflow"<<endl;
	}	
	
	heap_size++;
	arr[heap_size-1]=val;
	int i=heap_size-1;
	while(i!=0 && arr[parent(i)]>arr[i])
	{
		swap(arr[parent(i)],arr[i]);
		i=parent(i);
	}	
}

void Heap::decreaseKey(int i,int val)
{
	arr[i]=val;

	while(i!=0 && arr[parent(i)]>arr[i])
	{
		swap(arr[parent(i)],arr[i]);
		i=parent(i);
	}	
}

int Heap::extractMin()
{
	if(heap_size==0)
		return INT_MAX;

	if (heap_size==1)
	{
		heap_size--;
		return arr[0];
	}

	int root=arr[0];
	arr[0]=arr[heap_size-1];
	heap_size--;
	minheapify(0);
	return root;
}

void Heap::deleteKey(int i)
{
	decreaseKey(i,INT_MIN);
	extractMin();
}

void Heap::minheapify(int i)
{
	int left1=left(i);
	int right1=right(i);
	int smallest=i;

	if (left1<heap_size && arr[smallest]<arr[left1])
	{
		smallest=left1;
	}

	if(right1<heap_size && arr[smallest]<arr[right1])
	{
		smallest=right1;
	}	

	if(smallest!=i)
	{
		swap(arr[smallest],arr[i]);
		minheapify(smallest);
	}	

}

int main()
{
	Heap h(10);
	h.insertKey(10);
	h.insertKey(9);
	cout<<h.getMin();
	h.insertKey(8);
	h.insertKey(7);
	cout<<h.getMin();
	cout<<h.extractMin();
	return 0;
}


