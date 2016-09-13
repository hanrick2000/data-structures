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
 
};

private:
	/*
	We do a DFS traversal of the given graph. For every visited vertex ‘v’, 
	if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, 
	then there is a cycle in graph. 
	If we don’t find such an adjacent for any vertex, we say that there is no cycle. 
	The assumption of this approach is that there are no parallel edges between any two vertices.
	*/
	bool isCyclicUtil(string a,set<string> &visited,map<string,string> &my_map)
	{
		visited.insert(a);
		vector<string>* adj=edges[a];
		for (int i = 0; i < adj->size(); ++i)
		{
			if (visited.count(adj->at(i))!=0 && my_map[adj->at(i)]!=a)
			{
				return true; 
			}
			else
			{	
				my_map[adj->at[i]]=a;
				if (isCyclicUtil(adj->at(i),visited,my_map))
				{
					return true;
				}
			}		
		}

		return false;
	}


public: 
	/*O(V+E)*/
	bool detectACycle()
	{
		set<string> visited;
		//maintain child parent relationship
		map<string,string> my_map;
		for (int i = 0; i < vertices.size(); ++i)
		{
			if (visited.count(vertices[i])==0)
			{
				if (isCyclicUtil(vertices[i],visited,my_map))
				{
					return true;
				}
			}
		}	

		return false;
	}

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