#include<bits/stdc++.h>
using namespace std;
#define ll long long 



struct ab
{
	int difference;
	int andy;
	int bob;
};
bool compareab(ab a, ab b)
{
	return a.difference > b.difference;
}
int main()
{
	ll n,x,y;
	cin>>n>>x>>y;
	ab aba[n];
	
	for(int i=0;i<n;i++) cin>>aba[i].andy;
	for(int j=0;j<n;j++) 
	{
		cin>>aba[j].bob;
		aba[j].difference = aba[j].andy - aba[j].bob;
	}
	sort(aba, aba+n, compareab);
	ll totaltipmoney=0, andyo = 0 , bobo=0;
	for(int i=0;i<n;i++)
	{
		if(aba[i].andy > aba[i].bob)
		{
			if(andyo+1 <= x) 
			{
				andyo++;
				totaltipmoney += aba[i].andy;
			}
			else
			{
				bobo++;
				totaltipmoney += aba[i].bob;
			}
		}
		else
		{
			if(bobo+1 <= y)
			{
				bobo++;
				totaltipmoney += aba[i].bob;
			}
			else
			{
				andyo++;
				totaltipmoney += aba[i].andy;
			}
		}
	}
	cout<<totaltipmoney<<endl;
}