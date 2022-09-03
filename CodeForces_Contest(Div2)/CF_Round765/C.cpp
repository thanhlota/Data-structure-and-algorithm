#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> s(n);
    // sign
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    // min time
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    const long long inf = (long long)1e18;
    s.push_back(l);
    t.push_back(0);
    long long ans = inf;
    vector<vector<long long>> d(n + 1, vector<long long>(k + 1, inf));
    d[0][0] = 0;
    // for (int i = 1; i <= n; i++)
    //     d[i][0] = d[i - 1][0] + t[i - 1] * (s[i] - s[i - 1]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int p = i - 1; p >= 0; p--)
            {
                int old_j = j - (i - p - 1);
                if (old_j >= 0)
                {
                    d[i][j] = min(d[i][j], d[p][old_j] + t[p] * (s[i] - s[p]));
                }
            }
        }
    }
    for (int j = 0; j <= k; j++)
        ans = min(ans, d[n][j]);
    cout << ans;
}