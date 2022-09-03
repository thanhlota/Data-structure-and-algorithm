#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        int new_a = a;
        while (new_a <= b)
        {
            int x = new_a - a;
            for (int y = 0; y < b - a - 1; y++)
            {
                ans = min(ans, x + y + 1 + ((a + x) | (b + y)) - (b + y));
            }
            new_a=(new_a|(new_a-1))+1;
 
        }
        cout << ans << '\n';
    }
    return 0;
}