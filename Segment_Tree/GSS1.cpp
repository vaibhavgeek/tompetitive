#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX (1<<16)
#define MAX2 (MAX<<2)


struct Node {
	int maxPrefixSum;
	int maxSuffixSum;
	int totalSum;
	int maxSubSum;

	Node()
	{
		maxPrefixSum = maxSuffixSum = totalSum = maxSubSum = (-1)*MAX2;
	}
};

void constructTree(Node *segmentTree, int arr[], int low, int high, int pos);
Node queryMax(Node *segmentTree, int qlow, int qhigh, int low, int high, int pos);


Node merge(Node leftChild, Node rightChild)
{
	Node parentNode;
	parentNode.maxPrefixSum = max( leftChild.maxPrefixSum , leftChild.totalSum + rightChild.maxPrefixSum );
	parentNode.maxSuffixSum = max( rightChild.maxSuffixSum , rightChild.totalSum + leftChild.maxSuffixSum );
	parentNode.totalSum = rightChild.totalSum + leftChild.totalSum;
	parentNode.maxSubSum = max({leftChild.maxSubSum , rightChild.maxSubSum , leftChild.maxSuffixSum + rightChild.maxPrefixSum});
	return parentNode;
}
void constructTree(Node *segmentTree, int arr[], int low, int high, int pos)
{
	if(low == high)
	{
		segmentTree[pos].totalSum = arr[low];
		segmentTree[pos].maxSuffixSum = arr[low];
		segmentTree[pos].maxPrefixSum = arr[low];
		segmentTree[pos].maxSubSum = arr[low];
		return;
	}
	int mid = (low + high)/2;
	constructTree(segmentTree, arr, low, mid , 2*pos );
	constructTree(segmentTree, arr, mid+1, high, 2*pos + 1);

	segmentTree[pos] = merge(segmentTree[2*pos] , segmentTree[2*pos + 1]);
}
Node queryMax(Node *segmentTree, int qlow, int qhigh, int low, int high, int pos)
{

	if(low > qhigh || high < qlow) { Node nullnode; return nullnode; } 

	if(low >= qlow && high <= qhigh) { return segmentTree[pos]; } 

	int mid = (low+high)/2;
	Node left = queryMax(segmentTree, qlow, qhigh, low , mid , 2*pos );
	Node right = queryMax(segmentTree,qlow,qhigh, mid+1 , high, 2*pos + 1); 
	Node res =  merge(left, right);
	return res;
}
int main()
{
	int n;
	cin>>n;
	int pos = ceil(log2(n));
	int se = 2*pow(2,pos) - 1;

	int arr[n];
	Node *segmentTree = new Node[se];  

	for(int i=0;i<n;i++) cin>>arr[i]; 
	int q; cin>>q;
	constructTree(segmentTree, arr, 0 , n-1, 1);
	for(int i=0;i<q;i++)
	{
		int xi,yi; cin>>xi>>yi;
		cout<<queryMax(segmentTree, xi-1, yi-1, 0 , n-1, 1).maxSubSum<<endl;
	}
	return 0;
}
