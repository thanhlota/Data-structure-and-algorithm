#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        unsigned long long sum = 0;
        cin >> s;
        int first_one = n - 1;
        while (s[first_one] == '0')
            first_one -= 1;
        int foo = n - 1 - first_one;
        bool check = false;
        if (foo <= k)
        {
            swap(s[first_one], s[n - 1]);
            k -= foo;
            check = true;
        }
        first_one = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 && check == true)
                break;
            if (s[i] == '1')
            {
                first_one = i;
                break;
            }
        }
        if (first_one <= k)
        {
            swap(s[0], s[first_one]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
                sum += 1;
            if (s[i] == '1' && s[i + 1] == '0')
                sum += 10;
            if (s[i] == '1' && s[i + 1] == '1')
                sum += 11;
        }
        cout << sum << "\n";
        // cout.flush();
    }
}