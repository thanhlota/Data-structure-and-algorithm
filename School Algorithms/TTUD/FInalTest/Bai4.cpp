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
const int MAX = 86400;
int gd[MAX];
int minVal(int x, int y)
{
    return (x > y) ? x : y;
}
int getMid(int s, int e) { return s + (e - s) / 2; }
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MIN;
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
                  RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}
int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se,
                    int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                    constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;

    int *st = new int[max_size];

    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);

    // Return the constructed segment tree
    return st;
}
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
        string h, mi, s;
        h.push_back(t[0]);
        h.push_back(t[1]);
        mi.push_back(t[3]);
        mi.push_back(t[4]);
        s.push_back(t[6]);
        s.push_back(t[7]);
        int hour, minute, second;
        hour = stoi(h);
        minute = stoi(mi);
        second = stoi(s);
        int time = hour * 60 * 60 + minute * 60 + second;
        gd[time] = max(gd[time], m);
    }
    int *st = constructST(gd, MAX);
    string q;
    while (cin >> q)
    {
        if (q == "#")
            break;
        string t, t1;
        cin >> t >> t1;
        string h, mi, s;
        h.push_back(t[0]);
        h.push_back(t[1]);
        mi.push_back(t[3]);
        mi.push_back(t[4]);
        s.push_back(t[6]);
        s.push_back(t[7]);
        int h1, m1, s1;
        h1 = stoi(h);
        m1 = stoi(mi);
        s1 = stoi(s);
        int time1 = h1 * 60 * 60 + m1 * 60 + s1;
        h.clear();
        mi.clear();
        s.clear();
        h.push_back(t1[0]);
        h.push_back(t1[1]);
        mi.push_back(t1[3]);
        mi.push_back(t1[4]);
        s.push_back(t1[6]);
        s.push_back(t1[7]);
        int h2, m2, s2;
        h2 = stoi(h);
        m2 = stoi(mi);
        s2 = stoi(s);
        int time2 = h2 * 60 * 60 + m2 * 60 + s2;
        cout << RMQ(st, MAX, time1, time2) << "\n";
    }
    system("pause");
    // }
}
