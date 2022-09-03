#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 1 1 2 2 2
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        bool check = true;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<vector<int>> res(1);
        res[0].push_back(1);
        int j = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                res.resize(j + 1);
                j += 1;
            }
            res[j - 1].push_back(i + 1);
        }
        vector<int> ans;
        for (auto &i : res)
        {
            if (i.size() == 1)
            {
                check = false;
                break;
            }
            for (int j = 0; j < i.size() - 1; j++)
            {
                ans.push_back(i[j + 1]);
            }
            ans.push_back(i[0]);
        }
        if (!check)
        {
            cout << "-1";
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }
}