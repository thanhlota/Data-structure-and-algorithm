#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> res(n, 1);
    int mx = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
                res[i] = max(res[i], res[j] + 1);
        }
        mx = max(mx, res[i]);
    }
    cout << mx;
}