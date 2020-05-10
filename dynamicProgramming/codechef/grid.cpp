#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		char arr[n][n];
		for(ll i=0;i<n;i++)
			for(ll j=0;j<n;j++)
				cin>>arr[i][j];
		
		ll flagX[n][n]=0;
		ll flagY[n][n]=0;
		ll flag=0;
		//it is all OK. 
		// vertical I will see if I encounter a "#" and change flagY to 1 if not okay
		for(int j=0;j<n;j++)
		{
			flag =0;
			for(int i=n-1;i>=0;i--)
			{
				if(arr[i][j] == '#')
					flag =1;
				flagY[i][j] = flag;
			}

		}

		for(int i=0;i<n;i++)
		{
			flag = 0;
			for(int j=n-1;j>=0;j--)
			{
				if(arr[i][j] == '#')
					flag = 1;
				flagX[i][j] = flag;
			}
		}
		ll count = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(flagX[i][j] == 0 && flagY[i][j] == 0)
					count++;
			}
		}
		cout<<count<<endl;
	}
}