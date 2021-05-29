#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        int i;
        ll adder;
        ll ans = 0;
        for(i=0; a>0; i++)    
        {    
        
            if(a<=2048)
            {    if(a%2 == 1) ans++;
                 a = a/2;
            }
            else
            {
                 adder=a/2048;
                 a = a%2048;
                 ans = ans + adder;
            }
        }    
        cout<<ans<<endl; 
        
    }
	// your code goes here
	return 0;
}