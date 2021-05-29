#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        int ai = 30;
        int bi = 40;
        ll n;
        cin>>n;
        bool flag = false;
        for(int i=0;i<ai;i++)
        {
            for(int j=0;j<bi;j++)
            {
                ll p = pow(5,i+j);
                ll q = pow(2,i+2*j);
                if(p*q == n) { flag = true; break; } 
                
            }
        }
        if(flag) cout<<"yes";
        else cout<<"no";
        
        cout<<endl;
    }
	// your code goes here
	return 0;
}

