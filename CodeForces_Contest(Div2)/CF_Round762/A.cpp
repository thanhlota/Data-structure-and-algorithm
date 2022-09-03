#include <bits/stdc++.h>
using namespace std;
#define MAX 100001;
// 9 8 7 6 5 4 3 2 1
// n-1 n-2 .... 1
// vector<int> v;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] <= v[i + 1])
            {
                ok = true;
                break;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
        // cout << endl;
    }
}