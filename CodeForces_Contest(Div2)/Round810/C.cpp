#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD 1000000007
//(r-l+1)*(r+l)/2=n
// r^2-l^2+r-l = 2n
// (2r+1)^2-(2l+1)^2= 8n
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        while (k != 0)
        {
            v.push_back(k % 2);
            k /= 2;
        }
        int foo = v.size();
        vector<long long> dp(foo);
        dp[0] = 1;
        for (int i = 1; i < foo; i++)
        {
            dp[i] = dp[i - 1]*n%MOD;
        }
        long long res = 0;
        for (int i = 0; i < foo; i++)
        {
            if (v[i] == 1)
            {
                res = (res%MOD+ dp[i])%MOD;
            }
        }
        cout << res << "\n";
    }
}
