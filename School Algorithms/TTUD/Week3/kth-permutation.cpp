#include <bits./stdc++.h>
using namespace std;
#define ull unsigned long long
ull n, k;
ull res[10001];
ull indexed[10001];
ull factorial[14];
ull tmp;
void pre_process()
{
    factorial[0] = factorial[1] = 1;
    for (ull i = 2; i <= 13; i++)
        factorial[i] = i * factorial[i - 1];
}
void dl(ull k)
{
    ull i;
    for (i = k; i < n; i++)
        indexed[i] = indexed[i + 1];
}
void printSol()
{
    for (ull i = 1; i <= n; i++)
        cout << res[i] << " ";
}
void smalln()
{

    if (k > factorial[n])
    {
        cout << -1;
        return;
    }
    for (ull i = 1; i <= n; i++)
    {
        indexed[i] = i;
    }
    ull i = 1;
    while (i <= n)
    {
        tmp = k / factorial[n - i];
        tmp = ((k - tmp * factorial[n - i]) == 0) ? tmp : (tmp + 1);
        res[i] = indexed[tmp];
        k -= (tmp - 1) * factorial[n - i];
        dl(tmp);
        i++;
    }
    printSol();
}
void bign(ull v)
{
    for (ull i = 1; i <= v; i++)
    {
        res[i] = i;
    }
    for (ull i = 1; i <= n - v; i++)
    {
        indexed[i] = i + v;
    }
    ull i = v + 1;
    while (i <= n)
    {
        tmp = k / factorial[n - i];
        tmp = ((k - tmp * factorial[n - i]) == 0) ? tmp : (tmp + 1);
        res[i] = indexed[tmp];
        k -= (tmp - 1) * factorial[n - i];
        dl(tmp);
        i++;
    }
    printSol();
}
int main()
{
    cin >> n >> k;
    pre_process();
    for (ull i = 1; i <= n; i++)
    {
        res[i] = i;
        indexed[i] = i;
    }
    ull i = 12;
    while (k / factorial[i] == 0)
        --i;
    if (n - 1 <= i)
    {
        smalln();
    }
    else
    {
        bign(n - i - 1);
    }
    // system("pause");
}