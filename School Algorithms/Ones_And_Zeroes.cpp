#include <bits/stdc++.h>
using namespace std;
int slow0n3(vector<string> &strs, int m, int n)
{
    int sz = strs.size();
    vector<int> a(sz, 0); // number of one
    vector<int> b(sz, 0);
    for (int i = 0; i < sz; i++)
    {
        int ss = strs[i].size();
        for (int j = 0; j < ss; j++)
        {
            if (strs[i][j] == '1')
                a[i]++;
            else
                b[i]++;
        }
    }
    // matrix denote the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
    vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    dp[sz][m][n] = 0;
    int cnt = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = n; k >= 0; k--)
            {
                if (j - b[i] >= 0 && k - a[i] >= 0)
                    dp[i][j - b[i]][k - a[i]] = max(dp[i][j - b[i]][k - a[i]], dp[i + 1][j][k] + 1);
                dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
            }
        }
    }
    for (int j = m; j >= 0; j--)
    {
        for (int k = n; k >= 0; k--)
            cnt = max(dp[0][j][k], cnt);
    }
    return cnt;
}
int fast0n2(vector<string> strs, int m, int n)
{
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
    int numZeroes, numOnes;

    for (auto &s : strs)
    {
        numZeroes = numOnes = 0;
        // count number of zeroes and ones in current string
        for (auto c : s)
        {
            if (c == '0')
                numZeroes++;
            else if (c == '1')
                numOnes++;
        }
        // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
        // from the first few strings up to the current string s
        // Catch: have to go from bottom right to top left
        // Why? If a cell in the memo is updated(because s is selected),
        // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
        // If we go from top left to bottom right, we would be using results from this iteration => overcounting
        for (int i = m; i >= numZeroes; i--)
        {
            for (int j = n; j >= numOnes; j--)
            {
                memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
            }
        }
    }
    return memo[m][n];
}
int main()
{
    int k;
    cin >> k;
    vector<string> strs(k);
    for (int i = 0; i < k; i++)
        cin >> strs[i];
    int n, m;
    cin >> m >> n;
    cout << slow0n3(strs, m, n);
    system("pause");
}