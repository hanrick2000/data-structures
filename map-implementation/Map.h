#include "Hashnode.h"

/* visualize array+linked list style implementation*/
class map {
	
	int capacity;
	Hashnode** buckets;
	int size;
	int getBucketIndex(char* key);
public:
	map();
	~map();
	void deleteKey(char* key);
	int find(char* key);
	void insert(char* key,int val);
};


int map::getBucketIndex(char* key)
{
    	int currentPower = 1;
		int currentSum = 0;
		int i = strlen(key) - 1;
		for (; i >= 0; i--) {
			currentSum = currentSum + currentPower * key[i];
			currentPower = (31 * currentPower) % capacity;
			currentSum = currentSum % capacity;
		}
		return currentSum % capacity;
}

map :: map()
{
	int capacity=13;
	size=0;
	buckets=new Hashnode*[capacity];
	for(int i=0;i<capacity;i++)
	{
		buckets[i]=NULL;
	}	
}

map :: ~map()
{
	for(int i=0;i<capacity;i++)
	{
		if(buckets[i]!=NULL)
			delete buckets[i];
	}	

	delete[] buckets;
}

void map :: insert(char* key,int val)		 
{
    int index=getBucketIndex(key);
    Hashnode* head=buckets[index];
    while(head!=NULL)
    {
    	/*key already exists*/
    	if(strcmp(head->key,key)==0)
    	{
    		head->val=val;
    		return;
    	}	
    	head=head->next;
    }

    size++;
    Hashnode newNode=new Hashnode(key,val);
    newNode->next=buckets[index];
    buckets[index]=newNode;
}

int map::find(char* key)
{
	int index = getBucketIndex(key);
		HashNode* head = buckets[index];
		while (head != NULL) {
			if (strcmp(head->key,key) == 0) {
				return head->val;
			}
			head = head->next;
		}
		return 0;
}

void map::deleteKey(char* key)
{
   int index=getBucketIndex(key);
   HashNode *head=buckets[index];
   Hashnode *prev=NULL;

   /*deleting from LL consider all three possibilities*/

   while(head!=NULL)
   {
   	 if(strcmp(head->val,val)==0)
   	 {
   	 	break;  
   	 }
   	 prev=head;
   	 head=head->next;
   }
    /*doesn't exist*/
    if(head==NULL)
    	return;
    
    /*decreament the size of the hash table*/
    size--;
   if(prev!=NULL)
   {
   	  prev->next=head->next;  
   }
   else	
   {
   	 //prev null,head to be deleted directly;
   	 buckets[index]=head->next;
   }	

   head->next=NULL;
   delete head;

}