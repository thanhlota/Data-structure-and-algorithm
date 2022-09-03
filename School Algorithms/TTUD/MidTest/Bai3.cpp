#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    int m;
    cin >> m;
    vector<string> dp(m);
    for (int i = 0; i < m; i++)
        cin >> dp[i];
    long long res = 0;
    for (int i = 0; i < m; i++)
    {
        int bound = n - dp[i].length();
        int ind = 0;
        for (int k = 0; k < n; k++)
            for (int j = 0; j <= bound; j++)
            {
                int foo = j;
                while (foo < n && ind < dp[i].length() && v[k][foo] == dp[i][ind])
                {
                    ind++;
                    foo++;
                }
                if (ind == dp[i].length())
                    res += 1;
                ind = 0;
            }
    }
    cout << res;
    // system("pause");
}