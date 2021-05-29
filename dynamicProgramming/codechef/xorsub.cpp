#include <iostream>
using namespace std;

typedef long long int ll;

#define MAX 1001

ll n,k;
ll a[MAX];
ll dp[MAX][1025];

void init() {
    ll i,j;
    
    for ( i=0; i<n; i++ ) {
        for ( j=0; j<=1024; j++ )
           dp[i][j] = -1;
    }
}

void findMaxXorDp ( ll idx, ll currXor ) {
    
    if ( idx == n ) {
        dp[n-1][currXor] = 1;
        return;
    }
    
    if ( dp[idx][currXor] != -1 )
        return;
        
    dp[idx][currXor] = 1;
    
    findMaxXorDp(idx+1,currXor);
    findMaxXorDp(idx+1, (currXor^a[idx]));
    
}

int main() {
	// your code goes here
	
	ll test;
	cin>>test;
	
	while(test--) {
	   
	    cin>>n>>k;
	    
	    for ( ll i=0; i<n; i++ ) {
	        cin>>a[i];
	    }
	    
	    init();
	    
	    findMaxXorDp(0,0);
	    
	    ll res = 0;
	    for ( ll i=0; i<=1024; i++ ) {
	        if ( dp[n-1][i] != -1 )
	            res = max(res,(i^k));
	    }
	    
	    cout << res << endl;
	}
	
	return 0;
}
