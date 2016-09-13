#include<cstring>

class HashNode{
public:
	char* key; 
	int val;
	HashNode* next;
	/*Constructor call*/

	HashNode(char *key1,int val1)
	{
		key=new char[strlen(key1)+1];
		strcpy(key,key1);
		val=val1;
		next=NULL;
	}

	/*Destructor call*/
	~HashNode()
	{
		delete[] key;
		if(next!=NULL)
			delete next;
	}
};