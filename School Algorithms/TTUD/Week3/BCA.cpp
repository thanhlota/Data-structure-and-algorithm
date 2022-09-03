#include <bits/stdc++.h>
#define MAX 31
using namespace std;
int n, m, k;
bool c[MAX][MAX]{false};
bool nb[MAX][MAX]{false};
bool cur[MAX][MAX]{false};
int cnt[MAX]{0};
int res = INT_MAX;
bool check(int i, int v)
{
    if (cnt[i] + 1 >= res)
        return false;
    for (int j = 1; j < v; j++)
    {
        if (cur[i][j])
            if (nb[j][v])
                return false;
    }

    return true;
}
void Try(int v)
{
    if (v == m + 1)
    {
        int tmax = 0;
        for (int i = 1; i <= n; i++)
        {
            tmax = max(tmax, cnt[i]);
        }
        res = min(res, tmax);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (c[i][v] == true)
            {
                if (check(i, v))
                {
                    cnt[i] += 1;
                    cur[i][v] = true;
                    Try(v + 1);
                    cnt[i] -= 1;
                    cur[i][v] = false;
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    cin >> m;
    int tmp1, tmp2;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp1;
        for (int j = 0; j < tmp1; j++)
        {
            cin >> tmp2;
            c[i][tmp2] = true;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> tmp1 >> tmp2;
        nb[tmp1][tmp2] = true;
    }
    Try(1);
    if (res == INT_MAX)
        cout << "-1";
    else
        cout << res;
    // system("pause");
}