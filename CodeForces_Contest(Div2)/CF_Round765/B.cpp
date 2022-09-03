#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        unordered_map<int, vector<int>> mp;
        vector<int> v;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            mp[tmp].push_back(i);
        }
        for (auto &s : mp)
        {
            int size = s.second.size();
            if (size > 1)
            {

                int maximus = -1;
                for (int i = 0; i < size - 1; i++)
                {
                    maximus = max(maximus, (s.second)[i] + n - (s.second)[i + 1]);
                }
                v.push_back(maximus);
            }
        }
        int res = -1;
        if (!v.empty())
        {
            sort(v.rbegin(), v.rend());
            res = v[0];
        }
        cout << res << endl;
    }
}