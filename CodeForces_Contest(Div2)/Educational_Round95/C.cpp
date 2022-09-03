#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        // dp[i][j] denotes the min point use from 0-th to i-th and the next person is j
        // j=0 mean the next person is him and vice versa
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][1] = (v[0] == 1);
        dp[0][0] = 2;
        dp[1][0] = v[0];
        dp[1][1] = v[0] + v[1];
        for (int i = 2; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
            dp[i][1] = min(dp[i - 1][0] + v[i], dp[i - 2][0] + v[i] + v[i - 1]);
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
    }
}