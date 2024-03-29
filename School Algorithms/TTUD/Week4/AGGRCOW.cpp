#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll i = 1, j = (a[n - 1] - a[0]) / (c - 1), ans = 0;
        while (i <= j)
        {
            ll mid = ((j + i) / 2);
            int fi = a[0], temp = 1;
            for (int k = 1; k < n; k++)
            {
                if (a[k] - fi >= mid)
                    temp++, fi = a[k];
            }
            if (temp < c)
                j = mid - 1;
            else
            {
                ans = mid;
                i = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}