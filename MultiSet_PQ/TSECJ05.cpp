#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll k,n;
        cin>>k>>n;
        ll arr[n];
       // multiset <ll , greater<ll>> a;
        for(ll i=0;i<n;i++) {
           cin>>arr[i];
        }
        //cout<<*(++a.begin());
         priority_queue<int,vector<int>,greater<int> >q;
         for(int i=0;i<n;i++)
         {
                if(q.size()<k)
                {
                    q.push(arr[i]);
                        if(q.size()==k)cout<<q.top()<<" ";
                        else cout<<"-1"<<" ";
                    continue;
                }
                else if(arr[i]>q.top())
                {  
                    q.pop();
                    q.push(arr[i]);
                }
                
                cout<<q.top()<<" ";

        }
        
        cout<<endl;
       // multiset <int> b(a.begin(), a.end());

    }
    // your code goes here
    return 0;
}
