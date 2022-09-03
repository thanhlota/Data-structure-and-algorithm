// using dp and segment tree
#include <bits/stdc++.h>
using namespace std;
vector<long long> st;
void update(int id, int l, int r, int i, long long v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, i, v);
    update(id * 2 + 2, mid + 1, r, i, v);
    st[id] = max(st[id * 2 + 2], st[id * 2 + 1]);
}
long long get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return 0;
    }
    if (u <= l && r <= v)
    {
        return st[id];
    }
    int mid = (l + r) / 2;
    return max(get(id * 2 + 1, l, mid, u, v), get(id * 2 + 2, mid + 1, r, u, v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long mx = -1;
    vector<long long> dp(n);
    int x = (int)(ceil(log2(n)));
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
    st.resize(max_size, 0);
    for (int i = 0; i < l; i++)
    {
        dp[i] = v[i];
        update(0, 0, n - 1, i, v[i]);
    }
    for (int j = l; j < n; j++)
    {
        int t = max(j - r, 0);
        dp[j] = get(0, 0, n - 1, t, j - l) + v[j];
        mx = max(mx, dp[j]);
        update(0, 0, n - 1, j, dp[j]);
    }
    cout << mx;
    // system("pause");
}