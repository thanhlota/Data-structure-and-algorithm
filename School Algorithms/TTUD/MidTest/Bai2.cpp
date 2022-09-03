#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ull res = 0;
    vector<pair<ull, ull>> dp(n, {0, 0});
    if (v[0] % 2 == 0)
    {
        dp[0].first = 1;
    }
    else
        dp[0].second = 1;
    // 2 9 5 9 3
    for (int i = 1; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            dp[i].first += 1;
            dp[i].first += dp[i - 1].first;
            dp[i].second += dp[i - 1].second;
        }
        else
        {
            dp[i].second += 1;
            dp[i].first += dp[i - 1].second;
            dp[i].second += dp[i - 1].first;
        }
    }
    for (int i = 0; i < n; i++)
    {
        res = (res % MOD + dp[i].first % MOD) % MOD;
    }
    cout << res;
    // system("pause");
}
