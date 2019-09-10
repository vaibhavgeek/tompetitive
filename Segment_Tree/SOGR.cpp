#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int *constructTree(int inputA[], int *segmentTree, int low, int high, int pos);
int rangSumQuery( int *segmentTree, int qlow, int qhigh, int low, int high, int pos );
void updateTree(int *segmentTree, int low, int high, int diff, int pos, int i);


void updateTree(int *segmentTree, int low, int high, int diff, int pos, int i)
{
	if(i < low || i > high ) return;

	segmentTree[pos] = segmentTree[pos] + diff;
	if( low != high)
	{
		int mid = (low+high)/2;
		updateTree(segmentTree, low, mid, diff, 2*pos + 1, i);
		updateTree(segmentTree, mid+1, high, diff, 2*pos + 2, i);
	}
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
int rangSumQuery( int *segmentTree, int qlow, int qhigh, int low, int high, int pos )
{
	if(qlow <= low && qhigh >= high) return segmentTree[pos];
	if(qlow > high || qhigh < low) return 0;

	int mid= (low+high)/2;
	return rangSumQuery(segmentTree, qlow,qhigh,low, mid , 2*pos + 1) +  rangSumQuery(segmentTree,qlow,qhigh,mid+1,high, 2*pos + 2);
}

int main()
{
	int n;
	cin>>n;
	int pos = ceil(log2(n));
	int se = 2*pow(2,pos) - 1;

	int arr[n]; 
	int *segmentTree = new int[se];  


	for(int i=0;i<se;i++) segmentTree[i] = 0;
	for(int i=0;i<n;i++) cin>>arr[i];
	constructTree(arr, segmentTree, 0, n-1, 0);

	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int xi,yi; cin>>xi>>yi;
		cout<<rangSumQuery(segmentTree, xi, yi, 0 , n-1, 0)<<" ";
		cout<<"Input index to update";
		int ii; cin>>ii;
		cout<<"New Value?"; 
		int diffi, new_val; 
		cin>>new_val; 
		diffi = arr[ii] - new_val; 
		updateTree(segmentTree, 0 , n-1, diffi , 0 , ii);
		cout<<rangSumQuery(segmentTree, xi, yi, 0 , n-1, 0)<<" ";
	} 


}