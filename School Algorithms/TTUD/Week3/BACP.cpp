#include <bits/stdc++.h>
#define MAX 17
using namespace std;
int n, m;
int load[MAX];
int a[MAX][MAX];
int cnt[MAX];
int res = INT_MAX;
// mang chua khoa hoc lon nhat co the nhan cua tung mon hoc
int max_course[MAX];
bool check(int k, int v)
{
    if (v > max_course[k])
        return false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][k] == 1)
        {
            if (v == 1)
                return false;
            max_course[i] = min(max_course[i], v - 1);
        }
    }
    return true;
}
void Try(int k)
{
    if (k == (n + 1))
    {
        int tmp = INT_MIN;
        for (int i = 1; i <= m; i++)
        {
            tmp = max(tmp, cnt[i]);
        }
        res = min(res, tmp);
        return;
    }
    int temp[MAX];
    for (int i = 1; i <= n; i++)
        temp[i] = max_course[i];
    for (int v = 1; v <= m; v++)
    {
        if (check(k, v))
        {
            cnt[v] += load[k];
            Try(k + 1);
            cnt[v] -= load[k];
            for (int i = 1; i <= n; i++)
                max_course[i] = temp[i];
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        max_course[i] = m;
        cin >> load[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << res;
    // system("pause");
}