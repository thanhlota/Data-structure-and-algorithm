#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
int t, n;
int res[MAX];
// 1 2 3 1  2 3 4
map<int, int> mp;
int count()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[res[i]] != 0)
        {
            ans += 1;
            mp[res[i]]--;
        }
    }
    return (ans + 1) / 2;
}
int main()
{
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> res[i];
            if (mp[res[i]] < 2)
                mp[res[i]]++;
        }
        cout << count() << endl;
        mp.clear();
    }
    // system("pause");
}