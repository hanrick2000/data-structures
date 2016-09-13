#include <map>
using namespace std;

class TrieNode
{
public:
	char data;
	map<char,TrieNode*> children;
	bool isTerminal;
	TrieNode(char data)
	{
		this->data=data;
		isTerminal=false;
	}
};


class Trie
{
public:
	TrieNode* root;
	int numWords;
	Trie()
	{
		root=new TrieNode('\0');
		numWords=0;
	}
	

private:
	static bool insertRecursive(TrieNode* node,string word,int index)
	{
		if(word.size()==index)
		{
			if(node->isTerminal==true)
			{
				//word already present in the trie 
				return false;
			}	

			node->isTerminal=true;
			return true;
		}	

		char current_char=word[index];
		//Checking if the current char already exists
		TrieNode* nextNode=node->children[current_char];
		if(nextNode==NULL)
		{
			nextNode=new TrieNode(current_char);
			node->children[current_char]=nextNode;
		}	

		return insertRecursive(nextNode,word,index+1);
	}

	
	bool searchRecursive(TrieNode* node,string word,int size)
	{
		if (word.size()==size)
		{
			if(node->isTerminal==true)
				return true;
			return false;
		}	

		TrieNode* nextNode=node->children[word[size]];
		if (nextNode==NULL)
		{
			return false;
		}

		return searchRecursive(nextNode,word,size+1);
	}

	static bool removeRecursive(TrieNode* node,string word,int size)
	{

		if(index==word.length())
		{
			//if endOfWord is reached,
			if(!node->isTerminal)
				return false;
			node->isTerminal=false;

			return node.children.size()==0;
		}	

		char current_char=word[size];
		TrieNode* current=node->children[current_char];
		if (current==NULL)
		{
			return false;
		}

		bool shouldDeleteCurrentNode=removeRecursive(current,word,size+1);

		if(shouldDeleteCurrentNode)
		{
			node->children[current_char]=NULL;
			return node->children.size()==0;
		}	

		return false;
	}	

public:
	void insertRecursive(string word)
	{
		if(insertRecursive(root,word,0))
			numWords++;
	}


	void insert(string word)
	{
		TrieNode* current=root;

		for (int i = 0; i <=word.size(); ++i)
		{
			if (i==word.size())
			{
				if(current->isTerminal==false)
				{
					numWords++;
					current->isTerminal=true;
				}	
			
			}

			char current_char=word[i];
			TrieNode* nextNode=current->children[current_char];
			if(nextNode==NULL)
			{
				nextNode=new TrieNode(current_char);
				node->children[current_char]=nextNode;
			}	

			current=nextNode;
		}
	}

	bool search(string word)
	{
		TrieNode* current=root;
		int flag=true;
		for (int i = 0; i < word.size(); ++i)
		{
			char current_char=word[i];
			TrieNode* nextNode=current->children[current_char];
			if(nextNode==NULL)
			{
				flag=false
				break;
			}

			current=nextNode;		
		}

		if (flag==false)
		{
			return false;
		}
		else
		{	
			if(current->isTerminal==true)
				return true;
			return false;
		}	
	}

	bool searchRecursive(string word)
	{
		return searchRecursive(root,word,0);
	}
 	
 	void remove(string word)
 	{ 
 		removeRecursive(root,word,0);
 	}
	
};
