#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		cin>>k;	
		deque<int> de;
		for(int i=0;i<k;i++)
		{

			while((!de.empty()) && arr[i] >= arr[de.back()] )
				de.pop_back();
			
			de.push_back(i);
		}
		for(int i=k;i<n;i++)
		{
			cout<<arr[de.front()]<<" ";

			while ((!de.empty()) && de.front() < (i - k + 1))
            	de.pop_front(); 

			while((!de.empty()) && arr[i] >= arr[de.back()])
				de.pop_back();
			de.push_back(i);
		}
		cout<<arr[de.front()]<<" ";
	}
}