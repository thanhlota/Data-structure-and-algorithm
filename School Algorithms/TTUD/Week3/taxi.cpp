#include <bits/stdc++.h>
#define MAX 24
using namespace std;
int n;
int c[MAX][MAX];
bool visited[MAX];
int res = INT_MAX;
int cnt = 0;
bool check(int v, int prev)
{
    if (c[prev][v] == 0 || visited[v])
        return false;
    int tmp = cnt + c[prev][v] + c[v][v + n];
    if (tmp >= res)
        return false;
    else
    {
        cnt = tmp;
        return true;
    }
}
void Try(int k, int prev)
{
    if (k == (n + 1))
    {
        if (c[prev][0] != 0)
            res = min(res, cnt + c[prev][0]);
        return;
    }
    for (int v = 1; v <= n; v++)
    {
        if (check(v, prev))
        {
            visited[v] = true;
            Try(k + 1, v + n);
            visited[v] = false;
            cnt = cnt - c[prev][v]-c[v][v+n];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
        }
    }
    visited[0] = true;
    Try(1, 0);
    cout<<res;
    // system("pause");
}
