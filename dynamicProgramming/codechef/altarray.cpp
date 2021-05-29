#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{

        ll t,n;
        cin>>t;
        while(t--)
        {
        	cin>>n;
        	ll a[n];
        	for(int i=0;i<n;i++)
        		cin>>a[i];
        	ll dp[n];
        	dp[n-1] = 1;

        	for(int i=n-2;i>=0;i--)
        	{
        		if((a[i]*a[i+1])<0)
        			dp[i] = dp[i+1] +1;
        		else
        			dp[i] = 1;
        	}
        	for(int i=0;i<n;i++)
        		cout<<dp[i]<<" ";
        	cout<<endl;
        }	

}  