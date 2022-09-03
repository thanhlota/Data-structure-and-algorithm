#include <bits/stdc++.h>
#define MAX 51
using namespace std;
int a[MAX];
int b[MAX];
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int maxa = INT_MIN, maxb = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxa = max(maxa, a[i]);
        }
        cin >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            maxb = max(maxb, b[i]);
        }
        if (maxa == maxb)
        {
            cout << "Alice" << endl
                 << "Bob" << endl;
        }
        else
        {
            if (maxa > maxb)
            {
                cout << "Alice" << endl
                     << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl
                     << "Bob" << endl;
            }
        }
    }
}