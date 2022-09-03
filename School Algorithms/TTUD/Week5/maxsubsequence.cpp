#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    vector<int> dp(v.begin(), v.end());
    int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] > 0)
            dp[i] = dp[i - 1] + v[i];
        ans = max(ans, dp[i]);
    }
    cout<<ans;
}