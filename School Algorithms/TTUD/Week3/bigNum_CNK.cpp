// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000000
#define ull unsigned long long
ull n, r, m, t;
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
    // Returns: (a * b/2) mod c
    ull a2 = bigMod(a, b / 2);

    // Even factor
    if ((b & 1) == 0)
    {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2%m + a2%m) % m;
    }
    else
    {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % m) + (a2%m + a2%m)) % m;
    }
}
ull binomialCoeff()
{

    if (r > n)
        return 0;
    ull inv[r + 1] = {0};
    inv[0] = 1;
    inv[1] = 1;
    // Getting the modular inversion
    // for all the numbers
    ull tmp1, tmp2;
    for (ull i = 2; i <= r; i++)
    {
        tmp1 = m / i;
        tmp2 = inv[m % i];
        if (tmp1 <= MAX && tmp2 <= MAX)
            inv[i] = m - tmp1 * tmp2 % m;
        else
        {
            if (tmp1 > tmp2)
                inv[i] = m - bigMod(tmp1, tmp2);
            else
                inv[i] = m - bigMod(tmp2, tmp1);
            // (m - (m/i) * r[m%i] % m) % m;
            // m - (m / i) * inv[m % i] % m
        }
    }
    ull ans = 1;
    // for 1/(r!) part
    for (ull i = 2; i <= r; i++)
    {
        tmp1 = ans % m;
        tmp2 = inv[i] % m;
        if (tmp1 <= MAX && tmp2 <= MAX)
            ans = tmp1 * tmp2 % m;
        else
        {
            if (tmp1 > tmp2)
                ans = bigMod(tmp1, tmp2);
            else
                ans = bigMod(tmp2, tmp1);
        }
        // ans = ((ans % m) * (inv[i] % m)) % m;
    }
    // for (n)*(n-1)*(n-2)*...*(n-r+1) part
    for (ull i = n; i >= (n - r + 1); i--)
    {
        tmp1 = ans % m;
        tmp2 = i % m;
        if (tmp1 <= MAX && tmp2 <= MAX)
            ans = tmp1 * tmp2 % m;
        else
        {
            if (tmp1 > tmp2)
                ans = bigMod(tmp1, tmp2);
            else
                ans = bigMod(tmp2, tmp1);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t > 0)
    {
        cin >> n >> r >> m;
        cout << binomialCoeff() << endl;
        // system("pause");
        t--;
    }
    return 0;
}