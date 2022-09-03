#include <bits/stdc++.h>
#define MAX 100001
#define ull unsigned long long
using namespace std;
/* n      0 1 2 3 4 5  6
   k  0   1 1 1 1 1 1  1
      1     1 2 3 4 5  6
      2       1 3 6 10 15
      3         1 4 10 20
      4           1 5  15
      5             1
      6               1
*/
ull k, n, m;
ull c[2][MAX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin >> t;
    while (t > 0)
    {
        cin >> n >> k >> m;
        if (k == 1)
        {
            cout << (n % m) << endl;
            --t;
            continue;
        }
        if (k == n)
        {
            cout << 1 << endl;
            --t;
            continue;
        }
        if (k > (n / 2))
            k = n - k;

        c[0][0] = 1;
        for (ull i = 1; i <= k; i++)
        {
            c[1][0] = 1;
            c[1][i] = 1;
            for (ull j = 1; j < i; j++)
            {
                c[1][j] = (c[0][j - 1] + c[0][j]);
            }
            for (ull j = 0; j <= i; j++)
                c[0][j] = c[1][j];
        }
        // c[1][k]=1;
        for (ull i = k + 1; i <= n; i++)
        {
            c[1][0] = 1;
            for (ull j = 1; j <= k; j++)
            {
                c[1][j] = (c[0][j - 1] + c[0][j]) % m;
            }
            for (ull j = 0; j <= k; j++)
                c[0][j] = c[1][j];
        }
        cout << c[1][k] << endl;
        --t;
    }
    system("pause");
}