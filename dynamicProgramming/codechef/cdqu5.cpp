#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll dp[1000001];
        dp[0] = dp[1] = 0;
        dp[2] = dp[3] = 1;

        for(int i=4; i<=1000000; i++)
        {
            dp[i] = (dp[i-2]+dp[i-3])%1000000009;
        }
    ll t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        
        cout<<dp[x]<<endl;
    
    }
	// your code goes here
	return 0;
}
