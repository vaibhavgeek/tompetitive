/*
It's finally summer in Chefland! So our chef is looking forward to prepare some of the best "beat-the-heat" dishes to attract more customers. He summons the Wizard of Dessert to help him with one such dish.

The wizard provides the chef with a sequence of N ingredients where the ith ingredient has a delish value of D[i]. The preparation of the dish takes place in two phases.

Phase 1 : The chef chooses two indices i and j and adds the ingredients i, i+1, ..., j to his dish. He also finds the sum of the delish value in this range i.e D[i] + D[i+1] + ... + D[j].

Phase 2 : The chef chooses two more indices k and l and adds the ingredients k, k+1, ..., l to his dish. He also finds the sum of the delish value in this range i.e D[k] + D[k+1] + ... + D[l].

Note that 1 ≤ i ≤ j < k ≤ l ≤ N.

The total delish value of the dish is determined by the absolute difference between the values obtained in the two phases. Obviously, the chef wants to maximize the total delish value for his dish. So, he hires you to help him.

Input
First line of input contains an integer T denoting the number of test cases. For each test case, the first line contains an integer N denoting the number of ingredients. The next line contains N space separated integers where the ith integer represents the delish value D[i] of the ith ingredient.

Output
Print the maximum delish value of the dish that the chef can get.

Constraints
1 ≤ T ≤ 50
2 ≤ N ≤ 10000
-1000000000 (−109) ≤ D[i] ≤ 1000000000 (109)

Example
Input:
2
5
1 2 3 4 5
4
1 1 -1 -1

Output:
13
4
Explanation
Example case 1.
Chef can choose i = j = 1, k = 2, l = 5.
The delish value hence obtained is | (2+3+4+5) − (1) | = 13 .

Example case 2.
Chef can choose i = 1, j = 2, k = 3, l = 4.
The delish value hence obtained is | ( ( −1 ) + ( −1 ) ) − ( 1 + 1 ) | = 4 .


*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];

		ll dpmaxsumright[n]={0};
		ll dpmaxsumleft[n]={0};
		ll dpminsumright[n]={0};
		ll dpminsumleft[n]={0};

		for(int i=0;i<n;i++)
			cin>>arr[i];
			
		ll currmax = arr[0];
		ll currmin = arr[0];
		//  note that the sum would be contagious for either of the phases (i,j) and (k,l) 
		// we can ignore the fact
		dpmaxsumright[0] = arr[0];
		dpminsumright[0] = arr[0];
		for(int i=1;i<n;i++)
		{
			currmax = max(arr[i], currmax+arr[i]);
			dpmaxsumright[i] =max(dpmaxsumright[i-1], currmax);

			currmin = min(arr[i], currmin+arr[i]);
			dpminsumright[i] = min(dpminsumright[i-1], currmin);
		}
        dpmaxsumleft[n-1] = arr[n-1];
        dpminsumleft[n-1] = arr[n-1];
        currmax = arr[n-1];
        currmin = arr[n-1];
		for(int i=n-2;i>=0;i--)
		{
			currmax = max(arr[i], currmax+arr[i]);
			dpmaxsumleft[i] = max(currmax, dpmaxsumleft[i+1]);

			currmin = min(arr[i], currmin + arr[i]);
			dpminsumleft[i] = min(currmin, dpminsumleft[i+1]);
		}
/* the reason for creating 4 arrays instead of creating 2 is that take into considerations the ngeative values in array as well.
(something you missed previously you little piece of shit.)
	we need do dpmaxrightsum[i] - dpminleftsum[i+1] and dpminrightsum[i] - dpmaxrightsum[i-1] and the maximum of those would be the answer. 
*/		ll ans = (arr[1] - arr[0]); ll  preans;
		for(int i=0;i<(n-1);i++)
		{
		    //cout<<dpmaxsumright[i]<<" ";
			preans = dpmaxsumright[i] - dpminsumleft[i+1];
			if(preans >= ans) ans = preans;

			preans = dpmaxsumleft[i+1] - dpminsumright[i];
			if(preans >= ans) ans = preans;

		}
		cout<<ans<<endl;
	}
	return 0;
}
