#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {   int n;
        cin>>n;
        int sticks[n];
        int freq[1000]={0};
        for(int p=0;p<n;p++)
        {
            cin>>sticks[p];
            freq[sticks[p]]++;
        }
        int ans=0;
        for(int p=0;p<1000;p++)
        {
            if(freq[p] >= 4)
                {
                 if(ans < (p*p))
                    { ans = p*p; }
                }
            for(int q=(p+1);q<1000;q++)
            {
                if(freq[p] >= 2 && freq[q] >= 2)
                {
                 if(ans < (p*q))
                    { ans = p*q; }
                }
            }
        }
        if(ans == 0)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
    }
    
	// your code goes here
	return 0;
}
