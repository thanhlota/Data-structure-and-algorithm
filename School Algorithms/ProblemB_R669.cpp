#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int mx = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[mx])
                mx = i;
        }
        swap(a[mx], a[0]);
        int gcd = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            // gcd = 1;
            int tmp, foo;
            for (int j = i + 1; j < n; j++)
            {
                if (j == i + 1)
                {
                    foo = __gcd(a[i + 1], gcd);
                    mx = i + 1;
                    continue;
                }
                tmp = __gcd(a[j], gcd);
                if (foo < tmp)
                {
                    mx = j;
                    foo = tmp;
                }
            }
            gcd = __gcd(gcd, a[mx]);
            swap(a[i + 1], a[mx]);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}