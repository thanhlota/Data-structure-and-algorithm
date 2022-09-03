#include <bits/stdc++.h>
using namespace std;
// Truy vấn: A(i) = v
// Hàm cập nhật trên cây ST, cập nhật cây con gốc id quản lý đọan [l, r]
int ST[100000]{0};
void update(int id, int l, int r, int i, int v)
{
    if (l == r)
    {
        ST[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    if (i > mid)
    {
        update(2 * id + 2, mid + 1, r, i, v);
    }
    else
    {
        update(2 * id + 1, l, mid, i, v);
    }
    ST[id] = max(ST[2 * id + 2], ST[2 * id + 1]);
}
// Truy vấn: tìm max đoạn [u, v]
// Hàm tìm max các phần tử trên cây ST nằm trong cây con gốc id - quản lý đoạn [l, r]
int get(int id, int l, int r, int u, int v)
{
    if (l > u || r < v)
        return INT_MIN;
    if (l <= u && u <= r)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return max(get(2 * id + 1, l, mid, u, v), get(2 * id + 2, mid + 1, r, u, v)); // the first index is 0. if 1 return max(2*id, 2*id+1)
}
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        update(0, 0, 9, i, a[i]);
    }
}