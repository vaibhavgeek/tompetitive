#include <bits/stdc++.h>
using namespace std;

int main() {
     int t;
    cin>>t;
    while(t--)
    {
        int n; int k; int m;
        cin>>n;
        cin>>k;
        int w[n];
        for(int i=0;i<n;i++)
        {
         cin>>w[i];   
        }
        m = min(k,n-k);
        sort(w,w+n);
        int kid=0;
        for(int i=0;i<m;i++)
        {
            kid = kid + w[i];
        }
        int chef=0;
        for(int q=m;q<n;q++)
        {
            chef = chef + w[q];
        }
        cout<<chef-kid<<endl;
    }
    
	// your code goes here
	return 0;
}
