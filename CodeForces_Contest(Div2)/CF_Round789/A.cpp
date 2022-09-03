#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        set<int> mp;
        int non_zero = 0;
        for (int &i : v)
        {
            cin >> i;
            mp.insert(i);
            if (i != 0)
            {
                non_zero += 1;
            }
        }
        int res = 0;
        if (non_zero == n)
        {
            if (mp.size() == n)
                cout << n + 1 << "\n";
            else
                cout << n << "\n";
        }
        else
            cout << non_zero << "\n";
    }
}