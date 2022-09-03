#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a;
        ull sum_a = 0, sum_b = 0;
        int tmp;
        vector<pair<int, ull>> a1;
        vector<pair<int, ull>> b1;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            int foo = 1;
            while (tmp % m == 0)
            {
                foo *= m;
                tmp = tmp / m;
            }
            if (!a1.empty() && a1.back().first == tmp)
            {
                a1.back().second += foo;
            }
            else
            {
                a1.push_back({tmp, foo});
            }
        }
        int k;
        cin >> k;
        vector<int> b;
        for (int i = 0; i < k; i++)
        {
             cin >> tmp;
            int foo = 1;
            while (tmp % m == 0)
            {
                foo *= m;
                tmp = tmp / m;
            }
            if (!b1.empty() && b1.back().first == tmp)
            {
                b1.back().second += foo;
            }
            else
            {
                b1.push_back({tmp, foo});
            }
        }
        if (a1 == b1)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}