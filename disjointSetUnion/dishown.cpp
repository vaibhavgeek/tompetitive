#include<bits/stdc++.h>
using namespace std;
#define ll long long 

struct subset
{
	ll parent;
	ll rank;
};
struct Graph
{
	ll V;
};
ll find(struct subset subsets[], ll i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}
void Union(struct subset subsets[], ll x, ll y)
{
	ll xroot = find(subsets,x);
	ll yroot = find(subsets,y);

	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
		return;
	
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		ll s[n] = {0};
		for(int i=0;i<n;i++) cin>>s[i];
		
		ll q; cin>>q;
		Graph graph; graph.V = n; 
		subset subsets[n];
		for(int i=0;i<n;i++)
		{
			subsets[i].parent = i;
			subsets[i].rank = s[i];
		}
		for(int i=0;i<q;i++)
		{
			ll k;
			cin>>k;
			if(k)
			{
				ll x; cin>>x; x--;
				cout<<find(subsets, x)+1<<endl;
			}
			else
			{
				ll x,y;
				cin>>x>>y; x--; y--;
				int px = find(subsets, x);
				int py = find(subsets, y);
				if(px==py) cout<<"Invalid query!"<<endl;
				else Union(subsets,px,py);	
			}
		}
	}
}