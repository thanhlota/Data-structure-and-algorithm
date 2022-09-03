#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10001];
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= r; i++)
        cin >> a[i];
    int i = r;
    while (i >= 1 && a[i] == n - r + i)
    {
        i = i - 1;
    }
    if (i == 0)
    {
        cout << "-1";
        return 0;
    }
    a[i] = a[i] + 1;
    for (int j = i + 1; j <= r; j++)
    {
        a[j] = a[i] + j - i;
    }
    for (int i = 1; i <= r; i++)
        cout << a[i] << " ";
    // system("pause");
}
