// solution uses dp and bitmask
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<vector<ull>> v;
vector<vector<ull>> check;
int n, m, tmp1, tmp2;
ull count(int bitmask, int i)
{
    if (__builtin_popcount(bitmask) == 2)
        return v[0][i]; 
    bitmask = bitmask & (~(1 << i));
    ull ans = 1e18;
    for (int j = 1; j < n; j++)
    {
        if (bitmask & (1 << j))
        {
            if (check[bitmask][j] == 0)
            {
                check[bitmask][j] = count(bitmask, j);
            }
            ans = min(ans, check[bitmask][j] + v[j][i]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    v.resize(n, vector<ull>(n, 1e18));
    for (int i = 0; i < m; i++)
    {
        cin >> tmp1 >> tmp2;
        cin >> v[tmp1 - 1][tmp2 - 1];
    }
    ull ans = 1e18;
    int bitmask = 0;
    for (int i = 0; i < n; i++)
    {
        bitmask = bitmask | (1 << i);
    }
    check.resize(bitmask + 1, vector<ull>(n, 0));
    for (int i = 1; i < n; i++)
    {
        ull foo = count(bitmask, i);
        ans = min(ans, foo + v[i][0]);
    }
    cout << ans;
    // system("pause");
}