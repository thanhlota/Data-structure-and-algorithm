#include <bits/stdc++.h>
#define MAX 200001
#define ull unsigned long long
using namespace std;
ull res[MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull t, n, m, tmp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ull i = 1; i <= n; i++)
        {
            cin >> res[i];
        }
        ull sum = 0;
        cin >> m;
        while (m--)
        {
            cin >> tmp;
            sum += tmp;
        }
        ull i = sum % n+1;
        cout << res[i]<<endl;
    }
}