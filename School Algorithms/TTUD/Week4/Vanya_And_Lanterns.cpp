#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    double max_dis = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i + 1] - v[i] > max_dis)
            max_dis = v[i + 1] - v[i];
    }
    if (v[0] != 0)
    {
        if (max_dis < 2 * v[0])
            max_dis = 2 * v[0];
    }
    if (v[n - 1] != l)
    {
        if (max_dis < 2 * (l-v[n-1]))
            max_dis = 2 * (l-v[n-1]);
    }
    printf("%.9f", max_dis * 1.0 / 2);
    // system("pause");
}