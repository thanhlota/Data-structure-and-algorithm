#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int first;
    int second;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool check[101]{false};
    Node vec[101];
    int n;
    cin >> n;
    int front;
    int back;
    for (int i = 1; i <= n; i++)
    {
        cin >> front;
        cin >> back;
        vec[i].first = front;
        vec[i].second = back;
    }
    int tmp, nf, ne;
    check[1] = true;
    tmp = 1;
    while (vec[tmp].first != 0)
    {
        tmp = vec[tmp].first;
        check[tmp] = true;
    }
    nf = tmp;
    tmp = 1;
    while (vec[tmp].second != 0)
    {
        tmp = vec[tmp].second;
        check[tmp] = true;
    }
    ne = tmp;
    for (int i = 2; i <= n; i++)
    {
        tmp = i;
        if (check[i]==false)
        {
            while (vec[tmp].second != 0)
            {
                tmp = vec[tmp].second;
                check[tmp] = true;
            }
            vec[tmp].second = nf;
            vec[nf].first = tmp;
            tmp = i;
            while (vec[tmp].first != 0)
            {
                tmp = vec[tmp].first;
                check[tmp] = true;
            }
            nf = tmp;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << vec[i].first << " " << vec[i].second << endl;
    // system("pause");
}
