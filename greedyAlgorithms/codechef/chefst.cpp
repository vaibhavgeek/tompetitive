#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n1,n2,m;
        cin>>n1>>n2>>m;
        ll rem = (m*(m+1))/2;
        ll a = min(rem,n1);
        ll b = min(a,n2);
        
        cout<<n1+n2-2*b<<endl;
    }
	// your code goes here
	return 0;
}
