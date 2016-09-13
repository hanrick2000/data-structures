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


	//select one vertex and check if it connected to all the other vertices
	//If so,then the graph is connected.This is O(n^3)


	bool checkIfGraphIsConnected1()
	{
		string src=vertices[0];
		for (int i = 1; i <vertices.size(); ++i)
		{
			if(!hasPath(src,vertices[i]))
			{
				return false;
			}	
		}

		return true;
	}

	//Better method
 	//BFS style,then compare visted size and total no vertices. O(n^2)
  	bool checkIfGraphIsConnected()
  	{
  		string src=vertices[0];
  		queue<string> q;
  		q.push(src);
  		set<string> visited;
  		while(!q.empty())
  		{
  			string temp=q.front();
  			q.pop();
  			visited.insert(temp);
  			vector<string>* adjacent=edges[temp];

  			for (int i = 0; i < adjacent->size(); ++i)
  			{
  				if(visited.count(adjacent->at(i))!=0)
  				{
  					continue;
  				}	
  				else
  				{
  					q.push(adjacent->at(i));
  				}	
  			}

  		}	

  		if(visited.size()!=vertices.size())
  		{
  			return false;
  		}	
  		else
  		{
  			return true;
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

	cout<<g.checkIfGraphIsConnected1()<<endl; 


	return 0;
}