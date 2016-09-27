#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

int const MAX 1e5+5;
typedef pair<long long,int> PII;
bool visited[MAX];
vector<PII> adj[MAX];
int edges;


long long primsHelper(int source)
{
	priority_queue<PII,vector<PII>,greater<PII>> q;
	pair<PII> start(0,source);
	q.push(start);
	int minCost=0;
	while(!q.empty())
	{
		pair<PII> temp=q.top();
		q.pop();
		int x=temp.second;
		if(visited[x])
			continue;
		visited[x]=true;
		minCost+=temp.first;
		for (int i = 0; i < adj[x].size(); ++i)
		{
			int y=adj[x][i].second;
			if (visited[y]==false)
			{
				/* code */
				q.insert(adj[x][i]);
			}
		}

	}		

	return minCost;
}

long long prim()
{
	long long weight,minCost=0;
	cin>>edges;
	for (int i = 0; i < edges; ++i)
	{
		int x,y;
		long long weight;
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));	

	}

	cout<<"Enter source"<<endl;
	int source;
	cin>>source;
    minCost=primsHelper(source);

}

int main()
{
	prim();
	return 0;
}