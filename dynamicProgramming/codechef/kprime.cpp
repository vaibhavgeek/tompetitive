#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    ll t;
    cin>>t;
    
    ll arr[1000001]={0};
        for(int i=2;i<=1000000;i++)
        {
            if(arr[i] == 0)
                for(int j=i;j<=1000000;j+=i)
                    arr[j]++;
        }
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;
        
        ll count=0;
        for(int i=a;i<=b;i++) 
            {
                if(arr[i] == k) count++;
            }
            cout<<count<<endl;
    }
    
    return 0;
}