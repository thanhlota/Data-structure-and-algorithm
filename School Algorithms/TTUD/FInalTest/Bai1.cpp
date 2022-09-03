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
int main()
{
    vector<transact> v;
    string s;
    string r;
    int m;
    string t;
    string code;
    while (cin >> s)
    {
        if (s == "#")
            break;
        cin >> r >> m >> t >> code;
        v.push_back(transact(s, r, m, t, code));
    }
    string q;
    while (cin >> q)
    {
        if (q == "#")
            break;
        // if (q == "?total_money_transaction")
        // {
        long long res = 0;
        for (int i = 0; i < v.size(); i++)
            res += v[i].m;
        cout << res << "\n";
    }
    // system("pause");
    // }
}
