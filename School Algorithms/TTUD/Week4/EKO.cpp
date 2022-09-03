#include <iostream>
#define MAX 1000000
using namespace std;
long long a[MAX];
int n;
long long m, maximus = 0;
bool check(long long h)
{
    long long S = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > h)
            S += a[i] - h;
        if (S >= m)
            return true;
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maximus = (a[i] > maximus) ? a[i] : maximus;
    }
    long long l = 0, r = maximus, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
            r = mid - 1;
    }
    cout << res;
    //   cout<<maximus;
}