// 6x+4y=n; print min(x+y) max(x+y)
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull max_tires, min_tires;
void count(ull n)
{
    if (n % 2 == 1 || n < 4)
    {
        cout << "-1" << endl;
        return;
    }
    if (n == 4)
    {
        cout << 1 << " " << 1 << endl;
        return;
    }
    if (n == 10)
    {
        cout << 2 << " " << 2 << endl;
        return;
    }
    max_tires = n / 4;
    min_tires = n / 6;
    ull tmp1 = n - max_tires * 4;
    ull tmp2 = n - min_tires * 6;
    if (tmp1 % 2 != 0 || tmp2 % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }
    if (tmp2 != 0)
        min_tires += 1;
    cout << min_tires << " " << max_tires << endl;
}
int main()
{
    int t;
    cin >> t;
    ull n;
    while (t > 0)
    {
        cin >> n;
        count(n);
        t--;
    }
    // system("pause");
}