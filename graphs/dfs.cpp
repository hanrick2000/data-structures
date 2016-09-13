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
private:
    void dfsUtil(string a,set<string> &visited)
    {
    	visited.insert(a);
    	cout<<a<<" ";
    	vector<string>* adj=edges[a];

    	for (int i = 0; i < adj->size(); ++i)
    	{
    		if (visited.count(adj->at(i))!=0)
    		{
    			continue;
    		}
    		else
    		{
    			dfsUtil(adj->at(i),visited);
    		}	
    	}
    } 	
public:
	//This algo doesn't visit all the vertices
	void dfs1(string src)
	{
		set<string> vertices;

		dfsUtil(src,visited);
	} 	
	//This algo of dfs visits all the vertices
	void dfs()
	{
		set<string> visited;

		for (int i = 0; i < vertices.size(); ++i)
		{
			if (visited.count(vertices[i])==0)
			{
				dfsUtil(vertices[i],visited);
			}
		}
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