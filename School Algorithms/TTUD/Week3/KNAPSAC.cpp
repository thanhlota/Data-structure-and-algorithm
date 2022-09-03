#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull n, b;
    cin >> n >> b;
    vector<ull> a(n + 1), c(n + 1);
    for (ull i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    ull res = 0;
    vector<vector<ull>> dp(2, vector<ull>(b + 1, 0));
    int prev = 0, now = 1;
    for (ull j = 1; j <= n; j++)
    {
        {
            for (ull i = 1; i <= b; i++)
                if (a[j] <= i)
                {
                    dp[now][i] = max(dp[prev][i - a[j]] + c[j], dp[prev][i]);
                }

                else
                {
                    dp[now][i] = dp[prev][i];
                }
            prev = 1 - prev;
            now = 1 - now;
        }
    }
    for (ull i = 1; i <= b; i++)
        res = max(res, dp[prev][i]);
    cout << res << "\n";
    // system("pause");
}