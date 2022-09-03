// 60 points maximum :)) 
#include <bits/stdc++.h>
using namespace std;
long long res = 0;
int n, m;
vector<int> visited;
vector<vector<int>> foo;
vector<bool> foo2;
void sol(int k)
{
    if (k == n + 1)
    {
        res ++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (foo[k][i] || foo2[i])
            continue;
        visited[k] = i;
        ////////
        int tmp = 1;
        while (tmp < i && k + tmp <= n)
        {
            if (foo[k + tmp][i - tmp] != -1)
                foo[k + tmp][i - tmp] ++;
            tmp++;
        }
        //////////
        foo2[i] = true;
        ///////////
        tmp = 1;
        while ((i + tmp) <= n && k + tmp <= n)
        {
            if (foo[k + tmp][i + tmp] != -1)
                foo[k + tmp][i + tmp] ++;
            tmp++;
        }
        ///////
        sol(k + 1);
        ///////////
        tmp = 1;
        while (tmp < i && k + tmp <= n)
        {
            if (foo[k + tmp][i - tmp] != -1)
                foo[k + tmp][i - tmp] --;
            tmp++;
        }
        ///////////
        foo2[i] = false;
        ///////////
        tmp = 1;
        while ((i + tmp) <= n && k + tmp <= n)
        {
            foo[k + tmp][i + tmp] --;
            tmp++;
        }
    }
}
int main()
{

    while (cin >> n)
    {
        cin >> m;
        if (n == 0)
        {
            // system("pause");
            return 0;
        }
        // cin >> n;
        visited.clear();
        foo.clear();
        foo2.clear();
        visited.resize(n + 1);
        foo.resize(n + 1, vector<int>(n + 1, false));
        foo2.resize(n + 1, false);
        while (m--)
        {
            int r, c;
            cin >> r >> c;
            foo[r][c] = -1;
        }
        sol(1);
        cout << res << "\n";
        res = 0;
    }
}