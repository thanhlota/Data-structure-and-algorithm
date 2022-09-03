#include <bits/stdc++.h>
using namespace std;
struct transact
{
    string s;
    string r;
    int m;
    string t;
    string code;
    transact(string _s, string _r, int _m, string _t, string _code)
    {
        s = _s;
        r = _r;
        m = _m;
        t = _t;
        code = _code;
    }
};
vector<transact> v;
vector<vector<int>> g;
vector<vector<int>> res;
vector<bool> visited;
void dfs(int root, int t, int count)
{
    if (root == t && count != 0)
    {
        res[root].push_back(count);
        return;
    }
    for (int i = 0; i < g[t].size(); i++)
    {
        if (!visited[g[t][i]])
        {
            visited[g[t][i]] = true;
            dfs(root, g[t][i], count + 1);
            visited[g[t][i]] = false;
        }
    }
}
int main()
{

    string s;
    string r;
    int m;
    string t;
    string code;
    int cnt = 1;
    map<string, int> mp;
    while (cin >> s)
    {
        if (s == "#")
            break;
        cin >> r >> m >> t >> code;
        v.push_back(transact(s, r, m, t, code));
        if (mp[s] == 0)
        {
            mp[s] = cnt;
            cnt += 1;
        }
        if (mp[r] == 0)
        {
            mp[r] = cnt;
            cnt += 1;
        }
    }
    g.resize(mp.size() + 1);
    res.resize(mp.size() + 1);
    visited.resize(mp.size() + 1);
    for (int i = 0; i < v.size(); i++)
    {
        g[mp[v[i].s]].push_back(mp[v[i].r]);
    }
    for (int i = 1; i <= mp.size(); i++)
    {
        dfs(i, i, 0);
    }
    string q;
    while (cin >> q)
    {
        if (q == "#")
            break;
        string foo;
        cin >> foo;
        int root = mp[foo];
        int n;
        cin >> n;
        int ok = 0;
        for (int i = 0; i < res[root].size(); i++)
        {
            if (res[root][i] == n)
            {
                ok = 1;
                break;
            }
        }
        cout << ok << "\n";
    }
}
