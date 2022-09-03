#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
int t, n;
int res[MAX];
int cnt()
{
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (res[i] != i)
        {
            ans &= i;
        }
    }
    return ans;
}
int main()
{
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> res[i];
        cout << cnt() << endl;
        t--;
    }
    // system("pause");
}