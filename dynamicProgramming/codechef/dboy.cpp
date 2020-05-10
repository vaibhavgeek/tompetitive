/*

*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n; 
		cin>>n;
		ll maxi=0;
		ll h[n+1]; // no of kms away. 2*h[i] kms is the amount of petrol required as 1km = 1l  
		for(int i=1;i<=n;i++)
		{
			cin>>h[i];
			maxi = max(maxi, h[i]);
		} 
		ll k[n+1]; // k[i] amount of petrol will be filled up at ith fuel station
		for(int i=1;i<=n;i++) cin>>k[i];
		
		// dp[i][j] : (answer) minimum number of times he needs to travel to fill j litres using 0..ith fuel stations
		// sum of dp[N][2*h[i]] 
		ll dp[n+1][(2*maxi) + 1];
		dp[0][0] = 0;
		for(int j=1;j<=(2*maxi);j++) dp[0][j] = 10e9;

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=(2*maxi);j++)
			{
				dp[i][j] = dp[i-1][j];
				if(k[i] <= j)
				{
					dp[i][j] = min(dp[i][j], 1 + dp[i][j-k[i]]);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans = ans + dp[n][(2*h[i])];
		}
		cout<<ans<<endl;
	}
}