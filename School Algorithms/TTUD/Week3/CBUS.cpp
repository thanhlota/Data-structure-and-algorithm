#include <bits/stdc++.h>
#define MAX 24
using namespace std;
int n, m, p = 0, min_c = INT_MAX, l;
int c[MAX][MAX];
bool visited[MAX];
int res = INT_MAX;
int cnt = 0;
bool check(int v, int prev, int k)
{
    if (c[prev][v] == 0 || visited[v])
        return false;
    int tmp = cnt + c[prev][v] + (l - k) * min_c;
    if (tmp >= res)
        return false;
    else
        return true;
}
void Try(int k, int prev)
{
    if (k == (2 * n + 1))
    {
        if (c[prev][0] != 0)
            res = min(res, cnt + c[prev][0]);
        return;
    }
    for (int v = 1; v <= 2 * n; v++)
    {

        if (v <= n)
        {
            if (p + 1 <= m)
            {
                if (check(v, prev, k))
                {
                    p += 1;
                    cnt += c[prev][v];
                    visited[v] = true;
                    Try(k + 1, v);
                    p -= 1;
                    cnt -= c[prev][v];
                    visited[v] = false;
                }
            }
        }
        else
        {
            if (visited[v - n])
            {
                if (check(v, prev, k))
                {
                    p -= 1;
                    cnt += c[prev][v];
                    visited[v] = true;
                    Try(k + 1, v);
                    p += 1;
                    cnt -= c[prev][v];
                    visited[v] = false;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    l = 2 * n + 1;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
            {
                min_c = min(min_c, c[i][j]);
            }
        }
    }
    visited[0] = true;
    Try(1, 0);
    cout << res;
    // system("pause");
}
