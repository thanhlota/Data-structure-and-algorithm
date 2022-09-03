#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    ull t;
    cin >> t;
    while (t--)
    {
        ull n, l;
        cin >> n >> l;
        ull tmp;
        pair<int, int> res[100]{{0, 0}};
        // ull tmp = 1 << l - 1;
        for (ull i = 0; i < n; i++)
        {
            cin >> tmp;
            int j = 99;
            while (tmp)
            {
                if (tmp % 2 == 0)
                    res[j--].first += 1;
                else
                    res[j--].second += 1;
                tmp /= 2;
            }
            while (j >= 0)
            {
                res[j--].first += 1;
            }
        }
        ull ans = 0;
        for (int i = 99; i >= 0; i--)
        {
            if (res[i].second > res[i].first)
                ans += pow(2, 99 - i);
        }
        cout << ans << endl;
    }
}