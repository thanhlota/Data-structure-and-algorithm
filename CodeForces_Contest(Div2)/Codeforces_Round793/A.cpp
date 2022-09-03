#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int cnt()
{
    int res;
    int i = n / 2;
    int j;
    if (n % 2 == 0)
    {
        i -= 1;
        res = 2;
    }
    else
    {
        res = 1;
    }
    j = i - 1;
    while (s[j] == s[i] && j >= 0)
    {
        res += 2;
        j--;
    }
    return res;
}
int main()
{
    cin >> t;
    while (t > 0)
    {
        cin >> n >> s;
        cout << cnt() << endl;
        t--;
    }
    // system("pause");
}