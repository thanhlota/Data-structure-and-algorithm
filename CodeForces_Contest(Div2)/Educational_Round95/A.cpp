#include <bits/stdc++.h>
using namespace std;
#define ll long long
// void sol1(ll x, ll y, ll k)
// {
//     cin >> x >> y >> k;
//     ll ans = 0;
//     ll cnt1 = (k - 1) / (x - 1);
//     if (cnt1 * (x - 1) < (k - 1))
//         cnt1 += 1;
//     ll left = cnt1 * (x - 1) - (k - 1);
//     ans = cnt1;
//     // if (left / y > 0)
//     // {
//     ll foo = left / y;
//     if (k > foo)
//     {
//         k -= foo;
//         ans += foo;
//         left -= foo * y;
//         ll left2 = k * y - left;
//         ll cnt2 = left2 / (x - 1);
//         if (cnt2 * (x - 1) < left2)
//             cnt2 += 1;
//         ans += cnt2;
//     }
//     cout << ans + k << endl;
// }
// faster in time complexity and smaller in memory complexity
void sol2(ll x, ll y, ll k)
{
    // try to find the minimum number of stick
    ll minS = k * (y + 1) - 1;
    ll ans = (minS + (x - 2)) / (x - 1) + k;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        // sol2(x, y, k);
        ll minS = k * (y + 1) - 1;
        ll ans = (minS + (x - 2)) / (x - 1) + k;
        cout << ans << endl;
    }
}