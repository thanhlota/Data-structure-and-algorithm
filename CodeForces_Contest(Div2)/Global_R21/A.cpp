#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, z;
        cin >> n >> z;
        vector<int> v(n);
        int res = INT_MIN;
        for (int &i : v)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            res = max(res, v[i] | z);
        }
        cout << res << "\n";
    }
}