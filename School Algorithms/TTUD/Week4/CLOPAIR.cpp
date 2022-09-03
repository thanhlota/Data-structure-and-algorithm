#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>
pair<pdd, pdd> min_t;
vector<pdd> v;
double ans = 1e18;
void sol(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    if (r == l + 1)
    {
        double x = v[r].first - v[l].first;
        double y = v[r].second - v[l].second;
        double dist = sqrt(x * x + y * y);
        if (dist < ans)
        {
            ans = dist;
            min_t = {v[l], v[r]};
        }
        return;
    }
    int mid = (l + r) / 2;
    sol(l, mid);
    sol(mid + 1, r);
    vector<pdd> a;
    vector<pdd> b;
    for (int i = mid; i >= l; i--)
    {
        if (v[mid].first - v[i].first < ans)
        {
            a.push_back(v[i]);
        }
        else
            break;
    }
    for (int i = mid + 1; i <= r; i++)
    {
        if (v[i].first - v[mid].first < ans)
        {
            b.push_back(v[i]);
        }
        else
            break;
    }
    vector<pdd> t;
    for (int i = 0; i < a.size(); i++)
        t.push_back(a[i]);
    for (int i = 0; i < b.size(); i++)
        t.push_back(b[i]);
    sort(t.begin(), t.end(), [](pdd i, pdd j)
         { return i.second <= j.second; });
    for (int i = 0; i < t.size() - 1; i++)
    {
        int j = i + 1;
        while (t[j].second - t[i].second < ans && j < t.size())
        {
            double x = t[j].first - t[i].first;
            double y = t[j].second - t[i].second;
            double dist = sqrt(x * x + y * y);
            if (dist < ans)
            {
                ans = dist;
                min_t = {t[i], t[j]};
            }
            j += 1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (double i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    //foolish mistake :))
    vector<pdd> foo(v.begin(), v.end());
    sort(v.begin(), v.end());
    sol(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (foo[i] == min_t.first || foo[i] == min_t.second)
            cout << i << " ";
    }
    printf("%.6f\n", ans);
}
