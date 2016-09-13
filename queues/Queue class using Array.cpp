#include<iostream>
#include<cstring>
using namespace std;

class Queue
{
	int* arr;
	int front;
	int rear;
	int maxsize;
	int currentsize;
public:
	Queue(int maxsize)
	{
		this->maxsize=maxsize;
		arr=new int[maxsize];
		front=0;
		rear=-1;
		currentsize=0;
	}
	~Queue()
	{
		delete arr;
	}

	void enqueue(int data);
	int dequeue();
	bool isEmpty();

};

void Queue::enqueue(int data)
{
	if(currentsize==maxsize)
	{
		cout<<"Queue is full"<<endl;
		return;
	}
	rear++;
	currentsize++;
	arr[rear]=data;
}

int Queue::dequeue()
{
	if(currentsize==0)
	{
		cout<<"Queue empty"<<endl;
		return -1;
	}

	int data=arr[front];
	front++;
	currentsize--;
   return data;
}

bool Queue::isEmpty()
{
    if(currentsize==0)
    	return true;
    return false;
}

void print(Queue q){
while(!q.isEmpty())
   {
    cout<<q.dequeue()<<" ";
    }
 return ;
}

int main()
{
	Queue *q=new Queue(5);
q->enqueue(1);
q->enqueue(2);
q->enqueue(3);
q->enqueue(4);
q->enqueue(5);
q->enqueue(6);
q->enqueue(7);
print(*q);
	return 0;
}