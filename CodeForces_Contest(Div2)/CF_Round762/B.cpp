#include <bits/stdc++.h>
using namespace std;
// 0100
// 0111
// 0100
// 0010
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        int pre_i = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = -1;
            int tmp = v[i];
            while (tmp != 0)
            {
                tmp >>= 1;
                cnt += 1;
            }
            int bound = 1 << (cnt + 1);
            ans += pre_i - i;
            for (int j = pre_i + 1; j < n; j++)
            {
                if (v[j] < bound)
                {
                    pre_i = j;
                    ans += 1;
                }
                else
                    break;
            }
        }
        cout << ans << endl;
    }
}