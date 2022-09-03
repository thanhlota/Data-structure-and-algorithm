#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int even_num = 0;
        int odd_num = 0;
        long long sum = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 4 == 0)
            {
                even_num += 1;
                sum += v[i];
                // sum2 += v[i];
            }
            else
            {
                if (v[i] % 2 == 0)
                {
                    odd_num += 1;
                    // sum2 += v[i];
                }
            }
        }
        if (even_num + odd_num < n)
        {
            cout << even_num + odd_num;
        }
        else
        {
            long long mn = 1e18;
            for (int i = 0; i < n; i++)
            {
                long long k = 0;
                while (v[i] % 2 == 0)
                {
                    k += 1;
                    v[i] /= 2;
                }
                mn = min(mn, k);
            }
            cout << mn + n - 1;
        }
        cout << "\n";
    }
    // cout.flush();
}