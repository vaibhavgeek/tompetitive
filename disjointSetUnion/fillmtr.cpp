#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q; cin>>n>>q;
		ll matb[n][n];
		for(int i=0;i<q;i++)
		{
			ll a,b,val; cin>>a>>b>>val;
			matb[a][b] = val;
		}
	}
}
