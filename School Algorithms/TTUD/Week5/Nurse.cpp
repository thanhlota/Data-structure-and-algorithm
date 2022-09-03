#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
int n, k1, k2;
void count(vector<ull> &dp, int i)
{
    for (int j = k1 + 1; j <= k2 + 1; j++)
    {
        int t = i - j;
        if (t >= 0)
        {
            if (dp[t] == 0)
            {
                count(dp, t);
            }
            dp[i] = (dp[i] + dp[t] % MOD) % MOD;
        }
    }
}
int main()
{
    cin >> n >> k1 >> k2;
    // add two guards(break days) in the front and back
    vector<ull> dp(n + 2, 0);
    dp[0] = 1;
    dp[1] = 1; // the first day can be a break day
    count(dp, n + 1);
    count(dp, n); // the last day can be a break day
    cout << dp[n] + dp[n + 1];
    // system("pause");
}