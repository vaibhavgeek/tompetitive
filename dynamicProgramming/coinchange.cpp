#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   //ll t;
    //cin>>t;
   // while(t--)
   // {
        ll n,m;
        cin>>n;
        cin>>m;
        ll coin[m];
        
        for(int i=0;i<m;i++)
        {
            cin>>coin[i];
        }
	//cout<<m<<endl;
	
        ll dp[m][n+1];
        for(int i=0;i<m;i++) dp[i][0] = 1;

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if( j >= coin[i])
                {
                   dp[i][j] = min(1 + dp[i][j-coin[i]] , dp[i-1][j]);
                }
                else
                {
                	dp[i][j] = dp[i-1][j];
                }
            }
        }

        
        cout<<dp[m-1][n]<<" ";
       
    //}
    
	// your code goes here
	return 0;
}

