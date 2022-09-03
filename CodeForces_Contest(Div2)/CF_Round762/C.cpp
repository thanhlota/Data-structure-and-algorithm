#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        // int foo = INT_MAX;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = v[i];
            int nxt = (i == n - 1) ? 0 : v[i + 1];
            ans += max(cur - nxt, 0);
        }
        cout << ans << "\n";
        for (int i = 0; i < q; i++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            if(tmp1!=n&&tmp2!=n) ans+=

        }
    }
}