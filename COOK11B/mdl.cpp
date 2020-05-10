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
        vector<ll> vec;
       

        for(int i=0;i<n;i++) { ll tmp; cin>>tmp; vec.push_back(tmp); }
        ll a = *min_element(vec.begin(), vec.end());
        ll b = *max_element(vec.begin(), vec.end());
        
        vector<ll>::iterator i; 
        vector<ll>::iterator j; 
        i = find(vec.begin(), vec.end(), a);
        j = find(vec.begin(), vec.end(), b);
        if(i - vec.begin() + 1 > j - vec.begin() + 1) cout<<b<<" "<<a;
        else cout<<a<<" "<<b;
        cout<<endl;
    }
	// your code goes here
	return 0;
}

