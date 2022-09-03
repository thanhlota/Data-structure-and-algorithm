// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//         cin >> v[i];
//     vector<vector<int>> g(n);
//     auto Add = [&](int i, int j)
//     {
//         g[j].push_back(i);
//     };
//     for (int rot = 0; rot < 2; rot++)
//     {
//         vector<int> st;
//         // v[st[0]]>v[st[1]]>.....>v[st.back()]
//         for (int i = 0; i < n; i++)
//         {
//             // int foo;
//             // if (!st.empty())
//             //     foo = v[st.back()];
//             while (!st.empty() && v[st.back()] < v[i])
//             {
//                 Add(st.back(), i);
//                 st.pop_back();
//             }
//             if (!st.empty())
//             {
//                 Add(st.back(), i);
//                 if (v[st.back()] == v[i])
//                 {
//                     st.pop_back();
//                 }
//             }
//             st.push_back(i);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             v[i] = -v[i];
//         }
//     }
//     vector<int> dp(n, INT_MAX);
//     dp[0] = 0;
//     for (int i = 1; i < n; i++)
//     {

//         for (int &k : g[i])
//         {
//             dp[i] = min(dp[i], dp[k] + 1);
//         }
//     }
//     cout << dp[n - 1];
// }

/// 1 2 3 8 9 10
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool check = true;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        if (n % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> res;
        sort(v.begin(), v.end());
        int foo = (n + 1) / 2;
        auto print = [&](vector<int> res)
        {
            for (int i = 0; i < n; i++)
                cout << res[i] << " ";
        };
        for (int i = 0; i < foo; i++)
        {
            res.push_back(v[i]);
            if ((i + foo) >= n)
                continue;
            // if ((i + foo) < n)
            res.push_back(v[i + foo]);
        }
        for (int i = 1; i < n; i++)
        {
            if (res[i] == res[i - 1])
            {
                check = false;
                break;
            }
        }
        if (res[n - 1] == res[0])
            check = false;
        if (!check)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        print(res);
        cout << endl;
    }
}