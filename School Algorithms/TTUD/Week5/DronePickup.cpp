#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans = 0;
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
    dp[0][1] = c[1];
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k < j; k++)
            {
                if (a[k] >= j - k && dp[i - 1][k] != 0)
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + c[j]);
            }
    for (int i = 0; i <= k; i++)
        ans = max(ans, dp[i][n]);
    if (ans == 0)
        cout << "-1";
    else
        cout << ans;
    system("pause");
}