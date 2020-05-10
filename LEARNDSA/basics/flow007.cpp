#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll rev=0;
        while(n)
        {
            rev = (rev*10) + (n%10);
            n = n/10;
            
        }
        cout<<rev<<endl;
    }
	// your code goes here
	return 0;
}
