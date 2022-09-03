#include <bits/stdc++.h>
using namespace std;
// 111 - 262 + 2151= 2000
vector<int> x(7);
vector<int> cnt(10, 0);
int n;
long long res = 0;
bool check()
{

    int sum = x[0] * 100 + x[1] * 10 + x[2] * 2 - x[3] * 100 - 62 + x[4] * 1000 + x[5] * 100 + x[6] * 10;
    bool ok = true;
    for (int i = 1; i < 10; i++)
    {
        if (cnt[i] > 1)
        {
            ok = false;
            break;
        }
    }
    return ok && (sum == n);
}
void printSol()
{
    for (int i = 0; i < 7; i++)
        cout << x[i];
    cout << "\n";
}
void Try(int k)
{
    if (k == 7)
    {
        if (check())
        {
            res += 1;
            // printSol();
        }
        return;
    }
    for (int i = 1; i < 10; i++)
    {
        x[k] = i;
        cnt[i] += 1;
        Try(k + 1);
        cnt[i] -= 1;
    }
}
int main()
{

    cin >> n;
    Try(0);
    cout << res;
    system("pause");
    // I C T K H U S
}