#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct frogs
{
	int index;
	int position;
};
bool frogsCompare(frogs a, frogs b)
{
	return a.position > b.position;
}
int main()
{
	ll dp[100000];
	ll n,k,p;
	cin>>n>>k>>p;
	frogs a[n];
	ll temp;
	for(int i=0;i<n;i++){
		a[i].index = i;
		cin>>temp;
		a[i].position = temp; 
	}
	sort(frogs, frogs+n, frogsCompare); 
	dp[a[0].index] = a[0].position + k;

	for(int i=1;i<n;i++)
	{
		if(a[i-1].position - a[i].position <=k)
		{
			dp[a[i].index] = dp[a[i-1].index];
		}
		else
		{
			dp[a[i].index] = a[i].position + k;
		}
	}
	for(int i=0;i<p;i++)
	{
		ll p1; ll p2;
		cin>>p1>>p2;
		p1--; p2--;
		if(dp[p1] == dp[p2])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	
}