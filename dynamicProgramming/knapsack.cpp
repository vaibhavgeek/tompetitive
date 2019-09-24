#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   //ll t;
    //cin>>t;
   // while(t--)
   // {
        ll n,p,q,i,j;
        cin>>n;
        ll weight[n];
        ll cost[n];
        ll po=0;
        for(int i=0;i<n;i++)
        {
                cin>>weight[i]; cin>>cost[i];
		po = po + weight[i];
        }
	//cout<<m<<endl;
	for(int m=1;m<=po;m++){
        ll dp[n+1][m+1];
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=0;i<=m;i++) dp[0][i] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( j < weight[i-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = max(cost[i-1] + dp[i-1][j-weight[i-1]] , dp[i-1][j]);
                }
            }
        }

        
        cout<<dp[n][m]<<" ";
       }
    //}
    
	// your code goes here
	return 0;
}

