#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Graph
{
	vector<string> vertices;
	map<string,vector<string>* > edges;
public:
	
	void addVertex(string a)
	{
		if(!hasVertex(a))
		{
			vertices.push_back(a);
			edges[a]=new vector<string>();
		}	
	}

	void addEdge(string a,string b)
	{
		if(!hasVertex(a) || !hasVertex(b))
			return;
		edges[a]->push_back(b);
		edges[b]->push_back(a);
	}

	bool hasEdge(string a,string b)
	{
		if(!hasVertex(a) || !hasVertex(b))
			return false;

		if (find(edges[a]->begin(), edges[a]->end(),b)!=edges[a]->end())
		{
			return true;
		}
		else
		{	
			return false;
		} 	
	
	}

	bool hasVertex(string a)
	{
		for (int i = 0; i < vertices.size(); ++i)
		{
			if (vertices[i]==a)
			{
				return true;
			}
		}

		return false;
	}
 
 /*
 	In topsort we maintain a stack of elements unlike dfs.
 	In dfs we print an element and call the function recursively for other elements 
 	 
 	In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first 
    recursively call topological sorting for all its adjacent vertices, then push it to a stack. Finally, print contents of stack. Note that 
    a vertex is pushed to stack 
	only when all of its adjacent vertices (and their adjacent vertices and so on) are already in stack.
 */

private:
	void dfsUtil(string a,set<string> &visited,stack<string> &s)
	{
		visited.insert(a);
		vector<string>* adj=edges[a];
		for (int i = 0; i < adj->size(); ++i)
		{
			if (visited.count(adj->at(i))==0)
			{
				dfsUtil(adj->at[i],visited,s);
			}
		}

		s.push(a);
	}

public:
    void topsort()
    {
    	set<string> visited;
    	stack<string> s;
    	for (int i = 0; i < vertices.size(); ++i)
    	{
    		if (visited.count(vertices[i])!=0)
    		{
    			continue;
    		}
    		else
    		{
    			dfsUtil(vertices[i],visited,s);
    		}	
    	}

    	while(!s.empty())
    	{
    		int data=s.top();
    		s.pop();
    		cout<<data<<" ";
    	}	
    	cout<<endl;
    }	

};

int main()
{
	Graph g;
	
	g.addVertex("a");
	g.addVertex("b");
	g.addVertex("c");
	g.addVertex("d");
	g.addVertex("e");
	g.addEdge("a","b");
	g.addEdge("b","c");
	g.addEdge("c","d");
	g.addEdge("a","d");

	cout<<g.hasPath("a","c")<<endl;
	cout<<g.hasPath("a","e")<<endl;
	cout<<g.bfs("a","c")<<endl;
	cout<<g.bfs("a","e")<<endl;


	return 0;
}