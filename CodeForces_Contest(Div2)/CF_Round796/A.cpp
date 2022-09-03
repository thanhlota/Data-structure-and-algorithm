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
        long long x;
        cin >> x;
        if (x == 1)
            cout << 3 << "\n";
        else
        {
            int k = x;
            int bit = 0;
            while (k % 2 == 0)
            {
                k = k / 2;
                bit += 1;
            }
            k = 1 << bit;
            if (k < x)
                cout << k;
            else
                cout << k + 1;
            cout << "\n";
        }
    }
    // cout.flush();
}