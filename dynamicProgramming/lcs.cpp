#include<bits/stdc++.h>
using namespace std;
int main()
{
    string X;
    cin>>X;
    string Y;
    cin>>Y;
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];  
    int i, j;    
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            dp[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            dp[i][j] = dp[i - 1][j - 1] + 1;  
      
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
          
    cout<<dp[m][n]<<endl;
   }
