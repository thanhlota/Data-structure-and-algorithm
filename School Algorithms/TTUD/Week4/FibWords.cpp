
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<string> v(27, "");
void pre_process()
{
    v[0] = "0";
    v[1] = "1";
    for (int i = 2; i <= 26; i++)
    {
        v[i].append(v[i - 1]);
        v[i].append(v[i - 2]);
    }
}
void pre_count(vector<ull> &res, int n, string s)
{

    int bound = v[n].size() - s.size() + 1;
    for (int j = 0; j < bound; j++)
    {
        int foo = 0;
        int k = j;
        while (v[n][k] == s[foo])
        {
            k++;
            foo++;
            if (foo == s.size())
            {
                res[n] += 1;
                break;
            }
        }
    }
}

ull odd_mix_cnt(string s)
{
    ull cnt = 0;
    string tmp = v[25];
    tmp.append(tmp);
    // int sz = s.size();
    int init = v[25].size() - s.size() + 1;
    for (int i = init; i < v[25].size(); i++)
    {
        int j = i;
        int k = 0;
        while (tmp[j] == s[k])
        {
            j++;
            k++;
            if (k == s.size())
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
ull even_mix_cnt(string s)
{
    ull cnt = 0;
    string tmp = v[26];
    tmp.append(v[25]);
    // int sz = s.size();
    int init = v[26].size() - s.size() + 1;
    for (int i = init; i < v[26].size(); i++)
    {
        int j = i;
        int k = 0;
        while (tmp[j] == s[k])
        {
            j++;
            k++;
            if (k == s.size())
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int cs = 1;
    pre_process();
    while (cin >> n)
    {
        vector<ull> res(101, 0);
        string s;
        cin >> s;
        if (n <= 26)
            pre_count(res, n, s);
        else
        {
            pre_count(res, 25, s);
            pre_count(res, 26, s);
            ull tmp1 = odd_mix_cnt(s);
            ull tmp2 = even_mix_cnt(s);
            // ull cnt = mix_cnt(s);
            for (int i = 27; i <= n; i++)
            {
                res[i] = res[i - 1] + res[i - 2];
                if (i & 1)
                    res[i] += tmp1;
                else
                    res[i] += tmp2;
            }
        }
        cout << "Case " << cs << ": " << res[n] << "\n";
        cs++;
        // cout.flush();
    }
}