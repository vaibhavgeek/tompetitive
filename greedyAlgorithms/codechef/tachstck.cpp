#include <bits/stdc++.h>
using namespace std;

int main() {
    
        long long int n;
        long long int d;
        
        cin>>n;
        cin>>d;
        long long int l[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>l[i];
        }
        sort(l,l+n);
        long long int ans=0;
        
        for(long long int i=0;i<n;i++)
        {
            if(l[i+1] - l[i] <= d)
            {
                ans++;
                i++;
            }
        }
        cout<<ans<<endl;
    
	// your code goes here
	return 0;
}
