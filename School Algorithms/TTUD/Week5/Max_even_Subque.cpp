#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<pair<long long, long long>> dp(n, {-1e18, -1e18});
    if (abs(v[0]) % 2 == 1)
        dp[0].second = v[0];
    else
        dp[0].first = v[0];
    for (int i = 1; i < n; i++)
    {
        if (abs(v[i]) % 2 == 1)
        {
            if (dp[i-1].second != 0)
                dp[i].first = dp[i - 1].second + v[i];
            if (dp[i - 1].first <= 0)
                dp[i].second = v[i];
            else
                dp[i].second = dp[i - 1].first + v[i];
        }
        else
        {
            if (dp[i - 1].first <= 0)
                dp[i].first = v[i];
            else
                dp[i].first = dp[i - 1].first + v[i];
            if (dp[i - 1].second != 0)
                dp[i].second = dp[i - 1].second + v[i];
        }
    }
    long long mx = -1e18;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, dp[i].first);
    }
    if (mx == -1e18)
        cout << "NOT_FOUND";
    else
        cout << mx;
    system("pause");
}