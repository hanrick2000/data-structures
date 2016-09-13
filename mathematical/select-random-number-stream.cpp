#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/*
	How to pick a number randomly from a stream (or a linked list) with 
	a finite but unknown length N? Solution must use constant space and 
	guarantee that number is picked with probability = 1/N. 

Solution:
If we know the length of the stream, then problem is trivial. 
Simply generate a random number r between 1 and N. Declare the number 
at index r as the desired random number.

For an unknown but finite N, we need that elements are selected
 with equal probability. Let us first build the loop invariant property for the solution. Say we have seen k elements so far, the selected number (say n) must be selected with probability 1/k. As we see a new element (say n1), we should set n=n1 with probability 1/(k+1). This ensures that n1 is selected with probability 1/(k+1). In the other case, n (the one NOT replaced by n1) is selected with probability = 1/k * (1-1/(k+1)) = 1/(k+1). Hence this strategy ensures that a number a selected with probability 1/N for N>=k. This loop invariant is adhered by the following code:
n=0, N=0
while Stream.hasElement()
  ++N
  if rand <= 1/N 
    n = Stream.nextElement()
return n
After the algorithm processes all elements, n would contain the randomly selected element and N would contain the number of elements in the stream.

*/

/*
  We need to prove that every element is picked with 1/n probability where n is the number of items seen so far. For every new stream item x, we pick a random number from 0 to ‘count -1′, if the picked number is ‘count-1′, we replace the previous result with x.

To simplify proof, let us first consider the last element, the last element replaces the previously stored result with 1/n probability. So probability of getting last element as result is 1/n.

Let us now talk about second last element. When second last element processed first time, the probability that it replaced the previous result is 1/(n-1). The probability that previous result stays when nth item is considered is (n-1)/n. So probability that the second last element is picked in last iteration is [1/(n-1)] * [(n-1)/n] which is 1/n.

Similarly, we can prove for third last element and others.
*/


int selectRandom(int x)
{
	static int res;
	static int count=0;

	count++;
	if(count==1)
	{
		res=x;
	}
	else
	{
		int i=rand()%count+1;

		if(i==count-1)
		{
			res=x;
		}	
	}	

	return res;
}

int randomSelector()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};	
	int size=sizeof(arr)/sizeof(arr[0]);
	srand(time(NULL));

}




int main()
{
	
	return 0;
}
