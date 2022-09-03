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
        vector<int> res;
        while (n != 0)
        {
            res.push_back(n % 10);
            n = n / 10;
        }
        if (res.size() == 2)
        {
            cout << res[0];
        }
        else
        {
            int foo = 10;
            for (int i = 0; i < res.size(); i++)
            {
                foo = min(foo, res[i]);
            }
            cout << foo;
        }
        cout << "\n";
    }
}