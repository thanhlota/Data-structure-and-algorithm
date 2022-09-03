#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, d;
    cin >> n >> t >> d;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            for (int k = 1; k <= d; k++)
            {
                if (i >= k && j >= b[i])
                    dp[i][j] = max(dp[i][j], dp[i - k][j - b[i]] + a[i]);
            }
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx;
    // system("pause");
}