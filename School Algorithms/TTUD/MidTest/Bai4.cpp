#include <bits/stdc++.h>
using namespace std;
long long res = 0;
int n, b;
long long foo;
void Try(vector<int> v, long long nsum, int i)
{
    if (nsum == foo)
    {
        res += 1;
        return;
    }
    for (int j = i + 1; j < n; j++)
    {
        if (nsum + v[j] <= foo)
        {
            Try(v, nsum + v[j], j);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    vector<int> v(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    foo = sum + b;
    if (foo % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    foo /= 2;
    Try(v, v[0], 0);
    cout << res;
    // system("pause");
}
