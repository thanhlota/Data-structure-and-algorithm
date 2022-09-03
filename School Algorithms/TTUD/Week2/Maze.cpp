#include <bits/stdc++.h>
using namespace std;
int N, M, maze[1000][1000], x, y, dist[1000][1000];
bool checkRes(int i, int j)
{
    if (i == 0 || j == 0 || i == (N - 1) || j == (M - 1))
        return true;
    return false;
}
void bfsMaze()
{
    queue<pair<int, int>> q;
    q.push({x-1, y-1});
    if (maze[x-1][y-1])
    {
        cout << "-1";
        return;
    }
    dist[x-1][y-1] = 0;
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        int i = tmp.first;
        int j = tmp.second;
        q.pop();
        if (checkRes(i, j))
        {
            cout << dist[i][j] + 1;
            return;
        }
        if (!maze[i - 1][j])
        {
            maze[i - 1][j] = 1;
            q.push({i - 1, j});
            dist[i - 1][j] = dist[i][j] + 1;
        }
        if (!maze[i][j - 1])
        {
            maze[i][j - 1] = 1;
            q.push({i, j - 1});
            dist[i][j - 1] = dist[i][j] + 1;
        }
        if (!maze[i + 1][j])
        {
            maze[i + 1][j] = 1;
            q.push({i + 1, j});
            dist[i + 1][j] = dist[i][j] + 1;
        }
        if (!maze[i][j + 1])
        {
            maze[i][j + 1] = 1;
            q.push({i, j + 1});
            dist[i][j + 1] = dist[i][j] + 1;
        }
    }
    cout << "-1";
}
int main()
{
    cin >> N >> M >> x >> y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> maze[i][j];
    bfsMaze();
    // system("pause");
}