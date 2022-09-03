#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= m; i++)
        dp[0][i] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i]] + 1);
        }
    }
    cout << dp[n][m];
    system("pause");
}