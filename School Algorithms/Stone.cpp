#include <bits/stdc++.h>
#define MAX 200001
using namespace std;
unsigned long long n, q, t, i, x;
unsigned long long sum = 0;
int a[MAX];
unordered_map<int, int> m;
unordered_map<int, int>::iterator it;
int pre_num = -1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    while (q > 0)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> i >> x;
            it = m.find(i);
            if (it == m.end())
            {
                if (pre_num == -1)
                    sum += x - a[i];
                else
                {
                    sum += x - pre_num;
                    m.insert({i, x});
                }
                a[i] = x;
            }
            else
            {
                sum += x - a[i];
                m.erase(it);
                m.insert({i, x});
            }
        }
        else
        {
            cin >> x;
            sum = n * x, pre_num = x;
            m.clear();
        }
        cout << sum << endl;
        --q;
    }
}