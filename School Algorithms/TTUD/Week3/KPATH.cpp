#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long res = 0;
vector<vector<int>> v;
vector<bool> visited;
void DFS(int x, int prev)
{

    if (x == k + 1)
    {
        res += 1;
        return;
    }
    for (int i = 0; i < v[prev].size(); i++)
    {
        if (!visited[v[prev][i]])
        {
            visited[v[prev][i]] = true;
            DFS(x + 1, v[prev][i]);
            visited[v[prev][i]] = false;
        }
    }
}
void BFS()
{
}
int main()
{
    cin >> n >> k >> m;
    v.resize(n + 1);
    visited.resize(n + 1, false);
    while (m--)
    {
        int s, e, w;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    for (int i = 1; i <= n; i++)
        v[0].push_back(i);
    visited[0] = true;
    DFS(0, 0);
    cout << res/2;
    // system("pause");
}