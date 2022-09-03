// using the same method as aggrcow
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll m, k;
        cin >> m >> k;
        vector<ll> v(m);
        ll mn = INT_MAX;
        long long sum = 0;
        for (ll i = 0; i < m; i++)
        {
            cin >> v[i];
            sum += v[i];
            mn = min(v[i], mn);
        }
        ll l = mn;
        ll r = sum;
        ll res;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long cnt = 0, foo = 1;
            for (ll i = 0; i < m; i++)
            {
                if (v[i] > mid)
                {
                    foo = 501;
                    break;
                }
                if (cnt + v[i] > mid)
                {
                    cnt = 0;
                    foo += 1;
                }
                cnt += v[i];
            }
            if (foo <= k)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        long long foo = 1, cnt = 0;
        vector<ll> ans;
        for (ll i = m - 1; i >= 0; i--)
        {
            if (cnt + v[i] > res || i + 1 == k - foo)
            {
                cnt = 0;
                foo += 1;
                ans.push_back(-1);
            }
            cnt += v[i];
            ans.push_back(v[i]);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != -1)
            {
                cout << ans[i] << " ";
            }
            else
                cout << " / ";
        }
        cout << "\n";
    }
}
