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
        ll arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        ll dp[n];
        dp[0] = 1;
        for(int i=1;i<n;i++) 
            {
                if(arr[i] >= arr[i-1]) 
                    dp[i] = dp[i-1] + 1;
                else
                    dp[i] = 1;
            }
        ll count = 0;
        for(int i=0;i<n;i++)
            count=count+dp[i];
        cout<<count<<endl;
    }
    
    return 0;
}