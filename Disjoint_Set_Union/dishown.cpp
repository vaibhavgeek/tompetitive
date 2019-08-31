#include<bits/stdc++.h>
using namespace std;
#define ll long long 
struct  Edge
{
	int src, dest;
};
struct subset
{
	int parent;
	int rank;
};
struct Graph
{
	int V,E;
	struct Edge* edge;
};
struct  Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
	return graph;
};
int find(struct subset subsets[], int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++; 
	}
}
int isCycle(struct Graph* graph) 
{
	int V = graph->V;
	int E = graph->E;
	struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
	for(int v=0;v<V;v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		ll s[n];
		for(int i=0;i<n;i++) cin>>s[i];
		ll q; cin>>q;
		for(int i=0;i<q;i++)
		{
			ll k;
			cin>>k;
			if(k)
			{
				ll x; cin>>x;
			}
			else
			{
				ll x,y;
				cin>>x>>y;
			}
		}
	}
}