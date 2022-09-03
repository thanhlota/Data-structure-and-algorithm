#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int k1, k2;
    // vector<bool> check(n + 1, false);
    vector<int> v(n, 0);
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        cout << "? " << i + 1 << " " << j + 1 << endl;
        cin >> k1;
        cout << "? " << j + 1 << " " << i + 1 << endl;
        cin >> k2;
        if (k1 > k2)
        {
            v[i] = k1;
            i = j;
        }
        else
        {
            v[j] = k2;
        }
    }
    v[i] = n;
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    // system("pause");
    return 0;
}