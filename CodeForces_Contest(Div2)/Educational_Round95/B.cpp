#include <bits/stdc++.h>
using namespace std;
void printSol(vector<int> v)
{
    int s = v.size();
    for (int i = 0; i < s; i++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        // long long sum = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            // sum += v[i];
        }
        vector<int> check(n);
        // int ui = 0;
        vector<int> ul;
        // long long ps = 0;
        // long long ns = 0;
        vector<int> ns;
        for (int i = 0; i < n; i++)
        {
            cin >> check[i];
            if (!check[i])
            {
                if (v[i] >= 0)
                    ul.push_back(v[i]);
                else
                    ns.push_back(v[i]);
            }
        }
        sort(ul.rbegin(), ul.rend());
        sort(ns.rbegin(), ns.rend());
        for (int i = 0; i < ns.size(); i++)
            ul.push_back(ns[i]);
        int s = ul.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (!check[i])
            {
                v[i] = ul[j];
                j++;
            }
        }
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}