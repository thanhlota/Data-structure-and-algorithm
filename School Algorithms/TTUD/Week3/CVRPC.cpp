#include <bits/stdc++.h>
#define MAX 21
#define mod (1000000000 + 7)
#define ull unsigned long long
using namespace std;
int n, k, q;
int fleet_left;
int d[MAX];
// danh dau xe da dung
// bool fl[MAX];
ull cnt = 0;
int t = 1;
// so luong hang co the chua con lai cua tung xe
int l[MAX];
// so luong dia diem ma tung chiec xe da den
int visit[MAX]{0};
int giaiThua(int n)
{
    if(n==0) return 1;
    int giai_thua = 1;
    for (int i = 1; i <= n; i++)
        giai_thua *= i;
    return giai_thua;
}
void init()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= k; i++)
    {
        l[i] = q;
        t *= i;
    }
    fleet_left = k;
}
bool check(int i, int v)
{
    if (l[i] < d[v])
        return false;
    if (l[i] != q)
    {
        if (fleet_left > (n - v))
            return false;
    }
    else
    {
        fleet_left -= 1;
    }
    visit[i] += 1;
    return true;
}
ull count()
{
    ull tmp = 1;
    for (int i = 1; i <= k; i++)
    {
        tmp*=giaiThua(visit[i]);
    }
    return tmp;
}
void Try(int v)
{
    if (v == (n + 1))
    {
        int tmp=count();
        cnt += tmp;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (check(i, v))
        {
            l[i] -= d[v];
            Try(v + 1);
            visit[i]-=1;
            l[i] += d[v];
            if (l[i] == q)
            {
                fleet_left += 1;
            }
        }
    }
}
int main()
{
    init();
    Try(1);
    cnt/=t;
    cout << cnt % mod;
    // system("pause");
}