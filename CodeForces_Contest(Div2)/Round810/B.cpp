#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<long long> st;
#define pii pair<int, int>
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pii> v(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].second;
            v[i].first = i;
            res += v[i].second;
        }
        vector<int>
            cnt(n, 0);
        vector<pii> num(m);
        int tmp = m;
        while (m--)
        {
            int foo1, foo2;
            cin >> foo1 >> foo2;
            foo1--;
            foo2--;
            cnt[foo1] += 1;
            cnt[foo2] += 1;
            num[m].first = foo1;
            num[m].second = foo2;
        }
        if (tmp % 2 == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        sort(v.begin(), v.end(), [&](pii a, pii b)
             { return a.second < b.second; });
        for (int i = 0; i < n; i++)
        {
            if (cnt[v[i].first] % 2)
            {
                res = v[i].second;
                break;
            }
        }
        for (int i = 0; i < tmp; i++)
        {
            if (cnt[num[i].first] % 2 == 0 && cnt[num[i].second] % 2 == 0)
            {
                res = min(res, v[num[i].first].second + v[num[i].second].second);
            }
        }
        cout
            << res << "\n";
    }
}
