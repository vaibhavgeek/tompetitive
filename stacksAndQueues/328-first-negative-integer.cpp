#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll k;
        cin >> k;
        deque<int> window(k);

        window.clear();
        // store the first negative element in the deque for first k elements
        for (int i = 0; i < k; i++)
        {

            if (a[i] < 0)
            {
                window.push_back(i);
            }
        }

        for (int i = k; i < n; i++)
        {
            // if no non negative integer in first k elements
            if (!window.empty())
                cout << a[window.front()] << " ";
            else
                cout << "0"
                     << " ";
            // remove all elements except the sliding window of size k.
            while ((!window.empty()) && window.front() < (i - k + 1))
                window.pop_front();

            // for this sliding window have the first negative integer or zero
            if (a[i] < 0)
                window.push_back(i);
        }
        if (!window.empty())
            cout << a[window.front()] << " " << endl;
        else
            cout << "0"
                 << " " << endl;
    }
}