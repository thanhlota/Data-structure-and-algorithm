#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 100;
// he so nho nhat
int cmin;
// do dai ma tran chi phi
int n;
// ma tran chi phi
int c[MAX][MAX];
// cac diem da duyet
bool visited[MAX]{0};
// mang ket qua duong di
int res[MAX]{0};
// trong so hien tai
int ncost = 0;
// trong so nho nhat cho toi thoi diem hien tai
int minCost = INT_MAX;
// so chang da duyet tinh toi thoi diem hien tai
int cnt = -1;
void input()
{
    FILE *f = fopen("D:\\new project\\aaa\\TSP-13.inp", "r");
    fscanf(f, "%d", &n);
    // printf("read n = %d\n",n);
    cmin = 1000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fscanf(f, "%d", &c[i][j]);
            if (i != j && c[i][j] < cmin)
                cmin = c[i][j];
        }
    fclose(f);
}
void printSol()
{

    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
    cout << "minCost: " << minCost << endl;
}
bool check(int k, int i)
{
    if (visited[i])
        return false;
    ncost += c[res[k - 1]][i];
    if (((n - cnt) * cmin + ncost) > minCost)
    {
        ncost -= c[res[k - 1]][i];
        return false;
    }
    return true;
}
void Try(int k)
{

    for (int i = 1; i <= n; i++)
    {
        if (check(k, i))
        {
            res[k] = i;
            visited[i] = true;
            cnt++;
            if (k == n)
            {
                ncost += c[res[k]][res[1]];
                if (ncost < minCost)
                    minCost = ncost;
                ncost -= c[res[k]][res[1]];
            }
            else
                Try(k + 1);
            visited[i] = false;
            cnt--;
            ncost -= c[res[k - 1]][res[k]];
        }
    }
}
int main()
{
    input();
    Try(1);
    printSol();
    system("pause");
}