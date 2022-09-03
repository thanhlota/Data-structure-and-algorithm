#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n;)
        {
            if (v[i] != 0)
            {
                cnt1 += 1;
                while (i < n && v[i] != 0)
                    i++;
            }
            else
            {
                cnt2 += 1;
                while (i < n && v[i] == 0)
                    i++;
            }
        }
        if (cnt1 == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        if (cnt2 == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        if (cnt1 == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << 2 << "\n";
    }
}