#include <bits/stdc++.h>
using namespace std;
#define ll long long 
bool check2(ll a, ll b, ll c);
bool check2(ll a, ll b, ll c)
{
    if(a%2==0 && b%2==0 && c%2==0)
        return true;
    else
        return false;
}
int main() {
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll a1,b1,c1;
        a1 = a; b1=b, c1=c;
        ll flag = 0;
        if(check2(a1,b1,c1)) flag = 1;
        while(a1)
        {
            a1 = a1-3;
            c1--;
            if(check2(a1,b1,c1)){flag = 1; break; }
        }
        ll a2,b2,c2;
        a2=a;b2=b;c2=c;
        while(a2)
        {
            a2--;
            b2--;
            c2--;
            if(check2(a1,b1,c1)){ flag = 1; break; }
        }
        ll a3,b3,c3;
        a3=a;b3=b;c3=c;
        while(a3)
        {
            a3 = a3-2;
            b3 = b3--;
            if(check2(a1,b1,c1)){ flag = 1; break; }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
	// your code goes here
	return 0;
}
