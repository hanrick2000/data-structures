#include <iostream>
#include <utility>
#include <map>
using namespace std;

const int MAX 1e+4;
int id[MAX],edges,nodes;
pair<long long, pair<int,int> > p[MAX];

void initialize()
{
	for (int i = 0; i < MAX; ++i)
	{
		id[i]=i;
	}
}

int root(int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}		

	return x;
}


void union1(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

long long kruskal(pair<long long, pair<int,int> > *p)
{
	sort(p,p+edges);
	long long min_cost=0;
	for(int i=0;i<edges;i++)
	{
		int x=p[i].second.first;
		int y=p[i].second.second;
		long long cost=p[i].first;

		if(id[x]!=id[y])
		{
			min_cost+=cost;
			union1(x,y);
		}		
	}		

	return min_cost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
   
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}