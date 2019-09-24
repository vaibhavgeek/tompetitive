#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int *constructTree(int input[], int *segmentTree, int low, int high, int pos);
int rangSumQuery( int *segmentTree, int qlow, int qhigh, int low, int high, int pos );


int rangSumQuery( int *segmentTree, int qlow, int qhigh, int low, int high, int pos )
{
	if(qlow <= low && qhigh >= high) return segmentTree[pos];
	if(qlow > high || qhigh < low) return 0;

	int mid= (low+high)/2;
	return rangSumQuery(segmentTree, qlow,qhigh,low, mid , 2*pos + 1) +  rangSumQuery(segmentTree,qlow,qhigh,mid+1,high, 2*pos + 2);
}
int *constructTree(int inputA[], int *segmentTree, int low, int high, int pos)
{
	if(low == high)
		{ segmentTree[pos] = inputA[high]; return segmentTree; }
	int mid = (low+high)/2;
	constructTree(inputA, segmentTree, low, mid, 2*pos + 1);
	constructTree(inputA, segmentTree , mid+1, high, 2*pos +2);
	segmentTree[pos] = segmentTree[(2*pos) +1] +  segmentTree[(2*pos) + 2];
	return segmentTree;
}
int main()
{
	ll q;
	cin>>q;
	
	ll arr[200000] = {0};
	
	int pos = ceil(log2(n));
	int se = 2*pow(2,pos) - 1;
	int *segmentTree = new int[se];  

	for(int i=0;i<q;i++) 
	{
		char ch;
		cin>>ch;
		if(ch == 'I')
		{
			ll tmp; cin>>tmp;
			if(arr[tmp] == 0) 
			{
				arr[tmp]++;
				constructTree(arr, segmentTree, 0, n-1, 0);
			}
		}
		else if(ch == 'K')
		{
			ll k; cin>>k;
			ll blow = 0; ll bhigh=n-1;
			ll mid 

		}
		else if(ch == 'D')
		{
			ll tmp; cin>>tmp;
			if(arr[tmp] == 1) arr[tmp]--;
		}
		else if(ch == 'C')
		{
			ll x; cin>>x;
			cout<<rangSumQuery(segmentTree, 0, x-2, 0 , n-1, 0)<<endl;
		}
		else
		{
			cout<<"invalid";
		}
	}
	return 0;
}