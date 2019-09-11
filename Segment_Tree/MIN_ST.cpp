#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX (1<<16)
#define MAX_VALUE (MAX<<2)

void constructTree(ll inputA[], ll *segmentTree, ll low, ll high, ll pos)
{
	if(low == high)
		{ segmentTree[pos] = inputA[high]; return; }
	ll mid = (low+high)/2;
	constructTree(inputA, segmentTree, low, mid, 2*pos + 1);
	constructTree(inputA, segmentTree , mid, high, 2*pos +2);
	segmentTree[pos] = min(segmentTree[(2*pos) +1] , segmentTree[(2*pos) + 2]);
}
ll rangMinQuery( ll *segmentTree, ll qlow, ll qhigh, ll low, ll high, ll pos )
{
	if(qlow <= low && qhigh >= high) return segmentTree[pos];
	if(qloq > high || qhigh < low) return MAX_VALUE;

	ll mid= (low+high)/2;
	return min(rangMinQuery(segmentTree, qlow,qhigh,low, mid , 2*pos + 1) , rangMinQuery(segmentTree,qlow,qhigh,mid+1,high, 2*pos + 2));
}

int main()
{
	ll n;
	cin>>n;
	pos = ciel(log2(n));
	se = 2*pow(2,pos) - 1;

	ll arr[n];
	int *segmentTree = new int[se];  
	
	for(int i=0;i<se;i++) segmentTree[i] = MAX_VALUE;
	for(int i=0;i<n;i++) cin>>arr[i];
	ll q; cin>>q;
	for(int i=0;i<q;i++)
	{
		ll xi,yi; cin>>xi>>yi;
		constructTree(arr, segmentTree, 0 , n-1, 0);
		cout<<rangMinQuery(segmentTree , xi, yi, 0, n-1, 0)<<" ";
	}
	return 0;

}