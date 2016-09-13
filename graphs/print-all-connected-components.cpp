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
	bool hasPathHelper(string a,string b,set<string> &visited) //DFS
    {	
    	if(hasEdge(a,b))
    		return true;

    	visited.insert(a);

    	vector<string>* adj=edges[a];
    	for (int i = 0; i < adj->size(); ++i)
    	{
    		if (visited.count(adj->at(i))!=0)
    		{
    			continue;
    		}

    		if(hasPathHelper(adj->at(i),b,visited))
    			return true;
    	}

    	return false;
    }
public:
	bool hasPath(string a,string b)//DFS
	{
		if(!hasVertex(a) || !hasVertex(b))
			return false;

		set<string> visited;
		return hasPathHelper(a,b,visited);
	}


	void DFSUtil(string str,set<string> &visited)
	{
		visited.insert(str);
		cout<<str<<" ";

		vector<string>* adj=edges[str];

		for (int i = 0; i < adj->size(); ++i)
		{
			 if(visited.count(adj->at(i))!=0)
			 {
			 	continue;
			 }	

			 DFSUtil(adj->at(i),visited);
		}
	}

	void connectedComponents()
	{
		set<string> visited;

		for (int i = 0; i < vertices.size(); ++i)
		{
			if(visited.count(vertices[i])==0)
			{
				DFSUtil(vertices[i],visited);
				cout<<endl;
			}	
		}
	}	


	/*
	//Also remove the edges first
	void removeVertex(string a) {
		if (!hasVertex(a)) 
			return;

		vertices.erase(vertices.find(a));
	}
	*/

	 
	
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

	g.connectedComponents();


	return 0;
}