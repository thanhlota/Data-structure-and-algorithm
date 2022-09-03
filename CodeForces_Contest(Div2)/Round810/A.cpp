#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<long long> st;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cout << i + 1 << " ";
        }
        cout << 1 << "\n";
    }
}
