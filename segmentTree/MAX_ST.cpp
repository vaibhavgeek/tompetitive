#include<bits/stdc++.h>
using namespace std;
#define ll long long
void constructTree(ll inputA[], ll segmentTree[], ll low, ll high, ll pos)
{
	if(low == high)
		{ segmentTree[pos] = inputA[high]; return; }
	ll mid = (low+high)/2;
	constructTree(inputA, segmentTree, low, mid, 2*pos + 1);
	constructTree(inputA, segmentTree , mid, high, 2*pos +2);
	segmentTree[pos] = max(segmentTree[(2*pos) +1] , segmentTree[(2*pos) + 2]);
}
ll rangMaxQuery( ll segmentTree[], ll qlow, ll qhigh, ll low, ll high, ll pos )
{
	if(qlow <= low && qhigh >= high) return segmentTree[pos];
	if(qloq > high || qhigh < low) return MAX_VALUE;

	ll mid= (low+high)/2;
	return max(rangMaxQuery(segmentTree, qlow,qhigh,low, mid , 2*pos + 1) , rangMaxQuery(segmentTree,qlow,qhigh,mid+1,high, 2*pos + 2));
}

int main()
{
	ll n;
	cin>>n;
	pos = ciel(log2(n));
	se = 2*pow(2,pos) - 1;

	ll arr[n] , ll segmentTree[se];
	
	for(int i=0;i<se;i++) segmentTree[i] = -1;
	for(int i=0;i<n;i++) cin>>arr[i];
	ll q; cin>>q;
	for(int i=0;i<q;i++)
	{
		ll xi,yi; cin>>xi>>yi;


	}


}