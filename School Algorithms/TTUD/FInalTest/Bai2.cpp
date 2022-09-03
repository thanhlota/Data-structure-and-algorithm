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
    map<string, long long> mp;
    while (cin >> s)
    {
        if (s == "#")
            break;
        cin >> r >> m >> t >> code;
        v.push_back(transact(s, r, m, t, code));
        mp[s] += m;
    }
    string q;
    while (cin >> q)
    {
        if (q == "#")
            break;
        // if (q == "?total_money_transaction")
        // {
        string foo;
        cin >> foo;
        cout << mp[foo] << "\n";
    }
    // system("pause");
    // }
}
