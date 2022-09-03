#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }
    sort(a.begin(), a.end(), [&](pii i, pii j)
         { return i.second <= j.second; });
    // v[i] denotes the maximum length of segment till the coordinate i-th
    vector<int> v(a[n - 1].second + 1, 0);
    v[a[0].second] = a[0].second - a[0].first;
    for (int i = 1; i < n; i++)
    {
        int tmp = v[a[i - 1].second];
        for (int j = a[i - 1].second + 1; j < a[i].second; j++)
            v[j] = tmp;
        if (a[i].second - a[i].first >= v[a[i - 1].second])
        {
            v[a[i].second] = a[i].second - a[i].first;
        }
        else
        {
            v[a[i].second] = tmp;
        }
    }
    vector<long long> dp(n, 0);
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        int t = a[i].first - 1;
        if (t > 0 && v[t] != 0)
        {
            dp[i] = v[t] + a[i].second- a[i].first;
        }
    }
    for (int i = 1; i < n; i++)
        ans = max(ans, dp[i]);
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
    // cout.flush();
    // system("pause");
}