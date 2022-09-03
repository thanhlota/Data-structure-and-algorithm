#include <bits/stdc++.h>
using namespace std;
// vector<int> a;
// vector<int> b;
// void swap(int i, int j)
// {
//     int tmp = a[i];
//     a[i] = a[j];
//     a[j] = tmp;
//     tmp = b[i];
//     b[i] = b[j];
//     b[j] = tmp;
// }
// void selectionSort()
// {
//     vector<pair<int, int>> v;
//     int cnt = 0;
//     int k = a.size();
//     for (int i = 0; i < k - 1; i++)
//     {
//         int min_v = a[i];
//         for (int j = i + 1; j < k; j++)
//         {
//             if ((a[i] > a[j]) || (a[i] == a[j] && b[i] > b[j]))
//             {
//                 cnt += 1;
//                 swap(i, j);
//                 v.push_back({i, j});
//             }
//         }
//     }
//     cout << cnt << endl;
//     for (int i = 0; i < v.size(); i++)
//         cout << v[i].first + 1 << " " << v[i].second + 1 << endl;
// }
// bool check()
// {
//     int k = a.size();
//     for (int i = 0; i < k; i++)
//     {
//         for (int j = i + 1; j < k; j++)
//         {

//             int tmp = (a[i] - a[j]) * (b[i] - b[j]);
//             if (tmp < 0)
//                 return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int t, n;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n;
//         int tmp;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> tmp;
//             a.push_back(tmp);
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> tmp;
//             b.push_back(tmp);
//         }
//         if (!check())
//         {
//             cout << "-1" << endl;
//         }
//         else
//         {
//             selectionSort();
//         }
//         a.clear();
//         b.clear();
//     }
// }
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        vector<int> a, b;
        cin >> n;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            b.push_back(tmp);
        }
        vector<pair<int, int>> v;
        vector<pair<int, int>> res;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            v.push_back({a[i], b[i]});
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (v[j].first == a[i] && v[j].second == b[i])
                {
                    
                    ok = true;
                    if (i != j)
                    {
                        cnt += 1;
                        swap(v[i], v[j]);
                        res.push_back({i + 1, j + 1});
                    }
                    break;
                }
            }
            if (v[i]!=make_pair(a[i],b[i]))
            {
                ok=false;
                cout << -1 << endl;
                break;
            }
        }
        if (ok)
        {
            cout << cnt << endl;
            for (int i = 0; i < res.size(); i++)
                cout << res[i].first << " " << res[i].second << endl;
        }
    }
}