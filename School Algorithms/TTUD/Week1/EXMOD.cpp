#include <bits./stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;
ull a, b;
ull bigMod(ull a, ull b)
{
    if (a == 1)
    {
        return b;
    }
    if (b == 1)
    {
        return a;
    }
    ull a2 = bigMod(a, b / 2);
    if ((b & 1) == 0)
    {
        return (a2 % MOD + a2 % MOD) % MOD;
    }
    else
    {
        return ((a % MOD) + (a2 % MOD + a2 % MOD)) % MOD;
    }
}
ull bigExp(ull a, ull b)
{
    if (a == 1)
        return 1;
    if (b == 1)
        return a;
    if ((b & 1) == 0)
    {
        ull tmp = bigExp(a, b / 2);
        return bigMod(tmp, tmp);
    }
    else
    {
        return bigMod(a, bigExp(a, b - 1));
    }
}
int main()
{
    cin >> a >> b;
    cout << bigExp(a, b);
    system("pause");
}