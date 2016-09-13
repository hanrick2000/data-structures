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

	//two colourable logic
	// bool checkIfBipartite()
	// {
	// 	string src=vertices[0];
	// 	set<string> visited;
		
	// 	map<string,int> my_map;
	// 	bool flag=true;
	// 	int current_colour=1;
	// 	int adj_colour=2;

	// 	queue<string> q;
	// 	q.push(src);

	// 	while(!q.empty())
	// 	{	
	// 		if (flag)
	// 		{
	// 			current_colour=1;
	// 			adj_colour=2;
	// 		}
	// 		else
	// 		{
	// 		    current_colour=2;
	// 		    adj_colour=1;
	// 		}	

	// 		string temp=q.front();
	// 		q.pop();
	// 		if(my_map.count(temp)==0)	
	// 		{	
	// 			my_map[temp]=current_colour;
	// 		}	
	// 		else
	// 		{
	// 			flag=!flag;
	// 		}	
			
	// 		visited.insert(temp);

	// 		cout<<temp<<" "<<current_colour<<endl;

	// 		vector<string>* adj=edges[temp];

	// 		for (int i = 0; i < adj->size(); ++i)
	// 		{				

	// 			if(my_map.count(adj->at(i))!=0 && my_map[adj->at(i)]!=adj_colour)
	// 			{
	// 				return false;
	// 			}	
	// 			else
	// 			{	
	// 				if(visited.count(adj->at(i))==0)
	// 				{	
	// 					q.push(adj->at(i));
	// 					my_map[adj->at(i)]=adj_colour;
	// 				}	
	// 			}	

	// 		}

	// 		flag=!flag;
	// 	}	


	// 	return true;
	// } 



	bool checkIfBipartite()
	{
		
	
		int* color=new int[vertices.size()];
		memset(color,-1,sizeof(color));
		set<string> visited;

		queue<string> q;

		for (int i = 0; i < vertices.size(); ++i)
		{
			string src=vertices[i];
			if(color[i]==-1)
			{
				
			}	
			visited.insert(src);
			vector<string>* adj=edges[temp];

			for (int i = 0; i < edges->size(); ++i)
			{
				if()
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
	g.addVertex("f");
	g.addEdge("a","b");
	g.addEdge("b","c");
	g.addEdge("c","d");
	g.addEdge("d","e");
	g.addEdge("e","f");
	g.addEdge("f","a");

	cout<<g.checkIfBipartite()<<endl;


	return 0;
}