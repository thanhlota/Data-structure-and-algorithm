#include <bits/stdc++.h>
using namespace std;
struct jug
{
    int capacity;
    int amount;
};
int minStep = 0;
jug jug1, jug2;
int a, b, c;
bool visited[1000][1000];
map<pair<int, int>, int> dist;
void pourWater(jug &a, jug &b)
{
    if (a.amount + b.amount <= b.capacity)
    {
        b.amount += a.amount;
        a.amount = 0;
    }
    else
    {
        a.amount = a.amount + b.amount - b.capacity;
        b.amount = b.capacity;
    }
}
void fullJug(jug &a)
{
    a.amount = a.capacity;
}
void pourOut(jug &a)
{
    a.amount = 0;
}
bool checkRes(jug a, jug b)
{
    if (a.amount == c || b.amount == c)
        return true;
    return false;
}
bool checkVisit(jug a, jug b)
{
    if (visited[a.amount][b.amount])
        return false;
    visited[a.amount][b.amount] = true;
    return true;
}
void Waterbfs()
{
    jug tmp1;
    jug tmp2;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[{0, 0}] = 0;
    while (!q.empty())
    {
        jug1.amount = q.front().first;
        jug2.amount = q.front().second;
        tmp1 = jug1;
        tmp2 = jug2;
        q.pop();
        if (checkRes(jug1, jug2))
        {
            cout << dist[{jug1.amount, jug2.amount}];
            return;
        }

        fullJug(jug1);
        if (checkVisit(jug1, jug2))
        {
            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
        jug1 = tmp1;
        jug2 = tmp2;
        // pour water from jug1 to jug2
        pourWater(jug1, jug2);
        if (checkVisit(jug1, jug2))
        {

            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
        jug1 = tmp1;
        jug2 = tmp2;
        fullJug(jug2);
        if (checkVisit(jug1, jug2))
        {

            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
        jug1 = tmp1;
        jug2 = tmp2;

        pourWater(jug2, jug1);
        if (checkVisit(jug1, jug2))
        {

            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
        jug1 = tmp1;
        jug2 = tmp2;

        // pour all water in jug1
        pourOut(jug1);
        if (checkVisit(jug1, jug2))
        {

            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
        jug1 = tmp1;
        jug2 = tmp2;
        pourOut(jug2);
        if (checkVisit(jug1, jug2))
        {

            q.push({jug1.amount, jug2.amount});
            dist[{jug1.amount, jug2.amount}] = dist[{tmp1.amount, tmp2.amount}] + 1;
        }
    }
    cout << "-1";
}
int main()
{

    cin >> a >> b >> c;
    jug1.capacity = a;
    jug2.capacity = b;
    Waterbfs();
    // system("pause");
    return 0;
}