#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;

    int subsno = pow(2,n);
    multiset <int> sum_set;

    for(int i = 1; i <= subsno; i++)
    {
        int sum;
        cin>>sum;
        sum_set.insert(sum);
    }

    vector <long long> subset_sums;
    vector <int> original_array;

    
    sum_set.erase(0); 
    subset_sums.push_back(0);

    while(original_array.size() < n)
    {
        multiset <int> :: iterator it = sum_set.begin();
        int current_element = *it;

        int current_subset_sum_stored = subset_sums.size();

        for(int i = 0; i < current_subset_sum_stored; i++)
        {
            multiset <int> :: iterator it2 = sum_set.find(current_element + subset_sums[i]);

            int current_sum = *it2;

            sum_set.erase(it2);

            subset_sums.push_back(current_sum);
        }

        original_array.push_back(current_element);
    }

    for(int i = 0; i < n; i++)
        cout<<original_array[i]<<" ";
    
    cout<<endl;
    }
	// your code goes here
	return 0;
}

