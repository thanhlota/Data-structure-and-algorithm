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
        vector<int> v(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] & 1)
                odd++;
            else
                even++;
        }
        vector<int> res;
        if (odd > even)
        {
            cout << even;
        }
        else
        {
            cout << odd;
        }
        cout << "\n";
    }
}