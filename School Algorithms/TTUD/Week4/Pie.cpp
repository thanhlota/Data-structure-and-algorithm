#include <bits/stdc++.h>
const double PI = acos(-1);
#define error 1e-7
using namespace std;
int n, f;
unordered_map<double, int> mp;
double ans;
int r[100001];
bool check(double v)
{
    int count = 0;
    for (auto i : mp)
    {
        count += int(i.first / v) * i.second;
    }
    return count >= f;
}
double cnt(double min_v, double max_v)
{
    while (max_v - min_v >= error)
    {
        double mid = (min_v + max_v) / 2.0;
        if (check(mid))
        {
            min_v = mid;
        }
        else
        {
            max_v = mid;
        }
    }
    return max_v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    double tmp;
    while (t--)
    {
        double max_v = 0;
        cin >> n >> f;
        f++;
        for (int i = 1; i <= n; i++)
        {
            cin >> r[i];
            tmp = PI * r[i] * r[i];
            mp[tmp]++;
            max_v = max(max_v, tmp);
        }
        printf("%.6f\n", cnt(0, max_v));
        mp.clear();
    }
}